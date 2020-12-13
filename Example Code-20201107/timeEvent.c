// timeEvent.c
// FOSC = 32 MHz
// TMR0 uses FOSC/4 max period 2 seconds, M = 1
// button_RD1

#include "mcc_generated_files/mcc.h"
#include <stdio.h>    // C Library for printf() 
#include <math.h>     // C Library for pow(x,n) 
#include <stdbool.h>   
#include "putty.h"

extern volatile uint16_t timer0ReloadVal16bit;

int main(void)
{
 // Initialize the device
 SYSTEM_Initialize();
 unsigned int counter = 0, buttonpress = 0, flag = 0;
 float time; 
 unsigned char has_switch1_changed = 0;
 
 clearPuTTY();
 printf("Time Ten Button Presses \n\n\r");
 
 
while(1)
 {
   has_switch1_changed = poll_switch1_for_edges(button_RD1_GetValue());

   if ( has_switch1_changed == 1 ) //rising edge
        {
        counter++; // increment button counter 
        if (counter == 1) // start the timer on first press
          {  
                 TMR0_WriteTimer(0);     // reset counter 
                 TMR0IF = 0;             // clear flag
        }
        if (counter == 10)         // read the timer on 10th press
           {  
           time = (float)ReadTimer3()*4.0*N/(float)_XTAL_FREQ;
           flag = TMR0IF;
           printf("t = %f s (incorrect if overflow occurred) flag = %u \n\r",  time, flag);
           }
     } //end if

 } //end while  
} // end program


