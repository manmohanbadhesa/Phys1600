
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*
                         Main application
 */
int main()
{
   SYSTEM_Initialize();


	//Part (a)

	float x=2.25, y=3.72, z;
    
    z= sqrt(pow(x,2)+pow(y,2));

    
    printf(" Part a's answer is: %f ",z);


    //Part (b)

    float pi=4.0*atanf(1.0), R, A=4.27, beta=35.0*pi/180;
    
    R= A*cos(beta);


    printf("\n Part b's answer is: %f ",R);


    //Part (c)

    float X, D=6.85, alpha=33.0*pi/180; 

    X=D*pow(tan(alpha),2);

    printf("\n Part c's answer is: %f ",X);


    //Part (d)


    float v, J=2.15, g=9.81, theta=43.0*pi/180;

    v= sqrt(J*g*tan(theta));

    printf("\n Part d's answer is: %f ",v);
    
        while (1)
    {
       // Add your application code
    }

}