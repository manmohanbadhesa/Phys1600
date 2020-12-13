#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mcc_generated_files/mcc.h"
/*
                         Main application
 */
void main()
{
   SYSTEM_Initialize();
    
   /*
     
	float a=1,b=3; //limits of integration
	int i=0; 

	int n=100; //number from Simpson's Rule

	float deltax= (b-a)/n; //delta x for the approximated integral solution

	printf("\n\r\n\r deltax is: %f", deltax);

	float X=0, X1=0, Xn=0, sum1=0, sum2=0; // the Simpson's rule terms up to f of Xn  

	for(i=0;i<n+1;i++)
	{
		X1=0.5*i;
		printf(" \n X1 is: %f", X1);
		

		if(i==0)
		{
			X1= 0.5*a;
            printf("\n\r X1 is: %f", X1);
		}
     
		else
			{
						if(i==n)
                        {
                    	
                        Xn=0.5*b;
                        printf("\n\r Xn is: %f", Xn);
                     	}
                        else
                            {        
                                if(i%2 == 0)
                                {
                                    sum1 +=  2*0.5*(a+(i*(b-a)/n));
                                }
                                else
                                {
                                    sum2 += 4*0.5*(a+(i*(b-a)/n)) ;
                                }

                                //printf("\n sum 1 is: %f \n sum2 is: %f ", sum1, sum2);
                            }       
			}
		
	}

		printf("\n\r sum 1 is: %f \n\r sum2 is: %f ", sum1, sum2);

	for(i=n;i<n+1;i++)
	{
		Xn= 0.5*b;
		printf("\n\r Xn is: %f", Xn);
	}
    
	float area, sum3;

	sum3= X1 + Xn + sum1 + sum2;

	area = sum3* deltax/3;
    
    
    printf("sum3 is: %f",sum3);
	printf("\n\r The area under the function using Simpson's Rule is: %f",area);
    
    */
    
    // #2
    
    int l=0, sumL=0;
    
    for(l=0;l<101;l++)
    {
        sumL += l;
    }
    printf("\n\r The Sum is %d", sumL);
    
    
    // #1
    
    int k=0; 
    float sumK=0;
    
    for(k=0;k<21;k++)
    {
        sumK += pow(0.5,k);
    }
    printf("\n\r\n\r The Sum is %f", sumK);
    
    
    while (1)
    {
    }
    
}