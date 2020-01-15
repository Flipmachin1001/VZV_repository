/*
    iir.c - IIR direct form II biquads implementation
    prototype: void iir(int *, int, int *, float *, int, float *);

    Entry: arg0: pointer to the input sample buffer
           arg1: size of the input sample buffer
           arg2: pointer to the output sample buffer
           arg3: pointer to the coefficients array
           arg4: number of second-order IIR sections
           arg5: pointer to the filter delay-line buffer

    Return: None
*/



/*	
#define CHECK_OVERFLOW 1
#if CHECK_OVERFLOW
static 	float w_max=-1.,w_min=1.;
#endif
*/


void iir(short *x, int Nx, double *coef, int Ns, double *w)  
{      
    int i,j,n,m,k,l,p;
    double temp, w_0;
    
                   
    double  w_max=0.0,w_max2=0.0;      
    
                          
    m=Ns*5;             /* Setup for circular buffer coef[] */
    k=Ns*2;             /* Setup for circular buffer d[] */

    for (j=0,l=0,n=0; n<Nx; n++)        /* IIR filter */ 
    {
        w_0 = (double)(x[n]);    /* Q15 to float */   //w_0 = (double)(x[n]/32767.0);
        //w_0 = d[n];
        for (i=0; i<Ns; i++)
        {
            w_0 -= *(w+l) * *(coef+j); j++; l=(l+Ns)%k;
            w_0 -= *(w+l) * *(coef+j); j++; 
            
    
     	
            
        /////////////////////
	    
	    if (w_0 >= w_max) 	w_max = w_0;
	     	     
        //if (w_0 <= w_min)  	w_min = w_0; 
	    	    	    	    	    		
	 	///////////////////// 	    	   	  
    	
    
            
            
	    temp = *(w+l);
	    *(w+l) = w_0;   
	    
	   /* 
	    
	    #if CHECK_OVERFLOW            
            for (p=0;p<k;p++)
            {
                if (w_max <= w_0) w_max = w_0;
                if (w_min > w_0)  w_min = w_0; 
            } 
            #endif   
            
        */    
            
            
            			                    
            w_0  =   temp * *(coef+j); j++;                         //            w_0  =   temp * *(coef+j); j++; 
          	w_0 += *(w+l) * *(coef+j); j++; l=(l+Ns)%k;				//            w_0 += *(w+l) * *(coef+j); j++; l=(l+Ns)%k;
            w_0 += *(w+l) * *(coef+j); j=(j+1)%m; l=(l+1)%k;   		//			  w_0 += *(w+l) * *(coef+j); j=(j+1)%m; l=(l+1)%k; 
            
            
            
        /////////////////////
	    
	    if (w_0 >= w_max2) 	w_max2 = w_0;
	     	     
        //if (w_0 <= w_min2)  	w_min2 = w_0; 
	    	    	    	    	    		
	 	/////////////////////
	 	
	 	
	 	
	 	  	    
          /*  
            
            #if CHECK_OVERFLOW            
            for (p=0;p<k;p++)
            {
                if (w_max <= w_0) w_max = w_0;
                if (w_min > w_0) w_min = w_0; 
            } 
            #endif
            
           */            		
        }
        x[n] = (short)(w_0);        /* Q15 format output *///r[n] = (int)(w_0*32767);        /* Q15 format output */
        //d[n] = w_0;
    }
    
      w[0] = w_max;
      w[1] = w_max2;
      //max_min[1] = w_min;
      //max_min[2] = w_max2;
	  //max_min[3] = w_min2;

    
}




