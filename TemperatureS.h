/*
 *  Copyright 2010 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  I2C header file
 *
 */

#ifndef TemperatureS_
#define TemperatureS_



Int16 temperatura()
{		

#define OSD9616_I2C_ADDR 0x40    // SH21 I2C address



    Int16 tempL;
    Int16 tempH;
    Int16 tempS;
    Uint32 tempR;
    
    Int16 humL;
    Int16 humH;
    Int16 humS;
    Uint32 humR;
              
    //Int16 i;
	Uint8 cmd[3];    // For multibyte commands

    //SYS_PCGCR1 &= ~0x0040;
	
    /* Initialize I2C */
    USBSTK5515_I2C_init( );
       
    cmd[0] = 0xf3;  //Temper
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 1 );
                    
    waitusec( 30000 );      
                                
    cmd[0] = 0x00;
    cmd[1] = 0x00;    
    cmd[2] = 0x00;    
    USBSTK5515_I2C_read( OSD9616_I2C_ADDR, cmd, 3 );
                                                         
	tempH=cmd[0];
	tempL=cmd[1];	
	tempS=((tempH<<8)|tempL)&0xfffc;
	tempR=(Uint32)17572*tempS;		  // �u1077  �u1088 �u1074 �u1083 �u1085 ��u1095 �u1090 �u1077 � �u1090 �u1077 �u1072 �u1090  �u1089 �u1080  �u1086 �u1100 �u1077  �u1085 �u1095 �u1085 �u1077  �tempS �u1086 �u1100 �u1077  32768
	tempR=tempR>>16;
	tempR=tempR-4685;
	tempR=tempR/100;

    cmd[0] = 0xf5;    // RH
    USBSTK5515_I2C_write( OSD9616_I2C_ADDR, cmd, 1 );
    
                 
    waitusec( 30000 );      
                
                
    cmd[0] = 0x00;
    cmd[1] = 0x00;    
    cmd[2] = 0x00;    
    USBSTK5515_I2C_read( OSD9616_I2C_ADDR, cmd, 3 );
    
                                                      
	humH=cmd[0];
	humL=cmd[1];
	humS=((humH<<8)|humL)&0xfffc;	
	humR=(Uint32)125*humS/65535-6;  // �u1077  �u1088 �u1074 �u1083 �u1085 ��u1095 �u1090 �u1077 � �u1090 �u1077 �u1072 �u1090  �u1089 �u1080  �u1086 �u1100 �u1077  �u1085 �u1095 �u1085 �u1077  �tempS �u1086 �u1100 �u1077  32768
	

	printNumI(tempR,10,60,Num48x61,BLACK,WHITE);
	print("����",120,90,FontRus16x27,BLACK,WHITE);	
    	printNumI(humR,10,140,Num48x61,BLACK,WHITE);
    	print("����",120,170,FontRus16x27,BLACK,WHITE);	
   
	return 0;
}






Int16 counter()
{		      
    long i;	
    
    for(i=0;i<2000000000;i++)
    {
    printNumI(i,0,92,Font16x24,BLACK,WHITE);
    } 	 	
	return 0;
}





#endif
