#ifndef _I2S_Library_H_
#define _I2S_Library_H_

#define Rate48k 0x91
#define Rate8k  0xe1
#define Rate96k  0x81


// ------------------------------------------------------------------------  *
//                                                                           *
//   _AIC3204_rset( regnum, regval )                                         *
//                                                                           *
//       Set codec register regnum to value regval                           *
//                                                                           *
//  ------------------------------------------------------------------------ *
Int16 AIC3204_rset( Uint16 regnum, Uint16 regval )
{
    Uint8 cmd[2];
    cmd[0] = regnum & 0x007F;       // 7-bit Register Address
    cmd[1] = regval;                // 8-bit Register Data

    return USBSTK5515_I2C_write( AIC3204_I2C_ADDR, cmd, 2 );
}


	
	
	
	
Int16 Aic3204_Setup(Uint16 fs)
{
	/* Define sampling rate parameters */
	unsigned char pll_dh, pll_dl, madc, mdac, nadc, ndac;
	
	if(fs == Rate48k)
	{
	// PLL D = 560
	pll_dh = 0x02;
	pll_dl = 0x30;
	// MDAC & MACC = 3
	madc = 0x03;
	mdac = 0x03;
	// NDAC & NADC = 5
	nadc = 0x05;
	ndac = 0x05;
	}
	else // 8, 16, 24, 32, 48, 96 KHz
	{
		// PLL D = 1680
		pll_dh = 0x06;
		pll_dl = 0x90;
		switch(fs)
		{
			case Rate8k:
				madc = 0x0C;
				mdac = 0x0C;
				break;
			case Rate96k:
				madc = 0x01;
				mdac = 0x01;
				break;
		}
			// NDAC & NADC = 7
			nadc = 0x07;
			ndac = 0x07;
	}

	    /* Configure AIC3204 */
	    AIC3204_rset( 0, 0 );      // Select page 1
	    AIC3204_rset( 1, 1 );      // Reset codec
	    AIC3204_rset( 0, 1 );      // Point to page 1
	    AIC3204_rset( 1, 8 );      // Disable crude AVDD generation from DVDD
	    AIC3204_rset( 2, 1 );      // Enable Analog Blocks, use LDO power
	    AIC3204_rset( 0, 0 );
	    /* PLL and Clocks config and Power Up  */
	    AIC3204_rset(27, 0x1d);// BCLK and WCLK is set as o/p to AIC3204(Master)
	    AIC3204_rset(28, 0x00);// Data ofset = 0
	    AIC3204_rset(4, 3); // PLL setting: PLLCLK <‐ MCLK, CODEC_CLKIN <‐PLL CLK
	    AIC3204_rset(6, 0x07);// Set PLL J
	    AIC3204_rset(7, pll_dh);// PLL setting: D HI_BYTE(5:0)
	    AIC3204_rset(8, pll_dl);// PLL setting: D LO_BYTE(7:0)
	    AIC3204_rset(30, 0x88);// For 32 bit clocks per frame in Master mode ONLY

	// BCLK=DAC_CLK/N (12288000/8) = 1.536MHz = 32*fs

	    AIC3204_rset(5, 0x91);//PLL setting: Power up PLL, P=1 and R=1
	    AIC3204_rset(13, 0x00);// DOSR Hi_Byte(1:0) = 0
	    AIC3204_rset(14, 0x80);// DOSR Lo_Byte(7:0) = 128
	    AIC3204_rset(20, 0x80);// AOSR (7:0) = 128
	    AIC3204_rset(11, 0x80 | ndac);  // Power up NDAC and set NDAC value
	    AIC3204_rset(12, 0x80 | mdac);  // Power up MDAC and set MDAC value
	    AIC3204_rset(18, 0x80 | nadc);  // Power up NADC and set NADC value
	    AIC3204_rset(19, 0x80 | madc);  // Power up MADC and set MADC value

	/* DAC ROUTING and Power Up */
	    AIC3204_rset( 0, 1 );      // Select page 1
	    AIC3204_rset( 0x0c, 8 );   // LDAC AFIR routed to HPL
	    AIC3204_rset( 0x0d, 8 );   // RDAC AFIR routed to HPR
	    AIC3204_rset( 0, 0 );      // Select page 0
	    AIC3204_rset( 64, 2 );     // Left vol=right vol
	    AIC3204_rset( 65, 0 );     // Left DAC gain to 0dB VOL; Right tracks Left
	    AIC3204_rset( 63, 0xd4 );  // Power up left,right data paths and set channel
	    AIC3204_rset( 0, 1 );      // Select page 1
	    AIC3204_rset( 0x10, 10 );  // Unmute HPL , 10dB gain
	    AIC3204_rset( 0x11, 10 );  // Unmute HPR , 10dB gain

	    AIC3204_rset( 9, 0x30 );   // Power up HPL,HPR
	    AIC3204_rset( 0, 0 );      // Select page 0
	    USBSTK5515_wait( 100 );    // wait
	    /* ADC ROUTING and Power Up */
	    AIC3204_rset( 0, 1 );      // Select page 1
	    AIC3204_rset( 0x34, 0x30 );// STEREO 1 Jack
	                       // IN2_L to LADC_P through 40 kohm
	    AIC3204_rset( 0x37, 0x30 );// IN2_R to RADC_P through 40 kohmm
	    AIC3204_rset( 0x36, 3 );   // CM_1 (common mode) to LADC_M through 40 kohm
	    AIC3204_rset( 0x39, 0xc0 );// CM_1 (common mode) to RADC_M through 40 kohm
	    AIC3204_rset( 0x3b, 0 );   // MIC_PGA_L unmute
	    AIC3204_rset( 0x3c, 0 );   // MIC_PGA_R unmute
	    AIC3204_rset( 0, 0 );      // Select page 0
	    AIC3204_rset( 0x51, 0xc0 );// Powerup Left and Right ADC
	    AIC3204_rset( 0x52, 0 );   // Unmute Left and Right ADC

	    AIC3204_rset( 0, 0 );
	    USBSTK5515_wait( 100 );  // Wait
	    return 0;
}




	

