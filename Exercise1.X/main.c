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
    
    float x= 112/3.0; 
    
    printf("\n\r The answer with 2.3 is : %2.3f ", x);
    printf("\n\r The answer with 12.3 is : %12.3f ", x);
    printf("\n\r The answer with 012.3 is : %012.3f ", x);
    
    
    printf("\n\r 012345678901234567890123456789012345678901234567890123456789 \n\r");  //used to measure spacing
    printf("\n\r Hi \t my \t name \t is \t is \t\t\t\t mike. \n\r What \t is \n\r\n\r\n\r \t\t yours \t \n\r ?");
    //printf("\n\r Hi \t  my \t my \t name \t is \t\t\t\t mike. \n\r What \t is  \n\r\n\r\n\r \t\t yours \t \n\r?);
    
    
    // #3
    
    float a=117.0/9, b=15.78/1.73, c=127.8/2.89, d=278.3/14.1, e=1571.0/4.17, f=22.0/7;
    
    
    printf("\n\r      \t X     \t\t Y     \t\t Z");
    printf("\n\r\n\r 1 \t %0.2f  \t %0.2f  \t\t %0.2f",a,b,c);
    printf("\n\r\n\r 2 \t %0.2f  \t %0.2f  \t %0.2f",d,e,f);
    
    
    while (1)
    {
       // Add your application code
    }
}
/**
 End of File
*/