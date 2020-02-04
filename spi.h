/*
 *  Copyright 2010 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  spi header file
 *
 */

#ifndef spi_
#define spi_

static Uint16 spirombuf[spirom_PAGESIZE + 8];

static Uint16 statusbuf[20];
/* ------------------------------------------------------------------------ *
 *  spirom_init( )                                                          *
 * ------------------------------------------------------------------------ */
void spirom_init( )
{		
	Int16 i;		
	// Reset SPI Module //
	//////////////////////////////////////SYS_PRCNTRLR = 0x00ff;  
	for (i=0; i<1000; i++){} 
	// Enable SPICLK,RX,TX & CS0 //	
    //SYS_EXBUSSEL = 0x5100; // on  - spi-4,uart-4,lcd-8
	//SPI init
	SPI_SPICC2 =   (0<<15); // Reset SPI
    SPI_SPICC1 =   0x03E7;	//0x031;  	// 2MHz input clock f=100M /(0x031+1);yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
    SPI_SPIDC1 =   0x0005;  // polarnost CLK   // AD9833-0x0001; // AD5235-0x0005;OR AD5235-0x0000
    	
    //SPI_SPICR2 &= ~0x30F8;  // Enable CS0
    	
    SPI_SPICR2 |=  0x0038;  // Set word length as 1-byte
    SPI_SPICC2 =  (1<<15); 	// Enable SPI
	while((SPI_SPISR1 & 0x0001) != 0) {}; // Wait for SPI ready
	
	//spirom_status_set( 0xc3 );  // Clear Block Protection
	
    return;
}


/* ------------------------------------------------------------------------ *
 *  spirom_cycle(buf, len)                                                  *
 *                                                                          *
 *  Execute a SPI spirom data transfer cycle.  Each byte in buf is shifted  *
 *  out and replaced with data coming back from the spirom.                 *
 * ------------------------------------------------------------------------ */

int spirom_cycle(Uint16 *buf, Uint16 len)
{
    Uint16 i;
    Uint32 delay, MaxDelay;
    MaxDelay = 600000;
    SPI_SPICR1 = 0x0000 | len - 1;
    i = SPI_SPIDR2;  // Dummy read

   	/* Spirom access cycle */
	for (i = 0; i < len; i++)
	{
		SPI_SPIDR2 = buf[i] << 8;
		SPI_SPIDR1 = 0x0000;
        SPI_SPICR2 = 0x0039;  //  8-bit words, read
        delay=0;
        while((SPI_SPISR1 & 0x0002) == 0)
        {
        	delay++;
        	//if (delay > MaxDelay) return 1;
        };
        buf[i] = SPI_SPIDR2 & 0xff;
	}
	
	/* Wait for transfer to complete */
	delay = 0;
	while((SPI_SPISR1 & 0x0001) != 0)
	{
		delay++;
		//if (delay > MaxDelay) return 1;
	};
	return 0;
//	EVM5515_waitusec(100);
}

/* ------------------------------------------------------------------------ *
 *  spirom_status( )                                                        *
 * ------------------------------------------------------------------------ */
Uint16 spirom_status( )
{
    /* Issue read status command */
    statusbuf[0] = spirom_CMD_RDSR;
    statusbuf[1] = 0;
	if (spirom_cycle(statusbuf, 5) != 0)  return 1;
			else   return statusbuf[3];
}


/* ------------------------------------------------------------------------ *
 *  spirom_status_set( val )                                                *
 * ------------------------------------------------------------------------ */
Uint16 spirom_status_set( Uint8 val)
{
    /* Issue read status command */
    statusbuf[0] = spirom_CMD_WRSR;
    statusbuf[1] = val;
    
	if (spirom_cycle(statusbuf, 2) != 0) return 1;
	else return statusbuf[3];
}



/* ------------------------------------------------------------------------ *
 *  spirom_read( src, dst, len )                                             *
 * ------------------------------------------------------------------------ */
void spirom_read( Uint16 src, Uint32 dst, Uint32 length )
{
    Int32 i;
    Uint16 *psrc, *pdst;

	// Setup command
    spirombuf[0] = spirom_CMD_READ;
    spirombuf[1] = ( src >> 8 );
    spirombuf[2] = ( src >> 0 );

	// Execute spirom read cycle
	spirom_cycle(spirombuf, length + 5);

    // Copy returned data
    pdst = ( Uint16 * )dst;
    psrc = spirombuf + 5;
    for ( i = 0 ; i < length ; i++ )
        *pdst++ = *psrc++;

}
/* ------------------------------------------------------------------------ *
 *  spirom_write( src, dst, len )                                           *
 * ------------------------------------------------------------------------ */
void spirom_write( Uint32 src, Uint16 dst, Uint32 length )
{
    Int32 i;
    Int32 bytes_left;
    Int32 bytes_to_program;
    Uint16 *psrc;

    /* Establish source */
    psrc = ( Uint16 * )src;
    bytes_left = length;

    while ( bytes_left > 0 )
    {
        bytes_to_program = bytes_left;

        /* Most to program is spirom_CMD_BLOCKSIZE */
        if ( bytes_to_program > spirom_PAGESIZE )
             bytes_to_program = spirom_PAGESIZE;

        /* Make sure you don't run off the end of a block */
        if ( ( dst & spirom_PAGEMASK ) != ( ( dst + bytes_to_program ) & spirom_PAGEMASK ) )
            bytes_to_program -= ( dst + bytes_to_program ) - ( ( dst + bytes_to_program ) & spirom_PAGEMASK );

        /* Issue WPEN */
        spirombuf[0] = spirom_CMD_WREN;
        spirom_cycle(spirombuf, 1);

        /* Create command block for program operation */
        spirombuf[0] = spirom_CMD_WRITE;
        spirombuf[1] = ( Uint16 )( dst >> 8 );
        spirombuf[2] = ( Uint16 )( dst );

        for ( i = 0 ; i < bytes_to_program ; i++ )
            spirombuf[3+i] = *psrc++;

        /* Execute write command */
        spirom_cycle(spirombuf, bytes_to_program + 3 );

        /* Wait while busy */
        while( ( spirom_status( ) & 0x01 ) );

        /* Get ready for next iteration */
        bytes_left -= bytes_to_program;
        dst += bytes_to_program;
    }
}

