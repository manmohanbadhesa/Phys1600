#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
float table_function(float* x,int length);

void main()
{
    // Initialize the device
    SYSTEM_Initialize();

   // Arctan can be summoned by using atanf()
    float V1, V2, R=1.0, r=2.0, pi=4*atanf(1);
    
    //printf("\n\r\n\r pi is %f",pi);
    
    V1=4*pi*pow(R,3)/3;
    
    V2= 4*pi*pow(r,3)/3;
    
    
    printf("\n\r\n\r The volume of a sphere radius 1.0 is: %f",V1);
    printf("\n\r The volume of a sphere radius 2.0 is: %f",V2);
    
   
    
    \

    
    float x[]={4.1,4.49, 4.5, 4.51, 4.9, -4.1, -4.49, -4.5, -4.51, -4.9};
    
    int length= sizeof(x)/sizeof(x[0]);
    
    float j[10];
    float k[10];
    float l[10];
    float m[10];
    
   // printf("\n\rthe length of the array is: %d", length);
    
   // printf("\n\r\n\r the third number is: %g", x[3]);
    
    for(int i=0;i<length;i++)
    {
        j[i]= x[i];
        
        k[i]= floorf(x[i]);
        
        l[i]= ceil(x[i]);
        
        m[i]= (int)x[i];
        
        printf("\n\r\n\r %g \t\t  %g \t\t  %g \t\t  %g",j[i],k[i],l[i],m[i]);
    }
    while (1)
    {
       // Add your application code
    }


    

}
/**
 End of File
*/

    
    
    /*
float table_function(float* x,int length)
{
    float j[10];
    float k[10];
    float l[10];
    float m[10];
    
   // printf("\n\rthe length of the array is: %d", length);
    
   // printf("\n\r\n\r the third number is: %g", x[3]);
    
    for(int i=0;i<length+1;i++)
    {
        j[i]= x[i];
        
        k[i]= floorf(x[i]);
        
        l[i]= ceil(x[i]);
        
        m[i]= (int)x[i];
        
        printf("\n\r\n\r %g \t\t  %g \t\t  %g \t\t  %g",j[i],k[i],l[i],m[i]);
    }
    
        while (1)
    {
        // Add your application code
    }

}
      */