/*
 * Memory.h
 *
 *  Created on: 15 янв. 2020 г.
 *      Author: Александр Михалев
 */

#ifndef MEMORY_H_
#define MEMORY_H_

double KUS_ACC = 1.2;
double KUS_VEL = 1.2;
double KUS_DIS = 1.2;


Uint16 Coeff_A = 9.122723749; //9.122 723749
Uint16 Coeff_V = 50;
Uint16 Coeff_S = 50;

Uint8 Coeff_A_0 = 1.0;
Uint8 Coeff_V_0 = 0;
Uint8 Coeff_S_0 = 0;

Uint8 Coeff_A_00 = 0;
Uint8 Coeff_V_00 = 0;
Uint8 Coeff_S_00 = 0;

int debugMode = 1;

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




#endif /* MEMORY_H_ */
