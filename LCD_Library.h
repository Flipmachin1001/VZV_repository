/*   ==========================================================================
 *   Copyright (c) Shubin Vladimir, 2011
 *   ==========================================================================
 */

#ifndef _LCD_Library_H
#define _LCD_Library_H

//Uint8 Temp_Bat = 0;


//Color codes
#define RGB565CONVERT(red, green, blue)\
( (( red   >> 3 ) << 11 ) | \
(( green >> 2 ) << 5  ) | \
( blue  >> 3 ))

//Color codes

#define BLACK               RGB565CONVERT(0,    0,      0)
#define WHITE               RGB565CONVERT(255,  255,    255)
#define WHITE_ADV			RGB565CONVERT(250,  250,    250)

#define BLUE          	    RGB565CONVERT(0,    0,      255)
#define GREEN               RGB565CONVERT(0,    255,    0)
#define CYAN                RGB565CONVERT(0,    255,    255)
#define RED                 RGB565CONVERT(255,  0,      0)
#define MAGENTA             RGB565CONVERT(255,  0,      255)
#define YELLOW              RGB565CONVERT(255,  255,    0)
#define BROWN               RGB565CONVERT(255,  128,    0)

#define BRIGHTBLUE          RGB565CONVERT(0,    0,      128)
#define BRIGHTGREEN         RGB565CONVERT(0,    128,    0)
#define BRIGHTCYAN          RGB565CONVERT(0,    128,    128)
#define BRIGHTRED           RGB565CONVERT(128,  0,      0)
#define BRIGHTMAGENTA       RGB565CONVERT(128,  0,      128)
#define BRIGHTYELLOW        RGB565CONVERT(128,  128,    0)

#define LIGHTBLUE           RGB565CONVERT(128,  128,    255)
#define LIGHTGREEN          RGB565CONVERT(128,  255,    128)
#define LIGHTCYAN           RGB565CONVERT(128,  255,    255)
#define LIGHTRED            RGB565CONVERT(255,  128,    128)
#define LIGHTMAGENTA        RGB565CONVERT(255,  128,    255)
#define LIGHTYELLOW         RGB565CONVERT(255,  255,    128)
                            
#define GRAY0       	    RGB565CONVERT(224,  224,    224)
#define GRAY1         	    RGB565CONVERT(192,  192,    192)   
#define GRAY2               RGB565CONVERT(160,  160,    160)   
#define GRAY3               RGB565CONVERT(128,  128,    128)
#define GRAY4               RGB565CONVERT(96,   96,     96)
#define GRAY5               RGB565CONVERT(64,   64,     64)
#define GRAY6	            RGB565CONVERT(32,   32,     32)

#define BLUE0           	RGB565CONVERT(245,  245,    255)
#define BLUE1           	RGB565CONVERT(235,  235,    255)
#define BLUE2           	RGB565CONVERT(225,  225,    255)
#define BLUE3           	RGB565CONVERT(215,  215,    255)
#define BLUE4           	RGB565CONVERT(205,  205,    255)
#define BLUE5           	RGB565CONVERT(195,  195,    255)
#define BLUE6           	RGB565CONVERT(185,  185,    255)
#define BLUE7           	RGB565CONVERT(175,  175,    255)
#define BLUE8           	RGB565CONVERT(165,  165,    255)
#define BLUE9           	RGB565CONVERT(155,  155,    255)
#define BLUE10           	RGB565CONVERT(145,  145,    255)
#define BLUE11           	RGB565CONVERT(135,  135,    255)
#define BLUE12           	RGB565CONVERT(125,  125,    255)
#define BLUE13           	RGB565CONVERT(115,  115,    255)
#define BLUE14           	RGB565CONVERT(105,  105,    255)
#define BLUE15           	RGB565CONVERT(95 ,  95,     255)
#define BLUE16           	RGB565CONVERT(85 ,  85,     255)
#define BLUE17           	RGB565CONVERT(75 ,  75,     255)
#define BLUE18           	RGB565CONVERT(65 ,  65,     255)
#define BLUE19           	RGB565CONVERT(55 ,  55,     255)
#define BLUE20           	RGB565CONVERT(45 ,  45,     255)


