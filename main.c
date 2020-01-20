//  Vzv-1M5
//  Copyright 2011 by Shubin Vladimir.
//  Refactoryng by Alexander Mikhalev 2019 Deleted Over 9000 Lines Of Code
#define Stand_Stoping 2
#define Stand_Runing 1
#define Stand_Idle 0
#define MOD_Acc 0
#define MOD_Vel 1
#define MOD_Dis 2
#define Calibr_CODE 	1990
//#define Calibr_Null		1995
#define AD5272_I2C_ADDR 	0x2E    	// AD5272 	I2C address резистор 1024 позиции
#define INA219_I2C_ADDR0 	0x40    	// INA219 	I2C address вольтметр - амперметр
#define INA219_I2C_ADDR1 	0x41    	// INA219 	I2C address вольтметр - амперметр
#define INA219_I2C_ADDR2 	0x42    	// INA219 	I2C address вольтметр - амперметр
#define INA219_I2C_ADDR3 	0x43    	// INA219 	I2C address  
#define INA219_I2C_ADDR5 	0x45    	// INA219 	I2C address
#define INA219_I2C_ADDR6 	0x46    	// INA219 	I2C address
#define MAX_FREQ			99999		//Max freq
 
#define PCF8574_I2C_ADDR1 	0x20    	// PCF8574 	I2C address    
#define PCF8574_I2C_ADDR2 	0x21    	// PCF8574 	I2C address     
#define PCF8574_I2C_ADDR3 	0x23    	// PCF8574 	I2C address     
#define PCF8575_I2C_ADDR 	0x22    	// PCF8575 	I2C address     
 
#define TCA6424_I2C_ADDR1 	0x7F    	// TCA6424 	I2C address  0x22  
#define TCA6424_I2C_ADDR2 	0x23    	// TCA6424 	I2C address

#define DC1340_I2C_ADDR 	0x68    	// DC1340   I2C address

#define AIC3204_I2C_ADDR 	0x18    	// AIC3204 	I2C address

#define LM73_I2C_ADDR1 		0x4C    	// LM73 	I2C address
#define LM73_I2C_ADDR2 		0x4D    	// LM73 	I2C address
#define LM73_I2C_ADDR3 		0x4E    	// LM73 	I2C address

#define ADRUINO_SLAVE 		0x64    	// LM73 	I2C address
#define TCA8418_I2C_ADDR 	0x34    	// TCA8418 	I2C address
//#define ADS1115_I2C_ADDR 	0x48    	// TCA8418 	I2C address

#define TAS5424_I2C_ADDR 	0x6C    	// TAS5424 	I2C address

#define one 	129    				// 1
#define two 	130    				// 2
#define three 	131    				// 3
#define ENTER 	132    				// ENTER
#define four 	139    				// 4
#define five 	140    				// 5
#define six 	141   				// 6
#define MENU 	142    				// MENU
#define seven 	149    				// 7
#define eight 	150    				// 8
#define nine 	151    				// 9
#define zero 	152    				// 0
#define LEFT 	159    				// LEFT
#define UP 		160    				// UP
#define DOWN 	161    				// DOWN
#define RIHT 	162    				// RIHT
#define RIGHT_UP 34					// RIGHT_UP

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data_types.h"
#include "register_system.h"
#include "register_cpu.h"
#include "register_RTC.h"
#include "rtc.h"
#include "math.h"
#include "tms320.h"
#include "dsplib.h"
#include "misc.h"
#include "stdio.h"
#include "evm5515.h"
#include "i2c.h"
#include "evm5515_gpio.h"
#include "lcd.h"
#include "icon.h"
#include "font.h"
#include "LCD_Library.h"
#include "LCD_Initialize.h"
#include "i2c_lib.h"
#include "spirom.h"
#include "spi.h"
#include "sdram.h"
#include "evm5515_emif.h"
#include "NandFlash.h"
#include "uart.h"
#include "timer.h"
#include "control.h"
#include "i2s_bypass1.h"
#include "dma_bypass1.h"
#include "ref_data_bypass.h"
#include "SigProcessor.h"
#include "I2S_Library.h"
#include "FunctionRTC.h"
#include "menu.h"
#include "Memory.h"


extern void AIC3254_init(void);

char ADRUINO_CMD = ' ', ADRUINO_PREV_CMD = ' ';
Uint32 ADRUINO_Data = 0, ADRUINO_DATA_Prev = 0;
Uint16 ARDUINO_RMS = 0;

Uint8 StopWatchHour = 0;
Uint8 StopWatchMinut = 0;
Uint8 StopWatchSecond = 0;
Uint8 StopWatchStart = 0;

Uint16 Resistance=0;
Uint8 Bat = 0;    

Uint8 metka = 1;

Uint8 TempPoint=255; 
Uint8 TempSD=255;
Uint8 TempUSB=255;

Uint16 SpectrDiv = 1;
Int16  SpectrKur = 4;
Uint16 SpectrWid = 1;
Uint16 SpectrNul = 0;

Uint32 shifft = 0x314000;

int KeyDown = 0;
int KeyUp = 0;
int KeyRegId = 1;
int HoldTime = 0;


double Temper  = 0.0;
double RES_ACC = 0.0;
double RES_VEL = 0.0;
double RES_DIS = 0.0;
double KUS_ACC_DR = 0.0;
double KUS_VEL_DR = 0.0;
double KUS_DIS_DR = 0.0;
double ACC_D0 = 0.0;
double ACC_D1 = 0.0;
double ACC_D2 = 0.0;
double ACC_D3 = 0.0;
double ACC_D4 = 0.0;
double ACC_D5 = 0.0;
double ACC_D6 = 0.0;
double ACC_D7 = 0.0;
double ACC_D = 0.0;
double Reg_ACC_D = 0.0;
Uint32 Reg_ACC_DD = 0;

double VEL_D = 0.0;
double Reg_VEL_D = 0.0;
Uint32 Reg_VEL_DD = 0;

double DIS_D = 0.0;
double Reg_DIS_D = 0.0;
Uint32 Reg_DIS_DD = 0;

double KUS_1 = 0.000;
double KUS_2 = 0.000;
double KUS_3 = 0.000;

double Acc_temp = 0.000;
double Vel_temp = 0.000;
double Dis_temp = 0.000;

Uint32 res_rms_0,res_rms_1,res_rms_2;

Uint16 Temp_T = 0;
Uint16 Temp_B = 0;
Uint16 Temp_A = 0;

Int32 res_sss = 0;

Uint32 Dis_Pro = 0; 
Uint32 Dis_Pro_min = 0;
Uint32 Dis_Pro_max = 0;
Uint32 Dis_Pro_Delta = 0;

double res_rms_D0;
double res_rms_D1;
double res_rms_D2;
double res_rms_D3;

Uint16 Temp_REG = 0;	

double sam_rms_DD;
double res_rms_DD;
Uint16 Temp_I = 0;	
Uint16 Temp_II = 0;	
Uint16 Temp_III = 0;	

Uint16 Temp_A_ = 0;
Uint16 Temp_F_ = 0;

Uint16 Temp_AA = 0;
Uint16 Temp_FF = 0;
Uint16 EnergySaveClock = 0;
Uint16 EnergySaveTime = 300;
Uint8 IsSleep = 0;

Uint16 Temp_AAA = 0;

Uint8 ls5 = 10;

Uint8 RX_Uart[100];
Uint8 tx3[100];

int Temp_Bat = 0;

Uint8 TTT = 0;

int StandStatus = 0; //Idle = 0; Runing = 1; Stoping = 2;


void TAS5424_ON(void)
{
    	cmd[0] = 0x08;
		cmd[1] = 0x00;  // cmd[1] = 0x00; 		//0x00;-12dB //0x55;-20dB //0xAA;-26dB //0xff;-32dB
   		USBSTK5515_I2C_write( TAS5424_I2C_ADDR, cmd, 2 );

		cmd[0] = 0x0C;
		cmd[1] = 0x00;
		cmd[2] = 0x00;
   		USBSTK5515_I2C_write( TAS5424_I2C_ADDR, cmd, 3 );
}

void TAS5424_OFF(void)
{
	cmd[0] = 0x0C;
	cmd[1] = 0x90;
   	USBSTK5515_I2C_write( TAS5424_I2C_ADDR, cmd, 2 );
}

void LaserOFF(void)
{
	cmd[0] = 0x7F;
	USBSTK5515_I2C_write( PCF8574_I2C_ADDR1, cmd, 1 );
	fillRect(140,2,156,18,BLACK);
}

void LaserON(void)
{
	cmd[0] = 0xFF;
	USBSTK5515_I2C_write( PCF8574_I2C_ADDR1, cmd, 1 );
	ls5 = 0;
	drawBitmap(140,2,16,16,las1);
}

void SetDisplayLigth(int liht)
{
   int i,j;
   asm(" BIT (ST1, #ST1_XF) = #0");
   waitusec( 10000 );
   asm(" BIT (ST1, #ST1_XF) = #1");
   waitusec( 10000 );
   //liht = 1; // into memory

   for(i=0;i<liht;i++)
   {
	   for(j=0;j<31;j++)
	   {
		 asm(" BIT (ST1, #ST1_XF) = #0");
		 waitusec( 3 );		//4.5 mkC
		 asm(" BIT (ST1, #ST1_XF) = #1");
		 waitusec( 3 );
	   }
   }
}

// ------------------------------------------------------------------------	*                                                      				   	*
//							   InitSystem								    *
//  ----------------------------------------------------------------------- * 
void InitSystem(void)
{
	//Uint16 i;
	// PLL set up from RTC
    // bypass PLL
    CONFIG_MSW = 0x0;             
    PLL_CNTL1 = PLL_CNTL1 & 0x7FFF;    
    PLL_CNTL1 = 0x8BE8; //0x8BE8-100M////0x88ED-75M////0x8724-60M////0x8988-40M////0x8173-12.288M////0x8000-131.072k////0x8010-min//
    PLL_CNTL2 = 0x8000;
    PLL_CNTL3 = 0x0806;
    PLL_CNTL4 = 0x0000;   
    while ( (PLL_CNTL3 & 0x0008) == 0);
    // Switch to PLL clk
    CONFIG_MSW = 0x1;
	// clock gating
	// enable all clocks	
 	IDLE_PCGCR = 0x7231;			//	IDLE_PCGCR        // 0 - значит включенно , 1 - значит выключенно.
    IDLE_PCGCR_MSW = 0x007C;        //  IDLE_PCGCR_MSW    // 0 - значит включенно , 1 - значит выключенно.      
	// reset peripherals
    PER_RSTCOUNT = 0xffff;  ////////////////////////////////////0x02; 
    PER_RESET = 0x00fb;    
    //for (i=0; i< 200; i++);
    SYS_EXBUSSEL = 0x513f; // on  - spi-4,uart-4,lcd-8
    //SYS_EXBUSSEL = 0x593f; // on  - spi-4,uart-4,lcd-8
}


