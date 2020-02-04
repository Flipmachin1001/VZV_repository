#ifndef _MENU_H_
#define _MENU_H_

//------------------
char BufRTC[13];
Uint8 KurRTC  = 1;
Uint8 Regim_Ccalc = 1;
Uint8 Opera_Ccalc = 0;
Int8  liht = 15;
Int8  liht2 = 0;
Uint32 code = 0;

Uint16 LifeTime = 0;
Uint8 SecondsOnWork = 0;
Uint8 MinuntsOnWork = 0;
Uint16 HoursOnWork = 0;

Uint8 CalibrDate[3];
Uint16 regim = 0;
int MenuCursor;
Uint8 MenuLevel;

Uint32 reg_acseleration = 0;
Uint32 reg_frequency = 640;
Uint32 reg_velosity = 0;
Uint32 reg_displacement = 0;
Uint32 acseleration = 0;
Uint32 velosity = 0;
Uint32 displacement = 0;


double Ccalc_operand_1=0;
double Ccalc_operand_2=0;
double Ccalc_rezult=0;

int PCF8574Test, LM73Adr1Test, LM73Adr2Test, LM73Adr3Test, KeyBoardTest, PowerAmplTest, BatRTest;

void EnableTarget1(void)
{
        		fillCirclen(20,41,11,RED);
				fillCirclen(20,41,7,WHITE);
				fillCirclen(20,41,4,BLACK);											
				drawHLine(5,41,30,BLACK);
				drawVLine(20,26,30,BLACK);
}


void EnableTarget2(void)
{
				fillCirclen(219,298,11,RED);
				fillCirclen(219,298,7,WHITE);
				fillCirclen(219,298,4,BLACK);											
				drawHLine(204,298,30,BLACK);
				drawVLine(219,283,30,BLACK);
}




void ButtonRegim(void)
{		
				fillRoundRect(14,249,14+52,249+51,BLUE);
				drawRoundRect(14,249,14+52,249+51,BLACK);
}

void ButtonMenu(void)
{		
				fillRoundRect(94,249,94+52,249+51,BLACK);
				drawRoundRect(94,249,94+52,249+51,BLACK);
}


void ButtonPower(void)
{		
				fillRoundRect(174,249,174+52,249+51,RED);
				drawRoundRect(174,249,174+52,249+51,BLACK);
}


        	

void ButtonMarks(void)
{		
				fillRoundRect(1,25,238,135,WHITE);
				drawRoundRect(1,25,238,135,BLACK);
							
				drawButtonRusCal(1+20*0,140,18+20*0,170,WHITE,BLACK,BLACK,"й");  
				drawButtonRusCal(1+20*1,140,18+20*1,170,WHITE,BLACK,BLACK,"ц");  									
				drawButtonRusCal(1+20*2,140,18+20*2,170,WHITE,BLACK,BLACK,"у"); 
				drawButtonRusCal(1+20*3,140,18+20*3,170,WHITE,BLACK,BLACK,"к"); 
				drawButtonRusCal(1+20*4,140,18+20*4,170,WHITE,BLACK,BLACK,"е"); 
				drawButtonRusCal(1+20*5,140,18+20*5,170,WHITE,BLACK,BLACK,"н"); 
				drawButtonRusCal(1+20*6,140,18+20*6,170,WHITE,BLACK,BLACK,"г"); 															
				drawButtonRusCal(1+20*7,140,18+20*7,170,WHITE,BLACK,BLACK,"ш");  									
				drawButtonRusCal(1+20*8,140,18+20*8,170,WHITE,BLACK,BLACK,"щ"); 
				drawButtonRusCal(1+20*9,140,18+20*9,170,WHITE,BLACK,BLACK,"з"); 
				drawButtonRusCal(1+20*10,140,18+20*10,170,WHITE,BLACK,BLACK,"х"); 
				drawButtonRusCal(1+20*11,140,18+20*11,170,WHITE,BLACK,BLACK,"ъ"); 	
								
				drawButtonRusCal(11+20*0,175,28+20*0,205,WHITE,BLACK,BLACK,"ф");  
				drawButtonRusCal(11+20*1,175,28+20*1,205,WHITE,BLACK,BLACK,"ы");  									
				drawButtonRusCal(11+20*2,175,28+20*2,205,WHITE,BLACK,BLACK,"в"); 
				drawButtonRusCal(11+20*3,175,28+20*3,205,WHITE,BLACK,BLACK,"а"); 
				drawButtonRusCal(11+20*4,175,28+20*4,205,WHITE,BLACK,BLACK,"п"); 
				drawButtonRusCal(11+20*5,175,28+20*5,205,WHITE,BLACK,BLACK,"р"); 
				drawButtonRusCal(11+20*6,175,28+20*6,205,WHITE,BLACK,BLACK,"о"); 															
				drawButtonRusCal(11+20*7,175,28+20*7,205,WHITE,BLACK,BLACK,"л");  									
				drawButtonRusCal(11+20*8,175,28+20*8,205,WHITE,BLACK,BLACK,"д"); 
				drawButtonRusCal(11+20*9,175,28+20*9,205,WHITE,BLACK,BLACK,"ж"); 
				drawButtonRusCal(11+20*10,175,28+20*10,205,WHITE,BLACK,BLACK,"э"); 
											
				drawButtonRusCal(1+20*0,210,18+20*0,240,BLUE3,BLACK,BLACK," ");  
				drawButtonRusCal(1+20*1,210,18+20*1,240,WHITE,BLACK,BLACK,"я");  									
				drawButtonRusCal(1+20*2,210,18+20*2,240,WHITE,BLACK,BLACK,"ч"); 
				drawButtonRusCal(1+20*3,210,18+20*3,240,WHITE,BLACK,BLACK,"с"); 
				drawButtonRusCal(1+20*4,210,18+20*4,240,WHITE,BLACK,BLACK,"м"); 
				drawButtonRusCal(1+20*5,210,18+20*5,240,WHITE,BLACK,BLACK,"и"); 
				drawButtonRusCal(1+20*6,210,18+20*6,240,WHITE,BLACK,BLACK,"т"); 															
				drawButtonRusCal(1+20*7,210,18+20*7,240,WHITE,BLACK,BLACK,"ь");  									
				drawButtonRusCal(1+20*8,210,18+20*8,240,WHITE,BLACK,BLACK,"б"); 
				drawButtonRusCal(1+20*9,210,18+20*9,240,WHITE,BLACK,BLACK,"ю"); 
				drawButtonRusCal(1+20*10,210,18+20*10,240,WHITE,BLACK,BLACK,"е"); 
				drawButtonRusCal(1+20*11,210,18+20*11,240,BLUE3,BLACK,BLACK," "); 	
										
				drawButtonRusCal(1,245,58,275,WHITE,BLACK,BLACK,"Цифры");  				 			
				drawButtonRusCal(61,245,138,275,WHITE,BLACK,BLACK," Пробел");				 															
				drawButtonRusCal(141,245,178,275,WHITE,BLACK,BLACK," Ру");  																
				drawButtonRusCal(181,245,18+20*11,275,WHITE,BLACK,BLACK," Ввод"); 				 									
}



void ButtonCalk(void)
{		
				fillRoundRect(4,25,235,94,WHITE);
				drawRoundRect(4,25,235,94,BLACK);
				
			  	drawButton(4,99,58,138,BROWN,BLACK,BLACK,"C");   	
				drawButton(63,99,117,138,BROWN,BLACK,BLACK,"%");  
				drawButton(122,99,176,138,BROWN,BLACK,BLACK,"<");  
				drawButton(181,99,235,138,BROWN,BLACK,BLACK,"+"); 
	
		  		drawButton(4,143,58,182,WHITE,BLACK,BLACK,"7");   	
				drawButton(63,143,117,182,WHITE,BLACK,BLACK,"8");  
				drawButton(122,143,176,182,WHITE,BLACK,BLACK,"9");  
				drawButton(181,143,235,182,BROWN,BLACK,BLACK,"-");  
		
	  			drawButton(4,187,58,226,WHITE,BLACK,BLACK,"4");   	
				drawButton(63,187,117,226,WHITE,BLACK,BLACK,"5");  
				drawButton(122,187,176,226,WHITE,BLACK,BLACK,"6");  
				drawButton(181,187,235,226,BROWN,BLACK,BLACK,"*");  
		
  				drawButton(4,231,58,270,WHITE,BLACK,BLACK,"1");   	
				drawButton(63,231,117,270,WHITE,BLACK,BLACK,"2");  
				drawButton(122,231,176,270,WHITE,BLACK,BLACK,"3");  
				drawButton(181,231,235,270,BROWN,BLACK,BLACK,"/");  
	
				drawButton(4,275,58,314,WHITE,BLACK,BLACK,"0");   	
				drawButton(63,275,117,314,WHITE,BLACK,BLACK,".");  
				drawButton(122,275,176,314,GREEN,BLACK,BLACK,"=");  
								
				drawButtonRus(181,275,235,314,BLUE7,BLACK,WHITE,"Назад");  				
}





void ButtonBack(void)
{											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("Назад",185,295-1,FontRus8x15,WHITE,BLUE7); 
}

void ButtonNewBack(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("Создать",10,295-1,FontRus8x15,WHITE,BLUE7); 
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("Назад",185,295-1,FontRus8x15,WHITE,BLUE7); 
}


void ButtonSaveBack(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("Сохранить",2,295-1,FontRus8x15,WHITE,BLUE7); 
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("Назад",185,295-1,FontRus8x15,WHITE,BLUE7); 
}







void ButAdd(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("Добавить",6,294,FontRus8x15,WHITE,BLUE7);
}







void ButClear(void)
{
				fillRoundRect(0+9+74,280,0+74+9+74,319,YELLOW);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74,280,0+74+9+74,319,BLACK);	
				print("Сброс",85+17,295-1,FontRus8x15,BLACK,YELLOW); 
}