static Uint8 tx[spirom_PAGESIZE];
static Uint8 rx[spirom_PAGESIZE];

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  spirom_test( )                                                          *
 *      SPI ROM test, write then verify the contents of the first 4 pages   *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 spirom_test( )
{
    Int16 i, j;
    Uint16* pdata;

	/* Initialize the SPI interface */
    spirom_init( );

    /* Write to spirom */
    for ( i = 300 ; i < 302 ; i++ )
    {
        /* Create the test pattern */
        pdata = ( Uint16* )tx;
        for ( j = 0 ; j < spirom_PAGESIZE ; j++ )
            *pdata++ = ( Uint8 )( j + i + 8 );

        /* Write a page */
        spirom_write( ( Uint32 )tx, i * spirom_PAGESIZE, spirom_PAGESIZE );
    }
    
    // Read and verify spirom //
    for ( i = 300 ; i < 302 ; i++ )
    {
    	// Clear receive buffer //
        for ( j = 0 ; j < spirom_PAGESIZE ; j++ )
            rx[j] = 0;
            
        // Read a page //
        spirom_read( i * spirom_PAGESIZE, ( Uint32 )rx, spirom_PAGESIZE );

        // Check the pattern //
        pdata = ( Uint16* )rx;
        for ( j = 0 ; j < spirom_PAGESIZE ; j++ )
            if ( ( *pdata++ ) != rx[j] )
                return 1;  // Fail
    }
    return 0;
}


void spi_sin( Uint32 Frequency )
{          
    	Uint16 buf[20];
		Uint32 FregR=0;
		SYS_GlobalIntDisable();
    	SPI_SPIDC1 =   0x0001;
        FregR = (double)(Frequency / 0.4470348358154296875); //בûכמ ןנט 12 ÌÃצ
        EVM5515_GPIO_setOutput(5,0);
  		waitusec( 100 );
    	buf[0] = 0x21;
    	buf[1] = 0x00;
    	buf[3] = FregR;
    	buf[2] = ((((FregR>>8)&0x3F))|0x40);
    	buf[5] = FregR>>14;
    	buf[4] = ((((FregR>>22)&0x3F))|0x40);
    	buf[6] = 0x20;
    	buf[7] = 0x00;
		if (spirom_cycle(buf, 8) != 0) ;
		waitusec( 100 );
     	EVM5515_GPIO_setOutput(5,1);
     	SYS_GlobalIntEnable();
}


void spi_Kus( Uint16 TempKus)
{          						
	Uint16 buf[20];
	Uint16 TempKus1;
	Uint16 TempKus2;
	Uint16 TempKus3;
	Uint16 TempKus4;
	SYS_GlobalIntDisable();
	TempKus  = TempKus / 10;
	if( TempKus > 1023)
	{
		TempKus3 = 1023;
		TempKus2 = TempKus-1023;
		if (TempKus2 > 1023) TempKus2 = 1023;
	}
	else
	{
		TempKus3 = TempKus;
		TempKus2 = 0;
	}
	TempKus1 = 1023;
	if (TempKus > 20460) TempKus4 = TempKus-20460;
		else TempKus4 = TempKus % 10;

	SPI_SPIDC1 =   0x0005;
	EVM5515_GPIO_setOutput(4,0);
	waitusec( 100 );
	buf[0] 	= 0xb0;
	buf[1] 	= ((TempKus4>>8)&0x03);
	buf[2] 	= TempKus4;
	buf[3] 	= 0xb0;
	buf[4] 	= ((TempKus3>>8)&0x03);
	buf[5] 	= TempKus3;
	buf[6] 	= 0xb0;
	buf[7] 	= ((TempKus2>>8)&0x03);
	buf[8] 	= TempKus2;
	buf[9] 	= 0xb0;
	buf[10]	= ((TempKus1>>8)&0x03);
	buf[11]	= TempKus1;
	if (spirom_cycle(buf, 12) != 0) ;
	waitusec( 100 );
	EVM5515_GPIO_setOutput(4,1);
	SYS_GlobalIntEnable();
}


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////




void spi_Kus4( Uint16 TempKus )
{          						
		 
		SPI_SPIDC1 =   0x0005;
        EVM5515_GPIO_setOutput(4,0);
        waitusec( 100 );
		statusbuf[0] = 0xb1; 
		statusbuf[1] = 0;	
		statusbuf[2] = TempKus&0x07;
    	statusbuf[3] = 0xb1; 
		statusbuf[4] = ((TempKus>>11)&0x03);		
		statusbuf[5] = TempKus>>3;	    		      
		spirom_cycle(statusbuf, 6);
        waitusec( 100 );
		EVM5515_GPIO_setOutput(4,1);												    		
}



#endif