Uint16 fSineWave = 0;

void SYS_GlobalIntEnable(void)
{
    asm(" BIT (ST1, #ST1_INTM) = #0");
}

void SYS_GlobalIntDisable(void)
{
    asm(" BIT (ST1, #ST1_INTM) = #1");
}

void enable_sar_int(void)
{
    SAR_CLKCTRL = 0x00010;           
	SAR_PINCTRL = 0x03100;      
	SAR_GPOCTRL = 0x001C0;	  
}

interrupt void SAR_Isr(void) { }

interrupt void TIMER_isr(void) {}

interrupt void INT1_Isr(void) {}


//			        Прерывание от клаивиатуры								*
//  ----------------------------------------------------------------------- *
char FREQ_MODE = 0;

void KeyBoardEvent(char Key, char FREQ_MODE)
{
	Uint16 i,temp,Id;
	double SetDisp;
	int FreqId;

	EnergySaveClock = 0;
	SYS_GlobalIntDisable();
    cmd[0] = 0x04;                  
    USBSTK5515_I2C_write( TCA8418_I2C_ADDR, cmd, 1 );                                                                                                                                                                                                                                                                                    	                                            
   	USBSTK5515_I2C_read( TCA8418_I2C_ADDR, cmd, 1 );	// чтение кода клавиатуры
   	//printf("Key = %i",cmd[0]);

   	wait(100);
   	if(cmd[0] > 100)
	{															        	
		EVM5515_GPIO_setOutput(25,1); 		 		
		AIC3204_rset( 72, 0x04 ); //RIGHT BEEP //писк
		AIC3204_rset( 71, 0x80 ); //LEFT  BEEP	     				     	            		                		  		  
	}
   	if (IsSleep == 1)
   	{
   		EnergySaveClock = 0;
   		Key = 0;
   		IsSleep = 0;
   		SetDisplayLigth(liht);
   	} else
   		if (Key == 0)
   			{
   				  Key = cmd[0];
   				  KeyUp = Key;
   			} else KeyUp = 0;


switch (regim)
{
//AboutScreen
case 0:
		if(Key == MENU) PrintMainMenu(0);
break;

//Основное меню //1 - Режим //2 - Настройки //3 - Калибровка
case 1: case 2: case 3:
        switch (Key)
	        {
	        case MENU :
	        		PrintMainMenu(0);
	        		break;
	        case UP:
	        		MenuCursor--;
	        		if (MenuCursor < 0) MenuCursor = 2;
	        		PrintMainMenu(MenuCursor);
	        		break;
	        case DOWN:
	        		MenuCursor++;
	        		if (MenuCursor > 2) MenuCursor = 0;
	        		PrintMainMenu(MenuCursor);
	        		break;
	        case LEFT:
	        		PrintAboutScreen();
	        		break;
	        case  ENTER: case RIHT:
	        		switch (MenuCursor)
	                	{
	                	case 0:  PrintModeMenu(0);  break;//Режим
	                	case 1:  PrintSettingsMenu(0); break;  //Настройки
	                	case 2:  PrintCalibrMenu();  break;  // Калибровка
	               		};
	        		break;
	        }
break;
//Меню режим работы //11 - Вибростенд //12 - Виброметр //13 - Термометр
case  11: case 12: case 13:
   switch (Key)
   {
       case MENU: case LEFT: PrintMainMenu(0); break;
       case UP:
    	   MenuCursor--;
    	   if (MenuCursor < 0) MenuCursor = 1;
    	   PrintModeMenu(MenuCursor);
    	   break;
       case DOWN:
    	   MenuCursor++;
    	   if (MenuCursor > 1) MenuCursor = 0;
    	   PrintModeMenu(MenuCursor);
    	   break;
       case ENTER: case RIHT:
    	   switch (MenuCursor)
    	   {
    	   case 0: PrintStandMenu(0);  	break;
    	   case 1: PrintTermomentr(); break;
    	   //case 2: /*Меню Термометр*/ 	break;
    	   }
    	   break;
   }
break;
//Режим вибросетнда //111 - Ускорение //112 - Скорость //113 - Перемещение
//---------------------------------------------------------------------------------------------------------------------------------------------
case 111: case 112: case 113:
	switch (Key)
	{
		case MENU:  PrintMainMenu(0); break;
		case UP:
      			MenuCursor--;
				if (MenuCursor < 0) MenuCursor = 2;
				PrintStandMenu(MenuCursor);
				break;
		case DOWN:
				MenuCursor++;
				if (MenuCursor > 2) MenuCursor = 0;
				PrintStandMenu(MenuCursor);
				break;
		case LEFT: 	PrintModeMenu(0); break;
		case ENTER:
				switch (MenuCursor)
				{
				  case 0: PrintAccMenu(0); break; //Режим ускорения
				  case 1: PrintVelMenu(); break;  //Режим скорости
				  case 2: PrintDisMenu(); break;  //Режим Перемещения
				}
	}
break;
//Режим задания параметров ускорения, курсор на частоте или на амплитуде
case 1111: case 1112:
	switch (Key)
	{
	case RIHT: break;
	case MENU: PrintMainMenu(0); break;
	case LEFT: PrintStandMenu(0); break;
	case UP:   PrintAccMenu(0); break;
	case DOWN: PrintAccMenu(1); break;
	case ENTER:
		    KUS_ACC = GetKUSFromTable(AccelarationTable,reg_frequency/10, (float) reg_acseleration/10);
		    Coeff_A = KUS_ACC*1000/AccMult;
			Acc_temp = reg_frequency/1000.0;
        	Acc_temp = reg_acseleration/Acc_temp/Acc_temp/1.39577;
       		if(Acc_temp > 5000 || reg_frequency < 10)
        	{
			  LCD_Clear_1(BLUE_B);
      		  print(" Неверный ",80,100,FontRus16x28,WHITE,RED);
      		  print(" параметр!",80,140,FontRus16x28,WHITE,RED);
			  regim=1115;
        	}
        	else
       		{
			  LCD_Rectangle(3,220,165,226,BLUE_B);
			  LCD_Acsel(0,BLACK);
			  KUS_ACC_DR = GetKUSInit(reg_frequency);
			  spi_sin(reg_frequency);
			  spi_Kus(KUS_ACC_DR);   	//aga
			  TAS5424_ON();      		//aga
			  Temp_A=1;
			  Temp_REG=0;
			  PrintControlHelp("");
		      StandStatus = Stand_Runing;
			  if(reg_frequency <= LaserStartFreq)
        		{
				 	LaserON();
					regim=11132;
        		}
      			else
      			{
      				fillRect(140,2,156,18,BLACK);
					regim=1113;
      			}
        	}
       		break;
	default:
			if (regim == 1111) FreqInput(Key);
			else reg_acseleration = AmpInput(Key,MOD_Acc,reg_acseleration);
			break;
	}
break;
//Состояние ошибки по ускорению
case 1115:
   	if(Key == MENU) PrintMainMenu(0);
			else PrintAccMenu(0);
break;
//ВИбрация в режиме ускорения с лазером или без, курсор находится на изменении частоты
case 1113: case 11132:
   switch (Key)
   {
   	   case MENU: 	PrintMainMenu(0); break;
   	   case LEFT:
   		   	   	   reg_frequency--;
   		   	   	   LCD_Freq(reg_frequency,BLACK);
   		   	   	   if(reg_frequency > LaserStartFreq)
   		   	   	   {
   		   	   		   if (regim !=1113) LaserOFF();
   		   	   		   regim=1113;
   		   	   	   }
   		   	   	   else
   		   	   	   {
   		   	   		   if (regim != 11132) LaserON();
   		   	   		   regim=11132;
   		   	   	   }
   		   	   	   KUS_ACC = GetKUSFromTable(AccelarationTable,reg_frequency/10,(float)reg_acseleration/10);
   		   	   	   spi_sin(reg_frequency);

   		   	   	   break;
   	   case RIHT:
   			 	   if(code == Calibr_CODE) Save_All_Coeff();
   				   else
   						{
   					   	reg_frequency++;
   					   	LCD_Freq(reg_frequency,BLACK);
   						if(reg_frequency > LaserStartFreq)
   							{
   							if (regim !=1113) LaserOFF();
   							regim=1113;
   							}
   						else
   							{
   							if (regim != 11132) LaserON();
   							regim=11132;
   							}
   							spi_sin(reg_frequency);
   							KUS_ACC = GetKUSFromTable(AccelarationTable,reg_frequency/10,(float)reg_acseleration/10);
   						}
   					break;
   	   case ENTER:
   		   	   	/*spi_Kus(0);
				TAS5424_OFF();    
				LaserOFF();
        		Temp_A=0;*/
   		   	    StandStatus = Stand_Stoping;
        		PrintAccMenu(0);
        		break;
   	   case UP:
				switch (code)
				{
				case Calibr_CODE:

					SetDisp = (double) 50712*1.41*(reg_acseleration*0.1)/(reg_frequency*reg_frequency*0.01);
					if (SetDisp > 1500)
						{
							FreqId = (SetDisp - 1500)/500;
							AccMult = AccMult+0.01;
							AmpTable[FreqId] = AccMult*100;
							KUS_ACC = (double)Coeff_A/1000*AccMult;
						}
					else
					{
						Coeff_A = Coeff_A+5;
						KUS_ACC = (double)Coeff_A/1000;
					}

					break;
				//case Calibr_Null:  Coeff_A_0 = Coeff_A_0+5; break;
				default:
					reg_acseleration = reg_acseleration + 5;
					LCD_Acsel(reg_acseleration, BLACK);
				}
				break;
	  case DOWN:
		  	  	  switch (code)
		  		  {
		  			case Calibr_CODE:
		  				SetDisp = (double) 50712*1.41*(reg_acseleration*0.1)/(reg_frequency*reg_frequency*0.01);
		  				if (SetDisp > 1500)
		  				{
		  					FreqId = (SetDisp - 1500)/500;
		  					AccMult = AccMult-0.01;
		  					AmpTable[FreqId] = AccMult*100;
		  					KUS_ACC = (double)Coeff_A/1000*AccMult;
		  				}
		  				else
		  				{
		  					Coeff_A = Coeff_A-5;
		  					KUS_ACC = (double)Coeff_A/1000;
		  				}

		  				break;
		  			//case Calibr_Null:  Coeff_A_0 = Coeff_A_0-5; break;
		  			default:
		  				if (reg_acseleration > 5) reg_acseleration = reg_acseleration - 5;
		  				LCD_Acsel(reg_acseleration, BLACK);
		  		  }
		  		  break;
   }
break;
//Режим задания виброскорости курсор внизу или вверху
case 1121: case 1122:
	switch (Key)
	{
	  case MENU: PrintMainMenu(0); break;
	  case LEFT: PrintStandMenu(MOD_Vel); break;
	  case RIHT: break;
	  case UP:
				LCD_Rectangle(3,130,165,136,YELLOW_K);	
    			LCD_Rectangle(3,220,165,226,BLUE_B);  			    						          		            				    	                	    			 																						 			    	   
        		regim=1121;
        		break;
	  case DOWN:
				LCD_Rectangle(3,130,165,136,BLUE_B);	
    			LCD_Rectangle(3,220,165,226,YELLOW_K);  	   			    					          		            				    	                	    			 																						 			    	     
        		regim=1122;	      
        		break;
	  case ENTER:
				KUS_VEL=GetKUSFromTable(AccelarationTable,reg_frequency/10,(float)reg_velosity/10*0.00888*reg_frequency/10/1.4142);
		  	  	Vel_temp = reg_frequency/1000.0;
        		Vel_temp = reg_velosity/Vel_temp/2.221441469;
        		if(Vel_temp > 5000)
        		{
					LCD_Clear_1(BLUE_B);	    				      				      		
      				print(" Неверный ",80,100,FontRus16x28,WHITE,RED);  
      				print(" параметр!",80,140,FontRus16x28,WHITE,RED);
					regim=1125;	  
        		}
        		else
        		{        
					LCD_Rectangle(3,130,165,136,BLUE_B);	
    				LCD_Rectangle(3,220,165,226,BLUE_B);  	            		            				    	                			 				 	           		        
        			LCD_velosity(0);        	        			        	        			        	        				       
        			KUS_VEL_DR = GetKUSInit(reg_frequency);
        			spi_sin(reg_frequency);	 
        			spi_Kus(KUS_VEL_DR);						
					TAS5424_ON();			      	
      				Temp_A=1;      		
					Temp_REG=0;
					PrintControlHelp(" Помощь:лев/прав-изм.част,верх/низ-ампл. ");
					if(reg_frequency < LaserStartFreq)
        			{      			        				
					 	LaserON();
						regim=11232;
        			}
      				else
      				{
      					fillRect(140,2,156,18,BLACK);
						regim=1123;
      				}
        		}
	  default:
		  	  	 if (regim == 1121) FreqInput(Key);
		  	  	 	 else reg_velosity = AmpInput(cmd[0],MOD_Vel, reg_velosity);
		  	  	 break;
	}
break;
//Неверный параметр по виброскорости
case 1125:
	if(Key == MENU) PrintMainMenu(0);
			else PrintVelMenu();
break;
//Воспроизведение виброскорсти с лазером или без
case 1123: case 11232:
	switch (Key)
	{
	case MENU: 	PrintMainMenu(0); break;
	case LEFT:
				ChangeFreq(-1);
			 	if(reg_frequency > LaserStartFreq)
			 	{
			 		if (regim != 1123) LaserOFF();
			 		regim=1123;
			 	}
			 	else
			 		{
			 			if (regim != 11232) LaserON();
			 			regim=11232;
			 		}
			 	KUS_VEL=GetKUSFromTable(AccelarationTable,reg_frequency/10,(float)reg_velosity/10*0.00888*reg_frequency/10/1.4142);
				spi_sin(reg_frequency);
				break;
	case ENTER:
        		spi_Kus(0);
				TAS5424_OFF();
       		 	LaserOFF();
        		Temp_A=0;
//				regim=1121;
				PrintVelMenu();
				break;
	case  UP:
			switch (code)
			{
				case Calibr_CODE: Coeff_V = Coeff_V+1; KUS_VEL = (double)Coeff_V/1000; break;
				//case Calibr_Null: Coeff_V_0 = Coeff_V_0+1; break;
				default:
				       	   reg_velosity = reg_velosity + 5;
				       	   LCD_velosity(reg_velosity);
				       	   break;
			}
			break;
	case DOWN:
			switch (code)
			{
				case Calibr_CODE: Coeff_V = Coeff_V-1; KUS_VEL = (double)Coeff_V/1000; break;
				//case Calibr_Null: Coeff_V_0 = Coeff_V_0-1; break;
				default:
						   if (reg_velosity > 5) reg_velosity = reg_velosity - 5;
						   LCD_velosity(reg_velosity);
						   break;
			}
			break;

	case RIHT: 		// sawe
		 	 if(code == Calibr_CODE) Save_All_Coeff();
		   	    else
		   		{
		   		  ChangeFreq(1);
		   		  if(reg_frequency > LaserStartFreq)
		   				{
		   					if (regim != 1123) LaserOFF();
		   			 		regim=1123;
		   				}
		   			 	else
		   			 	{
		   					if (regim != 11232) LaserON();
		   					regim=11232;
		   				}
		   	     }
		 	 	  KUS_VEL=GetKUSFromTable(AccelarationTable,reg_frequency/10,(float) reg_velosity/10*0.00888*reg_frequency/10/1.4142);
		   		  spi_sin(reg_frequency);
		   	break;
	}
break;

// Установка виброперемещения курсор на частоте
case 1131: case 1132:
{	
	switch (Key)
	{
	case MENU: 	PrintMainMenu(0); break;
	case LEFT: 	PrintStandMenu(MOD_Dis); break;
	case RIHT: break;
	case UP:
			   	LCD_Rectangle(3,130,165,136,YELLOW_K);
    			LCD_Rectangle(3,220,165,226,BLUE_B);     			    			    						          		            				    	                	    			 																						 			    	   
        		regim=1131;
        		break;
	case DOWN:
				LCD_Rectangle(3,130,165,136,BLUE_B); 		
    			LCD_Rectangle(3,220,165,226,YELLOW_K);     			    					          		            				    	                	    			 																						 			    	     
        		regim=1132;
        		break;
	case ENTER:
				Dis_temp = reg_displacement;
        		if(Dis_temp > 5000)
        		{
					LCD_Clear_1(BLUE_B);	    				      				      		
      				print(" Неверный ",80,100,FontRus16x28,WHITE,RED);  
      				print(" параметр!",80,140,FontRus16x28,WHITE,RED);
					regim=1135;	  
        		}
        		else
        		{       
					LCD_Rectangle(3,130,165,136,BLUE_B); 		
    				LCD_Rectangle(3,220,165,226,BLUE_B);           		            				    	                			 				 	           		        
        			LCD_displacement(0);        	        			                			        				        			        	        			        	        				    
        			KUS_DIS_DR = GetKUSInit(reg_frequency);
        			KUS_DIS=GetKUSFromTable(AccelarationTable,reg_frequency/10,(float)0.00002*reg_displacement*reg_frequency/10*reg_frequency/10/1.4142);
        			spi_sin(reg_frequency);
        			spi_Kus(KUS_DIS_DR);							
					TAS5424_ON(); 			      	      				
      				Temp_A=1;
      				Temp_REG=0;
      				PrintControlHelp(" Помощь:лев/прав-изм.част,верх/низ-ампл. ");
      				if(reg_frequency <= LaserStartFreq)
        			{      			        						
					 	LaserON();
						regim=11332;							 	
        			}
      				else 
      				{    
      					fillRect(140,2,156,18,BLACK);
						regim=1133;	 
      				} 
        		  }
        		break;
	default:
			if (regim == 1131)  FreqInput(Key);
			   else
				  reg_displacement = AmpInput(Key, MOD_Dis, reg_displacement);
	}
break;

//Неверный параметр по перемещению
case 1135:
    if(Key == MENU) PrintMainMenu(0);
       	  else PrintDisMenu();
break;

//Воспроизведение виброперемещения с лазером и без
case 1133: case 11332:
    switch (Key)
    {
    case MENU: 	PrintMainMenu(0); break;
    case LEFT:
        		ChangeFreq(-1);
        		if (reg_frequency > 300)
        			{
        				if (regim != 1133) LaserOFF();
        				regim=1133;
        			}
        			else
        			{
        				if (regim != 11332) LaserON();
        				regim=11332;
        			}
        		KUS_DIS=GetKUSFromTable(AccelarationTable,reg_frequency/10, (float)0.00002*reg_displacement*reg_frequency/10*reg_frequency/10/1.4142);
        		spi_sin(reg_frequency);
        		LCD_Freq(reg_frequency,BLACK);
        		break;
    case UP:
    			switch (code)
    			{
    			  case Calibr_CODE:  Coeff_S = Coeff_S+5; KUS_DIS = (double)Coeff_S/1000; break;
    			  //case Calibr_Null: 	Coeff_S_0 = Coeff_S_0+1; break;
    			  default:	reg_displacement = reg_displacement + 50;
    						LCD_displacement(reg_displacement);
    						break;
        		}
    			break;
    case DOWN:		//уменьшить
    			switch (code)
    	    	{
    	    	  case Calibr_CODE:  Coeff_S = Coeff_S-5; KUS_DIS = (double)Coeff_S/1000; break;
    	    	 // case Calibr_Null: 	Coeff_S_0 = Coeff_S_0-1; break;
    	    	  default:
    	    		  	  if (reg_displacement > 50) reg_displacement = reg_displacement - 50;
    	    				LCD_displacement(reg_displacement);
    	    				break;
    	        }
    	    	break;
    case RIHT:
    			if(code == Calibr_CODE) Save_All_Coeff();
        		  else
        			{
        		      ChangeFreq(1);
        		      if (reg_frequency > 300) {
          				if (regim != 1133) LaserOFF();
          				regim=1133;
          			}
          			else
          			{
          				if (regim != 11332) LaserON();
          				regim=11332;
          			}
        		    	spi_sin(reg_frequency);
        		    	LCD_Freq(reg_frequency,BLACK);
        			}
    			KUS_DIS=GetKUSFromTable(AccelarationTable,reg_frequency/10,(float)0.00002*reg_displacement*reg_frequency/10*reg_frequency/10/1.4142);
    			break;

    case ENTER:
	    		spi_Kus(0);
				TAS5424_OFF();
				//отключаем питание лазера
				LaserOFF();
        		Temp_A=0;
				PrintDisMenu();
				break;
	}
break;
//---------------------------------------------------------------------------------------------------------------------------------------------
//Режим термометра
case 131:
	switch (Key)
	{
		case MENU: 	PrintMainMenu(0); break;
		case LEFT:  PrintModeMenu(2); break;
	}
break;

//Меню настрйоки
//---------------------------------------------------------------------------------------------------------------------------------------------
case 21: case 22: case 23: case 24:
	switch (Key)
	{
	case MENU:
	case LEFT:	PrintMainMenu(0); break;
	case UP:
      			MenuCursor--;
      			if (MenuCursor < 0) MenuCursor = 3;
				PrintSettingsMenu(MenuCursor);
				break;
	case DOWN:
				MenuCursor++;
				if (MenuCursor > 3) MenuCursor = 0;
				PrintSettingsMenu(MenuCursor);
				break;
	case RIHT:
	case ENTER:
				switch (MenuCursor)
				{
		   		 case 0: PrintDateTimeMenu(); break;
				 case 1: PrintScreenMenu(); break;
				 case 2: PrintBataryMenu(); break;
				 case 3: PrintStatistic(); break;
				}
				MenuLevel = 4;
				break;
	}
Key = 0;
break;
//---------------------------------------------------------------------------------------------------------------------------------------------
//Настройка даты и времени
//---------------------------------------------------------------------------------------------------------------------------------------------
case 211:
	switch (Key)
	{
	case MENU: 	PrintMainMenu(0); break;
	case LEFT:
				KurRTC--;
				if ( KurRTC < 1 ) KurRTC = 12;
				LoadRTCKur();
				break;
	case RIHT:
				KurRTC++;																															
				if ( KurRTC == 13 ) KurRTC = 1;
				LoadRTCKur();
				break;
	case ENTER:
				temp = RTC_CTR;
    			RTC_CTR =0;             // disable interrupt
				RTC_DAY   = (BufRTC[1]<<4) | BufRTC[2];							
    			RTC_MONTH = (BufRTC[3]<<4) | BufRTC[4];    			    		
    			RTC_YEAR  = (BufRTC[5]<<4) | BufRTC[6];     			 	  
				RTC_HOUR  = (BufRTC[7]<<4) | BufRTC[8];				     
				RTC_MIN   = (BufRTC[9]<<4) | BufRTC[10];				
				RTC_SEC   = (BufRTC[11]<<4)| BufRTC[12];										 
    			RTC_MSEC  =  0;
    			RTC_UPDT = 0x8000;      // update time    
    			while(RTC_UPDT != 0);    
    			RTC_CTR = temp;         // recover interrupt			
				WriteRTC();				// сохранение в DS1340	
				break;
	case one:
				BufRTC[ KurRTC ] = 1;							
				printNumIRTC();						
				KurRTC++;																															
				if ( KurRTC == 13 ) KurRTC = 1;
				LoadRTCKur();
				break;
	case two:
				BufRTC[ KurRTC ] = 2;							
				printNumIRTC();						
				KurRTC++;																															
				if ( KurRTC == 13 ) KurRTC = 1;
				LoadRTCKur();
				break;
	case three:
				BufRTC[ KurRTC ] = 3;							
				printNumIRTC();						
				KurRTC++;																															
				if ( KurRTC == 13 ) KurRTC = 1;
				LoadRTCKur();
				break;
	case four:
				BufRTC[ KurRTC ] = 4;							
				printNumIRTC();						
				KurRTC++;																															
				if ( KurRTC == 13 ) KurRTC = 1;
				LoadRTCKur();
				break;
	case five:
				BufRTC[ KurRTC ] = 5;							
				printNumIRTC();						
				KurRTC++;																															
				if ( KurRTC == 13 ) KurRTC = 1;
				LoadRTCKur();
				break;
	case six:
				BufRTC[ KurRTC ] = 6;							
				printNumIRTC();						
				KurRTC++;																															
				if ( KurRTC == 13 ) KurRTC = 1;
				LoadRTCKur();
				break;
	case seven:
				BufRTC[ KurRTC ] = 7;							
				printNumIRTC();						
				KurRTC++;																															
				if ( KurRTC == 13 ) KurRTC = 1;
				LoadRTCKur();
				break;
	case eight:
				BufRTC[ KurRTC ] = 8;							
				printNumIRTC();						
				KurRTC++;																															
				if ( KurRTC == 13 ) KurRTC = 1;
				LoadRTCKur();
				break;
	case nine:
				BufRTC[ KurRTC ] = 9;							
				printNumIRTC();						
				KurRTC++;																															
				if ( KurRTC == 13 ) KurRTC = 1;
				LoadRTCKur();
				break;
	case zero:
				BufRTC[ KurRTC ] = 0;							
				printNumIRTC();						
				KurRTC++;																															
				if ( KurRTC == 13 ) KurRTC = 1;
				LoadRTCKur();
				break;
	}
break;

case 221:			// Подсветка
	switch (Key)
	{
	case MENU: Save_All_Coeff(); PrintMainMenu(0); break;
	case LEFT: break;
	case UP:

				for(i=0;i<31;i++)        
    			{       		               					           		                         
      				asm(" BIT (ST1, #ST1_XF) = #0");  	                 	                                                                                                                                                 
					waitusec( 3 );		//4.5 mkC	
       				asm(" BIT (ST1, #ST1_XF) = #1");
					waitusec( 3 );	    		   				   		      	     		                             		       		             
    			}	         			
    			liht=liht-1;  					
    			if( liht==-1 )
    			{
    				liht=31;
    			}    			    		
    			liht2 = 99-(liht*3.2);
    			
    			    			    		
    			if(liht2 < 10)
      			{
      				print("-",120,100,Num40x53,BLACK,BLUE_B);
      				printNumI( liht2,160,100,Num40x53,BLACK,BLUE_B);     		
      			}	
      			else if (liht2 < 100)
      			{      		      				
      				printNumI( liht2,120,100,Num40x53,BLACK,BLUE_B);         				      				      				 
      			}		      	 	      	            			
    			break;
	case DOWN:
				for(i=0;i<1;i++)        
    			{       		               					           		                         
      				asm(" BIT (ST1, #ST1_XF) = #0");  	                 	                                                                                                                                                 
					waitusec( 3 );		//4.5 mkC	
       				asm(" BIT (ST1, #ST1_XF) = #1");
					waitusec( 3 );	    		   				   		      	     		                             		       		             
    			}	   	    			    			    	
    			liht=liht+1;   
    			
    			 				
    			if( liht==32 )
    			{
    				liht=0;
    			}    		    			
    			liht2 = 99-(liht*3.2);  
    			  			
    			if(liht2 < 10)
      			{
      				print("-",120,100,Num40x53,BLACK,BLUE_B);
      				printNumI( liht2,160,100,Num40x53,BLACK,BLUE_B);     		
      			}	
      			else if (liht2 < 100)
      			{      		
      				printNumI( liht2,120,100,Num40x53,BLACK,BLUE_B);         				      				      				 
      			}		      	 	      	            			
    			break;
	}
break;
//Аккумулятор

case 231:
    switch (Key)
    {
      case  MENU: PrintMainMenu(0); break;
      case  LEFT: PrintSettingsMenu(2); break;
	}
break;

//AUX режим!
case 241:
			if(Key == ENTER)
			{	
				MenuLevel = 4;
				TAS5424_OFF();
      			Temp_A=0;
      			EVM5515_GPIO_setOutput(21,0);	      
      			fillRect(140,2,156,18,BLACK);
			    PrintSettingsMenu(3);
			}								
break;

//Калибровка!
case 31:
	switch (Key)
	{
	case MENU:	PrintMainMenu(0); break;
	case LEFT:	PrintMainMenu(2); break;
	case ENTER:
		        switch (code)
		        {
		        case Calibr_CODE:
		        	print("    Режим калибровки активирован!",0,222,FontRus8x15,WHITE, BLUE_B);
		        	drawBitmap8bit(70,2,16,16,Calibr);
		        	break;
		        case 6666:
		        	print(" Калибровочная таблица сброшена! ",0,222,FontRus8x15,WHITE, BLUE_B);
		        	AccelarationTable.length = 0;
		        	//Save_All_Coeff();
		        	break;
		        case 1001:
		        	print(" Лазер активирован! ",0,222,FontRus8x15,WHITE, BLUE_B);
		        	LaserStartFreq = 300;
		        	Save_All_Coeff();
		        	break;
		        case 110:
		       		print(" Лазер дезактивирован! ",0,222,FontRus8x15,WHITE, BLUE_B);
		  		 	LaserStartFreq = 0;
		       	   	Save_All_Coeff();
		       	   	break;
		        case 7777:
		        	print("Режим отладки выключен!",0,222,FontRus8x15,WHITE, BLUE_B);
		        	debugMode = 0;
		        	HoursOnWork = 0;
		        	MinuntsOnWork = 0;
		        	liht = 99;
		        	Save_All_Coeff();
		        	SaveLifeTime();
		       	   	break;
		        case 2846:
		        	print("Режим отладки включен!",0,222,FontRus8x15,WHITE, BLUE_B);
		        	debugMode = 1;
		        	Save_All_Coeff();
		        	break;
		        default:
		           	print("    Введен Неверный код!         ",0,222,FontRus8x15,WHITE, BLUE_B);
		           	break;
		        }
		        break;
	case one:	//  1
				code=(code*10)+1;
     			code = code % 10000;     					 	 		 	 	 		      																				          	      	     	      	       	      	            			      			  
				LCD_Code(code);					      		  								   								        	        			  
				break;
	case two:	//  2
				code=(code*10)+2;
	     		code = code % 10000;
				LCD_Code(code);
				break;
	case three:	//  3
					code=(code*10)+3;
	     			code = code % 10000;
					LCD_Code(code);
					break;
	case four:	//  4
					code=(code*10)+4;
	     			code = code % 10000;
					LCD_Code(code);
					break;
	case five:	//  5
					code=(code*10)+5;
		     		code = code % 10000;
					LCD_Code(code);
					break;
	case six:	//  6
					code=(code*10)+6;
	     			code = code % 10000;
					LCD_Code(code);
					break;
	case seven:	//  7
					code=(code*10)+7;
		     		code = code % 10000;
					LCD_Code(code);
					break;
	case eight:	//  8
					code=(code*10)+8;
			     	code = code % 10000;
					LCD_Code(code);
					break;
	case nine:	//  9
					code=(code*10)+9;
			     	code = code % 10000;
					LCD_Code(code);
					break;
	case zero:	//  0
					code=(code*10)+0;
			     	code = code % 10000;
					LCD_Code(code);
					break;
	}
break;
}

}
    wait(1000);
	EVM5515_GPIO_setOutput(25,0); //////
	cmd[0] = 0x02; 
	cmd[1] = 0x1f;
	//скидываем нажатие
    USBSTK5515_I2C_write( TCA8418_I2C_ADDR, cmd, 2 );
    IFR0 = 0x0004;			//	clear INT0_Isr flag
    cmd[0] = 0x02;
    cmd[1] = 0x1f;
    //скидываем нажатие
    USBSTK5515_I2C_write( TCA8418_I2C_ADDR, cmd, 2 );
    IFR1 = 0x0008;
    IFR0 = 0x0004;			//	clear INT0_Isr flag
    //printf("\nREGIM = %i\n", regim);
    SYS_GlobalIntEnable();
}

