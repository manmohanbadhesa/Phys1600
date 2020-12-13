#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    #1

    
    float pi=0, pi2=4*atanf(1);
    
    
    for(int i=0;i<400;i++)
    {
        pi += pow(-1,i)*4/(2*i+1);
    }
    
    float difference= pi-pi2;
    
    printf("\n\r\n\r The difference between n values 400 is: %f", difference);
    
    
    
    #2

    long long factorial=1;
    
    int number=10;
    
    for(int i=0;i<number;i++)
    {
        factorial *= number-i;
               
    }
    
        
    
        printf("\n\r The factorial of %d is: %llu", number, factorial);
    
    
    
    
    
    #3
    
    
    	float a=0,b=1.0; //limits of integration
	int i=0; 

	int n=50; //number from Simpson's Rule

	float deltax= (b-a)/n; //delta x for the approximated integral solution

	printf("\n\r\n\r deltax is: %f", deltax);

	float X=0, X1=0, Xn=0, sum1=0, sum2=0; // the Simpson's rule terms up to f of Xn  

	for(i=0;i<n+1;i++)
	{
		/*X1=0.5*i;
		printf(" \n X1 is: %f", X1);
		*/

		if(i==0)
		{
			X1= cos(a);
            printf("\n\r X1 is: %f", X1);
		}
     
		else
			{
						if(i==n)
                        {
                    	
                        Xn=cos(b);
                        printf("\n\r Xn is: %f", Xn);
                     	}
                        else
                            {        
                                if(i%2 == 0)
                                {
                                    sum1 +=  2*cos((a+(i*(b-a)/n)));
                                }
                                else
                                {
                                    sum2 += 4*cos((a+(i*(b-a)/n))) ;
                                }

                                //printf("\n sum 1 is: %f \n sum2 is: %f ", sum1, sum2);
                            }       
			}
		
	}

		printf("\n\r sum 1 is: %f \n\r sum2 is: %f ", sum1, sum2);

	/*for(i=n;i<n+1;i++)
	{
		Xn= 0.5*b;
		printf("\n\r Xn is: %f", Xn);
	}
    */
	float area, sum3;

	sum3= X1 + Xn + sum1 + sum2;

	area = sum3* deltax/3;
    
    float A= sin(1);
    
    float diff= A-area;
    
    
    printf("sum3 is: %f",sum3);
	printf("\n\r The area under the function using Simpson's Rule is: %f  \n\r The exact answer is sin(1) = %f \n\r The difference between the two is: %f",area, A, diff);
    
    
    
    

    while (1)
    {
        // Add your application code
    }
}
/**
 End of File
*/