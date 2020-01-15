/*
 *  Copyright 2010 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  I2C header file
 *
 */

#ifndef BackLigth_
#define BackLigth_



Int16 BackLigth()
{		
    
#define OSD9616_I2C_ADDR 0x76    // TPS60252 I2C address


    
	Uint8 cmd[3];    

    //SYS_PCGCR1 &= ~0x0040;
	    
    USBSTK5515_I2C_init( );
                          
    cmd[0] = 0x00;
    cmd[1] = 0x21;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );                                
    //cmd[0] = 0x02;
    //cmd[1] = 0x0f;    
    //USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );                                           
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x00;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x01;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x02;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x03;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );			
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x04;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x05;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x06;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x07;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );					
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x08;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x09;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x0a;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x0b;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );					
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x0c;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x0d;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x0e;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x0f;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );							
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x10;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x11;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x12;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x13;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );						
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x14;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x15;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x16;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x17;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );				
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x18;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x19;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x1a;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x1b;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );					
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x1c;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x1d;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x1e;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x1f;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );						
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x20;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x21;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x22;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x23;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );						
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x24;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x25;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x26;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x27;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );						
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x28;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x29;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x2a;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x2b;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );						
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x2c;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x2d;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x2e;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x2f;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 10000 );
	cmd[0] = 0x02;
    cmd[1] = 0x30;    
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 2 );		
	waitusec( 100000 );
	waitusec( 100000 );
	waitusec( 100000 );
	waitusec( 100000 );
	waitusec( 100000 );
	waitusec( 100000 );
	
	
	return 0;
}




#endif
