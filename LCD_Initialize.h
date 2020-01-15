/*   ==========================================================================
 *   Copyright (c) Shubin Vladimir, 2011
 *   ==========================================================================
 */



#ifndef _LCD_Initialize_H
#define _LCD_Initialize_H



Int16 LCD_INI()
{

	Int16 i;
	for (i=0; i< 100; i++){}
	
	//Enable divide CLK
	LCD_LCDCR = 0x0000;  

	//Set AsyncMPU80 mode
	LCD_LCDLIDDCR &= ~0x07;
	LCD_LCDLIDDCR |=  0x03;

		
	// Max out strobe, setup and hold timings
	//LCD_LCDLIDDCS0CONFIG0 = 0xFFFD;  // Read Strobe Set-Up cycles		
	//LCD_LCDLIDDCS0CONFIG1 = 0x7FFF;  // Write		
	
	LCD_LCDLIDDCS0CONFIG0 = 0x0000;  // Read Strobe Set-Up cycles					
	LCD_LCDLIDDCS0CONFIG1 = 0x0062;  // Write	 0x0062;  // Write
	


    
    //LCD_Code = SSD2119;
	    
	LCD_WriteReg(0x28,0x0006);
	LCD_WriteReg(0x00,0x0001);		
	LCD_WriteReg(0x10,0x0000);		
	LCD_WriteReg(0x01,0x72ef);
	LCD_WriteReg(0x02,0x0600);
	LCD_WriteReg(0x03,0x6a38);	
	LCD_WriteReg(0x11,0x6874);
	LCD_WriteReg(0x0f,0x0000);    
	LCD_WriteReg(0x0b,0x5308);    
	LCD_WriteReg(0x0c,0x0003);
	LCD_WriteReg(0x0d,0x000a);
	LCD_WriteReg(0x0e,0x2e00);  
	LCD_WriteReg(0x1e,0x00be);
	LCD_WriteReg(0x25,0x8000);
	LCD_WriteReg(0x26,0x7800);
	LCD_WriteReg(0x27,0x0078);
	LCD_WriteReg(0x4e,0x0000);
	LCD_WriteReg(0x4f,0x0000);
	LCD_WriteReg(0x12,0x08d9);
	/* Adjust the Gamma Curve */
	LCD_WriteReg(0x30,0x0000);
	LCD_WriteReg(0x31,0x0104);	 
	LCD_WriteReg(0x32,0x0100);	
	LCD_WriteReg(0x33,0x0305);	
	LCD_WriteReg(0x34,0x0505);	 
	LCD_WriteReg(0x35,0x0305);	
	LCD_WriteReg(0x36,0x0707);	
	LCD_WriteReg(0x37,0x0300);	
	LCD_WriteReg(0x3a,0x1200);	
	LCD_WriteReg(0x3b,0x0800);		 
	LCD_WriteReg(0x07,0x0033);
        
	return 0;	
	
	
}




#endif  




