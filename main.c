//  Vzv-1M5
//  Copyright 2011 by Shubin Vladimir.
//  Refactoryng by Alexander Mikhalev 2019 Deleted Over 9000 Lines Of Code
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

extern void AIC3254_init(void);

//-------------------
Uint16 LoadingEnd = 0;
Uint16 XcordTemp = 0;
Uint16 YcordTemp = 0;
Uint16 X1cord = 0;
Uint16 X2cord = 0;
Uint16 Y1cord = 0;
Uint16 Y2cord = 0;
double DeltaX = 2.9805555;
double DeltaY = 1.9423755;
Uint16 Xleft  = 888;
Uint16 Xright = 170;
Uint16 Yleft  = 736;
Uint16 Yright = 112;
//------------------
Uint8 StopWatchHour = 0;
Uint8 StopWatchMinut = 0;
Uint8 StopWatchSecond = 0;
Uint8 StopWatchStart = 0;
//------------------
char BufRTC[13];
Uint8 KurRTC  = 1;
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
Uint16 ADRUINO_Data = 0;

double amp = 0.0;
double fri = 0.0;

Uint8 Regim_Ccalc = 1;
Uint8 Opera_Ccalc = 0;
double Ccalc_operand_1=0;
double Ccalc_operand_2=0;
double Ccalc_rezult=0;
Uint16 LaserStartFreq = 0;
Uint16 LifeTime = 0;
Uint8 SecondsOnWork = 0;
Uint8 MinuntsOnWork = 0;
Uint16 HoursOnWork = 0;
//------------------


Uint8 CalibrDate[3];

#include "menu.h"
#include "I2S_Library.h"
#include "FunctionRTC.h"

#include "Power.h"
#include "Expander.h"
#include "GetXY.h"

#define Rcv 0x08
#define Xmit 0x20

#define NBIQ 1
//#define NH 5 * NBIQ 
#define NH 201
//#define NH 325

#define NX 4800  //5000

#define M       NX     // Number of samples per block  //
#define Ns      1      // Number of 2nd order sections //

// 8000Hz //
// Hi-pass IIR filter coefficients //                                                                                                                                                                                                                                                                                                                                                                                                    
double HP4F10FS8000P1[Ns*5]  = {-1.98841801737465880, 0.98845726781873344, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};                      	                                                             
double HP4F10FS8000P2[Ns*5]  = {-1.99516324128386250, 0.99520262487551059, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};
double HP2F10FS8000P0[Ns*5]  = {-1.98889290589965320, 0.98895424993312653, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};
double HP2F30FS8000P0[Ns*5]  = {-1.96668138526348520, 0.96722742815186058, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};
double HP2F50FS8000P0[Ns*5]  = {-1.94447765776709320, 0.94597793623228121, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};	 
// Low-pass IIR filter coefficients //                               
double LP1F10FS8000P0[Ns*5]  = {-0.99764657698219905, 0.00000000000000000, 0.00000000000000000, 0.01790000000000000, 0.01790000000000000};                                                                                                                                                  
double LP2F10FS8000P0[Ns*5]  = {-1.99000359601345210, 0.99005331218623394, 0.00112320000000000, 0.00112320000000000, 0.00224640000000000};	

//iir(v,X1,HP2F05FS6000P0,Ns,w); 
// 6000Hz //
// Hi-pass IIR filter coefficients //   
double HP1F03FS6000P0[Ns*5]  = {-0.99686333183343800, 0.00000000000000000, 0.00000000000000000, 1.00000000000000000, -1.00000000000000000};  
double HP4F07FS6000P1[Ns*5]  = {-1.98649307898141060, 0.98654645179533407, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};                      	                                                             
double HP4F07FS6000P2[Ns*5]  = {-1.99435172830831610, 0.99440531226731355, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};
double HP4F10FS6000P1[Ns*5]  = {-1.98072746010922640, 0.98083607060779432, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};                      	                                                             
double HP4F10FS6000P2[Ns*5]  = {-1.99190800981960230, 0.99201723338841963, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};
double HP4F30FS6000P1[Ns*5]  = {-1.94263823054011380, 0.94359727847036723, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};                      	                                                             
double HP4F30FS6000P2[Ns*5]  = {-1.97526963485187320, 0.97624479235943995, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};
double HP2F05FS6000P0[Ns*5]  = {-1.99259522875030210, 0.99262254312709508, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};
double HP2F10FS6000P0[Ns*5]  = {-1.98519065789626130, 0.98529951312821451, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};    
double HP2F30FS6000P0[Ns*5]  = {-1.95557824031503520, 0.95654367651120320, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000}; 
double HP2F200FS6000P0[Ns*5]  = {-1.7055521455440841,  0.7436551950488659, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};                      
// Low-pass IIR filter coefficients //    
double LP1F10FS6000P0[Ns*5]  = {-0.99477767233477821, 0.00000000000000000, 0.00000000000000000, 0.02367000000000000, 0.02367000000000000};                                                                                                                                                  
double LP2F10FS6000P0[Ns*5]  = {-1.98815244952631210, 0.98822221966676327, 0.00019800000000000, 0.00019800000000000, 0.00039600000000000};    
      
// 6000Hz //
// Hi-pass IIR filter coefficients //  
double HP2F02FS6000P0[Ns*5]  = {-1.99703808020183130, 0.99704246020446452, 1.00000000000000000, 1.00000000000000000, -2.00000000000000000};  
Uint8 AmpTable[15];

typedef struct Point_t
{
	Uint16 Freq;
	Uint16 Kus;
} Point;

typedef struct AccTable_t
{
  Point Records[32];
  Uint8 length;
} AccTable;


Uint16 GetKUSInit(Uint16 Freq)
{
	Uint16 StartKus;
	if (Freq > LaserStartFreq)
	{
		//StartKus = 10000/Freq;
		StartKus = 1;
		if (StartKus > 0) return StartKus;
			else return 1;
	}
	else
		return 1;
}

float AccMult = 1.0;

double GetKUSFromTable(AccTable Table, Uint16 Freq, float Acceleration)
{
	Uint8 i;
	Uint16 df;
	int FreqId;
	double SetDisp, DeltaDisp, DeltaMult;

	float Acc_Table[15];
	int dk;
	float Fk;

	for (i=0; i<6; i++) Acc_Table[i] = AmpTable[i]*0.01;

	AccMult = 1.0;

	SetDisp = (double) 50712*1.41*(Acceleration)/(Freq*Freq);

	if (SetDisp > 1500)
	{

		FreqId = (SetDisp - 1500)/500;
		if (Freq < 16)
		{

			if (FreqId < 0) AccMult = 1.0;
			else
			{
				DeltaDisp = (FreqId)*500+1500;
				DeltaDisp = (float)(SetDisp-DeltaDisp)/500;
				DeltaMult = (Acc_Table[FreqId+1] - Acc_Table[FreqId]);
				AccMult = Acc_Table[FreqId]+DeltaMult*(DeltaDisp);
			}
		}
		else
		{
			AccMult = 1.0;
		}
	}

	if (Freq > 1000) return (float)(Table.Records[Table.length-1].Kus)/1000;

	if (Table.length == 0) return 1.0;
	else
	{
		for (i=0; i< Table.length; i++)
		{
			if (Freq <= Table.Records[i].Freq)
			{
				if (i > 0)
				{
					df = Table.Records[i].Freq-Table.Records[i-1].Freq;
					dk = Table.Records[i].Kus-Table.Records[i-1].Kus;
					Fk = (float) dk / df;
					return (float)(Table.Records[i-1].Kus+Fk*(Freq - Table.Records[i-1].Freq))/1000 * AccMult;
				} else return (float) (Table.Records[0].Kus)/1000 * AccMult;
			}
		}
	}
}

