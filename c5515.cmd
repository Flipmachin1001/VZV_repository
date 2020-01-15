/*-c */
/*-stack 0x2000 */                  /* PRIMARY STACK SIZE               */
/*-sysstack 0x2000 */               /* SECONDARY STACK SIZE             */
/*-heap  0x1000 */                  /* HEAP AREA SIZE  */  

/*_RTDX_interrupt_mask = ~0x06000010; */

/* Set entry point to Reset vector                                  */
/* - Allows Reset ISR to force IVPD/IVPH to point to vector table.  */
/*-e reset_isr */

MEMORY
{
    MMR      (RW) : origin = 0000000h length = 0000c0h      /* MMRs  */
    DARAM    (RW) : origin = 00000c0h length = 00FF40h      /* on-chip DARAM */
    SARAM    (RW) : origin = 0010000h length = 03E000h      /* on-chip SARAM */




    SAROM_0 (RX)  	: origin = 0fe0000h length = 008000h 	/* on-chip ROM 0 */
    SAROM_1 (RX)  	: origin = 0fe8000h length = 008000h 	/* on-chip ROM 1 */
    SAROM_2 (RX)  	: origin = 0ff0000h length = 008000h 	/* on-chip ROM 2 */
    SAROM_3 (RX)  	: origin = 0ff8000h length = 008000h 	/* on-chip ROM 3 */
    
    EMIF_CS0 (RW)  	: origin = 0050000h  length = 07B0000h   /* mSDR */ 
	EMIF_CS2 (RW)  	: origin = 0800000h  length = 0400000h   /* ASYNC1 : NAND */ 
	EMIF_CS3 (RW)  	: origin = 0C00000h  length = 0200000h   /* ASYNC2 : NAND  */
	EMIF_CS4 (RW)  	: origin = 0E00000h  length = 0100000h   /* ASYNC3 : NOR */
	EMIF_CS5 (RW)  	: origin = 0F00000h  length = 00E0000h   /* ASYNC4 : SRAM */
/*	EMIF_CS5 (RW)  : origin = 0F00000h  length = 0100000h*/   /* ASYNC4 : SRAM */

}


SECTIONS
{
    vectors (NOLOAD)
    .bss        : > DARAM /*, fill = 0 */
    vector      : > DARAM      ALIGN = 256 
    .stack      : > DARAM  
    .sysstack   : > DARAM  
	.sysmem 	: > DARAM 
/*	.sysmem 	: > EMIF_CS5 */
    .text       : > SARAM  
/*    .text       : > EMIF_CS5  */
    .data       : > SARAM
	.cinit 		: > DARAM
	.const 		: > SARAM 
	.cio		: > DARAM
	.usect   	: > DARAM
	.switch     : > DARAM 
	.emif_cs0   : > EMIF_CS0
	.emif_cs2   : > EMIF_CS2
	.emif_cs3   : > EMIF_CS3
	.emif_cs4   : > EMIF_CS4
	.emif_cs5   : > EMIF_CS5


}
