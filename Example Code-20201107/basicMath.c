// basicMath.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 = 9600

#include "mcc_generated_files/mcc.h"
#include <stdio.h> // has printf();

int main(void)
{
 // Initialize the device
 SYSTEM_Initialize();
 unsigned int a, b, c, d, e = 10;   // you can initialize a variable
 a = 5 + 2;  // note ; at end of line!!
 b = 5 – 2;
 c = 5 * 2;
 d = 5/2;
 e = 5%2; 

 printf(“a = %u, b = %u, c = %u, d = %u, e = %u \n\r”,a,b,c,d,e);
 return 0;
} // end program
