// mathShortcuts.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 = 9600

#include "mcc_generated_files/mcc.h"
#include <stdio.h> // library that has printf()

int main(void)
{
 // Initialize the device
 SYSTEM_Initialize();
 
 unsigned int a = 10, b = 5, c = 3, d = 2;   // you can initialize a variable
 
 a++;       // same as a = a + 1
 b--;       // same as b = b - 1
 c += 5;    // same as c = c + 5
 d *= 3;    // same as d = d * 3
       
 printf("a = %u, b = %u, c = %u, d = %u \n\r",a,b,c,d);
 while(1);
 return 0;
} // end program