AccTable AddRecToINterpolateTable(AccTable Table, Point P)
{
	Uint8 i,j;
	if (Table.length == 0)
	{
		Table.Records[0].Freq = 10;
		Table.Records[0].Kus = P.Kus;
		Table.Records[1].Freq = P.Freq;
		Table.Records[1].Kus = P.Kus;
		Table.Records[2].Freq = 9999;
		Table.Records[2].Kus = P.Kus;
		Table.length = 3;
	}
	//Find Fist Point Freq > LastFreq
	else
	{
		if (P.Freq == 10)
		{
			Table.Records[0] = P;
		}
		else
		{
			for (i = 0; i < Table.length; i++)
			{
				if (P.Freq > Table.Records[i].Freq)
				{
					; //next
				}
				else
				{
					if (P.Freq != Table.Records[i].Freq)
					{
						for (j = Table.length; j > i; j--)
						{
							Table.Records[j] = Table.Records[j-1];
						}
						Table.Records[i] = P;
						Table.length++;
						break;
					} else
					{
						Table.Records[i] = P;
						break;
					}
				}

			}
		}
	}
	return Table;
}

AccTable AccelarationTable;
           

double w[Ns*2];

// IIR filter function //
extern void iir(short*, int, double *, int, double *);

DATA v[NX];
//#pragma DATA_SECTION (samples,".samples")
//DATA samples[NX];

#pragma DATA_SECTION (amplitude,".amplitude")
DATA amplitude[NX];

#pragma DATA_SECTION (x,".input")
DATA x[2*NX];

#pragma DATA_SECTION (hw,".windows")
double hw[NX];

//DATA r[NX];

DATA m;

DATA r_val;
DATA r_idx;

DATA r_ove;


//Коэффициенты фильтра 12 кГц
DATA h[NH] = {

        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
       -1,
        0,
        1,
       -3,
        0,
        7,
      -10,
       -4,
       29,
      -25,
      -34,
      103,
      -51,
     -177,
      358,
      -50,
     -836,
     1394,
       -6,
    -3982,
     8742,
    21860,
     8742,
    -3982,
       -6,
     1394,
     -836,
      -50,
      358,
     -177,
      -51,
      103,
      -34,
      -25,
       29,
       -4,
      -10,
        7,
        0,
       -3,
        1,
        0,
       -1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
};


DATA db[NH+2];
DATA *dbptr=&db[0];
Uint16 regim = 0;
Uint32 reg_acseleration = 0;
Uint32 reg_frequency = 640;
Uint32 reg_velosity = 0;
Uint32 reg_displacement = 0;
Uint32 acseleration = 0;
Uint32 velosity = 0;
Uint32 displacement = 0;
Int8  liht = 15;
Int8  liht2 = 0;
Uint32 code = 0;
Uint32 shifft = 0x314000;

double KUS_ACC = 1.2;
double KUS_VEL = 1.2;
double KUS_DIS = 1.2;
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

Uint32 res_rms_000;
Uint32 res_rms_111;

Uint32 res_rms_222=0;

Uint32 res_acs;
Uint32 res_vel;
Uint32 res_dis;

Uint32 kof_acs;
Uint32 kof_vel;
Uint32 kof_dis;

Uint16 Coeff_A = 9.122723749; //9.122 723749
Uint16 Coeff_V = 50;
Uint16 Coeff_S = 50;

Uint8 Coeff_A_0 = 1.0;
Uint8 Coeff_V_0 = 0;				    	
Uint8 Coeff_S_0 = 0;				    	
    
Uint8 Coeff_A_00 = 0;			    	
Uint8 Coeff_V_00 = 0;			    	    	    
Uint8 Coeff_S_00 = 0;

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

Uint8 Skan_A = 0;
Uint8 Skan_V = 0;
Uint8 Skan_S = 0;

Uint8 Skan_A_T = 0;
Uint8 Skan_V_T = 0;
Uint8 Skan_S_T = 0;

Uint8 Skan_A_T2 = 0;
Uint8 Skan_V_T2 = 0;
Uint8 Skan_S_T2 = 0;

int MenuCursor;
Uint8 MenuLevel;

Uint8 TTT = 0;

int debugMode = 1;

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

typedef struct Chnl_Data_t
{
	double Avg;
    double Rms;
} ChnlData;


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