interrupt void INT0_Isr(void)
{
	KeyBoardEvent(0,0);
}


// ------------------------------------------------------------------------	*
//							        RTC_Isr									*
//  ----------------------------------------------------------------------- *
interrupt void RTC_Isr(void)
{

	Uint16 i;
    Uint16 temp,temp1;
    Uint32 res_rms,res_rms2;
    Int32 res__rms,res__rms2;
    Int16  VoltageSh;			
	Int16  CurrentSh;	    	  
    Uint16 VoltageBa2;	
    Int16 VoltageBa3_;
    Int16 VoltageBa3;
    float WavePoint;
    int GraphPoint,GraphPointPrev;
    int GrapFrameStep=15;
    double SetDisp;
    unsigned char buff[20];
    Uint16 I_RMS = 0;
    SYS_GlobalIntDisable();
	//clear RTC int flag
    //IFR1 = 0x0008;
    temp =RTC_STAT;
    RTC_STAT = temp;
    SecondsOnWork++;

    if (SecondsOnWork > 60)
    {
    	SecondsOnWork = 0;
    	MinuntsOnWork++;
    	if (MinuntsOnWork > 60)
    	{
    		MinuntsOnWork = 0;
    		HoursOnWork++;
    	}
    	SaveLifeTime();
    }

    if (code != Calibr_CODE)
    {
    	fillRect(70,0,90,20,BLACK);
    }
    //---------------------------------------------------------------- Clock
    if (TempPoint == 0)
	{
		print(":",266,4,Num8x12,WHITE,BLACK);
		TempPoint = 1;
	}
	else
	{
		print(";",266,4,Num8x12,WHITE,BLACK);
		TempPoint = 0;
	}

    EnergySaveClock++;
    if ((EnergySaveClock >= EnergySaveTime) && (IsSleep==0))
    {
    	SetDisplayLigth(1);
    	EnergySaveClock = EnergySaveTime;
    	IsSleep = 1;
    }

    if (IsSleep == 1)
    {
    	EVM5515_GPIO_setOutput(25,TempPoint);
    }

	printNumUI( ((RTC_MIN>>4)&0x000F),274,4,Num8x12,WHITE,BLACK);
	printNumUI( (RTC_MIN&0x000F),282,4,Num8x12,WHITE,BLACK);
	printNumUI( ((RTC_HOUR>>4)&0x000F),250,4,Num8x12,WHITE,BLACK);
	printNumUI( (RTC_HOUR&0x000F),258,4,Num8x12,WHITE,BLACK);
	printNumUI( ((RTC_DAY>>4)&0x000F),0,4,Num8x12,WHITE,BLACK);  //10*(RTC_DAY>>4)&0x000F + (RTC_DAY&0x000F)
	printNumUI( (RTC_DAY&0x000F),8,4,Num8x12,WHITE,BLACK);
	printNumUI( ((RTC_MONTH>>4)&0x000F),24,4,Num8x12,WHITE,BLACK);  //10*(RTC_MONTH>>4)&0x000F) + (RTC_MONTH&0x000F)
	printNumUI( (RTC_MONTH&0x000F),32,4,Num8x12,WHITE,BLACK);
	printNumUI( ((RTC_YEAR>>4)&0x000F),48,4,Num8x12,WHITE,BLACK); //  10*(RTC_YEAR>>4)&0x000F) + (RTC_YEAR&0x000F)
	printNumUI( (RTC_YEAR&0x000F),56,4,Num8x12,WHITE,BLACK);

	if(ls5 < 1)
	{
		ls5 = ls5+1;
	}	
					
	if(ls5 == 1)
	{	
		EVM5515_GPIO_setOutput(26,1);
		UART_TX_Char(0x53,0x54); 			// Зпуск Потока Результата ST
    	while((UART_LSR & 0x40)==0);  		// Wait for TX ready    */
    	EVM5515_GPIO_setOutput(26,0);
    	ls5 = 10;    	 
	}		


	//шлем текущуй режим вибростенда;
	buff[0] = regim ;
	buff[1] = regim >> 8;

	//шлем текущую частоту вибростенда
	buff[2] = reg_frequency & 0x000000FF;
	buff[3] = (reg_frequency & 0x0000FF00) >> 8;
	buff[4] = (reg_frequency & 0x00FF0000) >> 16;
	buff[5] = (reg_frequency & 0xFF000000) >> 24;

	//printf("%x %x %x %x\n",buff[5],buff[4],buff[3],buff[2]);

	//шлем теущее ускорение
	buff[6] = ARDUINO_RMS;
	buff[7] = ARDUINO_RMS >> 8;

	//шлем последнюю принятую команду обратно
		//cmd[8] = ADRUINO_CMD;

		USBSTK5515_I2C_write( ADRUINO_SLAVE, buff, 8 );

	    waitusec(10);
		//Читаем команду
		USBSTK5515_I2C_read ( ADRUINO_SLAVE, buff, 8 );

		I_RMS = (buff[6] << 8)| buff[7];


		//CRC8 = Crc8 (buff,6);
		//if (CRC8 == buff[6])
		//{
			//Shift Registers

			if ((buff[0]> '0') && (buff[0] < '9'))
			{
			  ADRUINO_PREV_CMD = ADRUINO_CMD;
			  ADRUINO_DATA_Prev = ADRUINO_Data;

			  ADRUINO_CMD = buff[0];
			  ADRUINO_Data = (Uint32)(buff[1]-48)*10000+(buff[2]-48)*1000+(buff[3]-48)*100+(buff[4]-48)*10+(buff[5]-48);

			  //I_RMS = (buff[6] << 8)| buff[7];
			}

			if ((ADRUINO_CMD != ADRUINO_PREV_CMD) || (ADRUINO_Data != ADRUINO_DATA_Prev))
				{
					switch (ADRUINO_CMD)
					{
						case '2': //CMD_CHANGE_MODE
						   switch (buff[5])
						   {
							   case '1': regim = 111; MenuCursor = 0; KeyBoardEvent(ENTER,0); break;
							   case '2': regim = 112; MenuCursor = 1; KeyBoardEvent(ENTER,0); break;
							   case '3': regim = 113; MenuCursor = 2; KeyBoardEvent(ENTER,0); break;
						   }
						   break;

						case '3': //CMD_CHANGE_FREQ
							reg_frequency = ADRUINO_Data;
							if ((regim == 1113)||(regim == 1114)||(regim == 11132)||(regim == 11142)) KeyBoardEvent(LEFT,1);
							if ((regim == 1123)||(regim == 1124)||(regim == 11232)||(regim == 11242)) KeyBoardEvent(LEFT,1);
							if ((regim == 1133)||(regim == 1134)||(regim == 11332)||(regim == 11342)) KeyBoardEvent(LEFT,1);
							LCD_Freq(reg_frequency,BLACK);
							break;
						case '4': //CMD_CHANGE_ACC
							reg_acseleration = ADRUINO_Data;
							LCD_Acsel(reg_acseleration,BLACK);
							break;
						case '5': //CMD_CHANGE_VEL
							reg_velosity = ADRUINO_Data;
							LCD_velosity(reg_velosity);
							break;
						case '6': //CMD_CHANGE_DISP
							reg_displacement = ADRUINO_Data;
							LCD_displacement(reg_displacement);
							break;
						case '7':
							KeyBoardEvent(ENTER,0);
							break;
						case '8':
							KeyBoardEvent(ENTER,0);
							break;
						default: ;
				}
			}
		//}


		
    //---------------------------------------------------------------- Acseleration	  
	  	  
	if((regim == 1113)||(regim == 1114)||(regim == 11132)||(regim == 11142))
	{									
	    if ((code == Calibr_CODE))
        {
        	SetDisp = (double) 50712*1.41*(reg_acseleration*0.1)/(reg_frequency*reg_frequency*0.01);
			if (SetDisp > 1500)
        	{
               print("Коэфф.усиления: ", 0, 50, FontRus8x15, WHITE, BLUE_B);
        	   printNumF(KUS_ACC/AccMult,'.',140,50,FontRus8x15,WHITE, BLUE_B);
        	   print("х", 200, 50, FontRus8x15, WHITE, BLUE_B);
        	   printNumF(AccMult,'.',240,50,FontRus8x15,WHITE, BLUE_B);
        	}
        	else
        	{
        		print("Коэфф.усиления: ", 0, 50, FontRus8x15, WHITE, BLUE_B);
        		printNumF(KUS_ACC,'.',140,50,FontRus8x15,WHITE, BLUE_B);
        	}
        }


	    if(KeyDown == KeyUp)
	    {

	    HoldTime++;
	    switch (KeyUp)
	    {
	    case RIHT:
	        reg_frequency = reg_frequency + HoldTime*10;
	    	spi_sin(reg_frequency);
	    	LCD_Freq(reg_frequency,BLACK);
	        break;
	    case LEFT:
		    reg_frequency = reg_frequency + HoldTime*10;
		    spi_sin(reg_frequency);
		    LCD_Freq(reg_frequency,BLACK);
		    break;
	    }
	    } else HoldTime = 0;
	    KeyDown = KeyUp;
		res_rms = RES_ACC+0.5;
        /////////////////////                    		  
		res_rms_D3 = res_rms_D2;   
		res_rms_D2 = res_rms_D1;    	      	      	      	      	  
		res_rms_D1 = res_rms;    	      	      	      	      	  		    	      	      	      	      	 
		res_rms_D0 = (double)res_rms_D1 + res_rms_D2 + res_rms_D3;
		res_rms_D0 = (double)res_rms_D0/3;		    	      	      	         
        res_rms = res_rms_D0+0.5;

        /////////////////////

        if (code == 9999)
            {
        		GrapFrameStep=(float)10/reg_frequency*300+1;
        		fillRect(0,46,320,215,BLACK);
            	GraphPointPrev=v[0]/136;;
            	for (i=1; i < 320; i++)
                  {
            	      	WavePoint = v[i*GrapFrameStep]/136;
            	      	GraphPoint = WavePoint-120;
            	      	drawLinen(i-1,GraphPointPrev,i,GraphPoint,WHITE);
            	      	GraphPointPrev=GraphPoint;
            			//LCD_PutPixel(i,GraphPoint-120,WHITE);
            	  }
            	print("Частота,Гц", 0, 50, FontRus8x15, WHITE, BLACK);
            	printNumF((float)reg_frequency/10,'.',100,50,FontRus8x15,WHITE, BLACK);
            	print("Амп.СКЗ,м/с2", 150, 50, FontRus8x15, WHITE, BLACK);
            	printNumF((float)res_rms/10,'.',260,50,FontRus8x15,WHITE, BLACK);
            }
        else

        if(res_rms < 9999)
      	{      		      		
        	if (((float)(res_rms - reg_acseleration)/reg_acseleration) > 0.01)
		      LCD_Acsel(res_rms,BLACK);
        	else LCD_Acsel(res_rms,BRIGHTGREEN);
        	ARDUINO_RMS = res_rms;
      	}
      	else 
      	{
      		//LCD_Clear_Area(0,39,8,24,WHITE);		      		
      		//print("ПЕРЕГРУЗКА",0,30,FontRus8x15,BLACK,WHITE);      		
      	}	
      	
      	      	         
      	if(KUS_ACC_DR >= 20000)
      	{
      		drawBitmap(160,2,16,16,max1); 	 	// предел	
      	}        	     
      	else
      	{
      		fillRect(160,2,176,18,BLACK);		// непредел
      	}
      	      	            	  	             	   			      	      		       		          		      	      	      	   	   	   				    
	}			
	
    //---------------------------------------------------------------- Velosity
    	 					
	else if((regim == 1123)||(regim == 1124)||(regim == 11232)||(regim == 11242))
	{									 
		 if (code == Calibr_CODE)
		        {
		        	print("Коэфф.усиления: ", 0, 50, FontRus8x15, WHITE, BLUE_B);
		        	printNumF(KUS_VEL,'.',140,50,FontRus8x15,WHITE, BLUE_B);
		        }


		res_rms = RES_VEL+0.5;
      	      	
      	      	
      	/////////////////////                    		  
		res_rms_D3 = res_rms_D2;   
		res_rms_D2 = res_rms_D1;    	      	      	      	      	  
		res_rms_D1 = res_rms;    	      	      	      	      	  		    	      	      	      	      	 
		res_rms_D0 = (double)res_rms_D1 + res_rms_D2 + res_rms_D3;
		res_rms_D0 = (double)res_rms_D0/3;		    	      	      	         
        res_rms = res_rms_D0+0.5;                              
        /////////////////////
         
      	                	      	     	      	       	      	     
      	if(res_rms < 9999)
      	{      		      		
			LCD_velosity(res_rms);
      	}	      	
      	else 
      	{
      		//LCD_Clear_Area(0,39,8,24,WHITE);		      		
      		//print("ПЕРЕГРУЗКА",0,30,FontRus8x15,BLACK,WHITE);      		
      	}	      	             	   
      	
      	
      	if(KUS_VEL_DR >= 20000)
      	{
      		drawBitmap(160,2,16,16,max1); 	 	// предел	
      	}        	     
      	else
      	{
      		fillRect(160,2,176,18,BLACK);	 	// предел
      	}      	      	      				      
	}		
			
    //---------------------------------------------------------------- displasement
     																	      	        	               					        		
	else if((regim == 1133)||(regim == 1134)||(regim == 11332)||(regim == 11342))
	{																
		if (code == Calibr_CODE)
		{
		  	print("Коэфф.усиления: ", 0, 50, FontRus8x15, WHITE, BLUE_B);
		   	printNumF(KUS_DIS,'.',140,50,FontRus8x15,WHITE, BLUE_B);
		}

		res_rms = RES_DIS+0.5;
 		
 		/////////////////////                    		  
		res_rms_D3 = res_rms_D2;   
		res_rms_D2 = res_rms_D1;    	      	      	      	      	  
		res_rms_D1 = res_rms;    	      	      	      	      	  		    	      	      	      	      	 
		res_rms_D0 = (double)res_rms_D1 + res_rms_D2 + res_rms_D3;
		res_rms_D0 = (double)res_rms_D0/3;		    	      	      	         
        res_rms = res_rms_D0+0.5;                              
        /////////////////////
        
 		                  	      	     	      	       	      	     
      	if(res_rms < 9999)
      	{      		      		
			LCD_displacement(res_rms);
      	}	      	
      	else 
      	{
      		//LCD_Clear_Area(0,39,8,24,WHITE);		      		
      		//print("ПЕРЕГРУЗКА",0,30,FontRus8x15,BLACK,WHITE);      		
      	}
      	
      	
      	if(KUS_DIS_DR >= 20000)
      	{
      		drawBitmap(160,2,16,16,max1); 	 		
      	}        	     
      	else
      	{
      		fillRect(160,2,176,18,BLACK);
      	}
      	
      	
      		      	             	   			      	  	        			   				        	   
	}	

	//---------------------------------------------------------------- Temper														        		        		         	      	         	      	         	      	         	                                                   	
	if(regim == 131)
	{							
					
		cmd[0] = 0x00;    
    	USBSTK5515_I2C_write( LM73_I2C_ADDR1, cmd, 1 );                                                          
    	USBSTK5515_I2C_read ( LM73_I2C_ADDR1, cmd, 2 );                                                       				
		Temper = (double)((cmd[0]<<8)|cmd[1])/128;		
		printNumF(Temper,1,224,80,FontRus16x28,WHITE,BLUE_B);			
										
		cmd[0] = 0x00;    
    	USBSTK5515_I2C_write( LM73_I2C_ADDR2, cmd, 1 );                                                          
    	USBSTK5515_I2C_read ( LM73_I2C_ADDR2, cmd, 2 );                                                       		
		Temper = (double)((cmd[0]<<8)|cmd[1])/128;		
		printNumF(Temper,1,224,120,FontRus16x28,WHITE,BLUE_B);	
				
		cmd[0] = 0x00;    
    	USBSTK5515_I2C_write( LM73_I2C_ADDR3, cmd, 1 );                                                          
    	USBSTK5515_I2C_read ( LM73_I2C_ADDR3, cmd, 2 );                                                       		
		Temper = (double)((cmd[0]<<8)|cmd[1])/128;		
		printNumF(Temper,1,224,160,FontRus16x28,WHITE,BLUE_B);	
																															 
	}						
	//---------------------------------------------------------------- SD
	
   	cmd[0] = 0xFF;       	 	   	
   	USBSTK5515_I2C_write( PCF8574_I2C_ADDR2, cmd, 1 );       	   	      	 	     	 
   	USBSTK5515_I2C_read(  PCF8574_I2C_ADDR2, cmd, 1 );          	    
   	   	          	     	   	          	    
	if ( TempSD != (cmd[0] & 0x80))
	{	
		if ((cmd[0] & 0x80) == 0)    
		{	
			//drawBitmap(200,2,16,16,sd1);
		}
		else	
		{
			fillRect(200,2,216,18,BLACK);
		}	
	}	
	else	
	{	
	}		
	TempSD = (cmd[0] & 0x80);  	
			                                            					                                            				                                            				                                                     
 	cmd[0] = 0xFF;       	 	   	
   	USBSTK5515_I2C_write( PCF8574_I2C_ADDR2, cmd, 1 );     	     	 	   
   	USBSTK5515_I2C_read(  PCF8574_I2C_ADDR2, cmd, 1 );      
   	   	    	   	     	   	 			  		 
	if ( TempUSB != (cmd[0] & 0x40))
	{	
		if ((cmd[0] & 0x40) == 0)    
		{	
			fillRect(180,2,196,18,BLACK);
		}
		else	
		{
			//drawBitmap(180,2,16,16,usb1);
		}	
	}	
	else	
	{	
	}		
	TempUSB = (cmd[0] & 0x40);
/*
 *
 *
 *
//Batary Charging
 *
 *
 *
 *
 *
*/
	//---------------------------------------------------------------- Accumulator	
					



	if(regim == 231)
	{
		//tok------------------------------------------------------------------------------------------
		cmd[0] = 0x01;    
    	USBSTK5515_I2C_write( INA219_I2C_ADDR2, cmd, 1 );                                        
    	USBSTK5515_I2C_read ( INA219_I2C_ADDR2, cmd, 2 );                                                              
	    waitusec( 100 );	    											
		cmd[0] = 0x01;    
    	USBSTK5515_I2C_write( INA219_I2C_ADDR2, cmd, 1 );                                        
    	USBSTK5515_I2C_read ( INA219_I2C_ADDR2, cmd, 2 );                                                             
		VoltageSh=((cmd[0]<<8)|cmd[1]);			
		CurrentSh=VoltageSh/1;		

		res__rms = CurrentSh;						
		if(res__rms < 9999)
      	{      		       		
      		if(res__rms >= 0)
      		{
      			print(" ",110-16,80,FontRus16x28,WHITE,BLUE_B);  
      		}  
      		else 
      		{      			
      			print("-",110-16,80,FontRus16x28,WHITE,BLUE_B);
      			res__rms = res__rms*(-1);      			 
      		}      			      	
      		res__rms2= res__rms % 10;      	
      		res__rms= res__rms / 10;    		
      		printNumI( res__rms2,110+16*3,80,FontRus16x28,WHITE,BLUE_B);      		
      		res__rms2= res__rms % 10;      	
      		res__rms= res__rms / 10;    		
      		printNumI( res__rms2,110+16*2,80,FontRus16x28,WHITE,BLUE_B);      		
      		res__rms2= res__rms % 10;      	
      		res__rms= res__rms / 10;    		
      		printNumI( res__rms2,110+16,80,FontRus16x28,WHITE,BLUE_B);      		
      		res__rms2= res__rms % 10;      	
      		res__rms= res__rms / 10;    		
      		printNumI( res__rms2,110,80,FontRus16x28,WHITE,BLUE_B);      		      	      		      	      		   
      	}	      	
      	else 
      	{
      		 		
      	}	      	             	   			      		

		//napregenie----------------------------------------------------------------------------------------																																				
 		cmd[0] = 0x02;    
    	USBSTK5515_I2C_write( INA219_I2C_ADDR2, cmd, 1 );                                        
    	USBSTK5515_I2C_read ( INA219_I2C_ADDR2, cmd, 2 );                                                          						
		VoltageBa2=(((cmd[0]<<8)|cmd[1])>>3)&0x1fff;	
		printNumF((double)VoltageBa2/250,1,110,110,FontRus16x28,WHITE,BLUE_B);  //(U*32)/8000 = x/250
		//zarad----------------------------------------------------------------------------------------------	
				
		//printNumI(VoltageBa2,0,30,Num8x8,WHITE,BLUE_B); 
				
		VoltageBa3_=VoltageBa2;
		VoltageBa3 = (VoltageBa3_-2500)/7;

		if (VoltageBa3 <= 0)
		{
			VoltageBa3 = 0;
			print("  ",126,50,FontRus16x28,WHITE,BLUE_B); 		
      		printNumUI(0,158,50,FontRus16x28,WHITE,BLUE_B);  
		}							
		else if(VoltageBa3 < 10)
      	{
      		print("  ",126,50,FontRus16x28,WHITE,BLUE_B); 		
      		printNumUI(VoltageBa3,158,50,FontRus16x28,WHITE,BLUE_B);  
      	}					
		else if (VoltageBa3 < 100)
      	{
      		print(" ",126,50,FontRus16x28,WHITE,BLUE_B); 		
      		printNumUI(VoltageBa3,142,50,FontRus16x28,WHITE,BLUE_B);  
      	}		      							
		else if (VoltageBa3 >= 100)
		{
			VoltageBa3 = 100;
			printNumUI(VoltageBa3,126,50,FontRus16x28,WHITE,BLUE_B);  
		}																																			      	    	      	      	       	         
      	else 
      	{
      			
      	}
								
		/*
		for(i=0; i<((100 - VoltageBa3)*1.2); i++)        
    	{       		               					           		                             		
    		drawBitmap(230,80+i,80,1,bat_fon);    		   		   				   		      	     		                             		       		            
    	}	    	    	

    	
		for(i=0; i< (VoltageBa3 * 1.2); i++)        
    	{       		               					           		                             		
    		drawBitmap(230,200-i,80,1,bat_big);    		   		   				   		      	     		                             		       		            
    	}*/
		//Temper----------------------------------------------------------------------------------------------
	
		cmd[0] = 0x00;    
    	USBSTK5515_I2C_write( LM73_I2C_ADDR1, cmd, 1 );                                                          
    	USBSTK5515_I2C_read ( LM73_I2C_ADDR1, cmd, 2 );                                                       				
		Temper = (double)((cmd[0]<<8)|cmd[1])/128;		
		printNumF( Temper,1,110,140,FontRus16x28,WHITE,BLUE_B);	
		//СТАТУС РАЗРЯЖАЕТСЯ----------------------------------------------------------------------------------------------						
		if (Temp_B == 0)    
		{					
			print("РАЗРЯЖАЕТСЯ",10+13*8,210,FontRus8x15,RED,BLUE_B); 	// заряд не идет											
		}
		else	
		{				
			print("ЗАРЯЖАЕТСЯ ",10+13*8,210,FontRus8x15,WHITE,BLUE_B);   // заряд идет								
						
		}	
	}
	else
	{		
	}		

	//------------------------- Напряжение Сети ---------------------- Zarad on/off	//от 9.5В до 14В, ток заряда 500 мА на 10 часов.
	cmd[0] = 0x02;    
    USBSTK5515_I2C_write( INA219_I2C_ADDR1, cmd, 1 );                                        
    USBSTK5515_I2C_read ( INA219_I2C_ADDR1, cmd, 2 );                                                          	
	
	VoltageSh=(((cmd[0]<<8)|cmd[1])>>3)&0x1fff;		 		
	VoltageSh=VoltageSh/25;
	

	if (VoltageSh < 95)    
	{					
		//fillRect(220,2,236,18,BLACK);		// заряд не идет
		Temp_B = 0;										
	}
	else	
	{				
		//drawBitmap(220,2,16,16,Power1);   	// заряд идет
		Temp_B = 1;			
	}
	//---------------------- Напряжение Аккумулятора -------------------	
	cmd[0] = 0x02;    
    USBSTK5515_I2C_write( INA219_I2C_ADDR2, cmd, 1 );                                        
    USBSTK5515_I2C_read ( INA219_I2C_ADDR2, cmd, 2 );                                                          		
	VoltageBa2=(((cmd[0]<<8)|cmd[1])>>3)&0x1fff;			                                                                     
   	temp1 = VoltageBa2/25;           
	

   	//это он рисует красивую батарейку!

	if(temp1 < 100)
	{					
		if(Temp_Bat == 0)					
		{				
			Temp_Bat = 1;
														
			/*drawBitmap(299,5,3,10,bat_smallzr);
    		drawBitmap(303,5,3,10,bat_smallzr); 
	    	drawBitmap(307,5,3,10,bat_smallzr); 
	    	drawBitmap(311,5,3,10,bat_smallzr); 
    		drawBitmap(315,5,3,10,bat_smallzr);**/
		}
    	else if(Temp_Bat == 1)					
		{					
			Temp_Bat = 0;
											
			/*drawBitmap(299,5,3,10,bat_smallz);
    		drawBitmap(303,5,3,10,bat_smallz); 
	    	drawBitmap(307,5,3,10,bat_smallz); 
	    	drawBitmap(311,5,3,10,bat_smallz); 
    		drawBitmap(315,5,3,10,bat_smallz); 	*/
		}
	}
	
	if( Temp_A==0 )
	{									

//---------------------- Напряжение Аккумулятора -------------------	
	cmd[0] = 0x02;    
    USBSTK5515_I2C_write( INA219_I2C_ADDR2, cmd, 1 );                                        
    USBSTK5515_I2C_read ( INA219_I2C_ADDR2, cmd, 2 );                                                          		
	VoltageBa2=(((cmd[0]<<8)|cmd[1])>>3)&0x1fff;			                                                                     
   	temp1 = VoltageBa2/25;           
          
	if 	(Temp_B == 0)
	{
		
		cmd[0] = 0x1c;
    	cmd[1] = 0x02;    
    	USBSTK5515_I2C_write( AD5272_I2C_ADDR, cmd, 2 );  	// iniChargBat 
		
		Resistance = 400;
		cmd[1] = Resistance;
		cmd[0] = (((Resistance>>8)&(0x03))|0x04);
		USBSTK5515_I2C_write( AD5272_I2C_ADDR, cmd, 2 );   						 							 							    	                                              		
	}
	else if(Temp_B == 1)
	{
		 
		cmd[0] = 0x01;    
    	USBSTK5515_I2C_write( INA219_I2C_ADDR2, cmd, 1 );                                        
    	USBSTK5515_I2C_read ( INA219_I2C_ADDR2, cmd, 2 );    
                                                          	
	    waitusec( 100 );
																																								        		        		         	      	         	      	         	      	         	                                               
		cmd[0] = 0x01;    
    	USBSTK5515_I2C_write( INA219_I2C_ADDR2, cmd, 1 );                                        
    	USBSTK5515_I2C_read ( INA219_I2C_ADDR2, cmd, 2 );    
                                                          
		VoltageSh=((cmd[0]<<8)|cmd[1]);			
		CurrentSh=VoltageSh/1;
															
		if(CurrentSh > 1500)
		{		
			Resistance = 400;	
		}
		else
		{
			if ((CurrentSh < 500) && (CurrentSh > 10))
			{
				Resistance = Resistance - 10;
			}
			else Resistance = 1;
		}
		
		cmd[0] = 0x1c;
    	cmd[1] = 0x02;    
    	USBSTK5515_I2C_write( AD5272_I2C_ADDR, cmd, 2 );  	// iniChargBat

		cmd[1] = Resistance;
		cmd[0] = (((Resistance>>8)&(0x03))|0x04);
		USBSTK5515_I2C_write( AD5272_I2C_ADDR, cmd, 2 );  
	}

	IFR1 = 0x0008;
    SYS_GlobalIntEnable();
}
}