#define BLUE_F           	RGB565CONVERT(54 ,  85,      129)

#define BLUE_T           	RGB565CONVERT(17 ,  42,      72)
#define BLUE_B           	RGB565CONVERT(72 ,  121,    197)
#define YELLOW_K           	RGB565CONVERT(255 , 170,      0)

/*
//Color codes
#define RED  	0xf800
#define GREEN	0x07e0
#define BLUE 	0x001f
#define WHITE	0xffff
#define BLACK	0x0000
#define YELLOW  0xFFE0
#define BLUE1 	0xFF1F
#define BLUE2 	0x001F
#define MAGENTA 0xf81f
#define CYAN 	0x07ff
#define BLUE3 	0x0FFC
#define GRAY 	0x07ff
#define SILVER 	0x07ff
#define GOLD 	0x07ff
#define WHITE1	0xcfff
#define BLACK2	0x8C71
*/





//  ----------------------------------------------------------------------- * 
#define LCD_ALIGNMENT VERTICAL
//#define LCD_ALIGNMENT HORIZONTAL  // Not finished yet!
//  ----------------------------------------------------------------------- * 
#define swap(a, b) { Int16 t = a; a = b; b = t; }






//  ----------------------------------------------------------------------- * 	
void wait1( Uint32 delay )
{
    //volatile Uint32 i;
   	Uint32 j;
    for ( j = 0 ; j < delay ; j++ ){ };
}

//  ----------------------------------------------------------------------- * 
void LCD_WriteIndex(Uint16 index)
{
  	// Write Index  
    LCD_LCDLIDDCS0ADDR  = 0x00;    
    LCD_LCDLIDDCS0ADDR  = index;
      
}

//  ----------------------------------------------------------------------- * 
void LCD_WriteData(Uint16 data)
{
	// Write Data
 	LCD_LCDLIDDCS0DATA = (data>>8); 	
 	LCD_LCDLIDDCS0DATA = data; 	
}  

//  ----------------------------------------------------------------------- * 	
void LCD_WriteReg(Uint16 index, Uint16 data)
{
	// Write Index
  	LCD_WriteIndex(index);  
  	// Write Data
  	LCD_WriteData(data);
}  

//  ----------------------------------------------------------------------- * 
void LCD_SolidFill(unsigned long count, unsigned int color)
{	
	unsigned long i;
  	// Write Index
  	LCD_WriteIndex(0x0022);
  	// Write Data  
  	LCD_LCDLIDDCS0DATA = (color>>8);
  	LCD_LCDLIDDCS0DATA = color;   	  
  	for (i=0; i <= count-1; i++)
  	{
    	// Write Data
   		LCD_LCDLIDDCS0DATA = (color>>8);
   		LCD_LCDLIDDCS0DATA = color;   
  	}
}

//  ----------------------------------------------------------------------- * 
void LCD_SolidFill2(unsigned long count, unsigned int color)
{	
	unsigned long i;
  	// Write Index
  	//LCD_WriteIndex(0x22);
  	// Write Data  
   	LCD_LCDLIDDCS0DATA = (color>>8);
   	LCD_LCDLIDDCS0DATA = color;    
  	for (i=0; i <= count-1; i++)
  	{
    	// Write Data
   		LCD_LCDLIDDCS0DATA = (color>>8);
   		LCD_LCDLIDDCS0DATA = color;       	    
  	}
}

//  ----------------------------------------------------------------------- * 	
void LCD_SolidFill3(unsigned long count, unsigned int color)
{	
	unsigned long i;
	// LCD_LCDLIDDCS0DATA = color;  
  	for (i=0; i <= count-1; i++)
  	{
  		// Write Data
   		LCD_LCDLIDDCS0DATA = (color>>8);
   		LCD_LCDLIDDCS0DATA = color;   
  	}
}

//  ----------------------------------------------------------------------- * 	
void LCD_SetCursor(unsigned int x, unsigned int y)
{
	LCD_WriteReg(0x004e,x); // 
  	LCD_WriteReg(0x004f,y); // 
}