void ButStop(void)
{
				fillRoundRect(0,280,0+74,319,GREEN);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("Стоп",23,294,FontRus8x15,WHITE,GREEN);
}

void ButZapusk(void)
{
				fillRoundRect(0,280,0+74,319,GREEN);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("Старт",19,294,FontRus8x15,BLACK,GREEN);
}


void ButInter(void)
{
				fillRoundRect(0+9+74,280,0+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74,280,0+74+9+74,319,BLACK);	
				print("Интервал",85,295-1,FontRus8x15,WHITE,BLUE7); 
} 


void ButBack(void)
{
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("Назад",185,295-1,FontRus8x15,WHITE,BLUE7); 
}


void ButtonZapuskInterBack(void)
{
				ButZapusk();
				ButInter();
				ButBack();
}


void ButtonZapuskClearBack(void)
{
				ButZapusk();
				ButClear();
				ButBack();
}


void ButtonAddBack(void)
{
				ButAdd();				
				ButBack();
}


void ButtonNastrBack(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("Настроить",2,295-1,FontRus8x15,WHITE,BLUE7);
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("Назад",185,295-1,FontRus8x15,WHITE,BLUE7); 
}


void ButtonSaveNastrBack(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("Сохранить",2,295-1,FontRus8x15,WHITE,BLUE7); 
		
				fillRoundRect(0+9+74,280,0+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74,280,0+74+9+74,319,BLACK);	
				print("Настроить",85,295-1,FontRus8x15,WHITE,BLUE7); 
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("Назад",185,295-1,FontRus8x15,WHITE,BLUE7); 
}

void ButtonSaveMenuBack(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("Сохранить",2,295-1,FontRus8x15,WHITE,BLUE7); 
		
				fillRoundRect(0+9+74,280,0+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74,280,0+74+9+74,319,BLACK);	
				print("Меню",105,295-1,FontRus8x15,WHITE,BLUE7); 
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("Назад",185,295-1,FontRus8x15,WHITE,BLUE7); 
}

void ButtonNastrMenuBack(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("Настроить",2,295-1,FontRus8x15,WHITE,BLUE7); 
		
				fillRoundRect(0+9+74,280,0+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74,280,0+74+9+74,319,BLACK);	
				print("Меню",105,295-1,FontRus8x15,WHITE,BLUE7); 
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("Назад",185,295-1,FontRus8x15,WHITE,BLUE7); 
}


void ButtonNastrRegimBack(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("Настроить",2,295-1,FontRus8x15,WHITE,BLUE7); 
		
				fillRoundRect(0+9+74,280,0+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74,280,0+74+9+74,319,BLACK);	
				print("Режим",105-4,295-1,FontRus8x15,WHITE,BLUE7); 
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("Назад",185,295-1,FontRus8x15,WHITE,BLUE7); 
}





void Button123(void)
{
	
		//sdReadGraphic( 0x3E000 );	
	
	   	//nand_readGrafic(0x1FEA0000, 0, 21,240,299 );  
		//nand_readGrafic(0x1FEA0000, 0, 0,240,320 );      
 	
 	/*	 	  	 	 		 		 	  	 	 		 		 	 	 	 	 	 	  	 	 	  	 	 	  	 	 	   	  	  	 
	LCD_Rectangle(0,0,239,20,GRAY4);	//Line 1	GRAY2	
	LCD_Rectangle(215,3,237,17,WHITE);  //Батарейка
	LCD_Rectangle(213,7,214,13,WHITE);	//Pupirka
	LCD_Rectangle(216,4,236,16,BLACK);  //Батарейка		
	//LCD_Rectangle(217,5,219,15,GREEN); 
	LCD_Rectangle(221,5,223,15,GREEN); 
	LCD_Rectangle(225,5,227,15,GREEN); 
	LCD_Rectangle(229,5,231,15,GREEN); 
	LCD_Rectangle(233,5,235,15,GREEN); 			
										
	print(":",162+20+4,3,Num8x15,WHITE,GRAY4); 		
	print(":",138+20+4,3,Num8x15,WHITE,GRAY4); 		
	print(".",19,3,Num8x15,WHITE,GRAY4); 		
	print(".",43,3,Num8x15,WHITE,GRAY4); 
	*/
	  
				//fillRoundRect(9+21,120-30,189+21,220-30,CYAN);                      
    			//drawRoundRect(9+21,120-30,189+21,220-30,BLACK); 	
				//print(":",90+6+21,148-30,Num8x15,BLACK,CYAN); 
					
				ButtonRegim();
        		print("Изменить",8,303,FontRus8x15,BLACK,WHITE);
				ButtonMenu(); 
				print("Меню",104,303,FontRus8x15,BLACK,WHITE);
				ButtonPower();				
				print("Питание",172,303,FontRus8x15,BLACK,WHITE);
}


void Button123_(void)
{
				ButtonRegim();
        		print("Изменить",8,303,FontRus8x15,BLACK,BLUE1);
				ButtonMenu(); 
				print("Меню",104,303,FontRus8x15,BLACK,BLUE1);
				ButtonPower();				
				print("Питание",172,303,FontRus8x15,BLACK,BLUE1);
}





void EnableTitleMenu(void)
{
				LCD_Rectangle(0,21,239,245,WHITE);
				
				fillRoundRect(14,26,14+52,26+52,RED);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(14,26,14+52,26+52,BLACK);	
				print("Ускорение",4,80+1,FontRus8x15,BLACK,WHITE); 					        	                              	                   
        		fillRoundRect(94,26,94+52,26+52,BLUE);                      
        		drawRoundRect(94,26,94+52,26+52,BLACK);                             		
        		print("Скорость",88,80+1,FontRus8x15,BLACK,WHITE);         	
        		fillRoundRect(174,26,174+52,26+52,GREEN);                      
        		drawRoundRect(174,26,174+52,26+52,BLACK);          		
        		print("Смещение",168,80+1,FontRus8x15,BLACK,WHITE); 
        	        	        
        		fillRoundRect(14,101,14+52,101+52,CYAN);                      
        		drawRoundRect(14,101,14+52,101+52,BLACK);          		
        		print("Заметки",12,155+1,FontRus8x15,BLACK,WHITE);         	
        		fillRoundRect(94,101,94+52,101+52,MAGENTA);                      
        		drawRoundRect(94,101,94+52,101+52,BLACK);          	        		
        		print("Калькулятор",76,155+1,FontRus8x15,BLACK,WHITE);         	
        		fillRoundRect(174,101,174+52,101+52,YELLOW);                      
        		drawRoundRect(174,101,174+52,101+52,BLACK);          	        		
        		print("Память",177,155+1,FontRus8x15,BLACK,WHITE);         	
        	        	        
        		fillRoundRect(14,176,14+52,176+52,BROWN);                      
        		drawRoundRect(14,176,14+52,176+52,BLACK);          	
        		print("Часы",24,230+1,FontRus8x15,BLACK,WHITE);         	
        		fillRoundRect(94,176,94+52,176+52,BRIGHTBLUE);                      
        		drawRoundRect(94,176,94+52,176+52,BLACK);          	        		
        		print("Конвертор",84,230+1,FontRus8x15,BLACK,WHITE);         	        	
        		fillRoundRect(174,176,174+52,176+52,GRAY2);                      
        		drawRoundRect(174,176,174+52,176+52,BLACK);          	  
        		print("Настройки",164,230+1,FontRus8x15,BLACK,WHITE);  
      	        	        	       
        		LCD_Rectangle(0,246,239,319,BLUE1);		
        		
        		
        		Button123_();
        		/*        		
        		drawBitmap (14,249,52,52,refresh);
				print("Изменить",8,302,FontRus8x15,BLACK,BLUE1);				
				drawBitmap (94,249,52,52,menu);
				print("Меню",104,302,FontRus8x15,BLACK,BLUE1);							
				drawBitmap (174,249,52,52,powerb);				
				print("Питание",172,302,FontRus8x15,BLACK,BLUE1);
				*/
				
												        
}








void Enable41(void)
{
				ButtonSaveBack();
}








void Enable90(void)
{
				LCD_Rectangle(0,21,239,319,BLUE1);
        	    LCD_Rectangle(0,21,239,24,BLUE);        	            	   
        	   	print("   Настройки   ",0,25,FontRus16x27,WHITE,BLUE);																
																										        	  						
											
				fillRoundRect(3,60,236,110,WHITE);
				drawRoundRect(3,60,236,110,BLACK);	
				print("Дисплей",20,74,FontRus16x27,BLACK,WHITE); 
																	
				fillRoundRect(3,115-1,236,165-1,WHITE);
				drawRoundRect(3,115-1,236,165-1,BLACK);
				print("Клавиатура",20,130-2,FontRus16x27,BLACK,WHITE); 
				
				fillRoundRect(3,170-2,236,220-2,WHITE);
				drawRoundRect(3,170-2,236,220-2,BLACK);				
				print("Дата и время",20,186-4,FontRus16x27,BLACK,WHITE); 								
								
				fillRoundRect(3,225-3,236,275-3,WHITE);
				drawRoundRect(3,225-3,236,275-3,BLACK);
				print("Общие",20,240-5,FontRus16x27,BLACK,WHITE); 				
																														
				ButtonBack();
}








void Enable91(void)
{
				LCD_Rectangle(0,21,239,319,BLUE1);
        	    LCD_Rectangle(0,21,239,24,BLUE);        	            	   
        	   	print("    Дисплей    ",0,25,FontRus16x27,WHITE,BLUE);																				
				
				fillRoundRect(3,60,236,110,WHITE);
				drawRoundRect(3,60,236,110,BLACK);	
				print("Яркость",20,74,FontRus16x27,BLACK,WHITE); 
																	
				fillRoundRect(3,115-1,236,165-1,WHITE);
				drawRoundRect(3,115-1,236,165-1,BLACK);
				print("Подсветка",20,130-2,FontRus16x27,BLACK,WHITE); 
																																											
				ButtonBack();
}