Uint16 tx1[512];
Uint16 rx1[512];


// ------------------------------------------------------------------------	*                                                        				   	*
//							        UART_Isr	Интерферометр				*
//  ----------------------------------------------------------------------- *
interrupt void TXRX_isr(void)
{
    //Uint16 temp;
	Uint16 temp = UART_IIR;
	temp = UART_RBR;	
	Uint16 FrameSize;
    Dis_Pro = 0;
    Dis_Pro = Dis_Pro + (UART_RBR & 0x0F)*10000;
    Dis_Pro = Dis_Pro + (UART_RBR & 0x0F)*1000;
    Dis_Pro = Dis_Pro + (UART_RBR & 0x0F)*100;
    Dis_Pro = Dis_Pro + (UART_RBR & 0x0F)*10;
    Dis_Pro = Dis_Pro + (UART_RBR & 0x0F);              
    temp = UART_RBR;

    if (reg_frequency <= 10) FrameSize = 500;
    	else FrameSize = 250;

    if ( Dis_Pro_max < Dis_Pro)	Dis_Pro_max = Dis_Pro;
  	if ( Dis_Pro_min > Dis_Pro)	Dis_Pro_min = Dis_Pro;
  	if( Temp_I >= FrameSize)
  	{  		       	    	    	    	    	
    	Dis_Pro_Delta = Dis_Pro_max - Dis_Pro_min;    	
    	RES_DIS = (double)Dis_Pro_Delta / 10.0;
    	Temp_I = 0;
    	Dis_Pro_min = 50000; 	
    	Dis_Pro_max = 0;
    	switch (regim)
    	{
    	case 11132: case 11142:
    		RES_ACC = (double)RES_DIS * reg_frequency * reg_frequency * 13.9577283992777  / 1000.0 / 10000.0; // V = 2*P*F*  S  *2*P*f/2*1.41*1000
    		Reg_ACC_D = (double)reg_acseleration;		
			KUS_1 = (double)Reg_ACC_D/RES_ACC;					
			KUS_ACC_DR = KUS_ACC_DR * KUS_1;				  				
			if (KUS_ACC_DR >= 20000) KUS_ACC_DR = 20000;
      		spi_Kus(KUS_ACC_DR);
      		break;
    	case 11232: case 11242:
			RES_VEL = (double)RES_DIS * reg_frequency * 2.221441469 / 1000.0;   	  	 		// V = S*2*P*f/2*1.41*1000								 						 								  				 								  				 								  			
    		Reg_VEL_D = (double)reg_velosity;
			KUS_2 = (double)Reg_VEL_D/RES_VEL;					
			KUS_VEL_DR = KUS_VEL_DR * KUS_2;		  						  						  	
			if(KUS_VEL_DR >= 20000) KUS_VEL_DR = 20000;
      		spi_Kus(KUS_VEL_DR);
      		break;
    	case 11332: case 11342:
    		Reg_DIS_D = (double)reg_displacement;    	    
			KUS_3 = (double)Reg_DIS_D/RES_DIS;					
			KUS_DIS_DR = KUS_DIS_DR * KUS_3;		  						  						  					
			if(KUS_DIS_DR >= 20000) KUS_DIS_DR = 20000;
			spi_Kus(KUS_DIS_DR);
			break;
    	default:
    		Temp_I++;
    		break;
    	}
  	}
}	


