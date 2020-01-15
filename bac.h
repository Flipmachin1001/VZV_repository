
			asm(" bclr XF");  
			asm(" bset XF");
			asm(" bclr XF");  
			asm(" bset XF");
			asm(" bclr XF");  
			asm(" bset XF");
			asm(" bclr XF");  
			asm(" bset XF");
			asm(" bclr XF");  
			asm(" bset XF");
			asm(" bclr XF");  
			asm(" bset XF");
			asm(" bclr XF");  
			asm(" bset XF");
			asm(" bclr XF");  
			asm(" bset XF");
			
			
			
			
	
	waitusec( 100000 );
			
					
		asm(" bset XF");
        
        
        waitusec( 100000 );
        
        
		asm(" bclr XF");  
		
			
		waitusec( 100000 );
			
					
		asm(" bset XF");
        
        
        waitusec( 100000 );
        
        
		asm(" bclr XF");  
		
						
		waitusec( 100000 );
			
					
		asm(" bset XF");
        
        
        waitusec( 100000 );
        
        
		asm(" bclr XF");  
		
		
		waitusec( 100000 );
			
					
		asm(" bset XF");
        
        
        waitusec( 100000 );
        
        
		asm(" bclr XF");  
		
			
		waitusec( 100000 );
			
					
		asm(" bset XF");
        
        
        waitusec( 100000 );
        
        
		asm(" bclr XF");  
		
						
		waitusec( 100000 );
			
					
		asm(" bset XF");
        
        
        waitusec( 100000 );
        
        
		asm(" bclr XF");  
		
		
 			
		waitusec( 100000 );
			
					
		asm(" bset XF");
        
        
        waitusec( 100000 );
        
        
		asm(" bclr XF");  
		
			
		waitusec( 100000 );
			
					
		asm(" bset XF");
        
        
        waitusec( 100000 );
        
        
		asm(" bclr XF");  
		
						
		waitusec( 100000 );
			
					
		asm(" bset XF");
        
        
        waitusec( 100000 );
        
        
		asm(" bclr XF");  




















