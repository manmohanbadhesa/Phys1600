#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

#1
    
    int i;
    printf("\n\r\n\r The numbers divisible by 3 and 7 are: \n\r");
    for(i=1;i<=1000;i++)
    {
        if(i%3==0 | i%7==0)
        {
            printf("%d \n\r",i);
        }
    }
    
    
#2   

    
    /*
    int n=0;
    
    for(n=0;n<=12;n++)
    {
       
    switch(n)
    {
        case 10:
        case 0:     printf("\n\n\rNumber is %d  Limit",n);
                    break;
        
        case 2:
        case 4:
        case 6:
        case 8:     printf("\n\r Number is %d  Even",n);
                    break;
        case 1:
        case 3:
        case 7:     printf("\n\r Number is %d  Odd",n);
                    break;
        default:    printf("\n\r Bingo");
                    break; 
    }
    
    }
*/
    while (1)
    {
        // Add your application code
    }


    
}
/*
 End of File
*/