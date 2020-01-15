/******************************************************************************
**+-------------------------------------------------------------------------+**
**|                            ****                                         |**
**|                            ****                                         |**
**|                            ******o***                                   |**
**|                      ********_///_****                                  |**
**|                      ***** /_//_/ ****                                  |**
**|                       ** ** (__/ ****                                   |**
**|                           *********                                     |**
**|                            ****                                         |**
**|                            ***                                          |**
**|                                                                         |**
**|         Copyright (c) 2006 - 2010    Texas Instruments Incorporated     |**
**|                        ALL RIGHTS RESERVED                              |**
**|                                                                         |**
**| Permission is hereby granted to licensees of Texas Instruments          |**
**| Incorporated (TI) products to use this computer program for the sole    |**
**| purpose of implementing a licensee product based on TI products.        |**
**| No other rights to reproduce, use, or disseminate this computer         |**
**| program, whether in part or in whole, are granted.                      |**
**|                                                                         |**
**| TI makes no representation or warranties with respect to the            |**
**| performance of this computer program, and specifically disclaims        |**
**| any responsibility for any damages, special or consequential,           |**
**| connected with the use of this program.                                 |**
**|                                                                         |**
**+-------------------------------------------------------------------------+**
******************************************************************************/
#include <stdio.h>
#include "data_types.h"
#include "register_cpu.h"
#include "register_RTC.h"
#include "rtc.h"


char Buf_sec[3];
char Buf_min[3];
char Buf_hour[3];
char Buf_day[3];
char Buf_month[3];
char Buf_year[3];

Uint16 Flag_RTC=0;
Uint16 Conunt_RTC =0;





void enable_rtc_second_int(void)
{
    RTC_CTR = 1;
    RTC_INT = 0x0002;           // enalbe  second int  0x8002;  
}









/*
void reset_RTC(void)
{
    Uint16 temp;
    
    temp = RTC_CTR;
    RTC_CTR =0;             // disable interrupt
    
    */
    
    /*
    i=1;										   	  
	RTC_DAY   = BufRTC[i++];
    RTC_MONTH = BufRTC[i++];
    RTC_YEAR  = BufRTC[i++]; 	   
	RTC_HOUR  = BufRTC[i++];   
	RTC_MIN   =	BufRTC[i++]; 
	RTC_SEC   = BufRTC[i++];	  
    RTC_MSEC  = 0;
    */     
    
    
    
    //ReadRTC();
    
    
 /*   
    
    RTC_MSEC  = 0x00;
    RTC_SEC   = 0x50;
    RTC_MIN   = 0x59;
    RTC_HOUR  = 0x23;
    
   	RTC_DAY   = 0x31;
    RTC_MONTH = 0x12;
    RTC_YEAR  = 0x12;        
    
    
    RTC_UPDT = 0x8000;      // update time
    
    while(RTC_UPDT != 0);
    
    RTC_CTR = temp;         // recover interrupt
}
*/

static char NtoC (char num)
{
    switch(num)
    {
        case 0:
            num= '0';
			break;
        case 1:
            num= '1';
			break;
        case 2:
            num= '2';
			break;
        case 3:
            num= '3';
			break;
        case 4:
            num= '4';
			break;
        case 5:
            num= '5';
			break;
        case 6:
            num= '6';
			break;
        case 7:
            num= '7';
			break;
        case 8:
            num= '8';
			break;
        case 9:
            num= '9';
			break;
        default:
            num = '0';
			break;
    }
    return (char)num;
}


// convert four digit number to string
void convert_number_to_string(Uint16 number, char *buf)
{
    char temp1, temp0;

    temp0 = (char)(number&0x000F);               // 1's position
    temp1 = (char)((number>>4)&0x000F);          // 10's 
    
    *(buf) = NtoC(temp1);
    *(buf+1) = NtoC(temp0); 
    *(buf+2) = 0;       
}


/*
interrupt void RTC_Isr(void)
{
    Uint16 temp,i;

	// clear RTC int flag
    IFR1 = 0x0004;
    
    temp =RTC_STAT;
    RTC_STAT = temp;

	Flag_RTC =1;
	Conunt_RTC ++;
	
	
		asm(" BIT (ST1, #ST1_XF) = #0");
	    for(i=1;i<6;i++ ) {}						
		asm(" BIT (ST1, #ST1_XF) = #1");
	
	
	//printNumI( RTC_SEC,24,70,Num8x12,BLACK,WHITE);	
		
}
*/







