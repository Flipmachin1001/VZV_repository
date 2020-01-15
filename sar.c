/**********************************************************************
**+-----------------------------------------------------------------+**
**|                            ****                                 |**
**|                            ****                                 |**
**|                            ******o***                           |**
**|                      ********_///_****                          |**
**|                      ***** /_//_/ ****                          |**
**|                       ** ** (__/ ****                           |**
**|                           *********                             |**
**|                            ****                                 |**
**|                            ***                                  |**
**|                                                                 |**
**|   Copyright (c) 2006 - 2010    Texas Instruments Incorporated   |**
**|                        ALL RIGHTS RESERVED                      |**
**|                                                                 |**
**| Permission is hereby granted to licensees of Texas Instruments  |**
**| Incorporated (TI) products to use this computer program for     |**
**| the sole purpose of implementing a licensee product based       |**
**| on TI products.No other rights to reproduce, use, or            |**
**| disseminate this computer program, whether in part or in whole, |**
**| are granted.TI makes no representation or warranties with       |**
**| respect to the performance of this computer program, and        |**
**| specifically disclaims any responsibility for any damages,      |**
**| special or consequential,connected with the use of this program.|**
**|                                                                 |**
**+-----------------------------------------------------------------+**
**********************************************************************/


#include "data_types.h"
#include "sar.h"

Uint16 preKey =NoKey;
Uint16 keyCnt1 =0;
Uint16 keyCnt2 =0;

void Init_SAR(void)
{
    *SARCTRL = 0x3C00;                      // select AIN3, which is GPAIN1
    //*SARDATA; 
    *SARCLKCTRL = 0x0031;                   // 100/50 = 2MHz 
    *SARPINCTRL = 0x7104;
    *SARGPOCTRL = 0; 
}

void Read_GPAIN1(void)
{
    Uint16 val, i;

    for(i=0;i<30; i++)
        asm("	nop");     

    while(1)
    {
        
        for(i=0;i<100; i++)
            asm("	nop");     

		*SARCTRL = 0xB400;     

        while(1)
        {
            for(i=0;i<50; i++)
                asm("	nop");     
            val = *SARDATA;
            if((val&0x8000) == 0)
                break;
        }
    }
}

Uint16 Get_Sar_Key(void)
{
    Uint16 val, i;

    //keyCnt1++;
    //if(keyCnt1 < 0x7FFF)
    //    return(NoKey);
    
    //keyCnt1=0;
    keyCnt2++;
    if(keyCnt2 > 90)   
    {
        keyCnt2=0;
        preKey = NoKey;
    }
    
    
	*SARCTRL = 0xB800;     
    while(1)
    {
        for(i=0;i<500; i++)
            asm("	nop");     
        val = *SARDATA;
        if((val&0x8000) == 0)
            break;
    }
    
    if(val == NoKey)
    {
        return(val);
    }
    else if((val==SW7)||(val==SW9)||(val==SW10)||(val==SW12))
    {
        if(val != preKey)
        {
            preKey = val;
            return(val);
        }
		else
		{
			return(NoKey);
		}

    }
    else
    {
        return(NoKey);
    }
    
    
}

