// SMT-Counter.c
// FOSC = 32 MHz
// UART 9600
// SMT counter mode.
// Set pin SMT1SIG to RC1
// Attach button to RC1/SMT1SIG
//
// Modes                                 input pin
// 0 Timer                               none      
// 1 Gated Timer                         SMT1SIG
// 2 Period and Duty-Cycle Acquisition   SMT1SIG
// 3 High and low time measurement       SMT1SIG
// 6 Time of flight                      SMT1WIN & SMT1SIG
// 7 Capture                             SMT1WIN  
// 8 Counter                             SMT1SIG


#include "mcc_generated_files/mcc.h"
#include <stdio.h>    // C Library for printf() 
#include <stdbool.h>   
#include "putty.h"

int main(void)
{
 // Initialize the device
 SYSTEM_Initialize();
 
 unsigned int newcount = 0, oldcount = 0;
 
 clearPuTTY();                // clear display
 printf("Test SMT as Counter \n\r");

 printf("Initial settings: Mode = %u (8 is counter), period = %lu, initial count = %lu \n\n\r", 
          SMT1CON1bits.MODE, SMT1_GetPeriod(), SMT1_GetTimerValue());

 // counter range is 0 to 10
 SMT1_ManualTimerReset();        // reset counter 
 printf("Ready \n\n\r"); 
 while(1){  // only shows 10 presses
     newcount = SMT1_GetTimerValue();
     DELAY_milliseconds(10);     
     if (newcount > oldcount){ // print only on change
         if( newcount > (oldcount + 1) )
         {
             newcount = oldcount + 1;
         }
         printf("Count = %u \n\r", newcount);
         oldcount++;
     }
 
     if (newcount >= 10){
         SMT1_ManualTimerReset(); // reset count to 0
         oldcount = 0;
     }
     
 } 
} // end program