//  ----------------------------------------------------------------------- * 
void LCD_ResetWindow()
{
	LCD_WriteReg(0x0044, 0xEF00);			// Vertical Address Start/end Position (239)           
    LCD_WriteReg(0x0045, 0x0000);          	// Horizontal Address Start Position  
    LCD_WriteReg(0x0046, 0x013F);			// Horizontal Address end Position (319)   
}

//  ----------------------------------------------------------------------- * 
void LCD_color(unsigned int color)
{	
  	unsigned long i;
  	LCD_SetCursor(0,0);
  	LCD_ResetWindow();  
 	//LCD_SolidFill(76800,);  // This is a faster method   
  	LCD_WriteIndex(0x0022);
  	for (i=0; i <= 76799; i++)
  	{
  		// Write Data
   		LCD_LCDLIDDCS0DATA = (color>>8);
   		LCD_LCDLIDDCS0DATA = color; 
  	}  
}

//  ----------------------------------------------------------------------- * 



//  ----------------------------------------------------------------------- * 
void LCD_Clear_Area(unsigned int x, unsigned int y, unsigned int k, unsigned int h, unsigned int color)
{	
  	int i=0,j=0;
  	//LCD_SetCursor(x,y);  	  	
    for (j=0; j < h; j++)
	{    
		LCD_SetCursor(x,y);		
  		for (i=0; i < k; i++)
		{
 			LCD_WriteData(~color);
		}		
		y = y+1;					
	}   
}

//  ----------------------------------------------------------------------- * 
void LCD_SetWindow(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2)
{  
	LCD_WriteReg(0x0044,((0x00FF & y1)|(0xFF00&(y2<<8)))); 		// Vertical Address Start/end Position (239)            
    LCD_WriteReg(0x0045,x1);           							// Horizontal Address Start Position  
    LCD_WriteReg(0x0046,x2);									// Horizontal Address end Position (319)   
}

//  ----------------------------------------------------------------------- * 


//  ----------------------------------------------------------------------- * 
void setXY(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2)
{
    LCD_WriteReg(0x0044,((0x00FF & y1)|(0xFF00&(y2<<8)))); 		// Vertical Address Start/end Position (239)            
    LCD_WriteReg(0x0045,x1);           							// Horizontal Address Start Position  
    LCD_WriteReg(0x0046,x2);									// Horizontal Address end Position (319)  
	LCD_WriteIndex(0x0022);   	 
}

//  ----------------------------------------------------------------------- * 
void LCD_PutPixel(unsigned int x, unsigned int y, unsigned int color)
{
  	LCD_SetCursor(x,y);
  	LCD_WriteIndex(0x0022);
  	LCD_WriteData(color);
}  

//  ----------------------------------------------------------------------- * 
void drawHLine(unsigned int x1,unsigned int y1,unsigned int l,unsigned int color)
{		
	LCD_SetCursor(x1,y1);
	setXY(x1, y1, x1+l, y1);	
	LCD_SolidFill(l,color);
	LCD_ResetWindow();
}

//  ----------------------------------------------------------------------- * 
void drawVLine(unsigned int x1,unsigned int y1,unsigned int l,unsigned int color)
{	
	LCD_SetCursor(x1,y1);
	setXY(x1, y1, x1,y1+l);	
	LCD_SolidFill2(l,color);
	LCD_ResetWindow();
}

//  ----------------------------------------------------------------------- * 
void drawVLine3(unsigned int x1,unsigned int y1,unsigned int l,unsigned int color)
{	
	LCD_SetCursor(x1,y1);
	setXY(x1, y1, x1,y1+l);	
	LCD_SolidFill3(l,color);
	LCD_ResetWindow();
}


//  ----------------------------------------------------------------------- * 
void LCD_Rectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color)
{      	
	unsigned long width;
	unsigned long height;	
    LCD_SetWindow(x1,y1,x2,y2);
    LCD_SetCursor(x1,y1);    
    width = x2-x1+1;
    height = y2-y1+1;
    LCD_SolidFill(width*height, color);
    LCD_ResetWindow();
}


