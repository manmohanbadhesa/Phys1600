// tmr0Counter.c
// FOSC = 32 MHz
// TMR0 uses Ext edge. N = M = 1
// button_RD1

#include "mcc_generated_files/mcc.h"
#include <stdio.h>    // C Library for printf() 
#include <math.h>     // C Library for pow(x,n) 
#include <stdbool.h>   
#include "putty.h"

extern volatile uint16_t timer0ReloadVal16bit;  // defined in tmr0.c

void timercounter()
{
 unsigned int oldcount = 0, newcount;
 
 clearPuTTY();                // clear display
 printf(" Test Timer as Counter \n\r");

 printf("Initial settings: TMR0H:TMR0L = %u prescaler = %u postscaler = %u\n\n\r", 
          timer0ReloadVal16bit, T0CON1bits.CKPS, T0CON0bits.OUTPS);

 // counter range is 0 to 10
 TMR0IF = 0;           // clear flag
 TMR0_WriteTimer(0);              // reset counter 

 printf(" Ready \n\n\r"); 
 while(1){  // only shows 10 presses
     newcount = TMR0_ReadTimer(1);
     if (newcount > oldcount){
         printf(" Count = %u \n\r", newcount);
         oldcount = newcount;
        }
     } 
 
} // end program