// ------------------------------------------------------------------------	*                                                       				   	*
//							    reset_RTC								    *
// ------------------------------------------------------------------------ *  
void reset_RTC(void)    // Загрузка времени и даты из 1340 в часы 5515
{
    Uint16 temp;    
    temp = RTC_CTR;
    RTC_CTR =0;             // disable interrupt
    RTC_PMGT = 0x0011;
    ReadRTC();
    RTC_MSEC  = 0x00;    
    RTC_SEC   = cmd[0]; 
    RTC_MIN   = cmd[1];
    RTC_HOUR  = cmd[2];              
   	RTC_DAY   = cmd[4];
    RTC_MONTH = cmd[5];
    RTC_YEAR  = cmd[6];               
    RTC_UPDT = 0x8000;      // update time    
    while(RTC_UPDT != 0);    
    RTC_CTR = temp;         // recover interrupt
}

// ------------------------------------------------------------------------	*                                                    				   	*
//							      SDRAM_INIT							    *
//                               MT48LC4M16A2B4                             *
// ------------------------------------------------------------------------ *  
SDRAM_INIT() 
{
    int i;           
    // reset EMIF 
    PRCR = 0x0002;
    for(i=0;i<0xff;i++);    
    //enable SDRAM clock
    CLKCFGL=0x0001;
	// enable word writes to EMIF regs 
    ESCR = 0;
    // step 1 
    SDTIMR1 = 0x4710;
    SDTIMR2 = 0x3911;
    SDSRETR = 0x0007;
    // step 2 
    SDRCR = 0x04E3;
    // step 3 
    SDCR1 = 0x4720;
    SDCR2 = 0x0001;
    // step 4 
    for(i=0;i<0xff;i++);
    // step 5 
    SDRCR = 0x061A;
}

