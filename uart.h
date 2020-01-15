#ifndef _uart_H_
#define _uart_H_







/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _UART_open( divisor )                                                   *
 *                                                                          *
 *      Open UART handle                                                    *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 UART_INIT( )
{
		       
        UART_PWREMU_MGMT &= ~0xe000;  // Place the UART transmitter and receiver in reset                        
                       
        UART_DLL = 0x0036;  		  //Divisor = UART input clock frequency / (Desired baud rate*16) = 115200 = 100MHz / (54 * 16)= 115200
        UART_DLH = 0x0000;
        
        UART_FCR = 0x00CF;            // Clear UART TX & RX FIFOs EN-FIFO
        //UART_FCR = 0xffff;          // Non-FIFO mode-UART_FCR = 0x0000;    
        UART_IER = 0x0003;            // Enable interrupts 0x0007; 
        UART_LCR = 0x0003;            // 8-bit words, 1 STOP bit generated, No Parity, No Stick paritiy, No Break control
                
        UART_MCR = 0x0000;            // RTS & CTS disabled, Loopback mode disabled, Autoflow disabled
                
        UART_PWREMU_MGMT = 0xe001;    // Enable TX & RX componenets
		
	    return 0;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _UART_putChar( uart_handle, data )                                      *
 *                                                                          *
 *      Send 1 byte of serial data                                          *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 EVM5515_UART_putChar( Uint8 data )
{
    UART_THR = data;

    return 0;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _UART_getChar( uart_handle, data )                                      *
 *                                                                          *
 *      Recv 1 byte of serial data                                          *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 EVM5515_UART_getChar( Uint8* data )
{
    *data = UART_THR;

    return 0;
}



// ------------------------------------------------------------------------	*
//                                                                         	*                                      
//      					TX 6 byte of serial data                        *
// 																			*
// ------------------------------------------------------------------------	*                                                                       	*  
Int16 UART_TX_Char(Uint8 data1,Uint8 data2)
{      	      
    
    while((UART_LSR & 0x60)==0);  		// Wait for TX ready  
      
    UART_THR = 0x23;	// Write 1 byte #
    UART_THR = 0x30;   	// Write 2 byte	0
    UART_THR = 0x31;   	// Write 3 byte	1
    UART_THR = data1;  	// Write 4 byte _
    UART_THR = data2;  	// Write 5 byte _  
    UART_THR = 0x0D;   	// Write 6 byte <cr>
      
    return 0;
}



// ------------------------------------------------------------------------	*
//                                                                         	*                                      
//      					TX 6 byte of serial data                        *
// 																			*
// ------------------------------------------------------------------------	*                                                                       	*  
Int16 UART_TX_Char2(Uint8 data1,Uint8 data2)
{      	      
    
    while((UART_LSR & 0x60)==0);  		// Wait for TX ready  
      
    UART_THR = 0x23;	// Write 1 byte #
    UART_THR = 0x30;   	// Write 2 byte	0
    UART_THR = 0x30;   	// Write 3 byte	1      UART_THR = 0x31;   	// Write 3 byte	1
    UART_THR = data1;  	// Write 4 byte _
    UART_THR = data2;  	// Write 5 byte _  
    UART_THR = 0x0D;   	// Write 6 byte <cr>
      
    return 0;
}


// ------------------------------------------------------------------------	*
//                                                                         	*                                      
//      					TX Write 9 byte of serial data                  *
// 																			*
// ------------------------------------------------------------------------	*                                                                       	*  
Int16 UART_TX_Write(Uint8 data1,Uint8 data2)
{      	  
    while((UART_LSR & 0x60)==0);  		// Wait for TX ready  
      
    UART_THR = 0x23;	// Write 1 byte #
    UART_THR = 0x30;   	// Write 2 byte	0
    UART_THR = 0x31;   	// Write 3 byte	1    
    UART_THR = 0x57;   	// Write 4 byte	W
    
    UART_THR = ((data1>>4)|0x30);  		// Write 5 byte
    UART_THR = ((data1&0x0F)|0x30) ;  	// Write 6 byte
      
    UART_THR = ((data2>>4)|0x30);  		// Write 7 byte
    UART_THR = ((data2&0x0F)|0x30) ;  	// Write 8 byte
      
    UART_THR = 0x0D;   	// Write 9 byte <cr>
      
    return 0;
}


// ------------------------------------------------------------------------	*
//                                                                         	*                                      
//      					TX Read 7 byte of serial data                  *
// 																			*
// ------------------------------------------------------------------------	*                                                                       	*  
Int16 UART_TX_Read(Uint8 data1)
{      	  
    while((UART_LSR & 0x60)==0);  		// Wait for TX ready  
      
    UART_THR = 0x23;	// Write 1 byte #
    UART_THR = 0x30;   	// Write 2 byte	0
    UART_THR = 0x31;   	// Write 3 byte	1    
    UART_THR = 0x57;   	// Write 4 byte	W
    
    UART_THR = ((data1>>4)|0x30);  		// Write 5 byte
    UART_THR = ((data1&0x0F)|0x30) ;  	// Write 6 byte
            
    UART_THR = 0x0D;   	// Write 7 byte <cr>
      
    return 0;
}




/////////////////////////////////////////////////////////////////////////////




// ------------------------------------------------------------------------	*
//                                                                         	*                                      
//      					RX Read  byte of serial data                  	*
// 																			*
// ------------------------------------------------------------------------	*    
Int16 UART_RX_Read(Uint8 data1)
{ 
	Uint8 rx[10];
    while((UART_LSR & 0x01)==0);  		// Wait for Rx ready
    //EVM5515_UART_getChar( &rx[i] );   	// Read 1 byte
    rx[0]=UART_RBR; 
    rx[1]=UART_RBR; 
    rx[2]=UART_RBR; 
    rx[3]=UART_RBR; 
    rx[4]=UART_RBR; 
    rx[5]=UART_RBR; 
	printf("NAND DEVID = %x\n", rx[0]);	//dec
    printf("NAND DEVID = %x\n", rx[1]);
    printf("NAND DEVID = %x\n", rx[2]);
   	printf("NAND DEVID = %x\n", rx[3]);	 
    printf("NAND DEVID = %x\n", rx[4]);
    printf("NAND DEVID = %x\n", rx[5]);
    return 0;
}











/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  uart_test( )                                                            *
 *      Simple UART loopback test.                                          *
 *      Will write then read back the byte sent to the RS232 connector.     *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 uart_test()
{
    Int16 i, errors = 0;
    
    Uint8 rx[256];
    Uint8 tx[256];

    //Int16 timeout = 0;



    //Open Uart Handle
    UART_INIT( );



    //Setup buffers
    for ( i = 0 ; i < 0x100 ; i++ )
    {
        tx[i] = i;
        rx[i] = 0;
    }



    //UART Test
    for ( i = 64 ; i < 96 ; i++ )
    {
    //TX
  	//timeout = test_timeout;
    while((UART_LSR & 0x60)==0);  // Wait for TX ready
    //{
    //if ( timeout-- < 0 )
    //return -1;
    //}
    EVM5515_UART_putChar( tx[i] );    // Write 1 byte



    /* RX */
   	//timeout = test_timeout;
    while((UART_LSR & 0x01)==0);  // Wait for Rx ready
    //{
    //if ( timeout-- < 0 )
    //return -1;
    //}
    EVM5515_UART_getChar( &rx[i] );   // Read 1 byte
    }

    /* Compare TX & RX buffers */
    for ( i = 64 ; i < 96 ; i++ )
        if ( tx[i] != rx[i] )
            errors++;
    return errors;
}










   
#endif
