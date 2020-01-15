#ifndef _NandFlash_H_
#define _NandFlash_H_

//Micron_MT29F256G08CJAAA 1 Device = (8192 Byte x 256 Page x 8192 Blocks = 16GByte) x2 = 32GByte
//Device Organization for Four-Die Package (TSOP)

//EMIF CS0 8M 	0x028000 
//EMIF CS2 4M 	0x400000
//EMIF CS3 2M 	0x600000
//EMIF CS4 1M 	0x700000
//EMIF CS5 1M 	0x780000


#define NANDFLASH_BASE                  0x400000  	// Low CS2
//#define NANDFLASH_BASE                  0x700000  	// Low CS4

#define NANDFLASH_BLOCKS                1024		// Колличество блоков LUN1+LUN2 4096 + 4096
#define NANDFLASH_PAGESPERBLOCK         64			// Страниц в блоке
#define NANDFLASH_PAGES                 (NANDFLASH_BLOCKS * NANDFLASH_PAGESPERBLOCK)// Колличество страниц всего
#define NANDFLASH_PAGESIZE              2048		// Размер страницы
#define NANDFLASH_SPARESIZE             64			// Размер страницы+

#define NANDFLASH_DATA  *( volatile Uint8* )( NANDFLASH_BASE + 0x00 )
#define NANDFLASH_CLE   *( volatile Uint8* )( NANDFLASH_BASE + 0x2000 )
#define NANDFLASH_ALE   *( volatile Uint8* )( NANDFLASH_BASE + 0x1000 )

#define CMD_READ_EC                		0xEC
#define CMD_READID                  	0x90
#define CMD_READ                    	0x00
#define CMD_READ_CONFIRM            	0x30
#define CMD_PROGRAM                 	0x80
#define CMD_PROGRAM_CONFIRM         	0x10
#define CMD_ERASE                   	0x60
#define CMD_ERASE_CONFIRM           	0xd0
#define CMD_STATUS                  	0x70
#define CMD_RESET                   	0xff

static Uint8 src[NANDFLASH_PAGESIZE + NANDFLASH_SPARESIZE];
static Uint8 dst[NANDFLASH_PAGESIZE + NANDFLASH_SPARESIZE];


// ------------------------------------------------------------------------	*
//                                                                         	*                                                        				   	
//							      nand_init									*
//                                                                          *
//  ----------------------------------------------------------------------- *

Int16 nand_init()
{
    Uint16 devid0;
    Uint16 devid1;
    Uint16 devid2;
    Uint16 devid3;
    Uint16 devid4;
    
    /* Configuring NAND */
	/* Reset Counter value */
///	*(ioport volatile unsigned *)0x1C04=0x10;
	/* reset Emif Module */
///	*(ioport volatile unsigned *)0x1C05=0x2;
///	for(i=0;i<500;i++){;}

///	*(ioport volatile int *)0x1C02 &= 0x77FF;
	/* Reset Counter value */
///	*(ioport volatile unsigned *)0x1C04=0x020;
	/* reset I2C Module */
///	*(ioport volatile unsigned *)0x1C05=0x00fb;
///	for(i=0; i<50; i++);
	
	// Config EMIF - ASYNC-Wait Config Regsiters
	EMIF_AWCCR1 = 0x0080;   // Maximum extended wait cycles. 0x1004
	EMIF_AWCCR2 = 0x00E4;	// bilo 0x00E4;. 0x1005
	
	// Configure as 8-bit data bus
	//EMIF_ACS2CR1 = 0xFFFC;	// задержки можно увеличить а пока по максимуму  0x1010
	// EMIF_ACS2CR2 = 0x4020;
	// Async1 uses Nand 
	
	
	//EMIF_ACS2CR1 = 0x0000;	
	//EMIF_ACS2CR2 = 0x0000;
	//EMIF_ACS3CR1 = 0x0000;	
	//EMIF_ACS3CR2 = 0x0000;
	//EMIF_ACS4CR1 = 0x0000;	
	//EMIF_ACS4CR2 = 0x0000;
	//EMIF_ACS5CR1 = 0x0000;	
	//EMIF_ACS5CR2 = 0x0000;
	
	
	
    EMIF_NANDFCR &= ~0x000F;
    EMIF_NANDFCR |=  0x000F;	//   bilo 0x0004 вкл. cs  0x1060
              
	NANDFLASH_CLE = CMD_RESET;
	EVM5515_waitusec(100000);

    // Start erase operation
    NANDFLASH_CLE = CMD_READID;
    NANDFLASH_ALE = 0x00;

	// Wait for command completion
	EVM5515_wait(1);
	while((EMIF_NANDFSR1 & 0x01) == 0); //0x08 for CS5 // 0x04 for CS4 // 0x02 for CS3 // 0x01 for CS2

	// Get IDs
    devid0 = NANDFLASH_DATA;
    devid1 = NANDFLASH_DATA;
    devid2 = NANDFLASH_DATA;
    devid3 = NANDFLASH_DATA;
    devid4 = NANDFLASH_DATA;
   
	printf("NAND DEVID = %02x\n", devid0);	
	printf("NAND DEVID = %02x\n", devid1);
	printf("NAND DEVID = %02x\n", devid2);
	printf("NAND DEVID = %02x\n", devid3);
	printf("NAND DEVID = %02x\n", devid4);





	if ((devid0 != 0x2C)&&(devid1 != 0xA8)&&(devid2 != 0x05)&&(devid3 != 0xCB)&&(devid4 != 0xA9))
	{
	    return 1;
	}
	else
	{
		return 0;
	}
}