void Enable92(void)
{
				LCD_Rectangle(0,21,239,319,BLUE1);
        	    LCD_Rectangle(0,21,239,24,BLUE);        	            	   
        	   	print("   Клавиатура   ",0,25,FontRus16x27,WHITE,BLUE);																				
																									
				drawHLine(1,53,30,BLACK);
				drawVLine(1,53,30,BLACK);
				
				drawHLine(208,53,30,BLACK);
				drawVLine(238,53,30,BLACK);
								
				drawHLine(1,278,30,BLACK);
				drawVLine(1,248,30,BLACK);
				
				drawHLine(208,278,30,BLACK);
				drawVLine(238,248,30,BLACK);												
													
				print(" Проверьте точность           ",0,75,FontRus8x15,BLACK,BLUE1);				
				print(" калибровки путем нажатия в   ",0,90,FontRus8x15,BLACK,BLUE1);				
				print(" различные места выделенной   ",0,105,FontRus8x15,BLACK,BLUE1);								
				print(" области тонким предметом.    ",0,120,FontRus8x15,BLACK,BLUE1);
				print(" Пробные нажатия необходимо   ",0,135,FontRus8x15,BLACK,BLUE1);				 
				print(" производить ближе к углам    ",0,150,FontRus8x15,BLACK,BLUE1);
				print(" выделенной области.          ",0,165,FontRus8x15,BLACK,BLUE1);
				print(" Если реальное нажатие в      ",0,180,FontRus8x15,BLACK,BLUE1);
				print(" какой-нибудь точке отлично   ",0,195,FontRus8x15,BLACK,BLUE1);
				print(" от появившейся более, чем на ",0,210,FontRus8x15,BLACK,BLUE1);
				print(" один миллиметр, то необходимо",0,225,FontRus8x15,BLACK,BLUE1);
				print(" произвести настройку.        ",0,240,FontRus8x15,BLACK,BLUE1);
				 				 							 							 																					 																																																														 																																						
	 			ButtonNastrBack();
}



void ButtonRTC(void)
{								
				LCD_Rectangle(0,138,239,319,GRAY3);
																	
				drawButtonClock(3,140,78,170,WHITE,BLACK,BLACK,"1");   	
				drawButtonClock(82,140,157,170,WHITE,BLACK,BLACK,"2");   
				drawButtonClock(161,140,236,170,WHITE,BLACK,BLACK,"3");  
				
				drawButtonClock(3,175,78,205,WHITE,BLACK,BLACK,"4");   	
				drawButtonClock(82,175,157,205,WHITE,BLACK,BLACK,"5");   
				drawButtonClock(161,175,236,205,WHITE,BLACK,BLACK,"6");  
				
				drawButtonClock(3,210,78,240,WHITE,BLACK,BLACK,"7");   	
				drawButtonClock(82,210,157,240,WHITE,BLACK,BLACK,"8");   
				drawButtonClock(161,210,236,240,WHITE,BLACK,BLACK,"9");  
				
				drawButtonClock(3,245,78,275,WHITE,BLACK,BLACK,"");   	
				drawButtonClock(82,245,157,275,WHITE,BLACK,BLACK,"0");   
				drawButtonClock(161,245,236,275,GRAY0,BLACK,BLACK,"C");  
}




//------------------------------------------------------------------------------------------------






void Enable93(void)
{
				LCD_Rectangle(0,21,239,137,BLUE1);			
				//LCD_Rectangle(0,136,239,319,GRAY3);
				
        	    LCD_Rectangle(0,21,239,24,BLUE);        	            	   
        	   	print("  Дата и время  ",0,25,FontRus16x27,WHITE,BLUE);																				
																																	
				print(":",73,108,Font16x24,BLACK,BLUE1); 
				print(":",152,108,Font16x24,BLACK,BLUE1);				
																											
				ButtonRTC();
				
				 							
				 				 							 							 																					 																																																														 																																						
	 			ButtonSaveBack();
}






/////////////////////////////////////////
////////////////////////////////////////
///////////////////////////////////////
//////////////////////////////////////
/////////////////////////////////////



