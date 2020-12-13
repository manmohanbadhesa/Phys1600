// mathFunctions.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 = 9600

#include "mcc_generated_files/mcc.h"
#include <stdio.h> // library that has printf()
#include <math.h> // library that has sin(), pow(), etc.

int main(void)
{
 // Initialize the device
 SYSTEM_Initialize();
 
 float a, b, c, d;   // you can initialize a variable
 
 a = 5.0*sin(0.1);
 b = sqrt(14.2);
 c = pow(5,3);       // same as c = (5)**3
 d = log(3.2);       // log means natural log ln
       
 printf("a = %f, b = %f, c = %f, d = %f \n\r",a,b,c,d);
 return 0;
} // end program
