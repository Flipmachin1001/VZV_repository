/*
 *  Copyright 2010 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  I2C header file
 *
 */

#ifndef _FunctionRTC_H_
#define _FunctionRTC_H_


void OnChargRTC(void)
{						         	                                                                            
    cmd[0] = 0x08;     
    cmd[1] = 0xA7; 	    	   
    USBSTK5515_I2C_write( DC1340_I2C_ADDR, cmd, 2 );                                            	                	                	                	                	                                                                                                                  	                                                     
}

void OffChargRTC(void)
{						         	                                                                              
    cmd[0] = 0x08;     
    cmd[1] = 0x00; 	    	   
    USBSTK5515_I2C_write( DC1340_I2C_ADDR, cmd, 2 );                                            	                	                	                	                	                                                                                                                  	                                                               
}

void ReadRTC___(void)
{						         	                                                                                    
    cmd[0] = 0x08;          
    USBSTK5515_I2C_write( DC1340_I2C_ADDR, cmd, 1 );                                                                                     
    cmd[0] = 0x00;          		     	  
    USBSTK5515_I2C_read( DC1340_I2C_ADDR, cmd, 1 );                                                                                                                     	                                                       	                                                                                                                  	                                                        
}

void ReadRTC(void)
{						         	                                                                                    
    cmd[0] = 0x00;          
    USBSTK5515_I2C_write( DC1340_I2C_ADDR, cmd, 1 );                                                                                     
    cmd[0] = 0x00;     
    cmd[1] = 0x00; 	
    cmd[2] = 0x00; 	
    cmd[3] = 0x00; 	
    cmd[4] = 0x00;     
    cmd[5] = 0x00; 	
    cmd[6] = 0x00; 		     	   
    USBSTK5515_I2C_read( DC1340_I2C_ADDR, cmd, 7 );                                                                                                                     	                                                       	                                                                                                                  	                                                     
}

void WriteRTC(void)
{				                                                                
    cmd[0] = 0x00;         
    cmd[1] = RTC_SEC;
    cmd[2] = RTC_MIN;     
    cmd[3] = RTC_HOUR;
    cmd[4] = 0x00;
    cmd[5] = RTC_DAY;     
    cmd[6] = RTC_MONTH;
    cmd[7] = RTC_YEAR;    
    USBSTK5515_I2C_write( DC1340_I2C_ADDR, cmd, 8 );                                                                                                                     	                                                 	    	                                                                                                                  	                                                      
}





#endif