//  ----------------------------------------------------------------------- * 
void drawRect(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int color)
{
	Int16 tmp;
	if (x1>x2)
	{
		tmp=x1;
		x1=x2;
		x2=tmp;
	}
	if (y1>y2)
	{
		tmp=y1;
		y1=y2;
		y2=tmp;
	}
	drawHLine(x1, y1, x2-x1,color);
	drawHLine(x1, y2, x2-x1,color);
	drawVLine(x1, y1, y2-y1,color);
	drawVLine(x2, y1, y2-y1,color);
}



//  ----------------------------------------------------------------------- * 

void fillRect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2,unsigned int color)
{
	unsigned int tmp;
	unsigned int i;	
	if (x1>x2)
	{
		tmp=x1;
		x1=x2;
		x2=tmp;
	}
	if (y1>y2)
	{
		tmp=y1;
		y1=y2;
		y2=tmp;
	}
		for (i=0; i<((y2-y1)/2)+1; i++)
		{
			drawHLine(x1, y1+i, x2-x1,color);
			drawHLine(x1, y2-i, x2-x1,color);
		}	
}


void LCD_Clear_1(unsigned int color)
{
	fillRect(0,20,319,239, color);
}


void LCD_Clear(unsigned int color)
{
  	LCD_SetCursor(0,0);
  	LCD_ResetWindow();
  	LCD_SolidFill(76800, color);  // This is a faster method
 	// LCD_WriteIndex(0x22);
 	// for (i=0; i <= 76799; i++){
 	// LCD_WriteData(color);
 	// }
}

/*
void LCD_Clear_1(unsigned int color)
{
    LCD_SetWindow(0,20,319,239);
    LCD_SetCursor(0,20);
    LCD_SolidFill(69861, color);
    LCD_ResetWindow();
} */


//  ----------------------------------------------------------------------- * 
void fillRoundRect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2,unsigned int color)
{
	unsigned int tmp;
	unsigned int i;	
	
	if (x1>x2)
	{
		tmp=x1;
		x1=x2;
		x2=tmp;
	}
	if (y1>y2)
	{
		tmp=y1;
		y1=y2;
		y2=tmp;
	}

	if ((x2-x1)>4 && (y2-y1)>4)
	{
		for (i=0; i<((y2-y1)/2)+1; i++)
		{
			switch(i)
			{
			case 0:
				drawHLine(x1+2, y1+i, x2-x1-4,color);
				drawHLine(x1+2, y2-i, x2-x1-4,color);
				break;
			case 1:
				drawHLine(x1+1, y1+i, x2-x1-2,color);
				drawHLine(x1+1, y2-i, x2-x1-2,color);
				break;
			default:
				drawHLine(x1, y1+i, x2-x1,color);
				drawHLine(x1, y2-i, x2-x1,color);
			}
		}
	}
}


//  ----------------------------------------------------------------------- * 
void drawRoundRect(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2,unsigned int color)
{
	unsigned int tmp;

	if (x1>x2)
	{
		tmp=x1;
		x1=x2;
		x2=tmp;
	}
	if (y1>y2)
	{
		tmp=y1;
		y1=y2;
		y2=tmp;
	}
	if ((x2-x1)>4 && (y2-y1)>4)
	{
		LCD_PutPixel(x1+1,y1+1,color);
		LCD_PutPixel(x2-1,y1+1,color);
		LCD_PutPixel(x1+1,y2-1,color);
		LCD_PutPixel(x2-1,y2-1,color);
		drawHLine(x1+2, y1, x2-x1-4,color);
		drawHLine(x1+2, y2, x2-x1-4,color);
		drawVLine(x1, y1+2, y2-y1-4,color);
		drawVLine(x2, y1+2, y2-y1-4,color);
	}
}


//  ----------------------------------------------------------------------- * 
void fillCirclen(Uint16 x0, Uint16 y0, Uint16 r, Uint16 color)
{
	
  Int16 f = 1 - r;
  Int16 ddF_x = 1;
  Int16 ddF_y = -2 * r;
  Int16 x = 0;
  Int16 y = r;

  drawVLine(x0, y0-r, 2*r+1, color);

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;
  
    drawVLine(x0+x, y0-y, 2*y+1, color);
    drawVLine(x0-x, y0-y, 2*y+1, color);
    drawVLine(x0+y, y0-x, 2*x+1, color);
    drawVLine(x0-y, y0-x, 2*x+1, color);
  	}
}