void printChar4( byte c, int x, int y, const byte* data, Int16 colorF , Int16 colorB )
{
	byte i,j,ch;
	word temp; 

 	byte  x_size,y_size,offset;//,numchars;

		x_size=data[0];
		y_size=data[1];
		offset=data[2];
		//numchars=data[3];





		//1111111111111111111111111111111111111111
		LCD_SetCursor(x,y);
		setXY(x,y,x+x_size-1,y+y_size-1);
	 	
		temp=((c-offset)*((x_size/8)*y_size))+4;
		for(j=0;j<((x_size/8)*y_size);j++)
		{
									
			ch=data[temp];
			//ch=SevenSegNumFont[temp];	
					
			for(i=0;i<8;i++)
			{   
				if((ch&(1<<(7-i)))!=0)   
				{
					  LCD_WriteData(colorF);
				} 
				else
				{
					  LCD_WriteData(colorB);
				}   
			}
		temp++;			
		}	
		//111111111111111111111111111111111111111111
		
		
		
		
		//222222222222222222222222222222222222222222
		LCD_SetCursor(x+x_size,y);
		setXY(x+x_size,y,x+x_size-1+x_size,y+y_size-1);
	 	
		temp=((c-offset)*((x_size/8)*y_size))+4;
		for(j=0;j<((x_size/8)*y_size);j++)
		{
									
			ch=data[temp];
			//ch=SevenSegNumFont[temp];	
					
			for(i=0;i<8;i++)
			{   
				if((ch&(1<<(7-i)))!=0)   
				{
					  LCD_WriteData(colorF);
				} 
				else
				{
					  LCD_WriteData(colorB);
				}   
			}
		temp++;			
		}	
		//22222222222222222222222222222222222222222
		
		//33333333333333333333333333333333333333333
		LCD_SetCursor(x+x_size+x_size,y);
		setXY(x+x_size+x_size,y,x+x_size-1+x_size+x_size,y+y_size-1);
	 	
		temp=((c-offset)*((x_size/8)*y_size))+4;
		for(j=0;j<((x_size/8)*y_size);j++)
		{
									
			ch=data[temp];
			//ch=SevenSegNumFont[temp];	
					
			for(i=0;i<8;i++)
			{   
				if((ch&(1<<(7-i)))!=0)   
				{
					  LCD_WriteData(colorF);
				} 
				else
				{
					  LCD_WriteData(colorB);
				}   
			}
		temp++;			
		}	
		//333333333333333333333333333333333333333333
		
		
		
		
		
		
		//44444444444444444444444444444444444444444
		LCD_SetCursor(x+x_size+x_size+x_size,y);
		setXY(x+x_size+x_size+x_size,y,x+x_size-1+x_size+x_size+x_size,y+y_size-1);
	 	
		temp=((c-offset)*((x_size/8)*y_size))+4;
		for(j=0;j<((x_size/8)*y_size);j++)
		{
									
			ch=data[temp];
			//ch=SevenSegNumFont[temp];	
					
			for(i=0;i<8;i++)
			{   
				if((ch&(1<<(7-i)))!=0)   
				{
					  LCD_WriteData(colorF);
				} 
				else
				{
					  LCD_WriteData(colorB);
				}   
			}
		temp++;			
		}	
		//4444444444444444444444444444444444444444
		
		
		
			//55555555555555555555555555555555555555
		LCD_SetCursor(x+x_size+x_size+x_size+x_size,y);
		setXY(x+x_size+x_size+x_size+x_size,y,x+x_size-1+x_size+x_size+x_size+x_size,y+y_size-1);
	 	
		temp=((c-offset)*((x_size/8)*y_size))+4;
		for(j=0;j<((x_size/8)*y_size);j++)
		{
									
			ch=data[temp];
			//ch=SevenSegNumFont[temp];	
					
			for(i=0;i<8;i++)
			{   
				if((ch&(1<<(7-i)))!=0)   
				{
					  LCD_WriteData(colorF);
				} 
				else
				{
					  LCD_WriteData(colorB);
				}   
			}
		temp++;			
		}	
		//5555555555555555555555555555555555555555555
							
}




















/*
void draw_font(Uint16 x, Uint16 y, Uint16 font, Int16 colorF, Int16 colorB)
{
    Uint16  i, j,bit;
    unsigned char *pData, data;    
    pData = lcdFontTable;

    for(i=0; i<8; i++)
    {
        data = *(pData + (font - ' ')*8  + i);         
        for(j=0; j<8; j++)
        {


		LCD_SetCursor(x+j,y+i);
		setXY(x+j,y+i,x+j,y+i);

    	   	
            bit = data&(0x80>>j);
            if(bit == 0)
            {               
				LCD_WriteData(colorB);
            }
            else
            {
				LCD_WriteData(colorF);
            }		   
        }
    }
}





void draw_string (Uint16 x, Uint16 y, char *pData,Int16 colorF , Int16 colorB)
{
    Uint16 font, i=0;
    
    
	font = strlen(pData);
    if(i > 8)
        return;
        
    while(1)
    {
        font = *(pData+i);
        if(font != 0)
        {
            draw_font(x+i*8,y,font,colorF,colorB);
            i++;
        }
        else
        {
            break;
        }
    }
}





*/