// ------------------------------------------------------------------------	*
//                                                                         	*                                                        				   	
//							  nand_eraseBlock							    *
//                                                                          *
//  ----------------------------------------------------------------------- *
Int16 nand_eraseBlock(Uint32 blocknum)
{
    Uint32 status;

    // Start erase operation
    NANDFLASH_CLE = CMD_ERASE;
    NANDFLASH_ALE = (blocknum & 0x00000003) << 6;
	NANDFLASH_ALE = (blocknum & 0x000003FC) >> 2;
	NANDFLASH_CLE = CMD_ERASE_CONFIRM;

	// Wait for erase completion
	EVM5515_wait(1);
	while((EMIF_NANDFSR1 & 0x01) == 0); //0x08 for CS5 // 0x04 for CS4 // 0x02 for CS3 // 0x01 for CS2

	// Check erase status
	NANDFLASH_CLE = CMD_STATUS;
	status = NANDFLASH_DATA;

	//NANDFLASH_CLE = CMD_RESET;
	if (status & 0x01)
        return 1;  // Error
	else
    	return 0;  // OK
}

// ------------------------------------------------------------------------	*
//                                                                         	*                                                        				   	
//							  nand_readPage							        *
//                                                                          *
//  ----------------------------------------------------------------------- *

Int16 nand_readPage(Uint32 pagenum, Uint8 *buf, Uint16 len)
{
    Uint8 *dptr;
	Uint16 i;

    NANDFLASH_CLE = CMD_READ;
	NANDFLASH_ALE = (pagenum & 0x000000FF);
	NANDFLASH_ALE = (pagenum & 0x00000700) >> 8;
    NANDFLASH_ALE = (pagenum & 0x0007F800) >> 11;
	NANDFLASH_ALE = (pagenum & 0x07F80000) >> 19;
	NANDFLASH_CLE = CMD_READ_CONFIRM;

	// Wait for read completion
	EVM5515_waitusec(1);
	while((EMIF_NANDFSR1 & 0x01) == 0);	//0x08 for CS5 // 0x04 for CS4 // 0x02 for CS3 // 0x01 for CS2

	// Read data
	dptr = buf;
	for (i = 0; i < len; i++)
	{
		*dptr++ = NANDFLASH_DATA; 			
	}
	return 0;
}



// ------------------------------------------------------------------------	*
//                                                                         	*                                                        				   	
//							 nand_writePage				    		        *
//                                                                          *
//  ----------------------------------------------------------------------- *