//  ----------------------------------------------------------------------- * 
// draw a circle outline
void drawCircle(Uint16 x0, Uint16 y0, Uint16 r, Uint16 color)

 {
  Int16 f = 1 - r;
  Int16 ddF_x = 1;
  Int16 ddF_y = -2 * r;
  Int16 x = 0;
  Int16 y = r;

  LCD_PutPixel(x0, y0+r, color);
  LCD_PutPixel(x0, y0-r, color);
  LCD_PutPixel(x0+r, y0, color);
  LCD_PutPixel(x0-r, y0, color);

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;
  
    LCD_PutPixel(x0 + x, y0 + y, color);
    LCD_PutPixel(x0 - x, y0 + y, color);
    LCD_PutPixel(x0 + x, y0 - y, color);
    LCD_PutPixel(x0 - x, y0 - y, color);
    
    LCD_PutPixel(x0 + y, y0 + x, color);
    LCD_PutPixel(x0 - y, y0 + x, color);
    LCD_PutPixel(x0 + y, y0 - x, color);
    LCD_PutPixel(x0 - y, y0 - x, color);
    
  }
}






//  ----------------------------------------------------------------------- * 
void drawLinen(Int16 x0, Int16 y0, Int16 x1, Int16 y1, Int16 color)
 {
 	
 	Int16 dx, dy;
 	Int16 err1;
 	Int16 ystep;
 	
 	
  Int16 steep = abs(y1 - y0) > abs(x1 - x0);
  
  if (steep) {
    swap(x0, y0);
    swap(x1, y1);
  }

  if (x0 > x1) {
    swap(x0, x1);
    swap(y0, y1);
  }

  //Int16 dx, dy;
  dx = x1 - x0;
  //dy = abs(y1 - y0);
  dy = abs(y1 - y0);
	
  err1 = dx / 2;
  //Int16 ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;}

  for (; x0<=x1; x0++) {
    if (steep) {
      LCD_PutPixel(y0, x0, color);
    } else {
      LCD_PutPixel(x0, y0, color);
    }
    err1 -= dy;
    if (err1 < 0) {
      y0 += ystep;
      err1 += dx;
    }
  }
}















//  ----------------------------------------------------------------------- * 
//void drawBitmap(Uint16 x, Uint16 y, Uint16 sx, Uint16 sy, unsigned int* data)
void drawBitmap(Uint16 x, Uint16 y, Uint16 sx, Uint16 sy, Uint16* data)
{
	unsigned int col;
	int tc;	
	LCD_SetCursor(x,y);
	setXY(x, y, x+sx-1, y+sy-1);
	for (tc=0; tc<(sx*sy); tc++)
	{									
		col=data[tc];																																
		LCD_WriteData(col);
	}													
}








//  ----------------------------------------------------------------------- * 
void drawBitmap8bit(Uint16 x, Uint16 y, Uint16 sx, Uint16 sy, Uint8* data)
{
	Uint16 col;
	Uint32 tc;
	LCD_SetCursor(x,y);
	setXY(x, y, x+sx-1, y+sy-1);
	for (tc=0; tc < (sx*sy); tc++)
	{			
		col = data[tc]|(data[tc]<<8);
		LCD_WriteData(col);										
	}													
}

















//  ----------------------------------------------------------------------- * 
void printChar(byte c, int x, int y,const byte* data, Int16 colorF , Int16 colorB )
{
	byte i,j,ch,x_size,y_size,offset;
	word temp; 
		
	x_size=data[0];
	y_size=data[1];
	offset=data[2];

		LCD_SetCursor(x,y);
		setXY(x,y,x+x_size-1,y+y_size-1);
	  
		temp=((c-offset)*((x_size/8)*y_size))+4;
		for(j=0;j<((x_size/8)*y_size);j++)
		{								
			ch=data[temp];							
			for(i=0;i<8;i++)
			{   													
				if((ch&(1<<(7-i)))!=0)   
				{
					//LCD_WriteData(colorF);
					LCD_LCDLIDDCS0DATA = (colorF>>8); 	
 					LCD_LCDLIDDCS0DATA = colorF; 	
				} 
				else
				{
					//LCD_WriteData(colorB);
					LCD_LCDLIDDCS0DATA = (colorB>>8); 	
 					LCD_LCDLIDDCS0DATA = colorB; 
				}   													
			}
		temp++;			
		}	
}	