/*





void setFont888(const byte* data)
{
	
	
	byte  x_size,y_size,offset;
	
	
	x_size=data[0];
	y_size=data[1];
	offset=data[2];
	
	
	
	//cfont.x_size=pgm_read_byte(&cfont.font[0]);
	//cfont.y_size=pgm_read_byte(&cfont.font[1]);
	//cfont.offset=pgm_read_byte(&cfont.font[2]);
	//cfont.numchars=pgm_read_byte(&cfont.font[3]);
}










//////////////////////////////////////////////////////////////


void printChar888(byte c, int x, int y)
{
	byte i,j,ch,x_size,y_size,offset;
	word temp; 

		
	
	
	x_size=SevenSegNumFont[0];
	y_size=SevenSegNumFont[1];
	offset=SevenSegNumFont[2];
  
		LCD_SetCursor(x,y);
		setXY(x,y,x+x_size-1,y+y_size-1);
	  
		temp=((c-offset)*((x_size/8)*y_size))+4;
		for(j=0;j<((x_size/8)*y_size);j++)
		{
			
			
			///////ch=pgm_read_byte(&cfont.font[temp]);
			
			//ch=data[temp];
			ch=SevenSegNumFont[temp];	
					
			for(i=0;i<8;i++)
			{   
				
				
				
				
				if((ch&(1<<(7-i)))!=0)   
				{
					  LCD_WriteData(RED);
				} 
				else
				{
					  LCD_WriteData(GREEN);
				}   
				
				
				
				
			}
		temp++;			
		}
	
}	




//////////////////////////////////////////////////////////






void print888(char *st, int x, int y)
{
	
	byte x_size;
	
	
	int stl, i;

	stl = strlen(st);

	setFont888(SevenSegNumFont);
	
	
	

	for (i=0; i<stl; i++)
		
			printChar888(*st++, x + (i*(x_size)), y);
		
}



*/








//print(" ! #$%&`()*+,-./",0,160,Font16x24,BLACK,WHITE);
	//print("0123456789:;<=>?",0,180,Font16x24,BLACK,WHITE);
	//print("@ABCDEFGHIJKLMNO",0,200,Font16x24,BLACK,WHITE);
	//print("PQRSTUVWXYZ[ ]^_",0,220,Font16x24,BLACK,WHITE);
	//print("`adcdefghijklmno",0,240,Font16x24,BLACK,WHITE);
	//print("pqrstuvwxyz{|}~",0,260,Font16x24,BLACK,WHITE);	
	
	//print(0,200,"¿¡¬√ƒ≈∆«»… ÀÃÕŒœ",BLACK,WHITE);		
	//print(0,210,"–—“”‘’÷◊ÿŸ⁄€‹›ﬁﬂ",BLACK,WHITE);		
	//print(0,230,"‡·‚„‰Â∏ÊÁËÍÎÏÌÓÔ",BLACK,WHITE);					
	//print(0,240,"ÒÚÛÙıˆ˜¯˘˙˚¸˝˛ˇ",BLACK,WHITE);	
	