void Enable70(void)
{
	
				LCD_Rectangle(0,21,239,62,WHITE);								
													 									 	
				fillRoundRect(5,23,50,62,BLUE1);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(5,23,50,62,BLACK);	
																
				fillRoundRect(51,23,96,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(51,23,96,62,BLACK);	
												
				fillRoundRect(97,23,142,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(97,23,142,62,BLACK);
									
				fillRoundRect(143,23,188,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(143,23,188,62,BLACK);
					
				fillRoundRect(189,23,234,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(189,23,234,62,BLACK);
					
										
				LCD_Rectangle(0,60,239,137,BLUE1);
									
				drawHLine(0,60,239,BLACK);
				drawHLine(6,60,43,BLUE1);
																																																					
				print("Буд",  13+3,35,FontRus8x15,BLACK,BLUE1);
				print("Сек",  59+3,35,FontRus8x15,WHITE,BLUE20);
				print("Тай", 105+3,35,FontRus8x15,WHITE,BLUE20);
				print("Мир",  151+3,35,FontRus8x15,WHITE,BLUE20);
				print("Нап",  197+3,35,FontRus8x15,WHITE,BLUE20);				
															
				print(":",73,108-20,Font16x24,BLACK,BLUE1); 
					

				fillRoundRect(171,70,171+52,70+52,GREEN); 					 				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(171,70,171+52,70+52,BLACK);	
				print("ВКЛ",171+14,91,FontRus8x15,BLACK,GREEN);



				print("  Час",12,121,FontRus8x15,BLACK,BLUE1);
				print("  Минута",80,121,FontRus8x15,BLACK,BLUE1);


				/*										
				fillRoundRect(40,71,109,126,CYAN);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(40,71,109,126,BLACK);						
				fillRoundRect(131,71,200,126,CYAN);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(131,71,200,126,BLACK);	
																																																																				
				printNumI( 24,43,74,Num32x50,BLACK,WHITE);								 			
				print(":",113,89,Font16x24,BLACK,BLUE1);				 	 				     
				printNumI( 24,134,74,Num32x50,BLACK,WHITE);
				*/
								
								
																																
				ButtonRTC();
				
				 							
				 				 							 							 																					 																																																														 																																						
	 			ButtonSaveNastrBack();
}



void Enable71(void)														// секундомер
{	
				LCD_Rectangle(0,21,239,62,WHITE);								
				//LCD_Rectangle(0,66,239,319,WHITE);	
								 												 	
				fillRoundRect(5,23,50,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(5,23,50,62,BLACK);	
																
				fillRoundRect(51,23,96,62,BLUE1);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(51,23,96,62,BLACK);	
												
				fillRoundRect(97,23,142,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(97,23,142,62,BLACK);
									
				fillRoundRect(143,23,188,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(143,23,188,62,BLACK);
					
				fillRoundRect(189,23,234,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(189,23,234,62,BLACK);
				
				
								
				LCD_Rectangle(0,60,239,319,BLUE1);
									
				drawHLine(0,60,239,BLACK);
				drawHLine(6+46,60,43,BLUE1);
								
				print("Буд",  13+3,35,FontRus8x15,WHITE,BLUE20);
				print("Сек",  59+3,35,FontRus8x15,BLACK,BLUE1);
				print("Тай", 105+3,35,FontRus8x15,WHITE,BLUE20);
				print("Мир",  151+3,35,FontRus8x15,WHITE,BLUE20);
				print("Нап",  197+3,35,FontRus8x15,WHITE,BLUE20);
				
				
				
				
				fillRoundRect(3,71,236,126,CYAN);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(3,71,236,126,BLACK);
				fillRoundRect(6,74,233,123,WHITE); 																																		
				print(":",66,89,Font16x24,BLACK,WHITE);
				print(":",137,89,Font16x24,BLACK,WHITE);	
																																																																																				   																																												 											 				 							 							 																					 																																																														 																											
	 			ButtonZapuskClearBack();
}

void Enable72(void)
{
	
				LCD_Rectangle(0,21,239,62,WHITE);								
				//LCD_Rectangle(0,66,239,319,WHITE);
										 												 		
				fillRoundRect(5,23,50,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(5,23,50,62,BLACK);	
																
				fillRoundRect(51,23,96,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(51,23,96,62,BLACK);	
												
				fillRoundRect(97,23,142,62,BLUE1);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(97,23,142,62,BLACK);
									
				fillRoundRect(143,23,188,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(143,23,188,62,BLACK);
					
				fillRoundRect(189,23,234,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(189,23,234,62,BLACK);
			
				LCD_Rectangle(0,60,239,137,BLUE1);
					
				drawHLine(0,60,239,BLACK);
				drawHLine(6+46+46,60,43,BLUE1);
			
				
				print("Буд",  13+3,35,FontRus8x15,WHITE,BLUE20);
				print("Сек",  59+3,35,FontRus8x15,WHITE,BLUE20);
				print("Тай", 105+3,35,FontRus8x15,BLACK,BLUE1);
				print("Мир",  151+3,35,FontRus8x15,WHITE,BLUE20);
				print("Нап",  197+3,35,FontRus8x15,WHITE,BLUE20);
				







				fillRoundRect(3,62,77,121,CYAN);  				
				drawRoundRect(3,62,77,121,BLACK);
				fillRoundRect(6,65,74,118,WHITE);
																						  				 				 				 				 			             	        				 				 				 	        	        	        			             	
				fillRoundRect(84,62,157,121,CYAN);   							  				 				 				 				 			             	        				 				 				 	        	        	        			             	 
				drawRoundRect(84,62,157,121,BLACK);	
 				fillRoundRect(87,65,154,118,WHITE);										
																																			  				 				 				 				 			             	        				 				 				 	        	        	        			             	  
				fillRoundRect(164,62,236,121,CYAN);  				  				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(164,62,236,121,BLACK);	
 				fillRoundRect(167,65,233,118,WHITE);




				//fillRoundRect(3,66,236,117,CYAN);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				//drawRoundRect(3,66,236,117,BLACK);	
				
				//drawVLine(80,67,50,BLACK);																																																														
				//drawVLine(160,67,50,BLACK); 		
												
												
				
				
				
				
				
												
												
												
												
												
				//printNumI( 24,9,67,Num32x50,BLACK,WHITE);								 							 	 				   
				//printNumI( 24,89,67,Num32x50,BLACK,WHITE);								   
				//printNumI( 24,169,67,Num32x50,BLACK,WHITE);    		
								
				
				
				print("  Час",12,123,FontRus8x15,BLACK,BLUE1);
				print("  Минута",80,123,FontRus8x15,BLACK,BLUE1);
				print("Секунда",172,123,FontRus8x15,BLACK,BLUE1);			
				
				
				
				ButtonRTC();
				
				
				 							
				 				 							 							 																					 																																																														 																																						
	 			ButtonZapuskClearBack();
}


void Enable73(void)
{
	
				LCD_Rectangle(0,21,239,62,WHITE);								
				//LCD_Rectangle(0,66,239,319,WHITE);
										 		
										 			
				fillRoundRect(5,23,50,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(5,23,50,62,BLACK);	
																
				fillRoundRect(51,23,96,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(51,23,96,62,BLACK);	
												
				fillRoundRect(97,23,142,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(97,23,142,62,BLACK);
									
				fillRoundRect(143,23,188,62,BLUE1);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(143,23,188,62,BLACK);
					
				fillRoundRect(189,23,234,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(189,23,234,62,BLACK);
					
			
				LCD_Rectangle(0,60,239,319,BLUE1);
					
				drawHLine(0,60,239,BLACK);
				drawHLine(6+46+46+46,60,43,BLUE1);
			
				
				print("Буд",  13+3,35,FontRus8x15,WHITE,BLUE20);
				print("Сек",  59+3,35,FontRus8x15,WHITE,BLUE20);
				print("Тай", 105+3,35,FontRus8x15,WHITE,BLUE20);
				print("Мир",  151+3,35,FontRus8x15,BLACK,BLUE1);
				print("Нап",  197+3,35,FontRus8x15,WHITE,BLUE20);
																																																																																		 				
				 				 							 							 																					 																																																														 																																						
	 			ButtonAddBack();
}



void Enable74(void)
{
	
				LCD_Rectangle(0,21,239,62,WHITE);								
				//LCD_Rectangle(0,66,239,319,WHITE);
										 		
										 			
				fillRoundRect(5,23,50,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(5,23,50,62,BLACK);	
																
				fillRoundRect(51,23,96,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(51,23,96,62,BLACK);	
												
				fillRoundRect(97,23,142,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(97,23,142,62,BLACK);
									
				fillRoundRect(143,23,188,62,BLUE20);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(143,23,188,62,BLACK);
					
				fillRoundRect(189,23,234,62,BLUE1);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(189,23,234,62,BLACK);
					
			
				LCD_Rectangle(0,60,239,137,BLUE1);
					
				drawHLine(0,60,239,BLACK);
				drawHLine(6+46+46+46+46,60,43,BLUE1);
			
				
				print("Буд",  13+3,35,FontRus8x15,WHITE,BLUE20);
				print("Сек",  59+3,35,FontRus8x15,WHITE,BLUE20);
				print("Тай", 105+3,35,FontRus8x15,WHITE,BLUE20);
				print("Мир",  151+3,35,FontRus8x15,WHITE,BLUE20);
				print("Нап",  197+3,35,FontRus8x15,BLACK,BLUE1);
					
				print(":",73,108,Font16x24,BLACK,BLUE1); 
				print(":",152,108,Font16x24,BLACK,BLUE1);		
					
					
					
					
				ButtonRTC();
																																																																																		 				
				 				 							 							 																					 																																																														 																																						
	 			ButtonSaveNastrBack();
}

















void Enable921(void)
{
				LCD_Rectangle(0,21,239,319,BLUE1);
        	  																																										
				print(" Нажмите точно  ",0,140,FontRus16x27,BLACK,BLUE1);
				print(" в центр мишени ",0,165,FontRus16x27,BLACK,BLUE1); 
								
				EnableTarget1();								
}





void Enable922(void)
{      	    
        	   	LCD_Rectangle(5,26,35,56,BLUE1);        	            	           	   																																																		
				EnableTarget2();
}			
		



void Enable923(void)
{
				LCD_Rectangle(0,21,239,319,BLUE1);
																																																					
				print(" Новые калибровочные данные   ",0,105,FontRus8x15,BLACK,BLUE1);								
				print(" для клавиатуры получены.     ",0,120,FontRus8x15,BLACK,BLUE1);
				print(" Если Вы хотите установить их ",0,135,FontRus8x15,BLACK,BLUE1);				 
				print(" в качестве основных, то      ",0,150,FontRus8x15,BLACK,BLUE1);
				print(" нажмите кнопку *Сохранить*.  ",0,165,FontRus8x15,BLACK,BLUE1);
				print(" Если хотите оставить         ",0,180,FontRus8x15,BLACK,BLUE1);
				print(" предыдущие значения, то      ",0,195,FontRus8x15,BLACK,BLUE1);
				print(" нажмите кнопку *Назад*.      ",0,210,FontRus8x15,BLACK,BLUE1);
																										 							 							 																					 																																																														 																																	
	 			ButtonSaveBack();
}			
		








void printNumICcalc1(void)			
{							
	
	      		LCD_Rectangle(5,50,234,74,WHITE);	
	      			
				if(Ccalc_operand_1 < 10)
      			{      			
			    printNumI( Ccalc_operand_1,215,50,Font16x24,BLACK,WHITE);			// 1	
      			}	
      			else if (Ccalc_operand_1 < 100)
      			{
			    printNumI( Ccalc_operand_1,215-16,50,Font16x24,BLACK,WHITE);		// 2
      			}		
      			else if (Ccalc_operand_1 < 1000)
      			{
			    printNumI( Ccalc_operand_1,215-16-16,50,Font16x24,BLACK,WHITE);		// 3
      			}		
				else if (Ccalc_operand_1 < 10000)
      			{
			    printNumI( Ccalc_operand_1,215-16-16-16,50,Font16x24,BLACK,WHITE);		// 4
      			}			
				else if (Ccalc_operand_1 < 100000)
      			{
			    printNumI( Ccalc_operand_1,215-16-16-16-16,50,Font16x24,BLACK,WHITE);		// 5
      			}				
				else if (Ccalc_operand_1 < 1000000)
      			{
			    printNumI( Ccalc_operand_1,215-16-16-16-16-16,50,Font16x24,BLACK,WHITE);		// 6
      			}					
				else if (Ccalc_operand_1 < 10000000)
      			{
			    printNumI( Ccalc_operand_1,215-16-16-16-16-16-16,50,Font16x24,BLACK,WHITE);		// 7
      			}							
				else if (Ccalc_operand_1 < 100000000)
      			{
			    printNumI( Ccalc_operand_1,215-16-16-16-16-16-16-16,50,Font16x24,BLACK,WHITE);		// 8
      			}	
			    else
      			{		      			
      			print("      Очень большое число   ",6,55,FontRus8x15,BLACK,WHITE);	   					   
      			}		

}


void printNumICcalc2(void)			
{							
	
	      		LCD_Rectangle(5,50,234,74,WHITE);
	      			
				if(Ccalc_operand_2 < 10)
      			{      			
			    printNumI( Ccalc_operand_2,215,50,Font16x24,BLACK,WHITE);			// 1	
      			}	
      			else if (Ccalc_operand_2 < 100)
      			{
			    printNumI( Ccalc_operand_2,215-16,50,Font16x24,BLACK,WHITE);		// 2
      			}		
      			else if (Ccalc_operand_2 < 1000)
      			{
			    printNumI( Ccalc_operand_2,215-16-16,50,Font16x24,BLACK,WHITE);		// 3
      			}		
				else if (Ccalc_operand_2 < 10000)
      			{
			    printNumI( Ccalc_operand_2,215-16-16-16,50,Font16x24,BLACK,WHITE);		// 4
      			}			
				else if (Ccalc_operand_2 < 100000)
      			{
			    printNumI( Ccalc_operand_2,215-16-16-16-16,50,Font16x24,BLACK,WHITE);		// 5
      			}				
				else if (Ccalc_operand_2 < 1000000)
      			{
			    printNumI( Ccalc_operand_2,215-16-16-16-16-16,50,Font16x24,BLACK,WHITE);		// 6
      			}					
				else if (Ccalc_operand_2 < 10000000)
      			{
			    printNumI( Ccalc_operand_2,215-16-16-16-16-16-16,50,Font16x24,BLACK,WHITE);		// 7
      			}							
				else if (Ccalc_operand_2 < 100000000)
      			{
			    printNumI( Ccalc_operand_2,215-16-16-16-16-16-16-16,50,Font16x24,BLACK,WHITE);		// 8
      			}	
			    else
      			{	
      			print("      Очень большое число   ",6,55,FontRus8x15,BLACK,WHITE);			      						   
      			}		
			    
}



//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------





void LoadRTCinBuf(void)	
{								 	
				int i=1;									
				BufRTC[i++] = ((RTC_DAY>>4)& 0x000F);		
				BufRTC[i++] = (RTC_DAY & 0x000F);
				BufRTC[i++] = ((RTC_MONTH>>4)& 0x000F);
				BufRTC[i++] = (RTC_MONTH & 0x000F);		
				BufRTC[i++] = ((RTC_YEAR>>4)& 0x000F);
				BufRTC[i++] = (RTC_YEAR & 0x000F);
				
				BufRTC[i++] = ((RTC_HOUR>>4)& 0x000F);		
				BufRTC[i++] = (RTC_HOUR & 0x000F);
				BufRTC[i++] = ((RTC_MIN>>4)& 0x000F);
				BufRTC[i++] = (RTC_MIN & 0x000F);		
				BufRTC[i++] = ((RTC_SEC>>4)& 0x000F);
				BufRTC[i++] = (RTC_SEC & 0x000F);										
}



      			//print( "    Дата и время    ",0,21,FontRus16x28,WHITE,BLUE_T);				
      			//print( "        .  .        ",0,100,FontRus16x28,WHITE,BLUE_T);        
      			//print( "        :  :        ",0,140,FontRus16x28,WHITE,BLUE_T);  


void printNumIRTC(void)			
{
				int i=1;
				printNumUI( BufRTC[i++],96,100,FontRus16x28,BLACK,BLUE_B);		
				printNumUI( BufRTC[i++],112,100,FontRus16x28,BLACK,BLUE_B);			        			
				printNumUI( BufRTC[i++],144,100,FontRus16x28,BLACK,BLUE_B);			
				printNumUI( BufRTC[i++],160,100,FontRus16x28,BLACK,BLUE_B);			        		
				printNumUI( BufRTC[i++],192,100,FontRus16x28,BLACK,BLUE_B);		
				printNumUI( BufRTC[i++],208,100,FontRus16x28,BLACK,BLUE_B);	
      			      			      			      			      
      			printNumUI( BufRTC[i++],96,140,FontRus16x28,BLACK,BLUE_B);	  			
				printNumUI( BufRTC[i++],112,140,FontRus16x28,BLACK,BLUE_B);	
				printNumUI( BufRTC[i++],144,140,FontRus16x28,BLACK,BLUE_B);	    			
				printNumUI( BufRTC[i++],160,140,FontRus16x28,BLACK,BLUE_B);	      			
    			printNumUI( BufRTC[i++],192,140,FontRus16x28,BLACK,BLUE_B);    		
				printNumUI( BufRTC[i++],208,140,FontRus16x28,BLACK,BLUE_B);	
}




void LoadRTCButton(void)
{
				  				 				 				 				 			             	        				 				 				 	        	        	        			             
				fillRoundRect(2,62,79,98,CYAN);  				
				drawRoundRect(2,62,79,98,BLACK);
				fillRoundRect(5,65,76,95,WHITE); 	
																						  				 				 				 				 			             	        				 				 				 	        	        	        			             	
				fillRoundRect(81,62,158,98,CYAN);   							  				 				 				 				 			             	        				 				 				 	        	        	        			             	 
				drawRoundRect(81,62,158,98,BLACK);	
				fillRoundRect(84,65,155,95,WHITE);  														
																																			  				 				 				 				 			             	        				 				 				 	        	        	        			             	  
				fillRoundRect(160,62,237,98,CYAN);  				  				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(160,62,237,98,BLACK);	
				fillRoundRect(163,65,234,95,WHITE);  
														
																																																												  				 				 				 				 			             	        				 				 				 	        	        	        			             	  
				fillRoundRect(13,100,68,136,CYAN);    														   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(13,100,68,136,BLACK);	
				fillRoundRect(16,103,65,133,WHITE);  	
																																																		  				 				 				 				 			             	        				 				 				 	        	        	        			             	    
				fillRoundRect(92,100,147,136,CYAN); 										 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(92,100,147,136,BLACK);	
				fillRoundRect(95,103,144,133,WHITE);  			
																																						  				 				 				 				 			             	        				 				 				 	        	        	        			             	  
				fillRoundRect(171,100,226,136,CYAN); 					 				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(171,100,226,136,BLACK);	
				fillRoundRect(174,103,223,133,WHITE);
				

}









void LoadRTCKur(void)				

{				
	
	
																																	
				if(KurRTC == 1)
				{								
				LCD_Rectangle(96,128,223,131,BLUE_B); 					
    			LCD_Rectangle(96,168,223,171,BLUE_B);
				LCD_Rectangle(96,128,111,131,YELLOW_K); 	   		      			     															 																																				
				}

				else if(KurRTC == 2)
				{																																
				LCD_Rectangle(96,128,223,131,BLUE_B); 					
    			LCD_Rectangle(96,168,223,171,BLUE_B);
				LCD_Rectangle(112,128,127,131,YELLOW_K); 	
				}				
				else if(KurRTC == 3)
				{																																
				LCD_Rectangle(96,128,223,131,BLUE_B); 					
    			LCD_Rectangle(96,168,223,171,BLUE_B);
				LCD_Rectangle(144,128,159,131,YELLOW_K); 	
				}																											
				else if(KurRTC == 4)
				{																																
				LCD_Rectangle(96,128,223,131,BLUE_B); 					
    			LCD_Rectangle(96,168,223,171,BLUE_B);
				LCD_Rectangle(160,128,175,131,YELLOW_K); 		
				}					
				else if(KurRTC == 5)
				{																																
				LCD_Rectangle(96,128,223,131,BLUE_B); 					
    			LCD_Rectangle(96,168,223,171,BLUE_B);
				LCD_Rectangle(192,128,207,131,YELLOW_K); 	
				}	
				else if(KurRTC == 6)
				{																																
				LCD_Rectangle(96,128,223,131,BLUE_B); 					
    			LCD_Rectangle(96,168,223,171,BLUE_B);
				LCD_Rectangle(208,128,223,131,YELLOW_K); 	
				}	
				
				
				
				
				
				else if(KurRTC == 7)
				{								
				LCD_Rectangle(96,128,223,131,BLUE_B); 					
    			LCD_Rectangle(96,168,223,171,BLUE_B);
				LCD_Rectangle(96,168,111,171,YELLOW_K); 	   		      			     															 																																				
				}

				else if(KurRTC == 8)
				{																																
				LCD_Rectangle(96,128,223,131,BLUE_B); 					
    			LCD_Rectangle(96,168,223,171,BLUE_B);
				LCD_Rectangle(112,168,127,171,YELLOW_K); 	
				}				
				else if(KurRTC == 9)
				{																																
				LCD_Rectangle(96,128,223,131,BLUE_B); 					
    			LCD_Rectangle(96,168,223,171,BLUE_B);
				LCD_Rectangle(144,168,159,171,YELLOW_K); 	
				}																											
				else if(KurRTC == 10)
				{																																
				LCD_Rectangle(96,128,223,131,BLUE_B); 					
    			LCD_Rectangle(96,168,223,171,BLUE_B);
				LCD_Rectangle(160,168,175,171,YELLOW_K); 		
				}					
				else if(KurRTC == 11)
				{																																
				LCD_Rectangle(96,128,223,131,BLUE_B); 					
    			LCD_Rectangle(96,168,223,171,BLUE_B);
				LCD_Rectangle(192,168,207,171,YELLOW_K); 	
				}	
				else if(KurRTC == 12)
				{																																
				LCD_Rectangle(96,128,223,131,BLUE_B); 					
    			LCD_Rectangle(96,168,223,171,BLUE_B);
				LCD_Rectangle(208,168,223,171,YELLOW_K); 	
				}	
				
				
						
				else 
				{																				
				}
				
												
}




//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------

void LoadRTCinBufAL(void)	
{								 	
				int i=1;									
				BufRTC[i++] = ((RTC_DAYAL>>4)& 0x000F);		
				BufRTC[i++] = (RTC_DAYAL & 0x000F);
				BufRTC[i++] = ((RTC_MONTHAL>>4)& 0x000F);
				BufRTC[i++] = (RTC_MONTHAL & 0x000F);		
				BufRTC[i++] = ((RTC_YEARAL>>4)& 0x000F);
				BufRTC[i++] = (RTC_YEARAL & 0x000F);
				
				BufRTC[i++] = ((RTC_HOURAL>>4)& 0x000F);		
				BufRTC[i++] = (RTC_HOURAL & 0x000F);
				BufRTC[i++] = ((RTC_MINAL>>4)& 0x000F);
				BufRTC[i++] = (RTC_MINAL & 0x000F);		
				BufRTC[i++] = ((RTC_SECAL>>4)& 0x000F);
				BufRTC[i++] = (RTC_SECAL & 0x000F);										
}


//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//----------------------------------------------------------------


void LoadRTCinBufBy(void)	
{								 	
				int i=1;									
				//BufRTC[i++] = ((RTC_DAYAL>>4)& 0x000F);		
				//BufRTC[i++] = (RTC_DAYAL & 0x000F);
				//BufRTC[i++] = ((RTC_MONTHAL>>4)& 0x000F);
				//BufRTC[i++] = (RTC_MONTHAL & 0x000F);		
				//BufRTC[i++] = ((RTC_YEARAL>>4)& 0x000F);
				//BufRTC[i++] = (RTC_YEARAL & 0x000F);
				
				BufRTC[i++] = ((RTC_HOURAL>>4)& 0x000F);		
				BufRTC[i++] = (RTC_HOURAL & 0x000F);
				BufRTC[i++] = ((RTC_MINAL>>4)& 0x000F);
				BufRTC[i++] = (RTC_MINAL & 0x000F);		
				//BufRTC[i++] = ((RTC_SECAL>>4)& 0x000F);
				//BufRTC[i++] = (RTC_SECAL & 0x000F);										
}


void printNumIRTCBy(void)			
{
				int i=1;																										
				//printNumI( BufRTC[i++],25, 70,Font16x24,BLACK,WHITE); 			// RTC_DAY
				//printNumI( BufRTC[i++],41, 70,Font16x24,BLACK,WHITE); 		    // RTC_DAY																																							
				//printNumI( BufRTC[i++],104,70,Font16x24,BLACK,WHITE); 			// RTC_MONTH
				//printNumI( BufRTC[i++],120,70,Font16x24,BLACK,WHITE); 		    // RTC_MONTH																															
				//printNumI( BufRTC[i++],183,70,Font16x24,BLACK,WHITE); 			// RTC_YEAR
				//printNumI( BufRTC[i++],199,70,Font16x24,BLACK,WHITE); 		    // RTC_YEAR
																																											
				printNumI( BufRTC[i++],25, 108-20,Font16x24,BLACK,WHITE); 			// RTC_HOUR
				printNumI( BufRTC[i++],41, 108-20,Font16x24,BLACK,WHITE); 			// RTC_HOUR								
				printNumI( BufRTC[i++],104,108-20,Font16x24,BLACK,WHITE); 			// RTC_MIN
				printNumI( BufRTC[i++],120,108-20,Font16x24,BLACK,WHITE); 			// RTC_MIN				
				//printNumI( BufRTC[i++],183,108,Font16x24,BLACK,WHITE); 			// RTC_SEC
				//printNumI( BufRTC[i++],199,108,Font16x24,BLACK,WHITE); 			// RTC_SEC
}


void LoadRTCButtonBy(void)
{
				  				 				 				 				 			             	        				 				 				 	        	        	        			             
				//fillRoundRect(2,62,79,98,CYAN);  				
				//drawRoundRect(2,62,79,98,BLACK);
				//fillRoundRect(5,65,76,95,WHITE); 	
																						  				 				 				 				 			             	        				 				 				 	        	        	        			             	
				//fillRoundRect(81,62,158,98,CYAN);   							  				 				 				 				 			             	        				 				 				 	        	        	        			             	 
				//drawRoundRect(81,62,158,98,BLACK);	
				//fillRoundRect(84,65,155,95,WHITE);  														
																																			  				 				 				 				 			             	        				 				 				 	        	        	        			             	  
				//fillRoundRect(160,62,237,98,CYAN);  				  				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				//drawRoundRect(160,62,237,98,BLACK);	
				//fillRoundRect(163,65,234,95,WHITE);  
														
																																																												  				 				 				 				 			             	        				 				 				 	        	        	        			             	  
				fillRoundRect(13,100-20,68,136-20,CYAN);    														   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(13,100-20,68,136-20,BLACK);	
				fillRoundRect(16,103-20,65,133-20,WHITE);  	
																																																		  				 				 				 				 			             	        				 				 				 	        	        	        			             	    
				fillRoundRect(92,100-20,147,136-20,CYAN); 										 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(92,100-20,147,136-20,BLACK);	
				fillRoundRect(95,103-20,144,133-20,WHITE);  			
																																						  				 				 				 				 			             	        				 				 				 	        	        	        			             	  
				//fillRoundRect(171,100,226,136,CYAN); 					 				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				//drawRoundRect(171,100,226,136,BLACK);	
				//fillRoundRect(174,103,223,133,WHITE);
				

}



void LoadRTCKurBy(void)				

{																		
																			
				if((KurRTC == 1)||(KurRTC == 2))
				{			
					
				drawRect(21,103-20,60,133-20,RED);		
				drawRect(22,104-20,59,132-20,RED);																			
				drawRect(100,103-20,139,133-20,WHITE);
				drawRect(101,104-20,138,132-20,WHITE);		
																			 		
				}
																																
				else if((KurRTC == 3)||(KurRTC == 4))
				{
				drawRect(21,103-20,60,133-20,WHITE);		
				drawRect(22,104-20,59,132-20,WHITE);																			
				drawRect(100,103-20,139,133-20,RED);
				drawRect(101,104-20,138,132-20,RED);		
				}				
																										
				
				
				else 
				{																				
				}
				
												
}




				//fillRoundRect(3,62,77,121,CYAN);  																										  				 				 				 				 			             	        				 				 				 	        	        	        			           
				//fillRoundRect(84,62,157,121,CYAN);   							  				 				 				 				 			             	        				 				 				 	        	        	        			             	 																																												  				 				 				 				 			             	        				 				 				 	        	        	        			             	  
				//fillRoundRect(164,62,236,121,CYAN);  				  				 				 				 				 			             	        				 				 				 	        	        	        			             	     




void LoadRTCKurTi(void)				

{																		
																			
				if((KurRTC == 1)||(KurRTC == 2))
				{																					
				drawRect(3+3,62+3,77-3,121-3,RED);		
				drawRect(3+4,62+4,77-4,121-4,RED);																						
				drawRect(84+3,62+3,157-3,121-3,WHITE);
				drawRect(84+4,62+4,157-4,121-4,WHITE);					
				drawRect(164+3,62+3,236-3,121-3,WHITE);
				drawRect(164+4,62+4,236-4,121-4,WHITE);																																			
				}																															
				else if((KurRTC == 3)||(KurRTC == 4))
				{
				drawRect(3+3,62+3,77-3,121-3,WHITE);		
				drawRect(3+4,62+4,77-4,121-4,WHITE);																						
				drawRect(84+3,62+3,157-3,121-3,RED);
				drawRect(84+4,62+4,157-4,121-4,RED);					
				drawRect(164+3,62+3,236-3,121-3,WHITE);
				drawRect(164+4,62+4,236-4,121-4,WHITE);	
				}																													
				else if((KurRTC == 5)||(KurRTC == 6))
				{
				drawRect(3+3,62+3,77-3,121-3,WHITE);		
				drawRect(3+4,62+4,77-4,121-4,WHITE);																						
				drawRect(84+3,62+3,157-3,121-3,WHITE);
				drawRect(84+4,62+4,157-4,121-4,WHITE);					
				drawRect(164+3,62+3,236-3,121-3,RED);
				drawRect(164+4,62+4,236-4,121-4,RED);			
				}													
				else 
				{																				
				}
				
												
}


void LCD_Freq(Uint32 x, Uint16 FontColor)
{
	 Uint32 er,ir;

	 char i;
	 er = x;
     for (i=5; i > 0; i--)
     {

       ir=er % 10;
       er=er / 10;
       printNumI(ir,i*40 - 38 + 57 ,70,Num40x53,FontColor,WHITE_ADV);
     }
     fillRoundRect(159+57,120,167+57,128,FontColor);

}

void LCD_Acsel(unsigned int x, Uint16 FontColor)
{
	 unsigned int er,ir,i;
     er = x;
     for (i=4; i > 0; i--)
     {

       ir=er % 10;
       er=er / 10;
       printNumI(ir,i*40+2 + 57,145,Num40x53,FontColor,WHITE_ADV);
     }
     fillRoundRect(159+57,200-5,167+57,208-5,FontColor);
}

void LCD_velosity(unsigned int x)
{
	 unsigned int er,ir;
     er = x;
     ir=er % 10;
     er=er / 10;
     printNumI( ir,129,150,Num40x53,WHITE,BLUE_B);
     ir=er % 10;
     er=er / 10;
     printNumI( ir,80,150,Num40x53,WHITE,BLUE_B);
     ir=er % 10;
     er=er / 10;
     printNumI( ir,40,150,Num40x53,WHITE,BLUE_B);
     ir=er % 10;
     er=er / 10;
     printNumI( ir,0,150,Num40x53,WHITE,BLUE_B);
     fillRoundRect(120,194,128,202,WHITE);
}

void LCD_displacement(unsigned int x)
{
	 unsigned int er,ir;
     er = x;
     ir=er % 10;
     er=er / 10;
     printNumI( ir,120,150,Num40x53,WHITE,BLUE_B);
     ir=er % 10;
     er=er / 10;
     printNumI( ir,80,150,Num40x53,WHITE,BLUE_B);
     ir=er % 10;
     er=er / 10;
     printNumI( ir,40,150,Num40x53,WHITE,BLUE_B);
     ir=er % 10;
     er=er / 10;
     printNumI( ir,0,150,Num40x53,WHITE,BLUE_B);
}

void LCD_Code(unsigned int x)
{
	 unsigned int er,ir;
     er = x;
     ir=er % 10;
     er=er / 10;
     printNumI( ir,200,100,Num40x53,WHITE,BLUE_B);
     ir=er % 10;
     er=er / 10;
     printNumI( ir,160,100,Num40x53,WHITE,BLUE_B);
     ir=er % 10;
     er=er / 10;
     printNumI( ir,120,100,Num40x53,WHITE,BLUE_B);
     ir=er % 10;
     er=er / 10;
     printNumI( ir,80,100,Num40x53,WHITE,BLUE_B);
}




void printNumIRTCTi(void)			
{
		
				//int i=1;																										

																																											
				//printNumI( BufRTC[i++],9, 67,Num32x50,BLACK,WHITE); 				// RTC_HOUR
				//printNumI( BufRTC[i++],9+32, 67,Num32x50,BLACK,WHITE); 				// RTC_HOUR	
											
				//printNumI( BufRTC[i++],89,67,Num32x50,BLACK,WHITE); 				// RTC_MIN
				//printNumI( BufRTC[i++],89+32,67,Num32x50,BLACK,WHITE); 				// RTC_MIN
											
				//printNumI( BufRTC[i++],169,67,Num32x50,BLACK,WHITE); 				// RTC_SEC
				//printNumI( BufRTC[i++],169+32,67,Num32x50,BLACK,WHITE); 			// RTC_SEC
				
				
}


void PrintStandMenu(int CursorPos)
{
	MenuCursor = CursorPos;
	if (MenuLevel!=2)
	{
		LCD_Clear_1(BLUE_B);
		print("  Режим вибростенда ",0,21,FontRus16x28,WHITE,BLUE_T);
	}
	switch (CursorPos)
	{
	case 0:

	  print( " Ускорение        ",16,60,FontRus16x28,BLACK,YELLOW_K);
	  print( " Скорость         ",16,90,FontRus16x28,WHITE,BLUE_T);
	  print( " Перемещение      ",16,120,FontRus16x28,WHITE,BLUE_T);
	  regim=111;
	  break;

	case 1:
	  print( " Ускорение        ",16,60,FontRus16x28,WHITE,BLUE_T);
	  print( " Скорость         ",16,90,FontRus16x28,BLACK,YELLOW_K);
	  print( " Перемещение      ",16,120,FontRus16x28,WHITE,BLUE_T);
	  regim=112;
	  break;

	case 2:
	  print( " Ускорение        ",16,60,FontRus16x28,WHITE,BLUE_T);
	  print( " Скорость         ",16,90,FontRus16x28,WHITE,BLUE_T);
	  print( " Перемещение      ",16,120,FontRus16x28,BLACK,YELLOW_K);
	  regim=113;
	  break;
	}
  MenuLevel = 2;
}

void PrintTermomentr()
{
	LCD_Clear_1(BLUE_B);
	print("      Термометр     ",0,21,FontRus16x28,WHITE,BLUE_T);

	print(" Внутри корп: ",0,120-40,FontRus16x28,BLACK,BLUE_B);
	print(" Усилитель:   ",0,120,FontRus16x28,BLACK,BLUE_B);
	print(" Блок питания:",0,120+40,FontRus16x28,BLACK,BLUE_B);

	print("0",319-16-8,121-40,Num8x8,WHITE,BLUE_B);
	print("С",319-16,120-40,FontRus16x28,WHITE,BLUE_B);

	print("0",319-16-8,121,Num8x8,WHITE,BLUE_B);
	print("С",319-16,120,FontRus16x28,WHITE,BLUE_B);

	print("0",319-16-8,121+40,Num8x8,WHITE,BLUE_B);
	print("С",319-16,120+40,FontRus16x28,WHITE,BLUE_B);

	regim=131;
}

void PrintClock(Uint8 Clock)
{
	int CurNumb = Clock % 10;
	switch (CurNumb)
	{
	 case 0: print("...  ",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 1: print(". .. ",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 2: print(". . .",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 3: print(" . ..",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 4: print("  ...",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 5: print(" . ..",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 6: print(". .. ",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 7: print(".. . ",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 8: print("...  ",70,0,FontRus8x15,WHITE,BLUE_T); break;
	 case 9: print("...  ",70,0,FontRus8x15,WHITE,BLUE_T); break;
	}
}

void PrintModeMenu(int CursorPos)
{
	MenuCursor = CursorPos;
	if (MenuLevel!=1)
	{
	LCD_Clear_1(BLUE_B);
	print("   Режим работы    ",0,21,FontRus16x28,WHITE,BLUE_T);
	}
	switch (CursorPos)
	{
	case 0:
		print( " Вибростенд       ",16,60,FontRus16x28,BLACK,YELLOW_K);
		print( " Термометр        ",16,90,FontRus16x28,WHITE,BLUE_T);
		//print( " Термометр        ",16,120,FontRus16x28,WHITE,BLUE_T);
		regim=11;
	    break;
	case 1:
		print( " Вибростенд       ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Термометр        ",16,90,FontRus16x28,BLACK,YELLOW_K);
		//print( " Термометр        ",16,120,FontRus16x28,WHITE,BLUE_T);
		regim=13;
	    break;
	    /*
	case 2:
		print( " Вибростенд       ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Виброметр        ",16,90,FontRus16x28,WHITE,BLUE_T);
		print( " Термометр        ",16,120,FontRus16x28,BLACK,YELLOW_K);
		regim=13;
		break;*/
	}
	MenuLevel = 1;
}

void PrintMainMenu(int CursorPos)
{
	MenuCursor = CursorPos;
	if (MenuLevel!=0)
	{
		LCD_Clear_1(BLUE_B);
		print("    Главное меню   ",0,21,FontRus16x28,WHITE,BLUE_T);
	}
	switch (CursorPos)
	{
	case 0:
		print( " Режим            ",16,60,FontRus16x28,BLACK,YELLOW_K);
	    print( " Настройки        ",16,90,FontRus16x28,WHITE,BLUE_T);
	    print( " Калибровка       ",16,120,FontRus16x28,WHITE,BLUE_T);
	    regim=1;
	    break;
	case 1:
		print( " Режим            ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Настройки        ",16,90,FontRus16x28,BLACK,YELLOW_K);
		print( " Калибровка       ",16,120,FontRus16x28,WHITE,BLUE_T);
		regim=2;
		break;
	case 2:
		print( " Режим            ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Настройки        ",16,90,FontRus16x28,WHITE,BLUE_T);
		print( " Калибровка       ",16,120,FontRus16x28,BLACK,YELLOW_K);
		regim=3;
		break;
	}
	MenuLevel = 0;
}

void PrintSettingsMenu(int CursorPos)
{
	MenuCursor = CursorPos;
	if (MenuLevel!=3)
	{
		LCD_Clear_1(BLUE_B);
		print("    Меню настроек   ",0,21,FontRus16x28,WHITE,BLUE_T);
	}
	switch (CursorPos)
	{
	case 0:
	    print( " Дата и Время     ",16,60,FontRus16x28,BLACK,YELLOW_K);
	    print( " Подсветка        ",16,90,FontRus16x28,WHITE,BLUE_T);
	    print( " Аккумулятор      ",16,120,FontRus16x28,WHITE,BLUE_T);
		print( " Статистика       ",16,150,FontRus16x28,WHITE,BLUE_T);
	    regim=21;
	    break;
	case 1:
		print( " Дата и Время     ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Подсветка        ",16,90,FontRus16x28,BLACK,YELLOW_K);
		print( " Аккумулятор      ",16,120,FontRus16x28,WHITE,BLUE_T);
		print( " Статистика       ",16,150,FontRus16x28,WHITE,BLUE_T);
		regim=22;
		break;
	case 2:
		print( " Дата и Время     ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Подсветка        ",16,90,FontRus16x28,WHITE,BLUE_T);
		print( " Аккумулятор      ",16,120,FontRus16x28,BLACK,YELLOW_K);
		print( " Статистика       ",16,150,FontRus16x28,WHITE,BLUE_T);
		regim=23;
		break;
	case 3:
		print( " Дата и Время     ",16,60,FontRus16x28,WHITE,BLUE_T);
		print( " Подсветка        ",16,90,FontRus16x28,WHITE,BLUE_T);
		print( " Аккумулятор      ",16,120,FontRus16x28,WHITE,BLUE_T);
		print( " Статистика       ",16,150,FontRus16x28,BLACK,YELLOW_K);
		regim=24;
		break;
	}
	MenuLevel = 3;
}


void PrintCalibrMenu()
{
	LCD_Clear_1(BLUE_B);
	print("     Введите код    ",0,21,FontRus16x28,WHITE,BLUE_T);
    printNumI( 0,80,100,Num40x53,BLACK,BLUE_B);
	printNumI( 0,120,100,Num40x53,BLACK,BLUE_B);
	printNumI( 0,160,100,Num40x53,BLACK,BLUE_B);
	printNumI( 0,200,100,Num40x53,BLACK,BLUE_B);
	code=0;
	regim=31;
	MenuLevel = 4;
}

void PrintDateTimeMenu()
{
	LCD_Clear_1(BLUE_B);
    print( "    Дата и время    ",0,21,FontRus16x28,WHITE,BLUE_T);
   	print( "        .  .        ",0,100,FontRus16x28,BLACK,BLUE_B);
    print( "        :  :        ",0,140,FontRus16x28,BLACK,BLUE_B);
    KurRTC = 1;
    LoadRTCKur();
    LoadRTCinBuf();
    printNumIRTC();
   	regim=211;
   	MenuLevel = 5;
}

void PrintScreenMenu()
{
	LCD_Clear_1(BLUE_B);
	print("      Подсветка     ",0,21,FontRus16x28,WHITE,BLUE_T);
	liht2 = 99-(liht*3.2);
	if(liht2 < 10)
	{
	   print("-",120,100,Num40x53,BLACK,BLUE_B);
	   printNumI( liht2,160,100,Num40x53,BLACK,BLUE_B);
	}
	else
		if (liht2 < 100)
	   {
	   		printNumI( liht2,120,100,Num40x53,BLACK,BLUE_B);
	   }

	print("/",200,100,Num40x53,BLACK,BLUE_B);
	regim=221;
	MenuLevel = 6;
}

void PrintBataryMenu()
{
	int i;
	LCD_Clear_1(BLUE_B);
	print("     Аккумулятор    ",0,21,FontRus16x28,WHITE,BLUE_T);
	print("ЗАРЯД:",10,60,FontRus8x15,BLACK,BLUE_B);
	print("ТОК:",10,90,FontRus8x15,BLACK,BLUE_B);
	print("НАПРЯЖЕНИЕ:",10,120,FontRus8x15,BLACK,BLUE_B);
	print("ТЕМПЕРАТУРА:",10,150,FontRus8x15,BLACK,BLUE_B);
	print("ОСТАЛОСЬ:",10,180,FontRus8x15,BLACK,BLUE_B);
	print("СТАТУС:",10,210,FontRus8x15,BLACK,BLUE_B);
	print("%",190,50,FontRus16x28,WHITE,BLUE_B);
	print("мА",190,80,FontRus16x28,WHITE,BLUE_B);
	print("В",190,110,FontRus16x28,WHITE,BLUE_B);
	print("0",182,141,Num8x8,WHITE,BLUE_B);
	print("С",190,140,FontRus16x28,WHITE,BLUE_B);

	/*
	for(i=0;i<10;i++)
	{
		drawBitmap(250,62+i,40,1,bat_nip);
	}
	for(i=0;i<8;i++)
	{
		drawBitmap(230,72+i,80,1,bat_up);
	}
	for(i=0;i<120;i++)
	{
		drawBitmap(230,80+i,80,1,bat_fon);
	}
	for(i=0;i<8;i++)
	{
		drawBitmap(230,200+i,80,1,bat_up);
	}
	*/
	regim=231;
	MenuLevel = 7;
}


void PrintStatistic()
{
	LCD_Clear_1(BLUE_B);
	print("     Статистика       ",0,21,FontRus16x28,WHITE,BLUE_T);
	print("Наработка:",10,60,FontRus16x28,WHITE,BLUE_B);
	printNumI(HoursOnWork,40,100,FontRus16x28,WHITE,BLUE_B);
	print("час.",100,100,FontRus16x28,WHITE,BLUE_B);
	printNumI(MinuntsOnWork,160,100,FontRus16x28,WHITE,BLUE_B);
	print("мин.",200,100,FontRus16x28,WHITE,BLUE_B);
	print("Дата калибровки:",10,140,FontRus16x28,WHITE,BLUE_B);
	printNumI(CalibrDate[0],20,180,FontRus16x28,WHITE,BLUE_B);
	print(".",60,180,FontRus16x28,WHITE,BLUE_B);
	printNumI(CalibrDate[1],70,180,FontRus16x28,WHITE,BLUE_B);
	print(".",110,180,FontRus16x28,WHITE,BLUE_B);
	printNumI(CalibrDate[2],120,180,FontRus16x28,WHITE,BLUE_B);
	regim = 241;
	//print(" Дата пос ",0,140,FontRus16x28,WHITE,BLUE_B);
	//print(ADRUINO_Data)
	/*TAS5424_ON();
	Temp_A=1;
	EVM5515_GPIO_setOutput(21,1);
	drawBitmap(140,2,16,16,las1);
	regim=241;
	MenuLevel = 8;*/
}


void PrintAccMenu(int CursorPos)
{
	if ((regim !=1111) && (regim != 1112))
	{
		LCD_Clear_1(GRAY0);
		print("Вибростенд/Ускорение",0,20,FontRus16x28,WHITE,BLUE_T);
		print(" Част.",10,80,FontRus8x15,BLACK,GRAY0);
		print("Воспр.",10,95,FontRus8x15,BLACK,GRAY0);
		print("Гц",270,84,FontRus16x28,BLACK,GRAY0);
		print("Ускор.",10,159,FontRus8x15,BLACK,GRAY0);
		print("  СКЗ",10,174,FontRus8x15,BLACK,GRAY0);
		print("м/",270,164,FontRus16x28,BLACK,GRAY0);
		print("с",292,164,FontRus16x28,BLACK,GRAY0);
		print("2",305,164,FontRus8x15,BLACK, GRAY0);
		fillRoundRect(57,143-5,264,210-5,YELLOW_K);
		fillRoundRect(57,64,264,130,YELLOW_K);
		fillRoundRect(58,65,263,129,WHITE_ADV);
		fillRoundRect(58,144-5,263,209-5,WHITE_ADV);
	}
	if (CursorPos == 0)
	{
	   LCD_Freq(reg_frequency,BLUE);
	   LCD_Acsel(reg_acseleration,BLACK);
	   regim=1111;
	}
	else
	{
		LCD_Freq(reg_frequency,BLACK);
		LCD_Acsel(reg_acseleration,BLUE);
		regim=1112;
	}

	MenuLevel = 9;
}


void PrintControlHelp(char * Msg)
{
	fillRect(0,214,320,240,BLUE_T);
	drawBitmap8bit(0,214,26,26,ArrowUp);
	drawBitmap8bit(26,214,26,26,ArrowDown);
	if (code != Calibr_CODE)
	{
	print(" Изм.амплитуды",52,222,FontRus8x15,WHITE,BLUE_T);
	drawBitmap8bit(170,214,26,26,ArrowLeft);
	drawBitmap8bit(196,214,26,26,ArrowRight);
	print(" Изм.частоты",222,222,FontRus8x15,WHITE,BLUE_T);
	}
	else
	{
		print(" Изм.коэфф.усил.",52,222,FontRus8x15,WHITE,BLUE_T);
		drawBitmap8bit(196,214,26,26,ArrowRight);
		print(" Сохранить",222,222,FontRus8x15,WHITE,BLUE_T);
	}
}

void PrintAboutScreen()
{
    LCD_Clear_1(BLUE_T);
	fillRoundRect(10,31,309,229,BLUE_T);
	print("    ВИБРОСТЕНД   ",16,50+20,FontRus16x28,YELLOW_K,BLUE_T);
	if (LaserStartFreq == 0)
		print("    ВЗВ2  ",24,90+20,FontRus16x28,YELLOW_K,BLUE_T);
	else
		print("   ВЗВ2  ",24,90+20,FontRus16x28,WHITE,BLUE_T);
	print("Версия ПО 20.0121",90,160,FontRus8x15,WHITE,BLUE_T);
	print("ООО НПФ ВИБРОН 2020(с)",80,210,FontRus8x15,WHITE,BLUE_T);

	//drawBitmap8bit(80,120,115,80,Vibron_logo);
	regim = 0;
	MenuLevel = 100;
}

void PrintVelMenu()
{
	LCD_Clear_1(BLUE_B);
	print("     Вибростенд     ",0,21,FontRus16x28,WHITE,BLUE_T);
	LCD_Freq(reg_frequency,BLACK);
	LCD_Rectangle(3,130,165,136,YELLOW_K);
	LCD_velosity(reg_velosity);
	LCD_Rectangle(3,220,165,240,BLUE_B);
	print(" Частота",176,69,FontRus16x28,WHITE,BLUE_B);
	print("      Гц",176,97,FontRus16x28,WHITE,BLUE_B);
	print(" Скорость",176,149,FontRus16x28,WHITE,BLUE_B);
	print(" СКЗ мм/с",176,177,FontRus16x28,WHITE,BLUE_B);
	regim=1121;
	MenuLevel = 10;
}


void PrintDisMenu()
{
	LCD_Clear_1(BLUE_B);
	print("     Вибростенд     ",0,21,FontRus16x28,WHITE,BLUE_T);
	LCD_Freq(reg_frequency,BLACK);
	LCD_Rectangle(3,130,165,136,YELLOW_K);
	LCD_displacement(reg_displacement);
	LCD_Rectangle(3,220,165,226,BLUE_B);
	print(" Частота",176,69,FontRus16x28,WHITE,BLUE_B);
	print("      Гц",176,97,FontRus16x28,WHITE,BLUE_B);
	print(" Перемещ.",176,149,FontRus16x28,WHITE,BLUE_B);
	print(" разм мкм",176,177,FontRus16x28,WHITE,BLUE_B);
	regim=1131;
	MenuLevel = 11;
}


void FreqInput(Uint8 Key)
{
	switch (Key)
	{
		case one: 		reg_frequency=(reg_frequency*10)+1; break;
		case two: 		reg_frequency=(reg_frequency*10)+2; break;
		case three: 	reg_frequency=(reg_frequency*10)+3; break;
		case four:		reg_frequency=(reg_frequency*10)+4; break;
		case five:		reg_frequency=(reg_frequency*10)+5; break;
		case six:		reg_frequency=(reg_frequency*10)+6; break;
		case seven:		reg_frequency=(reg_frequency*10)+7; break;
		case eight:		reg_frequency=(reg_frequency*10)+8; break;
		case nine:		reg_frequency=(reg_frequency*10)+9; break;
		case zero:		reg_frequency=(reg_frequency*10)+0; break;
	}
	reg_frequency = reg_frequency % 100000;
	LCD_Freq(reg_frequency,BLUE);
}

Uint32 AmpInput(Uint8 Key, Uint8 Mode, Uint32 reg)
{
	switch (Key)
	{
		case one: 		reg=(reg*10)+1; break;
		case two: 		reg=(reg*10)+2; break;
		case three: 	reg=(reg*10)+3; break;
		case four:		reg=(reg*10)+4; break;
		case five:		reg=(reg*10)+5; break;
		case six:		reg=(reg*10)+6; break;
		case seven:		reg=(reg*10)+7;	break;
		case eight:		reg=(reg*10)+8;	break;
		case nine:		reg=(reg*10)+9;	break;
		case zero:		reg=(reg*10)+0;	break;
	}
	reg = reg % 10000;
	switch (Mode)
	{
		case MOD_Acc: 	LCD_Acsel(reg,BLUE); break;
		case MOD_Vel: 	LCD_velosity(reg); break;
		case MOD_Dis: 	LCD_displacement(reg); break;
	}
    return reg;
}


void ChangeFreq(int x)
{
	int incr = 0;
	if (x>0) incr = 1;
			else incr = -1;
	if(reg_frequency < 100)
			 {
	        		   reg_frequency=reg_frequency+incr;
	        		 }
	        		  else
	        		 	   {
	        		        		    if (reg_frequency < 1000)
	        		        		     {
	        		        		      reg_frequency=reg_frequency+incr*10;
	        		        		     }
	        		        		      else
	        		        		     {
	        		        		       if (reg_frequency < 10000)
	        		        		    	  reg_frequency=reg_frequency+incr*100;
	        		        		       else reg_frequency=reg_frequency+incr*1000;
	        		        		     }
	        		        		    }

	if (reg_frequency > MAX_FREQ) reg_frequency = MAX_FREQ;

	if (code!=9999) LCD_Freq(reg_frequency,BLACK);
}

void PrintDebugInfo()
{
	LCD_Clear(BLUE_B);
	LCD_Rectangle(0,0,319,19,BLACK);
	print("PCF8474",1,20,Font16x24,WHITE,BLUE_B);
	printNumI(PCF8574Test,150,20,Font16x24,WHITE,BLUE_B);

	print("LM73-1",1,44,Font16x24,WHITE,BLUE_B);
	printNumI(LM73Adr1Test,150,44,Font16x24,WHITE,BLUE_B);

	print("LM73-2",1,68,Font16x24,WHITE,BLUE_B);
	printNumI(LM73Adr2Test,150,68,Font16x24,WHITE,BLUE_B);

	print("LM73-3",1,92,Font16x24,WHITE,BLUE_B);
	printNumI(LM73Adr3Test,150,92,Font16x24,WHITE,BLUE_B);

	print("KeyBrd",1,116,Font16x24,WHITE,BLUE_B);
	printNumI(KeyBoardTest,150,116,Font16x24,WHITE,BLUE_B);

	print("PwrAmp",1,140,Font16x24,WHITE,BLUE_B);
	printNumI(PowerAmplTest,150,140,Font16x24,WHITE,BLUE_B);

	print("PwrRst",1,164,Font16x24,WHITE,BLUE_B);
	printNumI(BatRTest,150,164,Font16x24,WHITE,BLUE_B);
}






#endif




				
			




