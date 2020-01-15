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

Uint16 LaserStartFreq = 0;

typedef struct Chnl_Data_t
{
	double Avg;
    double Rms;
} ChnlData;

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

Uint8 AmpTable[15];

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


// оэффициенты фильтра 12 к√ц
DATA h[NH] = {

0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 1, -3,  
0, 7,
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