// ------------------------------------------------------------------------  *
//                                                                           *
//   AIC3204 Loop                                                            *
//       Output input from STEREO IN 1 through the HEADPHONE jack            *
//                                                                           *
//  ------------------------------------------------------------------------ /

Int16 aic3204_loop_mono_in2(Uint16 SampleRate)
{      	
    // Configure AIC3204 //

    AIC3204_rset( 0,  0 );         // Select page 0
    AIC3204_rset( 1,  1 );         // Reset codec
    AIC3204_rset( 0,  1 );         // Select page 1
    AIC3204_rset( 1,  8 );         // Disable crude AVDD generation from DVDD
    AIC3204_rset( 2,  1 );         // Enable Analog Blocks, use LDO power
    AIC3204_rset( 0,  0 );         // Select page 0
    
    // PLL and Clocks config and Power Up  //
    AIC3204_rset( 27, 0x0d );      // BCLK and WCLK is set as o/p to AIC3204(Master)
    AIC3204_rset( 28, 0x00 );      // Data ofset = 0
    AIC3204_rset( 4,  3 );         // PLL setting: PLLCLK <- MCLK, CODEC_CLKIN <-PLL CLK
    AIC3204_rset( 6,  7 );         // PLL setting: J=7
    AIC3204_rset( 7,  0x06 );      // PLL setting: HI_BYTE(D=1680)
    AIC3204_rset( 8,  0x90 );      // PLL setting: LO_BYTE(D=1680)          
    AIC3204_rset( 30, 0x88 );      // For 32 bit clocks per frame in Master mode ONLY
                                   // BCLK=DAC_CLK/N =(12288000/8) = 1.536MHz = 32*fs
    //SampleRate
    AIC3204_rset( 5,  SampleRate);  		//0x91-48k//0xe1-8k//0x81-6k// PLL setting: Power up PLL, P=1 and R=1
    //

    AIC3204_rset( 13, 0 );         // Hi_Byte(DOSR) for DOSR = 128 decimal or 0x0080 DAC oversamppling
    AIC3204_rset( 14, 0x80 );      // Lo_Byte(DOSR) for DOSR = 128 decimal or 0x0080    
    AIC3204_rset( 20, 0x80 );    	//0x80  // AOSR for AOSR = 128 decimal or 0x0080 for decimation filters 1 to 6
    AIC3204_rset( 11, 0x82 );      // Power up NDAC and set NDAC value to 2
    AIC3204_rset( 12, 0x87 );      // Power up MDAC and set MDAC value to 7
    AIC3204_rset( 18, 0x87 );      // Power up NADC and set NADC value to 7
    AIC3204_rset( 19, 0x82 );  	   //0x82   // Power up MADC and set MADC value to 2  or 4
    EVM5515_wait( 500 );           // Wait

    // ADC ROUTING and Power Up //
    AIC3204_rset( 0, 1 );          // Select page 1                                        
    AIC3204_rset( 0x34, 0x10 );   // STEREO 1 Jack 		                    
    AIC3204_rset( 0x36, 0x40 );   // CM_1 (common mode) to LADC_M through 10 kohm
                                         
    AIC3204_rset( 0x3b, 0 );       // MIC_PGA_L unmute
    AIC3204_rset( 0x3c, 0 );       // MIC_PGA_R unmute
    AIC3204_rset( 0, 0 );          // Select page 0
    AIC3204_rset( 0x51, 0xc0 );    // Powerup Left and Right ADC
    AIC3204_rset( 0x52, 0 );       // Unmute Left and Right ADC
	AIC3204_rset( 0x52, 0x0d);       // GPIO = 1

    AIC3204_rset( 0, 0 );    
    EVM5515_wait( 200 );           // Wait
    return 0;
}