//  ----------------------------------------------------------------------- * 
void print( char *st, int x, int y,const byte* data, Int16 colorF , Int16 colorB )
{		
	int stl, i;

	stl = strlen(st);

	for (i=0; i<stl; i++)
	{						
		printChar(*st++, x + (i*(data[0])), y,data,colorF ,colorB );						           
	}		
}



//  ----------------------------------------------------------------------- * 
void drawButtonShift(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int color1,unsigned int color2,unsigned int color3, char *st, unsigned int x3,unsigned int y3)
{
	fillRoundRect(x1,y1,x2,y2,color1);	
	drawRoundRect(x1+1,y1+1,x2-1,y2-1,CYAN);  	   				 				 				 				 			             	        				 				 				 	        	        	        			             	    
	drawRoundRect(x1,y1,x2,y2,color2);				 				 				 				 			             	        				 				 				 	        	        	        			             	     			
	print(st,x1+x3,y1+y3,Font16x24,color3,color1);
}

//  ----------------------------------------------------------------------- * 
void drawButtonClock(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int color1,unsigned int color2,unsigned int color3, char *st)
{
	fillRoundRect(x1,y1,x2,y2,color1);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
	drawRoundRect(x1,y1,x2,y2,color2);				 				 				 				 			             	        				 				 				 	        	        	        			             	     			
	print(st,x1+29,y1+5,Font16x24,color3,color1);
}

//  ----------------------------------------------------------------------- * 
void drawButton(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int color1,unsigned int color2,unsigned int color3, char *st)
{
	fillRoundRect(x1,y1,x2,y2,color1);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
	drawRoundRect(x1,y1,x2,y2,color2);				 				 				 				 			             	        				 				 				 	        	        	        			             	     			
	print(st,x1+19,y1+10,Font16x24,color3,color1);
}


//  ----------------------------------------------------------------------- * 
void drawButtonRus(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int color1,unsigned int color2,unsigned int color3, char *st)
{
	fillRoundRect(x1,y1,x2,y2,color1);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
	drawRoundRect(x1,y1,x2,y2,color2);				 				 				 				 			             	        				 				 				 	        	        	        			             	     			
	print(st,x1+7,y1+13,FontRus8x15,color3,color1);
}


//  ----------------------------------------------------------------------- * 
void drawButtonRusCal(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int color1,unsigned int color2,unsigned int color3, char *st)
{
	fillRoundRect(x1,y1,x2,y2,color1);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
	drawRoundRect(x1,y1,x2,y2,color2);				 				 				 				 			             	        				 				 				 	        	        	        			             	     			
	print(st,x1+5,y1+10,FontRus8x15,color3,color1);
}

//  ----------------------------------------------------------------------- * 
void drawButtonNon(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2,unsigned int color1,unsigned int color2)
{
	fillRoundRect(x1,y1,x2,y2,color1);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
	drawRoundRect(x1,y1,x2,y2,color2);				 				 				 				 			             	        				 				 				 	        	        	        			             	     				
}



//  ----------------------------------------------------------------------- * 
void printNumI(long num, int x, int y,const byte* data, Int16 colorF , Int16 colorB)
{
  int i = 0;
  char buf[25];
  char st[27];              
  char neg=0;
  int c=0;    
  if (num==0)
  {
	  st[0]=48;
	  st[1]=0;
  }  
  else  
  {
	  if (num<0)
	  {
		neg=1;
		num=-num;
	  }
	  
	  while (num>0)
	  {
		buf[c]=48+(num % 10);
		c++;
		num=(num-(num % 10))/10;
	  }
	  buf[c]=0;
	  
	  if (neg==1)
	  {
		st[0]=45;
	  }
	  
	  for (i=0; i<c; i++)
	  {
		st[i+neg]=buf[c-i-1];
	  }
	  st[c+neg]=0;
  }
  print(st,x,y,data,colorF,colorB);
}