ChnlData accelerometr_new(unsigned short X1, double AVG)
{
		ChnlData Result;
		double sam_rms_D,res_rms_D;
		unsigned long i=0;
		while(i < X1)
		{      												        	             
        	v[i] = RcvL1[i];
 			i++; 	 			 					
		}



		//----HP 2Hz----//
	    /*for(i=0; i<Ns*2;i++) w[i]=0.0;
	    iir(v,X1,HP2F02FS6000P0,Ns,w);*/

		//----LP 1kHz----//	     	
		for(i=0;i<NH+2;i++) db[i]=0;
		fir(v,h,v,dbptr,X1,NH);

		for (i=0; i < X1; i++)
		{
			AVG+=v[i];
		}
		AVG=(double)AVG/X1;

      	res_rms_D = 0.0;
		for(i=0; i<X1; i++) 				
		{      					        	           	         	        		        	                       	         
        	sam_rms_D = (double)v[i] - AVG;
        	res_rms_D = res_rms_D + (sam_rms_D * sam_rms_D);      	          	       	          	     	     						 	
		}
		
      	res_rms_D = (double)res_rms_D/X1;	    			      	
      	res_rms_D = (double)sqrt(res_rms_D);   
      	      	           	      	     
      	res_rms_D = res_rms_D + 0.5 ;
      	Result.Rms = res_rms_D;
      	Result.Avg = AVG;
      	return Result;
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

	Uint16 x_coord;  	
	Uint16 y_coord;  	


void enable_sar_int(void)
{
    SAR_CLKCTRL = 0x00010;           
	SAR_PINCTRL = 0x03100;      
	SAR_GPOCTRL = 0x001C0;	  
}


void waitForTouchRelese(void)
{	
   	while((x_coord != 0)&&(y_coord != 0))
	{
	x_coord = GetX();	  			  			  			 	  			  			  			  					  				  				  										  				  				 	  					  					 										
	y_coord = GetY();		
	}	  
}          

void LCD_Freq(Uint32 x, Uint16 FontColor)
{    	 	
	 Uint32 er,ir;

	 char i;
	 er = x;
     for (i=5; i > 0; i--)
     {

       ir=er % 10;
       er=er / 10;
       printNumI(ir,i*40 - 38 + 57 ,70,Num40x53,FontColor,WHITE_ADV);
     }
     fillRoundRect(159+57,120,167+57,128,FontColor);

}

void LCD_Acsel(unsigned int x, Uint16 FontColor)
{    	 	
	 unsigned int er,ir,i;
     er = x; 		      		      		      		      
     for (i=4; i > 0; i--)
     {

       ir=er % 10;
       er=er / 10;
       printNumI(ir,i*40+2 + 57,145,Num40x53,FontColor,WHITE_ADV);
     }
     fillRoundRect(159+57,200-5,167+57,208-5,FontColor);
}

void LCD_velosity(unsigned int x)	
{    	 	
	 unsigned int er,ir;	 		 	 				      		    
     er = x; 		      		      		      		      
     ir=er % 10;      	
     er=er / 10;    		
     printNumI( ir,129,150,Num40x53,WHITE,BLUE_B);
     ir=er % 10;      	
     er=er / 10;    		
     printNumI( ir,80,150,Num40x53,WHITE,BLUE_B);
     ir=er % 10;      	
     er=er / 10;    		
     printNumI( ir,40,150,Num40x53,WHITE,BLUE_B);
     ir=er % 10;      	
     er=er / 10;    		
     printNumI( ir,0,150,Num40x53,WHITE,BLUE_B);
     fillRoundRect(120,194,128,202,WHITE);
}					

void LCD_displacement(unsigned int x)	
{    	 	
	 unsigned int er,ir;	 		 	 				      		    
     er = x; 		      		      		      		      
     ir=er % 10;      	
     er=er / 10;    		
     printNumI( ir,120,150,Num40x53,WHITE,BLUE_B);
     ir=er % 10;      	
     er=er / 10;    		
     printNumI( ir,80,150,Num40x53,WHITE,BLUE_B);
     ir=er % 10;      	
     er=er / 10;    		
     printNumI( ir,40,150,Num40x53,WHITE,BLUE_B);
     ir=er % 10;      	
     er=er / 10;    		
     printNumI( ir,0,150,Num40x53,WHITE,BLUE_B);
}					

void LCD_Code(unsigned int x)	
{    	 	
	 unsigned int er,ir;	 		 	 				      		    
     er = x; 		      		      		      		      
     ir=er % 10;      	
     er=er / 10;    		
     printNumI( ir,200,100,Num40x53,WHITE,BLUE_B);
     ir=er % 10;      	
     er=er / 10;    		
     printNumI( ir,160,100,Num40x53,WHITE,BLUE_B);
     ir=er % 10;      	
     er=er / 10;    		
     printNumI( ir,120,100,Num40x53,WHITE,BLUE_B);
     ir=er % 10;      	
     er=er / 10;    		
     printNumI( ir,80,100,Num40x53,WHITE,BLUE_B);
}
	
/* ------------------------------------------------------------------------ *
 *  					      Save_All_Coeff                                *
 * ------------------------------------------------------------------------ */

void SaveLifeTime()
{
	int i;
	Uint8 Id=0,FreqId;
	double SetDisp;
	Point X;
	nand_eraseBlock(1023);
	src[0] = liht;
	src[1] = Coeff_A;
	src[2] = Coeff_A >> 8;
	src[3] = Coeff_V;
	src[4] = Coeff_V >> 8;
	src[5] = Coeff_S;
	src[6] = Coeff_S >> 8;
	    /////////////////////////
	src[7] = Coeff_A_0;
	src[8] = Coeff_V_0;
	src[9] = Coeff_S_0;
	src[10] = Coeff_A_00;
	src[11] = Coeff_V_00;
	src[12] = Coeff_S_00;
	nand_writePage(0x0007FFFF00, src, 255);
		//Старая таблица коээфициентов
    src[0] = AccelarationTable.length;
	for (i = 0; i< 32; i++)
	    {
	    	src[1+4*i] = AccelarationTable.Records[i].Freq;
	    	src[2+4*i] = AccelarationTable.Records[i].Freq >> 8;
	    	src[3+4*i] = AccelarationTable.Records[i].Kus;
	    	src[4+4*i] = AccelarationTable.Records[i].Kus >> 8;
	    }
	src[200] = LaserStartFreq;
	src[201] = LaserStartFreq >> 8;

	AmpTable[5] = AmpTable[4];

	for (i=0; i<6; i++)
	{
	    	src[202+i] = AmpTable[i];
	}

	src[222] = debugMode;

	src[223] = MinuntsOnWork;
	src[224] = HoursOnWork >> 8;
	src[225] = HoursOnWork;

	src[230] = CalibrDate[0];
	src[231] = CalibrDate[1];
	src[232] = CalibrDate[2];

    nand_writePage(0x0007FFFE00, src, 255);
    printf("LifeTime is %i h %i m\n", HoursOnWork, MinuntsOnWork);
}

void LoadLifeTime()
{
	nand_readPage(0x0007FFFE00, dst, 255);
	MinuntsOnWork = dst[223];
   	HoursOnWork = (dst[224] << 8) |  dst[225];
	printf("LifeTime is %i h %i m\n", HoursOnWork, MinuntsOnWork);
}


void Save_All_Coeff(void)
{
	int i;
	Uint8 Id=0,FreqId;
	double SetDisp;
	Point X;
	nand_eraseBlock(1023);
    src[0] = liht;
	src[1] = Coeff_A;
    src[2] = Coeff_A >> 8;
    src[3] = Coeff_V;
    src[4] = Coeff_V >> 8;
    src[5] = Coeff_S;
    src[6] = Coeff_S >> 8;
    /////////////////////////
    src[7] = Coeff_A_0;			    	
    src[8] = Coeff_V_0;				    	
    src[9] = Coeff_S_0;
    src[10] = Coeff_A_00;			    	
    src[11] = Coeff_V_00;			    	    	    
    src[12] = Coeff_S_00;
	nand_writePage(0x0007FFFF00, src, 255);
	//Старая таблица коээфициентов

	X.Freq = reg_frequency/10;
	X.Kus = Coeff_A;
	AccelarationTable = AddRecToINterpolateTable(AccelarationTable,X);
	src[0] = AccelarationTable.length;
	printf("Table length = %i \n", AccelarationTable.length);
    /////////////////////////
    for (i = 0; i< 32; i++)
    {
    	src[1+4*i] = AccelarationTable.Records[i].Freq;
    	src[2+4*i] = AccelarationTable.Records[i].Freq >> 8;
    	src[3+4*i] = AccelarationTable.Records[i].Kus;
    	src[4+4*i] = AccelarationTable.Records[i].Kus >> 8;
    }
    src[200] = LaserStartFreq;
    src[201] = LaserStartFreq >> 8;

    AmpTable[5] = AmpTable[4];

    for (i=0; i<6; i++)
    {
    	src[202+i] = AmpTable[i];
    }


    src[222] = debugMode;

    src[223] = MinuntsOnWork;
    src[224] = HoursOnWork >> 8;
    src[225] = HoursOnWork;

    src[230] = 10*((RTC_DAY>>4)&0x000F) + (RTC_DAY&0x000F);
    src[231] = 10*((RTC_MONTH>>4)&0x000F) + (RTC_MONTH&0x000F);
    src[232] = 10*((RTC_YEAR>>4)&0x000F) + (RTC_YEAR&0x000F);


	printf("calibr date %i.%i.%i\n",src[230],src[231],src[232]);

    if (nand_writePage(0x0007FFFE00, src, 255) == 0) printf ("NAND OK\n");
    else printf ("NAND FAIL\n");

	printf("Table\n");
	for (i = 0; i < AccelarationTable.length; i++)
		{
			printf("F=%i A=%i \n",AccelarationTable.Records[i].Freq,AccelarationTable.Records[i].Kus);
		}
}

/* ------------------------------------------------------------------------ *
 *  					      Read_All_Coeff                                *
 * ------------------------------------------------------------------------ */
void Read_All_Coeff(void)
{
	int i;
	nand_readPage (0x0007FFFF00, dst, 255);

    liht = dst[0];
    Coeff_A = dst[1];
    Coeff_A = Coeff_A | dst[2]<<8;
    KUS_ACC = (double)Coeff_A/1000;		
    
    Coeff_V = dst[3];
    Coeff_V = Coeff_V | dst[4]<<8;
    KUS_VEL = (double)Coeff_V/1000;		
    
    Coeff_S = dst[5];
    Coeff_S = Coeff_S | dst[6]<<8;
    KUS_DIS = (double)Coeff_S/1000;

    Coeff_A_0 = dst[7];			    	
    Coeff_V_0 = dst[8];				    	
    Coeff_S_0 = dst[9];				    	
    
    Coeff_A_00 = dst[10];			    	
    Coeff_V_00 = dst[11];			    	    	    
    Coeff_S_00 = dst[12];

    //Читаем калибровочную таблицу
    nand_readPage(0x0007FFFE00, dst, 255);

    AccelarationTable.length = dst[0];

    if ((AccelarationTable.length < 2) || (AccelarationTable.length > 32))  AccelarationTable.length=0;
    printf("Table length = %i \n", AccelarationTable.length);
        /////////////////////////
        for (i = 0; i < 32; i++)
        {
        	//AccelarationTable.Records[i].Freq = dst[1+i*2+4*i];
        	AccelarationTable.Records[i].Freq = dst[1+4*i] | dst[2+4*i] << 8;
        	AccelarationTable.Records[i].Kus = dst[3+4*i] | dst[4+4*i] << 8;
        	printf("F = %i, A = %i \n",AccelarationTable.Records[i].Freq,AccelarationTable.Records[i].Kus);
        }
    LaserStartFreq = dst[200] | dst[201] << 8;
    if (LaserStartFreq > 300) LaserStartFreq = 0;

    for (i = 0; i<6; i++)
        {
        	if ((dst[202+i] > 0) && (dst[202+i] < 255)) AmpTable[i] = dst[202+i]; else AmpTable[i]=100;
        	printf("Mult = %i\n",AmpTable[i]);
        }
    debugMode = dst[222];

    CalibrDate[0] = dst[230];
    CalibrDate[1] = dst[231];
    CalibrDate[2] = dst[232];

    printf("calibr date %i.%i.%i\n",dst[230],dst[231],dst[232]);
}

void ChangeFreq(int x)
{
	int incr = 0;
	if (x>0) incr = 1;
			else incr = -1;
	if(reg_frequency < 100)
			 {
	        		   reg_frequency=reg_frequency+incr;
	        		 }
	        		  else
	        		 	   {
	        		        		    if (reg_frequency < 1000)
	        		        		     {
	        		        		      reg_frequency=reg_frequency+incr*10;
	        		        		     }
	        		        		      else
	        		        		     {
	        		        		       if (reg_frequency < 10000)
	        		        		    	  reg_frequency=reg_frequency+incr*100;
	        		        		       else reg_frequency=reg_frequency+incr*1000;
	        		        		     }
	        		        		    }

	if (reg_frequency > MAX_FREQ) reg_frequency = MAX_FREQ;

	if (code!=9999) LCD_Freq(reg_frequency,BLACK);
}

void PrintStandMenu(int CursorPos)
{
	MenuCursor = CursorPos;
	if (MenuLevel!=2)
	{
		LCD_Clear_1(BLUE_B);
		print("  Режим вибростенда ",0,21,FontRus16x28,WHITE,BLUE_T);
	}
	switch (CursorPos)
	{
	case 0:

	  print( " Ускорение        ",16,60,FontRus16x28,BLACK,YELLOW_K);
	  print( " Скорость         ",16,90,FontRus16x28,WHITE,BLUE_T);
	  print( " Перемещение      ",16,120,FontRus16x28,WHITE,BLUE_T);
	  regim=111;
	  break;

	case 1:
	  print( " Ускорение        ",16,60,FontRus16x28,WHITE,BLUE_T);
	  print( " Скорость         ",16,90,FontRus16x28,BLACK,YELLOW_K);
	  print( " Перемещение      ",16,120,FontRus16x28,WHITE,BLUE_T);
	  regim=112;
	  break;

	case 2:
	  print( " Ускорение        ",16,60,FontRus16x28,WHITE,BLUE_T);
	  print( " Скорость         ",16,90,FontRus16x28,WHITE,BLUE_T);
	  print( " Перемещение      ",16,120,FontRus16x28,BLACK,YELLOW_K);
	  regim=113;
	  break;
	}
  MenuLevel = 2;
}

void PrintTermomentr()
{
	LCD_Clear_1(BLUE_B);
	print("      Термометр     ",0,21,FontRus16x28,WHITE,BLUE_T);

	print(" Внутри корп: ",0,120-40,FontRus16x28,BLACK,BLUE_B);
	print(" Усилитель:   ",0,120,FontRus16x28,BLACK,BLUE_B);
	print(" Блок питания:",0,120+40,FontRus16x28,BLACK,BLUE_B);

	print("0",319-16-8,121-40,Num8x8,WHITE,BLUE_B);
	print("С",319-16,120-40,FontRus16x28,WHITE,BLUE_B);

	print("0",319-16-8,121,Num8x8,WHITE,BLUE_B);
	print("С",319-16,120,FontRus16x28,WHITE,BLUE_B);

	print("0",319-16-8,121+40,Num8x8,WHITE,BLUE_B);
	print("С",319-16,120+40,FontRus16x28,WHITE,BLUE_B);

	regim=131;
}

void PrintClock(Uint8 Clock)
{
	int CurNumb = Clock % 10;
	switch (CurNumb)
	{
	 case 0: print("...  ",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 1: print(". .. ",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 2: print(". . .",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 3: print(" . ..",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 4: print("  ...",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 5: print(" . ..",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 6: print(". .. ",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 7: print(".. . ",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 8: print("...  ",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 9: print("...  ",70,0,FontRus8x15,WHITE,BLUE_T); break;
	}
}

void PrintModeMenu(int CursorPos)
{
	MenuCursor = CursorPos;
	if (MenuLevel!=1)
	{
	LCD_Clear_1(BLUE_B);
	print("   Режим работы    ",0,21,FontRus16x28,WHITE,BLUE_T);
	}
	switch (CursorPos)
	{
	case 0:
		print( " Вибростенд       ",16,60,FontRus16x28,BLACK,YELLOW_K);
		print( " Термометр        ",16,90,FontRus16x28,WHITE,BLUE_T);
		//print( " Термометр        ",16,120,FontRus16x28,WHITE,BLUE_T);
		regim=11;
	    break;
	case 1:
		print( " Вибростенд       ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Термометр        ",16,90,FontRus16x28,BLACK,YELLOW_K);
		//print( " Термометр        ",16,120,FontRus16x28,WHITE,BLUE_T);
		regim=13;
	    break;
	    /*
	case 2:
		print( " Вибростенд       ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Виброметр        ",16,90,FontRus16x28,WHITE,BLUE_T);
		print( " Термометр        ",16,120,FontRus16x28,BLACK,YELLOW_K);
		regim=13;
		break;*/
	}
	MenuLevel = 1;
}

void PrintMainMenu(int CursorPos)
{
	MenuCursor = CursorPos;
	if (MenuLevel!=0)
	{
		LCD_Clear_1(BLUE_B);
		print("    Главное меню   ",0,21,FontRus16x28,WHITE,BLUE_T);
	}
	switch (CursorPos)
	{
	case 0:
		print( " Режим            ",16,60,FontRus16x28,BLACK,YELLOW_K);
	    print( " Настройки        ",16,90,FontRus16x28,WHITE,BLUE_T);
	    print( " Калибровка       ",16,120,FontRus16x28,WHITE,BLUE_T);
	    regim=1;
	    break;
	case 1:
		print( " Режим            ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Настройки        ",16,90,FontRus16x28,BLACK,YELLOW_K);
		print( " Калибровка       ",16,120,FontRus16x28,WHITE,BLUE_T);
		regim=2;
		break;
	case 2:
		print( " Режим            ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Настройки        ",16,90,FontRus16x28,WHITE,BLUE_T);
		print( " Калибровка       ",16,120,FontRus16x28,BLACK,YELLOW_K);
		regim=3;
		break;
	}
	MenuLevel = 0;
}

void PrintSettingsMenu(int CursorPos)
{
	MenuCursor = CursorPos;
	if (MenuLevel!=3)
	{
		LCD_Clear_1(BLUE_B);
		print("    Меню настроек   ",0,21,FontRus16x28,WHITE,BLUE_T);
	}
	switch (CursorPos)
	{
	case 0:
	    print( " Дата и Время     ",16,60,FontRus16x28,BLACK,YELLOW_K);
	    print( " Подсветка        ",16,90,FontRus16x28,WHITE,BLUE_T);
	    print( " Аккумулятор      ",16,120,FontRus16x28,WHITE,BLUE_T);
		print( " Статистика       ",16,150,FontRus16x28,WHITE,BLUE_T);
	    regim=21;
	    break;
	case 1:
		print( " Дата и Время     ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Подсветка        ",16,90,FontRus16x28,BLACK,YELLOW_K);
		print( " Аккумулятор      ",16,120,FontRus16x28,WHITE,BLUE_T);
		print( " Статистика       ",16,150,FontRus16x28,WHITE,BLUE_T);
		regim=22;
		break;
	case 2:
		print( " Дата и Время     ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Подсветка        ",16,90,FontRus16x28,WHITE,BLUE_T);
		print( " Аккумулятор      ",16,120,FontRus16x28,BLACK,YELLOW_K);
		print( " Статистика       ",16,150,FontRus16x28,WHITE,BLUE_T);
		regim=23;
		break;
	case 3:
		print( " Дата и Время     ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Подсветка        ",16,90,FontRus16x28,WHITE,BLUE_T);
		print( " Аккумулятор      ",16,120,FontRus16x28,WHITE,BLUE_T);
		print( " Статистика       ",16,150,FontRus16x28,BLACK,YELLOW_K);
		regim=24;
		break;
	}
	MenuLevel = 3;
}


void PrintCalibrMenu()
{
	LCD_Clear_1(BLUE_B);
	print("     Введите код    ",0,21,FontRus16x28,WHITE,BLUE_T);
    printNumI( 0,80,100,Num40x53,BLACK,BLUE_B);
	printNumI( 0,120,100,Num40x53,BLACK,BLUE_B);
	printNumI( 0,160,100,Num40x53,BLACK,BLUE_B);
	printNumI( 0,200,100,Num40x53,BLACK,BLUE_B);
	code=0;
	regim=31;
	MenuLevel = 4;
}

void PrintDateTimeMenu()
{
	LCD_Clear_1(BLUE_B);
    print( "    Дата и время    ",0,21,FontRus16x28,WHITE,BLUE_T);
   	print( "        .  .        ",0,100,FontRus16x28,BLACK,BLUE_B);
    print( "        :  :        ",0,140,FontRus16x28,BLACK,BLUE_B);
    KurRTC = 1;
    LoadRTCKur();
    LoadRTCinBuf();
    printNumIRTC();
   	regim=211;
   	MenuLevel = 5;
}

void PrintScreenMenu()
{
	LCD_Clear_1(BLUE_B);
	print("      Подсветка     ",0,21,FontRus16x28,WHITE,BLUE_T);
	liht2 = 99-(liht*3.2);
	if(liht2 < 10)
	{
	   print("-",120,100,Num40x53,BLACK,BLUE_B);
	   printNumI( liht2,160,100,Num40x53,BLACK,BLUE_B);
	}
	else
		if (liht2 < 100)
	   {
	   		printNumI( liht2,120,100,Num40x53,BLACK,BLUE_B);
	   }

	print("/",200,100,Num40x53,BLACK,BLUE_B);
	regim=221;
	MenuLevel = 6;
}

void PrintBataryMenu()
{
	int i;
	LCD_Clear_1(BLUE_B);
	print("     Аккумулятор    ",0,21,FontRus16x28,WHITE,BLUE_T);
	print("ЗАРЯД:",10,60,FontRus8x15,BLACK,BLUE_B);
	print("ТОК:",10,90,FontRus8x15,BLACK,BLUE_B);
	print("НАПРЯЖЕНИЕ:",10,120,FontRus8x15,BLACK,BLUE_B);
	print("ТЕМПЕРАТУРА:",10,150,FontRus8x15,BLACK,BLUE_B);
	print("ОСТАЛОСЬ:",10,180,FontRus8x15,BLACK,BLUE_B);
	print("СТАТУС:",10,210,FontRus8x15,BLACK,BLUE_B);
	print("%",190,50,FontRus16x28,WHITE,BLUE_B);
	print("мА",190,80,FontRus16x28,WHITE,BLUE_B);
	print("В",190,110,FontRus16x28,WHITE,BLUE_B);
	print("0",182,141,Num8x8,WHITE,BLUE_B);
	print("С",190,140,FontRus16x28,WHITE,BLUE_B);

	/*
	for(i=0;i<10;i++)
	{
		drawBitmap(250,62+i,40,1,bat_nip);
	}
	for(i=0;i<8;i++)
	{
		drawBitmap(230,72+i,80,1,bat_up);
	}
	for(i=0;i<120;i++)
	{
		drawBitmap(230,80+i,80,1,bat_fon);
	}
	for(i=0;i<8;i++)
	{
		drawBitmap(230,200+i,80,1,bat_up);
	}
	*/
	regim=231;
	MenuLevel = 7;
}


void PrintStatistic()
{
	LCD_Clear_1(BLUE_B);
	print("     Статистика       ",0,21,FontRus16x28,WHITE,BLUE_T);
	print("Наработка:",10,60,FontRus16x28,WHITE,BLUE_B);
	printNumI(HoursOnWork,40,100,FontRus16x28,WHITE,BLUE_B);
	print("час.",100,100,FontRus16x28,WHITE,BLUE_B);
	printNumI(MinuntsOnWork,160,100,FontRus16x28,WHITE,BLUE_B);
	print("мин.",200,100,FontRus16x28,WHITE,BLUE_B);
	print("Дата калибровки:",10,140,FontRus16x28,WHITE,BLUE_B);
	printNumI(CalibrDate[0],20,180,FontRus16x28,WHITE,BLUE_B);
	print(".",60,180,FontRus16x28,WHITE,BLUE_B);
	printNumI(CalibrDate[1],70,180,FontRus16x28,WHITE,BLUE_B);
	print(".",110,180,FontRus16x28,WHITE,BLUE_B);
	printNumI(CalibrDate[2],120,180,FontRus16x28,WHITE,BLUE_B);
	regim = 241;
	//print(" Дата пос ",0,140,FontRus16x28,WHITE,BLUE_B);
	//print(ADRUINO_Data)
	/*TAS5424_ON();
	Temp_A=1;
	EVM5515_GPIO_setOutput(21,1);
	drawBitmap(140,2,16,16,las1);
	regim=241;
	MenuLevel = 8;*/
}


void PrintAccMenu(int CursorPos)
{
	if ((regim !=1111) && (regim != 1112))
	{
		LCD_Clear_1(GRAY0);
		print("Вибростенд/Ускорение",0,20,FontRus16x28,WHITE,BLUE_T);
		print(" Част.",10,80,FontRus8x15,BLACK,GRAY0);
		print("Воспр.",10,95,FontRus8x15,BLACK,GRAY0);
		print("Гц",270,84,FontRus16x28,BLACK,GRAY0);
		print("Ускор.",10,159,FontRus8x15,BLACK,GRAY0);
		print("  СКЗ",10,174,FontRus8x15,BLACK,GRAY0);
		print("м/",270,164,FontRus16x28,BLACK,GRAY0);
		print("с",292,164,FontRus16x28,BLACK,GRAY0);
		print("2",305,164,FontRus8x15,BLACK, GRAY0);
		fillRoundRect(57,143-5,264,210-5,YELLOW_K);
		fillRoundRect(57,64,264,130,YELLOW_K);
		fillRoundRect(58,65,263,129,WHITE_ADV);
		fillRoundRect(58,144-5,263,209-5,WHITE_ADV);
	}
	if (CursorPos == 0)
	{
	   LCD_Freq(reg_frequency,BLUE);
	   LCD_Acsel(reg_acseleration,BLACK);
	   regim=1111;
	}
	else
	{
		LCD_Freq(reg_frequency,BLACK);
		LCD_Acsel(reg_acseleration,BLUE);
		regim=1112;
	}

	MenuLevel = 9;
}


void PrintControlHelp(char * Msg)
{
	fillRect(0,214,320,240,BLUE_T);
	drawBitmap8bit(0,214,26,26,ArrowUp);
	drawBitmap8bit(26,214,26,26,ArrowDown);
	if (code != Calibr_CODE)
	{
	print(" Изм.амплитуды",52,222,FontRus8x15,WHITE,BLUE_T);
	drawBitmap8bit(170,214,26,26,ArrowLeft);
	drawBitmap8bit(196,214,26,26,ArrowRight);
	print(" Изм.частоты",222,222,FontRus8x15,WHITE,BLUE_T);
	}
	else
	{
		print(" Изм.коэфф.усил.",52,222,FontRus8x15,WHITE,BLUE_T);
		drawBitmap8bit(196,214,26,26,ArrowRight);
		print(" Сохранить",222,222,FontRus8x15,WHITE,BLUE_T);
	}
}

void PrintAboutScreen()
{
    LCD_Clear_1(BLUE_T);
	fillRoundRect(10,31,309,229,BLUE_T);
	print("    ВИБРОСТЕНД   ",16,50+20,FontRus16x28,WHITE,BLUE_T);
	if (LaserStartFreq == 0)
		print("    ВЗВ2  ",24,90+20,FontRus16x28,WHITE,BLUE_T);
	else
		print("   ВЗВ2  ",24,90+20,FontRus16x28,WHITE,BLUE_T);
	print("Версия ПО 20.0108",90,160,FontRus8x15,WHITE,BLUE_T);
	print("ООО НПФ ВИБРОН 2020(с)",80,210,FontRus8x15,WHITE,BLUE_T);

	//drawBitmap8bit(80,120,115,80,Vibron_logo);
	regim = 0;
	MenuLevel = 100;
}

void PrintVelMenu()
{
	LCD_Clear_1(BLUE_B);
	print("     Вибростенд     ",0,21,FontRus16x28,WHITE,BLUE_T);
	LCD_Freq(reg_frequency,BLACK);
	LCD_Rectangle(3,130,165,136,YELLOW_K);
	LCD_velosity(reg_velosity);
	LCD_Rectangle(3,220,165,240,BLUE_B);
	print(" Частота",176,69,FontRus16x28,WHITE,BLUE_B);
	print("      Гц",176,97,FontRus16x28,WHITE,BLUE_B);
	print(" Скорость",176,149,FontRus16x28,WHITE,BLUE_B);
	print(" СКЗ мм/с",176,177,FontRus16x28,WHITE,BLUE_B);
	regim=1121;
	MenuLevel = 10;
}


void PrintDisMenu()
{
	LCD_Clear_1(BLUE_B);
	print("     Вибростенд     ",0,21,FontRus16x28,WHITE,BLUE_T);
	LCD_Freq(reg_frequency,BLACK);
	LCD_Rectangle(3,130,165,136,YELLOW_K);
	LCD_displacement(reg_displacement);
	LCD_Rectangle(3,220,165,226,BLUE_B);
	print(" Частота",176,69,FontRus16x28,WHITE,BLUE_B);
	print("      Гц",176,97,FontRus16x28,WHITE,BLUE_B);
	print(" Перемещ.",176,149,FontRus16x28,WHITE,BLUE_B);
	print(" разм мкм",176,177,FontRus16x28,WHITE,BLUE_B);
	regim=1131;
	MenuLevel = 11;
}


void FreqInput(Uint8 Key)
{
	switch (Key)
	{
		case one: 		reg_frequency=(reg_frequency*10)+1; break;
		case two: 		reg_frequency=(reg_frequency*10)+2; break;
		case three: 	reg_frequency=(reg_frequency*10)+3; break;
		case four:		reg_frequency=(reg_frequency*10)+4; break;
		case five:		reg_frequency=(reg_frequency*10)+5; break;
		case six:		reg_frequency=(reg_frequency*10)+6; break;
		case seven:		reg_frequency=(reg_frequency*10)+7; break;
		case eight:		reg_frequency=(reg_frequency*10)+8; break;
		case nine:		reg_frequency=(reg_frequency*10)+9; break;
		case zero:		reg_frequency=(reg_frequency*10)+0; break;
	}
	reg_frequency = reg_frequency % 100000;
	LCD_Freq(reg_frequency,BLUE);
}

Uint32 AmpInput(Uint8 Key, Uint8 Mode, Uint32 reg)
{
	switch (Key)
	{
		case one: 		reg=(reg*10)+1; break;
		case two: 		reg=(reg*10)+2; break;
		case three: 	reg=(reg*10)+3; break;
		case four:		reg=(reg*10)+4; break;
		case five:		reg=(reg*10)+5; break;
		case six:		reg=(reg*10)+6; break;
		case seven:		reg=(reg*10)+7;	break;
		case eight:		reg=(reg*10)+8;	break;
		case nine:		reg=(reg*10)+9;	break;
		case zero:		reg=(reg*10)+0;	break;
	}
	reg = reg % 10000;
	switch (Mode)
	{
		case MOD_Acc: 	LCD_Acsel(reg,BLUE); break;
		case MOD_Vel: 	LCD_velosity(reg); break;
		case MOD_Dis: 	LCD_displacement(reg); break;
	}
    return reg;
}

interrupt void SAR_Isr(void) { }

interrupt void TIMER_isr(void) {}

interrupt void INT1_Isr(void) {}


//			        Прерывание от клаивиатуры								*
//  ----------------------------------------------------------------------- *
interrupt void INT0_Isr(void)
{		

	Uint16 i,temp, Key,Id;
	double SetDisp;
	int FreqId;

	EnergySaveClock = 0;
	SYS_GlobalIntDisable();
    cmd[0] = 0x04;                  
    USBSTK5515_I2C_write( TCA8418_I2C_ADDR, cmd, 1 );                                                                                                                                                                                                                                                                                    	                                            
   	USBSTK5515_I2C_read( TCA8418_I2C_ADDR, cmd, 1 );	// чтение кода клавиатуры
   	//printf("Key = %i",cmd[0]);
   	Key = cmd[0];
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
   	} else Key = cmd[0];

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
   		   	   	   ChangeFreq(-1);
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
   						ChangeFreq(1);
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
   		   	   	spi_Kus(0);
				TAS5424_OFF();    
				LaserOFF();
        		Temp_A=0;        		        		        		    	
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
    else
    {
    	FrameSize = 250;
    }


  	if( Dis_Pro_max < Dis_Pro)
  	{
  		Dis_Pro_max = Dis_Pro;
  	}  	  	    	
  	if ( Dis_Pro_min > Dis_Pro)
  	{
  		Dis_Pro_min = Dis_Pro; 	   	
  	}  	  	
  	if( Temp_I >= FrameSize)// 200)
  	{  		       	    	    	    	    	
    	Dis_Pro_Delta = Dis_Pro_max - Dis_Pro_min;    	
    	RES_DIS = (double)Dis_Pro_Delta / 10.0;
    	Temp_I = 0;
    	Dis_Pro_min = 50000; 	
    	Dis_Pro_max = 0;    	    
    	if((regim == 11132)||(regim == 11142))
		{			    	    	    	

			RES_ACC = (double)RES_DIS * reg_frequency * reg_frequency * 13.9577283992777  / 1000.0 / 10000.0; // V = 2*P*F*  S  *2*P*f/2*1.41*1000 
    		Reg_ACC_D = (double)reg_acseleration;		
			KUS_1 = (double)Reg_ACC_D/RES_ACC;					
			KUS_ACC_DR = KUS_ACC_DR * KUS_1;				  				
			if(KUS_ACC_DR >= 20000)
      		{
      			KUS_ACC_DR = 20000;
      		}        	     
      		spi_Kus(KUS_ACC_DR);         	    	
		}

    	else if((regim == 11232)||(regim == 11242))
		{			    	    	    	
			
			RES_VEL = (double)RES_DIS * reg_frequency * 2.221441469 / 1000.0;   	  	 		// V = S*2*P*f/2*1.41*1000								 						 								  				 								  				 								  			
    		Reg_VEL_D = (double)reg_velosity;
			KUS_2 = (double)Reg_VEL_D/RES_VEL;					
			KUS_VEL_DR = KUS_VEL_DR * KUS_2;		  						  						  	
			if(KUS_VEL_DR >= 20000)
      		{
      			KUS_VEL_DR = 20000;
      		}        	     
      		spi_Kus(KUS_VEL_DR);    
		}
    		    	
    	else if((regim == 11332)||(regim == 11342))
		{			    	    	    	    	    		     		    	       	    	    	    	    
    		Reg_DIS_D = (double)reg_displacement;    	    
			KUS_3 = (double)Reg_DIS_D/RES_DIS;					
			KUS_DIS_DR = KUS_DIS_DR * KUS_3;		  						  						  					
			if(KUS_DIS_DR >= 20000)
      		{
      			KUS_DIS_DR = 20000;
      		}        	           	      
      		spi_Kus(KUS_DIS_DR);
		}

  	}  	  	 
  	else
  	{
  		Temp_I++;		   	   	
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
//
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




void main(void)
 {
	SYS_GlobalIntDisable();
	Uint32 i,j;
	IsSleep = 0;
	EnergySaveTime = 30000;
	int BuffCount = 1;
	double CurrAVG = 0;
	int FrameSize;
	int PCF8574Test, LM73Adr1Test, LM73Adr2Test, LM73Adr3Test, KeyBoardTest, PowerAmplTest, BatRTest;
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

// ------------------------------------------------------------------------	*
//						  		PCF8574_INIT							    *                                                                          
// ------------------------------------------------------------------------ *
    for (i = 0; i < 10; i++)
    {
      cmd[0] = 0x0F;
      PCF8574Test = USBSTK5515_I2C_write( PCF8574_I2C_ADDR1, cmd, 1 );

      cmd[0] = 0x0f;
      PCF8574Test -= USBSTK5515_I2C_write( PCF8574_I2C_ADDR1, cmd, 1 );
   
   	  cmd[0] = 0x7F;
   	  PCF8574Test -= USBSTK5515_I2C_write( PCF8574_I2C_ADDR1, cmd, 1 );

   	  if (PCF8574Test == 0) break;
   	  waitusec(1000000);
    }

    LCD_Rectangle(20,110,40,130,WHITE);
// ------------------------------------------------------------------------	*
//						  		LM73_INIT	датчики температуры			    *
// ------------------------------------------------------------------------ *
	cmd[0] = 0x04;    
	cmd[1] = 0x68;		
	LM73Adr1Test = USBSTK5515_I2C_write( LM73_I2C_ADDR1, cmd, 2 );

    cmd[0] = 0x04;
	cmd[1] = 0x68;		
	LM73Adr2Test = USBSTK5515_I2C_write( LM73_I2C_ADDR2, cmd, 2 );

 	cmd[0] = 0x04;    
	cmd[1] = 0x68;		
	LM73Adr3Test = USBSTK5515_I2C_write( LM73_I2C_ADDR3, cmd, 2 );
	LCD_Rectangle(20,110,60,130,WHITE);
// ------------------------------------------------------------------------	*
//						  		TCA8418_INIT	клавиатура				    *
// ------------------------------------------------------------------------ *
    waitusec( 65000 );
    cmd[0] = 0x01;
    cmd[1] = 0x91; //0x81
    KeyBoardTest = USBSTK5515_I2C_write( TCA8418_I2C_ADDR, cmd, 2 );
    waitusec( 65000 );
    cmd[0] = 0x1D;
    cmd[1] = 0xFF;
    cmd[2] = 0xFF;
    cmd[3] = 0x03;
    KeyBoardTest -= USBSTK5515_I2C_write( TCA8418_I2C_ADDR, cmd, 4 );
    LCD_Rectangle(20,110,80,130,WHITE);

    //Усилитель мощности
	cmd[0] = 0x0C;
	cmd[1] = 0x90;
	PowerAmplTest = USBSTK5515_I2C_write( TAS5424_I2C_ADDR, cmd, 2 );

	LCD_Rectangle(20,110,100,130,WHITE);

	//Потенциометр для зарядки аккумулятора
 	cmd[0] = 0x1c;
    cmd[1] = 0x02;
    BatRTest = USBSTK5515_I2C_write( AD5272_I2C_ADDR, cmd, 2 );  	// iniChargBat
    Resistance = 400;     //0x3ff; //0x000; 400;
    cmd[1] = Resistance;
	cmd[0] = (((Resistance>>8)&(0x03))|0x04);
	BatRTest -= USBSTK5515_I2C_write( AD5272_I2C_ADDR, cmd, 2 );  	// writeChargBat


	LCD_Rectangle(20,110,140,130,WHITE);
    setDMA_address();//
    set_i2s0_slave();      
    //AIC3254_init();
   	//aic3204_loop_mono_in2(Rate48k);
    Aic3204_Setup(Rate48k);
	enable_i2s0();			
    enable_dma_int();  //
    /*
// ------------------------------------------------------------------------	*
//						  		DAC_INIT							        *                                                                          
// ------------------------------------------------------------------------ *
    // DAC ROUTING and Power Up 
    AIC3204_rset(  0, 0x01 );      // Select page 1
    AIC3204_rset( 14, 0x08 );      // LDAC AFIR routed to LOL
    AIC3204_rset( 15, 0x08 );      // RDAC AFIR routed to LOR
    AIC3204_rset(  0, 0x00 );      // Select page 0
    AIC3204_rset( 64, 0x02 );      // Left vol=right vol
    AIC3204_rset( 65, 0x00 );      // Left DAC gain to 0dB VOL; Right tracks Left
    AIC3204_rset( 63, 0xd4 );      // Power up left,right data paths and set channel
    AIC3204_rset(  0, 0x01 );      // Select page 1
    AIC3204_rset( 18, 0x00 );      // Unmute LOL , 0dB gain
    AIC3204_rset( 19, 0x00 );      // Unmute LOR , 0dB gain
    AIC3204_rset(  9, 0x0C );      // Power up LOL,LOR
    AIC3204_rset(  0, 0x00 );      // Select page 0
    EVM5515_wait( 500 );           // Wait
                                            
   	AIC3204_rset( 60, 0xf9 );      // Power up LOL,LOR
                 
	//BEEP LENGTH
	AIC3204_rset( 73, 0x00 ); //MSB
	AIC3204_rset( 74, 0x02 ); //MID
	AIC3204_rset( 75, 0x60 ); //LSB
	 
	//SINE
	AIC3204_rset( 76, 0x93 );  //MSB 
	AIC3204_rset( 77, 0xfb);   //LSB
	
	//CONSINE	
	AIC3204_rset( 78, 0x00);   //MSB
	AIC3204_rset( 79, 0x00 );  //LSB		
    
 	/////////////////////////////////////
	LCD_Rectangle(20,110,180,130,WHITE);
 	waitusec( 60000 ); 
 	LCD_Rectangle(20,110,240,130,WHITE);
 	waitusec( 60000 ); 
 	
  	AIC3204_rset( 72, 0x04 ); //RIGHT BEEP   один писк при включениии
	AIC3204_rset( 71, 0x80 ); //LEFT  BEEP	*/
  	////////////////////////////////////
              
    //set_dma0_ch2_i2s0_Lin();//
	set_dma0_ch2_i2s0_Lin_non();

	LCD_Rectangle(20,110,250,130,WHITE);

	//debugMode = 1;
	//MinuntsOnWork = 10;
	//SaveLifeTime();

	if (debugMode != 0)
	{
		LCD_Clear(BLUE_B);
		LCD_Rectangle(0,0,319,19,BLACK);
		print("PCF8474",1,20,Font16x24,WHITE,BLUE_B);
		printNumI(PCF8574Test,150,20,Font16x24,WHITE,BLUE_B);

		print("LM73-1",1,44,Font16x24,WHITE,BLUE_B);
		printNumI(LM73Adr1Test,150,44,Font16x24,WHITE,BLUE_B);

		print("LM73-2",1,68,Font16x24,WHITE,BLUE_B);
		printNumI(LM73Adr2Test,150,68,Font16x24,WHITE,BLUE_B);

		print("LM73-3",1,92,Font16x24,WHITE,BLUE_B);
		printNumI(LM73Adr3Test,150,92,Font16x24,WHITE,BLUE_B);

		print("KeyBrd",1,116,Font16x24,WHITE,BLUE_B);
		printNumI(KeyBoardTest,150,116,Font16x24,WHITE,BLUE_B);

		print("PwrAmp",1,140,Font16x24,WHITE,BLUE_B);
		printNumI(PowerAmplTest,150,140,Font16x24,WHITE,BLUE_B);

		print("PwrRst",1,164,Font16x24,WHITE,BLUE_B);
		printNumI(BatRTest,150,164,Font16x24,WHITE,BLUE_B);
	}
	else
	{
		LCD_Clear(BLUE_B);
		LCD_Rectangle(0,0,319,19,BLACK);				// Rectangle
		LCD_Rectangle(319-22,3,319,16,WHITE);  			// Батарейка
		LCD_Rectangle(319-22-2,7,319-22-1,12,WHITE);	// Батарейка
		LCD_Rectangle(298,4,318,15,BLACK);  			// Батарейка
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
//----------------accelerometr-------------------
		
	if((regim == 1113)||(regim == 1114))
	{							      	
		BuffCount = 480/reg_frequency+1;

		ACC_D = 0.0;
		for (j = 0; j < BuffCount; j++)
		{
			set_dma0_ch2_i2s0_Lin_non();
			waitusec( 500000 );
			PrevChnlData = accelerometr_new(4800,PrevChnlData.Avg);
			ACC_D = (double)ACC_D + PrevChnlData.Rms;
		}
			ACC_D = (double)ACC_D/BuffCount;

   		RES_ACC =(double)ACC_D/KUS_ACC;	   // (9.122723749/1.6);  		KUS_ACC;
		Reg_ACC_D = (double)reg_acseleration;
		KUS_1 = (double)Reg_ACC_D/RES_ACC;
		KUS_ACC_DR = KUS_ACC_DR * KUS_1;
		if(KUS_ACC_DR >= 21483)
      	{
      		KUS_ACC_DR = 21483;
      	}

      	spi_Kus(KUS_ACC_DR);
	}

//----------------velocimetr-------------------
 	
 	else if((regim == 1123)||(regim == 1124))
	{							      	
 		BuffCount = 480/reg_frequency+1;

 		ACC_D = 0.0;
 		for (j = 0; j < BuffCount; j++)
 		{
 			set_dma0_ch2_i2s0_Lin_non();
 			waitusec( 500000 );
 			PrevChnlData = accelerometr_new(4800,PrevChnlData.Avg);
 			ACC_D = (double)ACC_D + PrevChnlData.Rms;
 		}
 		ACC_D = (double)ACC_D/BuffCount;

		RES_VEL = (double) 112.5*1.41*(ACC_D/KUS_VEL)/(reg_frequency*0.1);
		Reg_VEL_D = (double)reg_velosity;
		KUS_2 = (double)Reg_VEL_D/RES_VEL;					
		KUS_VEL_DR = KUS_VEL_DR * KUS_2;		  						  						  	
		if(KUS_VEL_DR >= 20000)
      	{
      		KUS_VEL_DR = 20000;
      	}        	     
      	spi_Kus(KUS_VEL_DR);
	}
    

//----------------displasement-------------------  
	 
	else if((regim == 1133)||(regim == 1134))
	{							      	
		BuffCount = 480/reg_frequency+1;
		ACC_D = 0.0;
		for (j = 0; j < BuffCount; j++)
		{
		 	set_dma0_ch2_i2s0_Lin_non();
		 	waitusec( 500000 );
			PrevChnlData = accelerometr_new(4800,PrevChnlData.Avg);
			ACC_D = (double)ACC_D + PrevChnlData.Rms;
		}
		ACC_D = (double)ACC_D/BuffCount;

		////////////////////////////////

   		RES_DIS = (double) 50712*1.41*(ACC_D/KUS_DIS)/(reg_frequency*reg_frequency*0.1);
		Reg_DIS_D = (double)reg_displacement;
		KUS_3 = (double)Reg_DIS_D/RES_DIS;					
		KUS_DIS_DR = KUS_DIS_DR * KUS_3;		  						  						  	
		if(KUS_DIS_DR >= 20000)
      	{
      		KUS_DIS_DR = 20000;
      	}        	           	      
      	spi_Kus(KUS_DIS_DR);      
 	}
	else
	{
		PrevChnlData.Avg=0.0;
		//PrevChnlData.Rms=0.0;
	}
	cmd[0] = 0x02;
	cmd[1] = 0x1f;	      	//cmd[1] = 0x11;
	USBSTK5515_I2C_write( TCA8418_I2C_ADDR, cmd, 2 );
}

}