void GPIOConfig()
{
	EVM5515_GPIO_init( );
	EVM5515_GPIO_setDirection(4,0);		// cs_amp
	EVM5515_GPIO_setDirection(5,0);		// cs_sin
	//EVM5515_GPIO_setDirection(7,0);		// cs_STM32
	EVM5515_GPIO_setDirection(21,0);	// sin1-sin2
	EVM5515_GPIO_setDirection(22,0);	// en_standby tas5424
	EVM5515_GPIO_setDirection(23,0);	// сброс индикатора!
	EVM5515_GPIO_setDirection(24,0);	// en_c
	EVM5515_GPIO_setDirection(25,0);	// led_BLUE_T
	EVM5515_GPIO_setDirection(26,0);	// en_re/de
	EVM5515_GPIO_setOutput(4,1);
	EVM5515_GPIO_setOutput(5,1);
	EVM5515_GPIO_setOutput(21,0);
	EVM5515_GPIO_setOutput(22,1);
	EVM5515_GPIO_setOutput(23,0);
	EVM5515_GPIO_setOutput(24,0);
	EVM5515_GPIO_setOutput(25,0);
	EVM5515_GPIO_setOutput(26,0);
	EVM5515_GPIO_setOutput(23,0);   // сброс индикатора!!!
	waitusec( 60000 );
	waitusec( 60000 );
	waitusec( 60000 );
	EVM5515_GPIO_setOutput(23,1);
	waitusec( 60000 );
	waitusec( 60000 );
	waitusec( 60000 );
	waitusec( 60000 );
	spi_sin(640);
	waitusec( 60000 );
	spi_Kus(0);
	waitusec( 60000 );
}

