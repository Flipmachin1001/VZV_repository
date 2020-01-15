/*
 *  Copyright 2009 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  SPI ROM header file
 *
 */

#include "evm5515.h"

/* ------------------------------------------------------------------------ *
 *  SPI ROM Definitions                                                     *
 * ------------------------------------------------------------------------ */
#define spirom_SIZE               0x8000
#define spirom_BASE               0x0000
#define spirom_PAGESIZE           32
#define spirom_PAGEMASK           0xffc0

/* ------------------------------------------------------------------------ *
 *  SPI ROM Commands                                                        *
 * ------------------------------------------------------------------------ */
#define spirom_CMD_WREN           0x06
#define spirom_CMD_WRDI           0x04
#define spirom_CMD_RDSR           0x05
#define spirom_CMD_WRSR           0x01
#define spirom_CMD_READ           0x03
#define spirom_CMD_WRITE          0x02

/* ------------------------------------------------------------------------ *
 *  SPI Controller                                                          *
 * ------------------------------------------------------------------------ */

#define SPI_SPICC1         *(volatile ioport Uint16*)(0x3000)
#define SPI_SPICC2         *(volatile ioport Uint16*)(0x3001)
#define SPI_SPIDC1         *(volatile ioport Uint16*)(0x3002)
#define SPI_SPIDC2         *(volatile ioport Uint16*)(0x3003)
#define SPI_SPICR1         *(volatile ioport Uint16*)(0x3004)
#define SPI_SPICR2         *(volatile ioport Uint16*)(0x3005)
#define SPI_SPISR1         *(volatile ioport Uint16*)(0x3006)
#define SPI_SPISR2         *(volatile ioport Uint16*)(0x3007)
#define SPI_SPIDR1         *(volatile ioport Uint16*)(0x3008)
#define SPI_SPIDR2         *(volatile ioport Uint16*)(0x3009)

/* ------------------------------------------------------------------------ *
 *  Prototype                                                               *
 * ------------------------------------------------------------------------ */
void spirom_init( );
Uint16 spirom_status_set( Uint8 val);
void spirom_read( Uint16 src, Uint32 dst, Uint32 length );
void spirom_write( Uint32 src, Uint16 dst, Uint32 length );


