#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Library4.h"


float z(float x,float y)
{
    float z;
    z= sqrt(pow(x,2)+pow(y,2));
    return z;
}
float R(float A,float beta)
{
    float R;
    R= A*cos(beta*pi/180);
    return R;
}

float X(float D,float alpha)
{
    float X;
    X=D*pow(tan(alpha*pi/180),2);
    return X;
}

float v(float R,float g,float theta)
{
    float v;
    v= sqrt(R*g*tan(theta*pi/180));
    return v;
}

float e(float a,float k)
{
    int i=0; 
    float sumK=0;
    
    for(i=0;i<=k;i++)
    {
        sumK += pow(0.5,i);
    }
    return sumK;
}

float f(float k)
{
    int l=0, sumL=0;
    
    for(l=0;l<=k;l++)
    {
        sumL += l;
    }
    return sumL;
}

float integral(float a,float b,float n)
{
    
	int i=0; 

	float deltax= (b-a)/n; //delta x for the approximated integral solution

	float X=0, X1=0, Xn=0, sum1=0, sum2=0; // the Simpson's rule terms up to f of Xn  

	for(i=0;i<=n;i++)
	{
		X1=0.5*i;
		if(i==0)
		{
			X1= 0.5*a;
            
		}     
		else
			{
					if(i==n)
                        {
                    	Xn=0.5*b;
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
                            }       
			}
		
	}

    float area, sum3;
	sum3= X1 + Xn + sum1 + sum2;
	area = sum3* deltax/3;
    return area;
}