//  ----------------------------------------------------------------------- * 
void printNumUI(unsigned long num, int x, int y,const byte* data, Int16 colorF , Int16 colorB)
{
  int i = 0;
  char buf[11];
  char st[11];              
  int c=0;    
  if (num==0)
  {
	  st[0]=48;
	  st[1]=0;
  }  
  else  
  {
	  	 
	  while (num>0)
	  {
		buf[c]=48+(num % 10);
		c++;
		num=(num-(num % 10))/10;
	  }
	  buf[c]=0;
	  
	  
	  
	  for (i=0; i<c; i++)
	  {
		st[i]=buf[c-i-1];
	  }
	  st[c]=0;
  }
  
  
  
  print(st,x,y,data,colorF,colorB);
}







//  ----------------------------------------------------------------------- * 
void printNumF(double num, byte dec, int x, int y,const byte* data, Int16 colorF , Int16 colorB)
{
  int i,j;
  char buf[25];
  char st[27];
  char neg=0;
  int c=0;
  int c2;
  unsigned long inum;
  
  if (num==0)
  {
	  st[0]=48;
	  st[1]=46;
	  for ( i=0; i<dec; i++)
		  st[2+i]=48;
	  st[2+dec]=0;
  }
  else
  {
	  if (num<0)
	  {
		neg=1;
		num=-num;
	  }
	  
	  if (dec<1)
		dec=1;
	  if (dec>5)
		dec=5;
	  
	  inum=(long)(num*pow(10,dec));
	  
	  while (inum>0)
	  {
		buf[c]=48+(inum % 10);
		c++;
		inum=(inum-(inum % 10))/10;
	  }
	  
	  
	  j=dec-c+1;
	  
	  ///////////////////////
	  if ((num<1) && (num>0))
	  {	  		  	  	  		  		
	  	
	  	for ( i=0; i<j; i++)
	  	{			  		  		  	
		 buf[c]=48;
		 c++;
	  	}
	  	 		  		
	  }
	  buf[c]=0;
	  ////////////////////////
	  
	  
	  
	  if (neg==1)
	  {
		st[0]=45;
	  }
	  
	  c2=neg;
	  for ( i=0; i<c; i++)
	  {
		st[c2]=buf[c-i-1];
		c2++;
		if ((c-(c2-neg))==dec)
		{
		  st[c2]=46;
		  c2++;
		}
	  }
	  st[c2]=0;
  }

  print(st,x,y,data,colorF,colorB);
}

















/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  EVM5515_wait( delay )                                                   *
 *                                                                          *
 *      Wait in a software loop for 'x' delay                               *
 *                                                                          *
 * ------------------------------------------------------------------------ */
