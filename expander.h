/*
 *  Copyright 2010 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  I2C header file
 *
 */

#ifndef Expander_
#define Expander_



/*

Int16 Expander_INI()
{		
						         	             
    Uint8 cmd[4];      
     USBSTK5515_I2C_init( );
                                                                   
    cmd[0] = 0x8c;     
    cmd[1] = 0x00; 	
    cmd[2] = 0x00; 	
    cmd[3] = 0xf0; 	
    USBSTK5515_I2C_write( TCA6424_I2C_ADDR1, cmd, 4 );                                
                                                                                     	                                              
   	cmd[0] = 0x84;     
   	cmd[1] = 0x50; 	
   	cmd[2] = 0x74; 	// 72-1G 74-100M 78-10M + DA14
   	cmd[3] = 0x00; 	
   	USBSTK5515_I2C_write( TCA6424_I2C_ADDR1, cmd, 4 );              	      	     
   	      	      	      	      	      	      	      	      	      	      	      	      	      	      	      	      
    return 0;
}





Int16 Expander1_Read()
{		
						         	             
    
    cmd[0] = 0x8c;     
    cmd[1] = 0x00; 	
    cmd[2] = 0x00; 	
    cmd[3] = 0xf0; 	
    USBSTK5515_I2C_write( TCA6424_I2C_ADDR1, cmd, 4 );     
    
                                                                   
    cmd[0] = 0x80;     
    USBSTK5515_I2C_write_non_stop( TCA6424_I2C_ADDR1, cmd, 1 );                                
    
    
                                                                                    	                                                 	     
   	USBSTK5515_I2C_read( TCA6424_I2C_ADDR1, cmd, 3 );              	      	     
   	      	      	      	      	      	      	      	      	      	      	      	      	      	      	      	      
    return 0;
}


*/

    /*                                         
    cmd[0] = 0x80;          
    USBSTK5515_I2C_write_non_stop( OSD9616_I2C_ADDR, cmd, 1 );         
     
    cmd[0] = 0xff;     //na vixod
    cmd[1] = 0xff; 	
    cmd[2] = 0xff; 	
    //cmd[3] = 0x00; 	
    USBSTK5515_I2C_read( OSD9616_I2C_ADDR, cmd, 3 );                      	
						
    print("               ",0,60,Font16x24,BLACK,WHITE);	
    printNumI(cmd[0],0,60,Font16x24,BLACK,WHITE);
    print("               ",0,90,Font16x24,BLACK,WHITE);	
    printNumI(cmd[1],0,90,Font16x24,BLACK,WHITE);
    print("               ",0,120,Font16x24,BLACK,WHITE);	
    printNumI(cmd[2],0,120,Font16x24,BLACK,WHITE);                                                               
    */              
                                          





/*


// ------------------------------------------------------------------------	*
//                                                                         	*                                                        				   	
//							       PowerOn									*
//                                                                          *
//  ----------------------------------------------------------------------- *

Int16 PowerOn()
{		

//#define OSD9616_I2C_ADDR 0x23    // TCA6424 I2C address
			         	               
    Uint8 cmd[2];         
    USBSTK5515_I2C_init( );
                                                                   
    cmd[0] = 0x0c;     
    cmd[1] = 0x00; 	  
    USBSTK5515_I2C_write( TCA6424_I2C_ADDR2, cmd, 2 );                                
                                                                                     	                                              
   	cmd[0] = 0x04;     
   	cmd[1] = 0x01; 	 	
   	USBSTK5515_I2C_write( TCA6424_I2C_ADDR2, cmd, 2 );            
   	           
    return 0;
}



// ------------------------------------------------------------------------	*
//                                                                         	*                                                        				   	
//							      PowerOff									*
//                                                                          *
//  ----------------------------------------------------------------------- *

Int16 PowerOff()
{		

//#define OSD9616_I2C_ADDR 0x23    // TCA6424 I2C address
			         	               
    Uint8 cmd[2];         
    USBSTK5515_I2C_init( );
                                                                   
    cmd[0] = 0x0c;     
    cmd[1] = 0x00; 	  
    USBSTK5515_I2C_write( TCA6424_I2C_ADDR2, cmd, 2 );                                
                                                                                     	                                              
   	cmd[0] = 0x04;     
   	cmd[1] = 0x00; 	 	
   	USBSTK5515_I2C_write( TCA6424_I2C_ADDR2, cmd, 2 );            
   	           
    return 0;
}


*/




#endif
