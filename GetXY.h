/*
 *  Copyright 2010 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  GetXY header file
 *
 */

#ifndef GetXY_
#define GetXY_





Int16 GetX( )
{	
			Uint16 Get_X;
			SAR_CLKCTRL = 0x00010;           
			SAR_PINCTRL = 0x03100;      
			SAR_GPOCTRL = 0x00132;			
			waitusec( 6000*3 ); 			       
			SAR_CTRL    = 0x0D400;      									  	
	  		waitusec( 10*3 ); 	  							
    		    		    		    		    		   
    		if (((SAR_DATA&0x03FF) > Xleft))
    		{	  		
	  			 Get_X=0;
	  		}
	  		else if ((SAR_DATA&0x03FF)< Xright)
	  		{
	  			 Get_X=0;
	  		}	  			  
	  		else if (((SAR_DATA&0x03FF)<=Xleft)&&(SAR_DATA&0x03FF)>=Xright)
	  		{
	  			 //Get_X=(Uint16)((Xleft-(SAR_DATA&0x03FF)))/DeltaX;	
	  			 
	  			 Get_X=(Uint16)(((SAR_DATA&0x03FF)/DeltaX)-57);
	  			   			 
	  			 XcordTemp = SAR_DATA&0x03FF;	  			 	  			
	  		}	  			  						  			  	
	  		else
	  		{
	  		;	  			 
	  		}	  	    
	  			  	
	  		
    		//print("    ",0,60,Font16x24,BLACK,WHITE);	
    		//printNumI( Get_X,0,60,Font16x24,BLACK,WHITE);		//Get_X
    		
    		return Get_X;
}

Int16 GetY( )
{					
			Uint16 Get_Y;	
			SAR_CLKCTRL = 0x00010;           
			SAR_PINCTRL = 0x03100;      
			SAR_GPOCTRL = 0x001C8;  								
			waitusec( 6000*3 ); 			      
			SAR_CTRL    = 0x0B400;      						
  			waitusec( 10*3 ); 
  			  			  			  	
  			if (((SAR_DATA&0x03FF) > Yleft))
    		{	  		
	  			 Get_Y=0;
	  		}
	  		else if ((SAR_DATA&0x03FF)< Yright)
	  		{
	  			 Get_Y=0;
	  		}	  			  
	  		else if (((SAR_DATA&0x03FF)<=Yleft)&&(SAR_DATA&0x03FF)>=Yright)
	  		{
	  			 Get_Y=(Uint16)((Yleft-(SAR_DATA&0x03FF)))/DeltaY;	  			 
	  			 YcordTemp = SAR_DATA&0x03FF;	  			 	  			
	  		}	  			  						  			  	
	  		else
	  		{
	  		;	  			 
	  		}	  	  			  			  			  
  			

  			
			//print("    ",0,90,Font16x24,BLACK,WHITE);	
    		//printNumI( Get_Y,0,90,Font16x24,BLACK,WHITE);    //Get_Y
    		return Get_Y;
}

          



                                




#endif