void wait( Uint32 delay )
{
    volatile Uint32 i;
    for ( i = 0 ; i < delay ; i++ ){ };
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _waitusec( usec )      3.54 x 10 -6 sec  = 1                                                 *
 *                                                                          *
 *      Wait in a software loop for 'x' microseconds                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
void waitusec( Uint32 usec )
{
    EVM5515_wait( (Uint32)usec * 8 );
}







//  ----------------------------------------------------------------------- * 
void LCD_HardwareScroll(int y)
{
    while (y < 0)
        y += 320;
    while (y >= 320)
        y -= 320;
    LCD_WriteReg(0x6a,y);
}    




//  ----------------------------------------------------------------------- * 
void LCD_Clear_ScrollUp(byte delay_between, unsigned int color)
{
	int i;			
  	for (i=1; i <= 320; i++) {    
    LCD_HardwareScroll(i);
    //LCD_HorLine(0,239,i-1,color);    
    waitusec(delay_between);    
  }
  LCD_HardwareScroll(0);
}  



//  ----------------------------------------------------------------------- * 
void LCD_Clear_ScrollDown(byte delay_between, unsigned int color)
{	
	int i;
  	for (i=-1; i >= -320; i--) {    
    //LCD_HorLine(0,239,320+i,color);  
    LCD_HardwareScroll(i);  
    waitusec(delay_between);    
  }
  LCD_HardwareScroll(0);  
} 









/*

void LCD_BAT_ZAR(unsigned int x )
{	



	if(x < 100)					
	{					
		if(Temp_Bat == 0)					
		{				
			Temp_Bat = 1;
														
			drawBitmap(299,5,3,10,bat_smallzr);   		   				   		      	     		                             		       		             
    		drawBitmap(303,5,3,10,bat_smallzr); 
	    	drawBitmap(307,5,3,10,bat_smallzr); 
	    	drawBitmap(311,5,3,10,bat_smallzr); 
    		drawBitmap(315,5,3,10,bat_smallzr);
		}
    	else if(Temp_Bat == 1)					
		{					
			Temp_Bat = 0;
											
			drawBitmap(299,5,3,10,bat_smallz);   		   				   		      	     		                             		       		             
    		drawBitmap(303,5,3,10,bat_smallz); 
	    	drawBitmap(307,5,3,10,bat_smallz); 
	    	drawBitmap(311,5,3,10,bat_smallz); 
    		drawBitmap(315,5,3,10,bat_smallz); 	   											      	        	               					        
		}	    	    
		else 			
		{					
   											      	        	               					        
		}	    
			    	    	 
	}	
	else if(x < 106)					
	{													
		drawBitmap(299,5,3,10,bat_smallz);   		   				   		      	     		                             		       		             
    	drawBitmap(303,5,3,10,bat_smallz); 
	    drawBitmap(307,5,3,10,bat_smallz); 
	    drawBitmap(311,5,3,10,bat_smallz); 
    	drawBitmap(315,5,3,10,bat_smallz); 	   											      	        	               					        
	}	
	else if(x < 112)
	{													
		drawBitmap(299,5,3,10,bat_smallz);   		   				   		      	     		                             		       		             
    	drawBitmap(303,5,3,10,bat_smallz); 
	    drawBitmap(307,5,3,10,bat_smallz); 
	    drawBitmap(311,5,3,10,bat_smallz); 
    	drawBitmap(315,5,3,10,bat_small);   											      	        	               					        
	}	
	else if(x <= 118)
	{													
		drawBitmap(299,5,3,10,bat_smallz);   		   				   		      	     		                             		       		             
    	drawBitmap(303,5,3,10,bat_smallz); 
	    drawBitmap(307,5,3,10,bat_smallz); 
	    drawBitmap(311,5,3,10,bat_small); 
    	drawBitmap(315,5,3,10,bat_small); 	   											      	        	               					        
	}				     
	else if(x < 124)
	{													
		drawBitmap(299,5,3,10,bat_smallz);   		   				   		      	     		                             		       		             
    	drawBitmap(303,5,3,10,bat_smallz); 
	    drawBitmap(307,5,3,10,bat_small); 
	    drawBitmap(311,5,3,10,bat_small); 
    	drawBitmap(315,5,3,10,bat_small);    											      	        	               					        
	}				   
	else if(x < 130)
	{													
		drawBitmap(299,5,3,10,bat_smallz);   		   				   		      	     		                             		       		             
    	drawBitmap(303,5,3,10,bat_small); 
	    drawBitmap(307,5,3,10,bat_small); 
	    drawBitmap(311,5,3,10,bat_small); 
    	drawBitmap(315,5,3,10,bat_small);       											      	        	               					        
	}	
	else if(x < 140)
	{													
		drawBitmap(299,5,3,10,bat_small);   		   				   		      	     		                             		       		             
    	drawBitmap(303,5,3,10,bat_small); 
	    drawBitmap(307,5,3,10,bat_small); 
	    drawBitmap(311,5,3,10,bat_small); 
    	drawBitmap(315,5,3,10,bat_small);       											      	        	               					        
	}	
	else
	{													
		drawBitmap(299,5,3,10,bat_small);   		   				   		      	     		                             		       		             
    	drawBitmap(303,5,3,10,bat_small); 
	    drawBitmap(307,5,3,10,bat_small); 
	    drawBitmap(311,5,3,10,bat_small); 
    	drawBitmap(315,5,3,10,bat_small);       											      	        	               					        
	}		
	
	
	
				

}


*/







#endif  

