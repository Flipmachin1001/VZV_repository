
#ifndef _SDRAM_H_
#define _SDRAM_H_

Uint32 sdram_base;
Uint32 sdram_size;


/*

// ------------------------------------------------------------------------	*
//                                                                         	*                                                        				   	*
//							    sdramSet							        *
//                                                                          *
//  ----------------------------------------------------------------------- * 
void sdramSet( Uint32 start, Uint32 len, Uint16 val )
{
    Uint32 i;
    Uint16 *pdata;
	pdata = (Uint16 *)start;
    for ( i = 0; i < len; i++ )
    {
        *pdata++ = val;  
    } 
}

// ------------------------------------------------------------------------	*
//                                                                         	*                                                        				   	*
//							      MemWrite							        *
//                                                                          *
//  ----------------------------------------------------------------------- * 
Uint32 MemWrite( Uint32 start, Uint32 len, Uint16* data )
{
    Uint32 k;
    Uint32 errorcount = 0;
	Uint16 *pdata;
	pdata = (Uint16 *)start;
    for ( k = 0; k < len; k++ )
    {    	    
	   *pdata++ = data[k]; 		   	          
    }
    return errorcount;
}

// ------------------------------------------------------------------------	*
//                                                                         	*                                                        				   	*
//							      MemRead							        *
//                                                                          *
//  ----------------------------------------------------------------------- * 
Uint32 MemRead( Uint32 start, Uint32 len, Uint16* data )
{
    Uint32 k;
    Uint32 errorcount = 0;
	Uint16 *pdata;
	pdata = (Uint16 *)start;
    for ( k = 0; k < len; k++ )
    {        	    	    		   
		data[k] = (*pdata++) & (0xFFFF);		         	   	   	      	    		  	
    }
    return errorcount;
}




Uint16 memfill16( Uint32 start, Uint32 len, Uint16 val )
{
    Uint32 i;
    Uint32 errorcount = 0;
	Uint32 *pdata;
    // Write Pattern //
	pdata = (Uint32 *)start;
    for ( i = 0; i < len; i++ )
    {
        *pdata++ = val;
    }

    // Read Pattern //
	pdata = (Uint32 *)start;
    for ( i = 0; i < len; i++ )
    {
    	
    	
        if ( (*pdata & 0xFFFF) != val )
        {
            errorcount++;
            break;
        }
        
        pdata++;
        
    }

    return errorcount;
}






// ------------------------------------------------------------------------	*
//                                                                         	*                                                        				   	*
//							      sdram_test							    *
//                                                                          *
//  ----------------------------------------------------------------------- *  
Uint16 sdram_test( )
{
    Int16 errors = 0;

    sdram_base = 0x028000;       // sdram memory
    sdram_size = 0x3D8000;       // 8 MB (Word address)

   
    if ( memfill16( sdram_base, sdram_size, 0xFFFF ) )
        errors += 1; 
    if ( memfill16( sdram_base, sdram_size, 0x0000 ) )
        errors += 8; 
        
    return errors;
}



*/








// ------------------------------------------------------------------------	*
//                      Timings based on EMIF clk = 100MHz                 	*                                                        				   	*
//							      SDRAM_INIT							    *
//                          mSDRAM = MT48H4M16LF-8                          *
//  ----------------------------------------------------------------------- *  




/*
SDRAM_INIT() 
{
    int i;

    / reset EMIF /
    *(short *)PRCR@IO = 0x0002;
    for(i=0;i<0xff;i++);

    //enable SDRAM clock
    *(short*)CLKCFGL@IO=0x0001;

	// enable word writes to EMIF regs //
    *(short *)ESCR@IO = 0;

    // step 1 //
    *(short *)SDTIMR1@IO = 0x4710;
    *(short *)SDTIMR2@IO = 0x3911;
    *(short *)SDSRETR@IO = 0x0007;

    // step 2 /
    *(short *)SDRCR@IO = 0x04E3;
    
    // step 3 //
    *(short *)SDCR1@IO = 0x4720;
    *(short *)SDCR2@IO = 0x0001;

    // step 4 //
    for(i=0;i<0xff;i++);

    // step 5 //
    *(short *)SDRCR@IO = 0x061A;

    
}

*/















Uint16 memfill16( Uint32 start, Uint32 len, Uint32 val )
{
    Uint32 i;
    Uint32 end = start + len;
    Uint32 errorcount = 0;
	Uint16 *pdata;

    /* Write Pattern */
	pdata = (Uint16 *)start;
    for ( i = start; i < end; i += 1 )
    {
        *pdata++ = val;
    }

    /* Read Pattern */
	pdata = (Uint16 *)start;
    for ( i = start; i < end; i += 1 )
    {
        if ( *pdata++ != val )
        {
            errorcount++;
            break;
        }
    }

    return errorcount;
}





Uint16 memasdram16( Uint32 start, Uint32 len )
{
    Uint32 i;
    Uint32 end = start + len;
    Uint32 errorcount = 0;
	Uint16 *pdata;


    /* Write Pattern */
	pdata = (Uint16 *)start;
    for ( i = start; i < end; i ++ )
    {
	    *pdata++ = i & 0xFFFF;

    }

    /* Read Pattern */
	pdata  = (Uint16 *)start;
    for ( i = start; i < end; i ++ )
    {
        if ( *pdata++ != (i & 0xFFFF) )
        {
            errorcount++;
            break;
        }
    }

    return errorcount;
}




Uint16 meminvasdram16( Uint32 start, Uint32 len )
{
    Uint32 i;
    Uint32 end = start + len;
    Uint32 errorcount = 0;
	Uint16 *pdata;

    /* Write Pattern */
	pdata = (Uint16 *)start;
    for ( i = start; i < end; i ++ )
    {
        *pdata++ = (~i & 0xFFFF);
    }

    /* Read Pattern */
	pdata = (Uint16 *)start;
    for ( i = start; i < end; i ++ )
    {
        if ( *pdata++ != (~i & 0xFFFF)  )
        {
            errorcount++;
            break;
        }
    }

    return errorcount;
}







Uint16 sdram_test( )
{
	
	
    Int16 errors = 0;

    sdram_base = 0x028000;       // sdram memory
    sdram_size = 0x7B0000 / 2;       // 8 MB (Word address)

    printf( "  > Data test \n" );
    if ( memfill16( sdram_base, sdram_size, 0xFFFF ) )
        errors += 1;

    if ( memfill16( sdram_base, sdram_size, 0xAAAA ) )
        errors += 2;

    if ( memfill16( sdram_base, sdram_size, 0x5555 ) )
        errors += 4;

    if ( memfill16( sdram_base, sdram_size, 0x0000 ) )
        errors += 8;

    if ( errors )
	    printf( "        > Error = 0x%x\n", errors );





    sdram_base = 0x028000;       // sdram memory
    sdram_size = 0x7B0000 / 2;       // 8 MB (Word address)

    printf( "  > Address test\n" );
    if ( memasdram16( sdram_base, sdram_size ) )
        errors += 16;



    printf( "  > Inv Address test\n" );
    if ( meminvasdram16( sdram_base, sdram_size ) )
        errors += 16;




	printf("\n");

    return errors;
}


















    
#endif