/*


		LCD_color(WHITE);
		  		               					           		                        
		LCD_PutPixel(160,120,RED); 	
		wait1( 10000000 );   				   		      	     		                             		       		             
    	LCD_color(WHITE);	
			 		               					           		                        
		drawHLine(0,120,319,RED);	
		wait1( 10000000 );   				   		      	     		                             		       		             
  		LCD_color(WHITE);
		 		               					           		                       
		drawVLine(160,0,239,BLUE);
		wait1( 10000000 );   				   		      	     		                             		       		             
   		LCD_color(WHITE);
		
		drawLinen(0,0,319,239,RED);
		wait1( 10000000 );   				   		      	     		                             		       		             
    	LCD_color(WHITE);
    	    
    	drawLinen(319,0,0,239,RED);
		wait1( 10000000 );   				   		      	     		                             		       		             
    	LCD_color(WHITE);
    	    	    	   
    	for(e=0; e < 200; e++)        
    	{       		               					           		                         
			drawVLine(i,0,239,BLUE);
			wait1( 100000 );   				   		      	     		                             		       		             
    	}		
    	LCD_color(WHITE);
    	    	    
    	for(e=0; e < 200; e++)        
    	{       		               					           		                         
			drawHLine(0,i,319,RED);
			wait1( 100000 );   				   		      	     		                             		       		             
    	}		
    	LCD_color(WHITE);
    					               					           		                     
		LCD_Rectangle(100,100,200,200,YELLOW);
		wait1( 10000000 );   				   		      	     		                             		       		             
    	LCD_color(WHITE);
		               					           		                        
		drawRect(100,100,200,200,RED);
		wait1( 10000000 );   				   		      	     		                             		       		             
  		LCD_color(WHITE);
   
  		fillRect(100,100,200,200,MAGENTA);
		wait1( 10000000 );   
		LCD_color(WHITE);
  
    	fillRoundRect(100,100,200,200,MAGENTA);
		wait1( 10000000 );   
		LCD_color(WHITE);
  
      	drawRoundRect(100,100,200,200,RED);
		wait1( 10000000 );   
		LCD_color(WHITE);
                     		               					           		                 
		drawCircle(160, 120, 120, CYAN);
		wait1( 10000000 );   				   		      	     		                             		       		                	  
  		LCD_color(WHITE);
  
   		               					           		                         
		drawCircle(160, 120, 120, BROWN);
		wait1( 10000000 );   				   		      	     		                             		       		             
		LCD_color(WHITE);
  
	for(e=0; e < 120; e++)        
    {       		               					           		                         
		fillCirclen(160, 120, e, RED);
		wait1( 50000 );   				   		      	     		                             		       		             
    }		
	
	for(e=0; e < 120; e++)        
    {       		               					           		                         
		fillCirclen(160, 120, e, BLUE);
		wait1( 50000 );   				   		      	     		                             		       		             
    }
			
	for(e=0; e < 120; e++)        
    {       		               					           		                         
		fillCirclen(160, 120, e, GREEN);
		wait1( 50000 );   				   		      	     		                             		       		             
    }
	
	for(e=0; e < 120; e++)        
    {       		               					           		                         
		fillCirclen(160, 120, e, MAGENTA);
		wait1( 50000 );   				   		      	     		                             		       		             
    }
	
	LCD_color(WHITE);
		
	wait1( 1000000 );	
		
	print("1234",100,100,Num16x24,BLACK,WHITE);   
	wait1( 10000000 );
	LCD_color(WHITE);
	print("1234",50,70,Num32x50,BLACK,WHITE);   
	wait1( 10000000 );
	LCD_color(WHITE);	
	print("1234",20,50,Num48x61,BLACK,WHITE);   
	wait1( 10000000 );
	LCD_color(WHITE);	
	print("1234",0,30,Num64x100,BLACK,WHITE);   
	wait1( 10000000 );	
	LCD_color(WHITE);
		
	for(e=0; e < 300; e++)        
    {       		               					           		                         
		printNumUI(e,20,30,Num64x100,BLACK,WHITE);   
		wait1( 50000 );	
		//LCD_color(WHITE);		   				   		      	     		                             		       		            
    }
	LCD_color(WHITE);	
		
	print("¬»¡–Œ—“≈Õƒ ¬«¬",100,50,FontRus8x15,BLACK,WHITE);   
	wait1( 10000000 );	
	LCD_color(WHITE);
		
	print("¬»¡–Œ—“≈Õƒ ¬«¬",40,50,FontRus16x27,RED,WHITE);	
	wait1( 5000000 );
	LCD_color(WHITE);	
		
	print("¬»¡–Œ—“≈Õƒ ¬«¬",40,50,FontRus16x27,BLUE,WHITE);	
	wait1( 5000000 );
	LCD_color(WHITE);
		
	print("¬»¡–Œ—“≈Õƒ ¬«¬",40,50,FontRus16x27,MAGENTA,WHITE);	
	wait1( 5000000 );
	LCD_color(WHITE);
		
	print("¬»¡–Œ—“≈Õƒ ¬«¬",40,50,FontRus16x27,YELLOW,WHITE);	
	wait1( 5000000 );
	LCD_color(WHITE);
		
	wait1( 10000000 );				
	LCD_color(BLUE);
	wait1( 10000000 );	
	LCD_color(GREEN);
	wait1( 10000000 );
	LCD_color(CYAN);
	wait1( 10000000 );	
	LCD_color(RED);
	wait1( 10000000 );
	LCD_color(MAGENTA);
	wait1( 10000000 );
	LCD_color(YELLOW);	
	wait1( 10000000 );	
	LCD_color(BLACK);	
	wait1( 10000000 );
	
	
	
	*/



			