Int16 nand_writePage(Uint32 pagenum, Uint8 *buf, Uint16 len)
{
    Uint8 *dptr;
    Uint16 i;
    Uint32 status;

	// Start program operation
    NANDFLASH_CLE = CMD_PROGRAM;
	NANDFLASH_ALE = (pagenum & 0x000000FF);
	NANDFLASH_ALE = (pagenum & 0x00000700) >> 8;
    NANDFLASH_ALE = (pagenum & 0x0007F800) >> 11;
	NANDFLASH_ALE = (pagenum & 0x07F80000) >> 19;

	
	dptr = buf;
	for (i = 0; i < len; i++)
	{	
		NANDFLASH_DATA = *dptr++;
	}
	
	NANDFLASH_CLE = CMD_PROGRAM_CONFIRM;


	// Wait for program completion
    EVM5515_waitusec(1);
	while((EMIF_NANDFSR1 & 0x01) == 0);	//0x08 for CS5 // 0x04 for CS4 // 0x02 for CS3 // 0x01 for CS2


	// Check program status
	NANDFLASH_CLE = CMD_STATUS;
	status = NANDFLASH_DATA;

	//NANDFLASH_CLE = CMD_RESET;
	if (status & 0x01)
        return 1;  // Error
	else
    	return 0;  // OK
}













// ------------------------------------------------------------------------	*
//                                                                         	*                                                        				   	
//							 nandflash_test				    		        *
//                            4MB of NAND                                   *
//  ----------------------------------------------------------------------- *

Int16 nandflash_test( )
{

	Uint32 i, errors;
	
	// Initialize NAND
	// nand_init();

    // Erase all of NAND 
	printf("Erasing NAND blocks...\n");
	errors = 0;
	
	
	
	
	for (i = 0; i < 1024; i++)
	{ 				
        errors += nand_eraseBlock(i);
	}
	printf("--> %d block erase errors\n", errors);
		
	
	if (errors >= 3)
	{
		printf("Erasing NAND blocks EEERRoooooooooooooooooooooooor\n");
	}	
	else
	{
		;
	}
	
	
	nand_eraseBlock(1023);
	
	 
	for (i = 0; i < 16; i++)
	{		
		src[i] = i;     	    	               	   	     
	}
		
	nand_writePage(0x0007FFFF00, src, 16);

	for (i = 0; i < 16; i++)
	{		
		dst[i] = 0;	        	    	               	   	     
	}

	nand_readPage(0x0007FFFF00, dst, 16);




	printf("NAND DEVID = %x\n", dst[0]);	//hex
	printf("NAND DEVID = %x\n", dst[1]);
	printf("NAND DEVID = %x\n", dst[2]);
	printf("NAND DEVID = %x\n", dst[3]);
	printf("NAND DEVID = %x\n", dst[4]);
	printf("NAND DEVID = %x\n", dst[5]);	
	printf("NAND DEVID = %x\n", dst[6]);
	printf("NAND DEVID = %x\n", dst[7]);
	printf("NAND DEVID = %x\n", dst[8]);
	printf("NAND DEVID = %x\n", dst[9]);
	printf("NAND DEVID = %x\n", dst[10]);
	printf("NAND DEVID = %x\n", dst[11]);	
	printf("NAND DEVID = %x\n", dst[12]);
	printf("NAND DEVID = %x\n", dst[13]);
	printf("NAND DEVID = %x\n", dst[14]);
	printf("NAND DEVID = %x\n", dst[15]);




    printf("NAND DEVID = %d\n", dst[0]);	//dec
    printf("NAND DEVID = %d\n", dst[1]);
    printf("NAND DEVID = %d\n", dst[2]);
   	printf("NAND DEVID = %d\n", dst[3]);	 
    printf("NAND DEVID = %d\n", dst[4]);
    printf("NAND DEVID = %d\n", dst[5]);
    printf("NAND DEVID = %d\n", dst[6]);
   	printf("NAND DEVID = %d\n", dst[7]);	
   	printf("NAND DEVID = %d\n", dst[8]);
    printf("NAND DEVID = %d\n", dst[9]);
    printf("NAND DEVID = %d\n", dst[10]);
   	printf("NAND DEVID = %d\n", dst[11]);
   	printf("NAND DEVID = %d\n", dst[12]);
    printf("NAND DEVID = %d\n", dst[13]);
    printf("NAND DEVID = %d\n", dst[14]);
   	printf("NAND DEVID = %d\n", dst[15]);		
   	
	return 0;
	
	
}










   
#endif