int PCF8574_INIT()
{
	int i;
	int Status;
	for (i = 0; i < 10; i++)
	    {
	      cmd[0] = 0x0F;
	      Status = USBSTK5515_I2C_write( PCF8574_I2C_ADDR1, cmd, 1 );

	      cmd[0] = 0x0f;
	      Status -= USBSTK5515_I2C_write( PCF8574_I2C_ADDR1, cmd, 1 );

	   	  cmd[0] = 0x7F;
	   	  Status -= USBSTK5515_I2C_write( PCF8574_I2C_ADDR1, cmd, 1 );

	   	  if (Status == 0) return 0;
	   	  waitusec(1000000);
	    }
	return -1;
}


int LM73_INIT(Uint16 Adress)
{
	cmd[0] = 0x04;
	cmd[1] = 0x68;
	return USBSTK5515_I2C_write(Adress, cmd, 2);
}


int TCA8418_INIT()
{
	int Status;
	waitusec( 65000 );
	cmd[0] = 0x01;
	cmd[1] = 0x91; //0x81
	Status = USBSTK5515_I2C_write( TCA8418_I2C_ADDR, cmd, 2 );
	waitusec( 65000 );
	cmd[0] = 0x1D;
	cmd[1] = 0xFF;
	cmd[2] = 0xFF;
	cmd[3] = 0x03;
	Status -= USBSTK5515_I2C_write( TCA8418_I2C_ADDR, cmd, 4 );
	return Status;
}


