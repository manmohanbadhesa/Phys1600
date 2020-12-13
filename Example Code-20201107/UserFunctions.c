// UserFunctions.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 = 9600

#include "mcc_generated_files/mcc.h"
#include <stdio.h> // library that has printf()

int main(void)
{
 // Initialize the device
 SYSTEM_Initialize();
 
 unsigned int i, sum = 0;   
 
 printf("==============================================================\n\r");
 printf("=                       Physics 1600                         =\n\r");
 printf("==============================================================\n\r");
 
 for ( i=0; i <= 100; i = i++ )  // sum from 0 to 100 inclusive in increments of 1 
   {
    sum = sum + i;  // could write sum += i; 
   }
 printf("sum = %u \n\r",sum);
 
 while(1);
 return 0;
} // end program
