/*
 *  Copyright 2010 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  I2C header file
 *
 */

#ifndef Power_
#define Power_








/*

Int16 WriteOnCharge()
{	
   	//USBSTK5515_I2C_init();  
	cmd[0] = 0x1c;
    cmd[1] = 0x0f;    
    USBSTK5515_I2C_write( AD5272_I2C_ADDR, cmd, 2 );      

	return 0;
}

*/







/*

Int16 Power()
{				
	Int16 voltL;
    Int16 voltH;
    Int16 voltS;
    Uint32 voltR;
	
	Int16 voltShL;
    Int16 voltShH;
    Int16 voltShS;
    Int32 voltShR;
		        		        		         	      	         	      	         	      	         	           
	Uint8 cmd[2];        
    USBSTK5515_I2C_init( );                                                                   
	cmd[0] = 0x01;    
    USBSTK5515_I2C_write( INA219_I2C_ADDR, cmd, 1 );                                    
 	cmd[0] = 0x00;
    cmd[1] = 0x00;    
    USBSTK5515_I2C_read( INA219_I2C_ADDR, cmd, 2 );                                                          
	voltShH=cmd[0];
	voltShL=cmd[1];	
	voltShS=((voltShH<<8)|voltShL);			
	voltShR=voltShS/18;
	print("    ",100,11,Num8x8,BLACK,GRAY4);			 				 	
	printNumI(voltShR,100,11,Num8x8,WHITE,GRAY4);
	
	
	
	
	
	       
 	cmd[0] = 0x02;    
    USBSTK5515_I2C_write( INA219_I2C_ADDR, cmd, 1 );                                    
 	cmd[0] = 0x00;
    cmd[1] = 0x00;    
    USBSTK5515_I2C_read( INA219_I2C_ADDR, cmd, 2 );                                                          
	voltH=cmd[0];
	voltL=cmd[1];	
	voltS=(((voltH<<8)|voltL)>>3)&0x1fff;
	voltR=(Uint32)32*voltS;		 		
	voltR=voltR/80;
	print("    ",100,2,Num8x8,BLACK,GRAY4);	
	printNumI(voltR,100,2,Num8x8,WHITE,GRAY4);

	return 0;
}


*/



#endif
