// timeCodeExecution.c
// 16bitTimersAsDelays.c
// Generate MCC so that the FOSC = 32 MHZ and Delays
// TMR0 and LED on RD2 (led_RD2) 

#include "mcc_generated_files/mcc.h"
#include <stdio.h>    // C Library for printf() 
#include <math.h>     // C Library for pow(x,n) 
#include "buttons.h"
#include "putty.h"
#include "myUART.h"

int main(void)
{
 // Initialize the device
 SYSTEM_Initialize();
 unsigned int flag = 0, counter = 0, n, m;
 float time;

 //   T0CON1bits.CKPS = 1;   // N = 2^1 = 2 
 //   T0CON0bits.OUTPS = 0;  // M = 2 + 1 = 3
 n = T0CON1bits.CKPS;   // prescaler setting
 m = T0CON0bits.OUTPS;  // postscaler setting 

 clearPuTTY();                   // clear display

 TMR0IF = 0;                      // clear flag 
 TMR0_WriteTimer(0);              // reset counter 
 printf(" Timing Code Execution   \n\n\r"); // can time single or multiple lines of code
 flag = TMR0IF;
 counter = TMR0_ReadTimer();
 time = (float)counter*pow(2.0,n)*(m+1.0)/ 32.0e6;

 printf("counter = %u, flag = %u (if = 1, time overflowed), t = %f \n\n\r", counter, flag, time);
 
 TMR0IF = 0;                      // clear flag 
 TMR0_WriteTimer(0);              // reset counter 
 DELAY_milliseconds(300);         // can time single or multiple lines of code
 flag = TMR0IF;
 counter = TMR0_ReadTimer();
 time = (float)counter*pow(2.0,n)*(m+1.0)/ 32.0e6;
 printf("counter = %u, flag = %u (if = 1, time overflowed), t = %f \n\r", counter, flag, time);
 
 TMR0IF = 0;                      // clear flag 
 TMR0_WriteTimer(0);              // reset counter 
 DELAY_milliseconds(500);         // can time single or multiple lines of code
 flag = TMR0IF;
 counter = TMR0_ReadTimer();
 time = (float)counter*pow(2.0,n)*(m+1.0)/ 32.0e6;
  printf("counter = %u, flag = %u (if = 1, time overflowed), t = %f \n\r", counter, flag, time);

 while(1);  
} // end program