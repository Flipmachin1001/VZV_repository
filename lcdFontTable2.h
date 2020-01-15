/*   ==========================================================================
 *   Copyright (c) Texas Instruments Inc , 2004
 *
 *   Use of this software is controlled by the terms and conditions found
 *   in the license agreement under which this software has been supplied
 *   provided
 *   ==========================================================================
 */

/** \file  lcdFontTable.h
    \brief LCD Driver Font table defnition API header file
    \internal
    \date 16th Feb, 2005
    \author Ganesh K 
*/

#ifndef _LCDFONTTABLE2_H
#define _LCDFONTTABLE2_H

/***********************************************************************
 *                       #define SECTION                               *
 ***********************************************************************/

#define FONT_BITMAP_SIZE    8
/**< hash define value for font bimap size */
#define FONT_TABLE_SIZE      sizeof(lcdFontTable)
/**< size of complete font table */

#define LCD_CHAR_HEIGHT 				8
/**< no of bytes to diplay one character  */
#define LCD_CHAR_WIDTH                   8
/**< total no of bits taken by one character */

/***********************************************************************
 *                    ERROR & WARNING CODES                            *
 ***********************************************************************/

/***********************************************************************
 *                    CONSTANTS DECLARATION SECTION                    *
 ***********************************************************************/

static unsigned char lcdFontTable[5] = 
	{



    };	
/**< lcd Font table declaration variable  */

#endif  /* #ifndef LCDFONTTABLE_H */