// ------------------------------------------------------------------------  *
//                                                                           *
//   AIC3204 Loop                                                            *
//       Output input from STEREO IN 1 through the HEADPHONE jack            *
//                                                                           *
//  ------------------------------------------------------------------------ /
Int16 aic3204_loop_stereo_in1( )
{      	
    // Configure AIC3204 //

    AIC3204_rset( 0,  0 );         // Select page 0
    AIC3204_rset( 1,  1 );         // Reset codec
    AIC3204_rset( 0,  1 );         // Select page 1
    AIC3204_rset( 1,  8 );         // Disable crude AVDD generation from DVDD
    AIC3204_rset( 2,  1 );         // Enable Analog Blocks, use LDO power
    AIC3204_rset( 0,  0 );         // Select page 0
    // PLL and Clocks config and Power Up  //
    AIC3204_rset( 27, 0x0d );      // BCLK and WCLK is set as o/p to AIC3204(Master)
    AIC3204_rset( 28, 0x00 );      // Data ofset = 0
    AIC3204_rset( 4,  3 );         // PLL setting: PLLCLK <- MCLK, CODEC_CLKIN <-PLL CLK
    AIC3204_rset( 6,  7 );         // PLL setting: J=7
    AIC3204_rset( 7,  0x06 );      // PLL setting: HI_BYTE(D=1680)
    AIC3204_rset( 8,  0x90 );      // PLL setting: LO_BYTE(D=1680)
    AIC3204_rset( 30, 0x88 );      // For 32 bit clocks per frame in Master mode ONLY
                                   // BCLK=DAC_CLK/N =(12288000/8) = 1.536MHz = 32*fs
    	AIC3204_rset( 5,  0x81 );  //0x91-48k//0xe1-8k//0x81-6k// PLL setting: Power up PLL, P=1 and R=1     
    AIC3204_rset( 13, 0 );         // Hi_Byte(DOSR) for DOSR = 128 decimal or 0x0080 DAC oversamppling
    AIC3204_rset( 14, 0x80 );      // Lo_Byte(DOSR) for DOSR = 128 decimal or 0x0080    
    	AIC3204_rset( 20, 0x80 );    	//0x80  // AOSR for AOSR = 128 decimal or 0x0080 for decimation filters 1 to 6
    AIC3204_rset( 11, 0x82 );      // Power up NDAC and set NDAC value to 2
    AIC3204_rset( 12, 0x87 );      // Power up MDAC and set MDAC value to 7
    AIC3204_rset( 18, 0x87 );      // Power up NADC and set NADC value to 7
    	AIC3204_rset( 19, 0x82 );  //0x82   // Power up MADC and set MADC value to 2  or 4
    // DAC ROUTING and Power Up //
    AIC3204_rset(  0, 0x01 );      // Select page 1
    AIC3204_rset( 12, 0x08 );      // LDAC AFIR routed to HPL
    AIC3204_rset( 13, 0x08 );      // RDAC AFIR routed to HPR
    AIC3204_rset(  0, 0x00 );      // Select page 0
    AIC3204_rset( 64, 0x02 );      // Left vol=right vol
    AIC3204_rset( 65, 0x00 );      // Left DAC gain to 0dB VOL; Right tracks Left
    AIC3204_rset( 63, 0xd4 );      // Power up left,right data paths and set channel
    AIC3204_rset(  0, 0x01 );      // Select page 1
    AIC3204_rset( 16, 0x00 );      // Unmute HPL , 0dB gain
    AIC3204_rset( 17, 0x00 );      // Unmute HPR , 0dB gain
    AIC3204_rset(  9, 0x30 );      // Power up HPL,HPR
    AIC3204_rset(  0, 0x00 );      // Select page 0
    EVM5515_wait( 500 );           // Wait
    
    // ADC ROUTING and Power Up //
    AIC3204_rset( 0, 1 );          // Select page 1
           
           
           
           
    AIC3204_rset( 0x34, 0x10 );   // STEREO 1 Jack 		                    
    AIC3204_rset( 0x36, 0x40 );   // CM_1 (common mode) to LADC_M through 10 kohm
    
    //AIC3204_rset( 0x34, 0x01 );   // STEREO 1 Jack 		                    
    //AIC3204_rset( 0x36, 0x40 );   // CM_1 (common mode) to LADC_M through 10 kohm        
              
              
              
    AIC3204_rset( 0x3b, 0 );       // MIC_PGA_L unmute
    AIC3204_rset( 0x3c, 0 );       // MIC_PGA_R unmute
    AIC3204_rset( 0, 0 );          // Select page 0
    AIC3204_rset( 0x51, 0xc0 );    // Powerup Left and Right ADC
    AIC3204_rset( 0x52, 0 );       // Unmute Left and Right ADC
    
    //AIC3204_rset( 52, 0x0c);       // GPIO = 0	
	AIC3204_rset( 52, 0x0d);       // GPIO = 1       	
              
    AIC3204_rset( 0, 0 );    
    EVM5515_wait( 200 );           // Wait
    // I2S settings //
    I2S0_SRGR = 0x0;
    I2S0_CR = 0x8010;    		   // 16-bit word, slave, enable I2C
    I2S0_ICMR = 0x3f;              // Enable interrupts
                                               
    // Disble I2S //
	///I2S0_CR = 0x00;
   
    return 0;
}


    
#endif