int TAS5424_INIT()
{
	cmd[0] = 0x0C;
	cmd[1] = 0x90;
	return USBSTK5515_I2C_write( TAS5424_I2C_ADDR, cmd, 2 );
}


int AD5272_INIT()
{
	int Status;
	int R;
	//Потенциометр для зарядки аккумулятора
	cmd[0] = 0x1c;
	cmd[1] = 0x02;
	Status = USBSTK5515_I2C_write( AD5272_I2C_ADDR, cmd, 2 );  	// iniChargBat
	R = 400;     //0x3ff; //0x000; 400;
	cmd[1] = R;
	cmd[0] = (((R>>8)&(0x03))|0x04);
	Status -= USBSTK5515_I2C_write( AD5272_I2C_ADDR, cmd, 2 );  	// writeChargBat
	return Status;
}

ChnlData ReadAccData(int BuffCount, ChnlData PrevChnlData)
{
	int j;
	double ACC_D = 0.0;
	for (j = 0; j < BuffCount; j++)
	{
		set_dma0_ch2_i2s0_Lin_non();
		waitusec( 500000 );
		PrevChnlData = accelerometr_new(4800,PrevChnlData.Avg);
		ACC_D = (double)ACC_D + PrevChnlData.Rms;
	}
	PrevChnlData.Rms = ACC_D/BuffCount;
	return PrevChnlData;
}

void main(void)
{
	SYS_GlobalIntDisable();
	Uint32 i,j;
	IsSleep = 0;
	EnergySaveTime = 30000;
	int BuffCount = 1;
	double CurrAVG = 0;
	int FrameSize;
	ChnlData PrevChnlData;
	PrevChnlData.Avg=0.0;
	PrevChnlData.Rms=0.0;
    InitSystem();
   	waitusec( 65000 );
   	spirom_init( );
  	waitusec( 65000 );
  	GPIOConfig();
    nand_init();
    LoadLifeTime();
    Read_All_Coeff();
    if (liht > 100)
      {
        	liht = 99;
      }
  	SetDisplayLigth(liht);
    LCD_INI();
    LCD_Clear(BLUE_B);
    UART_INIT( );
    USBSTK5515_I2C_reset();     						// i2c reset
    waitusec(65000);
    print("Загрузка...",110,90,FontRus8x15,WHITE,BLUE_B);
    LCD_Rectangle(20,110,30,130,WHITE);
    //инициализация расширителя портов
    PCF8574Test = PCF8574_INIT();
    LCD_Rectangle(20,110,40,130,WHITE);
    //Инициализация датчиков тока и напряжения
    LM73Adr1Test = LM73_INIT(LM73_I2C_ADDR1);
    LM73Adr2Test = LM73_INIT(LM73_I2C_ADDR2);
    LM73Adr3Test = LM73_INIT(LM73_I2C_ADDR3);
	LCD_Rectangle(20,110,60,130,WHITE);
	//Инициализация контроллера клавиатуры
    KeyBoardTest = TCA8418_INIT();
    LCD_Rectangle(20,110,80,130,WHITE);
    //Инициализация усилителя мощности
    PowerAmplTest = TAS5424_INIT();
	LCD_Rectangle(20,110,100,130,WHITE);
    //Инициализация потенциометра
    BatRTest = AD5272_INIT();
	LCD_Rectangle(20,110,140,130,WHITE);
	//
    setDMA_address();
    set_i2s0_slave();
    //Инициализация кодека
    Aic3204_Setup(Rate48k);
	enable_i2s0();			
    enable_dma_int();
	set_dma0_ch2_i2s0_Lin_non();
	LCD_Rectangle(20,110,250,130,WHITE);
	if (debugMode != 0) PrintDebugInfo();
	else
	{
		LCD_Clear(BLUE_B);
		LCD_Rectangle(0,0,319,19,BLACK);				// Rectangle
		print(".",16,4,Num8x12,WHITE,BLACK);
		print(".",40,4,Num8x12,WHITE,BLACK);
		PrintAboutScreen();
	}

	Timer0Init();
	IFR0 = 0x0004;			//	clear INT0_Isr flag
	IER0 = 0x004C;  		// enable KEY int0,int1 & UART int   0x0044;
	IER1 = 0x0004;      	// enable RTC int
	SYS_GlobalIntEnable();
    OnChargRTC();			//OffChargRTC();    
	reset_RTC();
	enable_rtc_second_int();
	MenuLevel = 100;


	while (1 > 0)
	{
		BuffCount = 480/reg_frequency+1;
		switch (regim)
		{
			//Acceleration Mode
			case 1113: case 1114:
				PrevChnlData = ReadAccData(BuffCount, PrevChnlData);
				RES_ACC =(double)PrevChnlData.Rms/KUS_ACC;
				Reg_ACC_D = (double)reg_acseleration;
				KUS_1 = (double)Reg_ACC_D/RES_ACC;
				KUS_ACC_DR = KUS_ACC_DR * KUS_1;
				if(KUS_ACC_DR >= 21483) KUS_ACC_DR = 21483;
				spi_Kus(KUS_ACC_DR);
				break;
			//Velosity mode
			case 1123: case 1124:
				PrevChnlData = ReadAccData(BuffCount, PrevChnlData);
				RES_VEL = (double) 112.5*1.41*(PrevChnlData.Rms/KUS_VEL)/(reg_frequency*0.1);
				Reg_VEL_D = (double)reg_velosity;
				KUS_2 = (double)Reg_VEL_D/RES_VEL;
				KUS_VEL_DR = KUS_VEL_DR * KUS_2;
				if(KUS_VEL_DR >= 21483) KUS_VEL_DR = 21483;
				spi_Kus(KUS_VEL_DR);
				break;
			//Displacement mode
			case 1133: case 1134:
				PrevChnlData = ReadAccData(BuffCount, PrevChnlData);
				RES_DIS = (double) 50712*1.41*(ACC_D/KUS_DIS)/(reg_frequency*reg_frequency*0.1);
				Reg_DIS_D = (double)reg_displacement;
				KUS_3 = (double)Reg_DIS_D/RES_DIS;
				KUS_DIS_DR = KUS_DIS_DR * KUS_3;
				if(KUS_DIS_DR >= 21483) KUS_DIS_DR = 20000;
				spi_Kus(KUS_DIS_DR);
				break;
			default:
				if (StandStatus == Stand_Stoping)
				{
					KUS_ACC_DR = KUS_ACC_DR*0.95;
					if (KUS_ACC_DR > 1)
					{
						spi_Kus(KUS_ACC_DR);
						waitusec(5000);
					}
					else
					{
						spi_Kus(0);
						TAS5424_OFF();
						LaserOFF();
						StandStatus = Stand_Idle;
						PrevChnlData.Avg=0.0;
						PrevChnlData.Rms=0.0;
					}
				}
				break;
		}
		cmd[0] = 0x02;
		cmd[1] = 0x1f;	      	//cmd[1] = 0x11;
		USBSTK5515_I2C_write( TCA8418_I2C_ADDR, cmd, 2 );
	}
}



