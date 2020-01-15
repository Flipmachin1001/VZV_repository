#ifndef _MENU_H_
#define _MENU_H_



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
							
				drawButtonRusCal(1+20*0,140,18+20*0,170,WHITE,BLACK,BLACK,"�");  
				drawButtonRusCal(1+20*1,140,18+20*1,170,WHITE,BLACK,BLACK,"�");  									
				drawButtonRusCal(1+20*2,140,18+20*2,170,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*3,140,18+20*3,170,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*4,140,18+20*4,170,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*5,140,18+20*5,170,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*6,140,18+20*6,170,WHITE,BLACK,BLACK,"�"); 															
				drawButtonRusCal(1+20*7,140,18+20*7,170,WHITE,BLACK,BLACK,"�");  									
				drawButtonRusCal(1+20*8,140,18+20*8,170,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*9,140,18+20*9,170,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*10,140,18+20*10,170,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*11,140,18+20*11,170,WHITE,BLACK,BLACK,"�"); 	
								
				drawButtonRusCal(11+20*0,175,28+20*0,205,WHITE,BLACK,BLACK,"�");  
				drawButtonRusCal(11+20*1,175,28+20*1,205,WHITE,BLACK,BLACK,"�");  									
				drawButtonRusCal(11+20*2,175,28+20*2,205,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(11+20*3,175,28+20*3,205,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(11+20*4,175,28+20*4,205,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(11+20*5,175,28+20*5,205,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(11+20*6,175,28+20*6,205,WHITE,BLACK,BLACK,"�"); 															
				drawButtonRusCal(11+20*7,175,28+20*7,205,WHITE,BLACK,BLACK,"�");  									
				drawButtonRusCal(11+20*8,175,28+20*8,205,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(11+20*9,175,28+20*9,205,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(11+20*10,175,28+20*10,205,WHITE,BLACK,BLACK,"�"); 
											
				drawButtonRusCal(1+20*0,210,18+20*0,240,BLUE3,BLACK,BLACK," ");  
				drawButtonRusCal(1+20*1,210,18+20*1,240,WHITE,BLACK,BLACK,"�");  									
				drawButtonRusCal(1+20*2,210,18+20*2,240,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*3,210,18+20*3,240,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*4,210,18+20*4,240,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*5,210,18+20*5,240,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*6,210,18+20*6,240,WHITE,BLACK,BLACK,"�"); 															
				drawButtonRusCal(1+20*7,210,18+20*7,240,WHITE,BLACK,BLACK,"�");  									
				drawButtonRusCal(1+20*8,210,18+20*8,240,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*9,210,18+20*9,240,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*10,210,18+20*10,240,WHITE,BLACK,BLACK,"�"); 
				drawButtonRusCal(1+20*11,210,18+20*11,240,BLUE3,BLACK,BLACK," "); 	
										
				drawButtonRusCal(1,245,58,275,WHITE,BLACK,BLACK,"�����");  				 			
				drawButtonRusCal(61,245,138,275,WHITE,BLACK,BLACK," ������");				 															
				drawButtonRusCal(141,245,178,275,WHITE,BLACK,BLACK," ��");  																
				drawButtonRusCal(181,245,18+20*11,275,WHITE,BLACK,BLACK," ����"); 				 									
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
								
				drawButtonRus(181,275,235,314,BLUE7,BLACK,WHITE,"�����");  				
}





void ButtonBack(void)
{											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("�����",185,295-1,FontRus8x15,WHITE,BLUE7); 
}

void ButtonNewBack(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("�������",10,295-1,FontRus8x15,WHITE,BLUE7); 
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("�����",185,295-1,FontRus8x15,WHITE,BLUE7); 
}


void ButtonSaveBack(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("���������",2,295-1,FontRus8x15,WHITE,BLUE7); 
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("�����",185,295-1,FontRus8x15,WHITE,BLUE7); 
}







void ButAdd(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("��������",6,294,FontRus8x15,WHITE,BLUE7);
}







void ButClear(void)
{
				fillRoundRect(0+9+74,280,0+74+9+74,319,YELLOW);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74,280,0+74+9+74,319,BLACK);	
				print("�����",85+17,295-1,FontRus8x15,BLACK,YELLOW); 
}


void ButStop(void)
{
				fillRoundRect(0,280,0+74,319,GREEN);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("����",23,294,FontRus8x15,WHITE,GREEN);
}

void ButZapusk(void)
{
				fillRoundRect(0,280,0+74,319,GREEN);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("�����",19,294,FontRus8x15,BLACK,GREEN);
}


void ButInter(void)
{
				fillRoundRect(0+9+74,280,0+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74,280,0+74+9+74,319,BLACK);	
				print("��������",85,295-1,FontRus8x15,WHITE,BLUE7); 
} 


void ButBack(void)
{
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("�����",185,295-1,FontRus8x15,WHITE,BLUE7); 
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
				print("���������",2,295-1,FontRus8x15,WHITE,BLUE7);
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("�����",185,295-1,FontRus8x15,WHITE,BLUE7); 
}


void ButtonSaveNastrBack(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("���������",2,295-1,FontRus8x15,WHITE,BLUE7); 
		
				fillRoundRect(0+9+74,280,0+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74,280,0+74+9+74,319,BLACK);	
				print("���������",85,295-1,FontRus8x15,WHITE,BLUE7); 
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("�����",185,295-1,FontRus8x15,WHITE,BLUE7); 
}

void ButtonSaveMenuBack(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("���������",2,295-1,FontRus8x15,WHITE,BLUE7); 
		
				fillRoundRect(0+9+74,280,0+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74,280,0+74+9+74,319,BLACK);	
				print("����",105,295-1,FontRus8x15,WHITE,BLUE7); 
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("�����",185,295-1,FontRus8x15,WHITE,BLUE7); 
}

void ButtonNastrMenuBack(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("���������",2,295-1,FontRus8x15,WHITE,BLUE7); 
		
				fillRoundRect(0+9+74,280,0+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74,280,0+74+9+74,319,BLACK);	
				print("����",105,295-1,FontRus8x15,WHITE,BLUE7); 
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("�����",185,295-1,FontRus8x15,WHITE,BLUE7); 
}


void ButtonNastrRegimBack(void)
{
				fillRoundRect(0,280,0+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0,280,0+74,319,BLACK);	
				print("���������",2,295-1,FontRus8x15,WHITE,BLUE7); 
		
				fillRoundRect(0+9+74,280,0+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74,280,0+74+9+74,319,BLACK);	
				print("�����",105-4,295-1,FontRus8x15,WHITE,BLUE7); 
											
				fillRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLUE7);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(0+9+74+9+74,280,0+74+9+74+9+74,319,BLACK);
				print("�����",185,295-1,FontRus8x15,WHITE,BLUE7); 
}





void Button123(void)
{
	
		//sdReadGraphic( 0x3E000 );	
	
	   	//nand_readGrafic(0x1FEA0000, 0, 21,240,299 );  
		//nand_readGrafic(0x1FEA0000, 0, 0,240,320 );      
 	
 	/*	 	  	 	 		 		 	  	 	 		 		 	 	 	 	 	 	  	 	 	  	 	 	  	 	 	   	  	  	 
	LCD_Rectangle(0,0,239,20,GRAY4);	//Line 1	GRAY2	
	LCD_Rectangle(215,3,237,17,WHITE);  //���������
	LCD_Rectangle(213,7,214,13,WHITE);	//Pupirka
	LCD_Rectangle(216,4,236,16,BLACK);  //���������		
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
        		print("��������",8,303,FontRus8x15,BLACK,WHITE);
				ButtonMenu(); 
				print("����",104,303,FontRus8x15,BLACK,WHITE);
				ButtonPower();				
				print("�������",172,303,FontRus8x15,BLACK,WHITE);
}


void Button123_(void)
{
				ButtonRegim();
        		print("��������",8,303,FontRus8x15,BLACK,BLUE1);
				ButtonMenu(); 
				print("����",104,303,FontRus8x15,BLACK,BLUE1);
				ButtonPower();				
				print("�������",172,303,FontRus8x15,BLACK,BLUE1);
}





void EnableTitleMenu(void)
{
				LCD_Rectangle(0,21,239,245,WHITE);
				
				fillRoundRect(14,26,14+52,26+52,RED);   				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(14,26,14+52,26+52,BLACK);	
				print("���������",4,80+1,FontRus8x15,BLACK,WHITE); 					        	                              	                   
        		fillRoundRect(94,26,94+52,26+52,BLUE);                      
        		drawRoundRect(94,26,94+52,26+52,BLACK);                             		
        		print("��������",88,80+1,FontRus8x15,BLACK,WHITE);         	
        		fillRoundRect(174,26,174+52,26+52,GREEN);                      
        		drawRoundRect(174,26,174+52,26+52,BLACK);          		
        		print("��������",168,80+1,FontRus8x15,BLACK,WHITE); 
        	        	        
        		fillRoundRect(14,101,14+52,101+52,CYAN);                      
        		drawRoundRect(14,101,14+52,101+52,BLACK);          		
        		print("�������",12,155+1,FontRus8x15,BLACK,WHITE);         	
        		fillRoundRect(94,101,94+52,101+52,MAGENTA);                      
        		drawRoundRect(94,101,94+52,101+52,BLACK);          	        		
        		print("�����������",76,155+1,FontRus8x15,BLACK,WHITE);         	
        		fillRoundRect(174,101,174+52,101+52,YELLOW);                      
        		drawRoundRect(174,101,174+52,101+52,BLACK);          	        		
        		print("������",177,155+1,FontRus8x15,BLACK,WHITE);         	
        	        	        
        		fillRoundRect(14,176,14+52,176+52,BROWN);                      
        		drawRoundRect(14,176,14+52,176+52,BLACK);          	
        		print("����",24,230+1,FontRus8x15,BLACK,WHITE);         	
        		fillRoundRect(94,176,94+52,176+52,BRIGHTBLUE);                      
        		drawRoundRect(94,176,94+52,176+52,BLACK);          	        		
        		print("���������",84,230+1,FontRus8x15,BLACK,WHITE);         	        	
        		fillRoundRect(174,176,174+52,176+52,GRAY2);                      
        		drawRoundRect(174,176,174+52,176+52,BLACK);          	  
        		print("���������",164,230+1,FontRus8x15,BLACK,WHITE);  
      	        	        	       
        		LCD_Rectangle(0,246,239,319,BLUE1);		
        		
        		
        		Button123_();
        		/*        		
        		drawBitmap (14,249,52,52,refresh);
				print("��������",8,302,FontRus8x15,BLACK,BLUE1);				
				drawBitmap (94,249,52,52,menu);
				print("����",104,302,FontRus8x15,BLACK,BLUE1);							
				drawBitmap (174,249,52,52,powerb);				
				print("�������",172,302,FontRus8x15,BLACK,BLUE1);
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
        	   	print("   ���������   ",0,25,FontRus16x27,WHITE,BLUE);																
																										        	  						
											
				fillRoundRect(3,60,236,110,WHITE);
				drawRoundRect(3,60,236,110,BLACK);	
				print("�������",20,74,FontRus16x27,BLACK,WHITE); 
																	
				fillRoundRect(3,115-1,236,165-1,WHITE);
				drawRoundRect(3,115-1,236,165-1,BLACK);
				print("����������",20,130-2,FontRus16x27,BLACK,WHITE); 
				
				fillRoundRect(3,170-2,236,220-2,WHITE);
				drawRoundRect(3,170-2,236,220-2,BLACK);				
				print("���� � �����",20,186-4,FontRus16x27,BLACK,WHITE); 								
								
				fillRoundRect(3,225-3,236,275-3,WHITE);
				drawRoundRect(3,225-3,236,275-3,BLACK);
				print("�����",20,240-5,FontRus16x27,BLACK,WHITE); 				
																														
				ButtonBack();
}








void Enable91(void)
{
				LCD_Rectangle(0,21,239,319,BLUE1);
        	    LCD_Rectangle(0,21,239,24,BLUE);        	            	   
        	   	print("    �������    ",0,25,FontRus16x27,WHITE,BLUE);																				
				
				fillRoundRect(3,60,236,110,WHITE);
				drawRoundRect(3,60,236,110,BLACK);	
				print("�������",20,74,FontRus16x27,BLACK,WHITE); 
																	
				fillRoundRect(3,115-1,236,165-1,WHITE);
				drawRoundRect(3,115-1,236,165-1,BLACK);
				print("���������",20,130-2,FontRus16x27,BLACK,WHITE); 
																																											
				ButtonBack();
}

void Enable92(void)
{
				LCD_Rectangle(0,21,239,319,BLUE1);
        	    LCD_Rectangle(0,21,239,24,BLUE);        	            	   
        	   	print("   ����������   ",0,25,FontRus16x27,WHITE,BLUE);																				
																									
				drawHLine(1,53,30,BLACK);
				drawVLine(1,53,30,BLACK);
				
				drawHLine(208,53,30,BLACK);
				drawVLine(238,53,30,BLACK);
								
				drawHLine(1,278,30,BLACK);
				drawVLine(1,248,30,BLACK);
				
				drawHLine(208,278,30,BLACK);
				drawVLine(238,248,30,BLACK);												
													
				print(" ��������� ��������           ",0,75,FontRus8x15,BLACK,BLUE1);				
				print(" ���������� ����� ������� �   ",0,90,FontRus8x15,BLACK,BLUE1);				
				print(" ��������� ����� ����������   ",0,105,FontRus8x15,BLACK,BLUE1);								
				print(" ������� ������ ���������.    ",0,120,FontRus8x15,BLACK,BLUE1);
				print(" ������� ������� ����������   ",0,135,FontRus8x15,BLACK,BLUE1);				 
				print(" ����������� ����� � �����    ",0,150,FontRus8x15,BLACK,BLUE1);
				print(" ���������� �������.          ",0,165,FontRus8x15,BLACK,BLUE1);
				print(" ���� �������� ������� �      ",0,180,FontRus8x15,BLACK,BLUE1);
				print(" �����-������ ����� �������   ",0,195,FontRus8x15,BLACK,BLUE1);
				print(" �� ����������� �����, ��� �� ",0,210,FontRus8x15,BLACK,BLUE1);
				print(" ���� ���������, �� ����������",0,225,FontRus8x15,BLACK,BLUE1);
				print(" ���������� ���������.        ",0,240,FontRus8x15,BLACK,BLUE1);
				 				 							 							 																					 																																																														 																																						
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
        	   	print("  ���� � �����  ",0,25,FontRus16x27,WHITE,BLUE);																				
																																	
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
																																																					
				print("���",  13+3,35,FontRus8x15,BLACK,BLUE1);
				print("���",  59+3,35,FontRus8x15,WHITE,BLUE20);
				print("���", 105+3,35,FontRus8x15,WHITE,BLUE20);
				print("���",  151+3,35,FontRus8x15,WHITE,BLUE20);
				print("���",  197+3,35,FontRus8x15,WHITE,BLUE20);				
															
				print(":",73,108-20,Font16x24,BLACK,BLUE1); 
					

				fillRoundRect(171,70,171+52,70+52,GREEN); 					 				 				 				 				 			             	        				 				 				 	        	        	        			             	     
				drawRoundRect(171,70,171+52,70+52,BLACK);	
				print("���",171+14,91,FontRus8x15,BLACK,GREEN);



				print("  ���",12,121,FontRus8x15,BLACK,BLUE1);
				print("  ������",80,121,FontRus8x15,BLACK,BLUE1);


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



void Enable71(void)														// ����������
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
								
				print("���",  13+3,35,FontRus8x15,WHITE,BLUE20);
				print("���",  59+3,35,FontRus8x15,BLACK,BLUE1);
				print("���", 105+3,35,FontRus8x15,WHITE,BLUE20);
				print("���",  151+3,35,FontRus8x15,WHITE,BLUE20);
				print("���",  197+3,35,FontRus8x15,WHITE,BLUE20);
				
				
				
				
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
			
				
				print("���",  13+3,35,FontRus8x15,WHITE,BLUE20);
				print("���",  59+3,35,FontRus8x15,WHITE,BLUE20);
				print("���", 105+3,35,FontRus8x15,BLACK,BLUE1);
				print("���",  151+3,35,FontRus8x15,WHITE,BLUE20);
				print("���",  197+3,35,FontRus8x15,WHITE,BLUE20);
				







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
								
				
				
				print("  ���",12,123,FontRus8x15,BLACK,BLUE1);
				print("  ������",80,123,FontRus8x15,BLACK,BLUE1);
				print("�������",172,123,FontRus8x15,BLACK,BLUE1);			
				
				
				
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
			
				
				print("���",  13+3,35,FontRus8x15,WHITE,BLUE20);
				print("���",  59+3,35,FontRus8x15,WHITE,BLUE20);
				print("���", 105+3,35,FontRus8x15,WHITE,BLUE20);
				print("���",  151+3,35,FontRus8x15,BLACK,BLUE1);
				print("���",  197+3,35,FontRus8x15,WHITE,BLUE20);
																																																																																		 				
				 				 							 							 																					 																																																														 																																						
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
			
				
				print("���",  13+3,35,FontRus8x15,WHITE,BLUE20);
				print("���",  59+3,35,FontRus8x15,WHITE,BLUE20);
				print("���", 105+3,35,FontRus8x15,WHITE,BLUE20);
				print("���",  151+3,35,FontRus8x15,WHITE,BLUE20);
				print("���",  197+3,35,FontRus8x15,BLACK,BLUE1);
					
				print(":",73,108,Font16x24,BLACK,BLUE1); 
				print(":",152,108,Font16x24,BLACK,BLUE1);		
					
					
					
					
				ButtonRTC();
																																																																																		 				
				 				 							 							 																					 																																																														 																																						
	 			ButtonSaveNastrBack();
}

















void Enable921(void)
{
				LCD_Rectangle(0,21,239,319,BLUE1);
        	  																																										
				print(" ������� �����  ",0,140,FontRus16x27,BLACK,BLUE1);
				print(" � ����� ������ ",0,165,FontRus16x27,BLACK,BLUE1); 
								
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
																																																					
				print(" ����� ������������� ������   ",0,105,FontRus8x15,BLACK,BLUE1);								
				print(" ��� ���������� ��������.     ",0,120,FontRus8x15,BLACK,BLUE1);
				print(" ���� �� ������ ���������� �� ",0,135,FontRus8x15,BLACK,BLUE1);				 
				print(" � �������� ��������, ��      ",0,150,FontRus8x15,BLACK,BLUE1);
				print(" ������� ������ *���������*.  ",0,165,FontRus8x15,BLACK,BLUE1);
				print(" ���� ������ ��������         ",0,180,FontRus8x15,BLACK,BLUE1);
				print(" ���������� ��������, ��      ",0,195,FontRus8x15,BLACK,BLUE1);
				print(" ������� ������ *�����*.      ",0,210,FontRus8x15,BLACK,BLUE1);
																										 							 							 																					 																																																														 																																	
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
      			print("      ����� ������� �����   ",6,55,FontRus8x15,BLACK,WHITE);	   					   
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
      			print("      ����� ������� �����   ",6,55,FontRus8x15,BLACK,WHITE);			      						   
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



      			//print( "    ���� � �����    ",0,21,FontRus16x28,WHITE,BLUE_T);				
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







#endif




				
			




