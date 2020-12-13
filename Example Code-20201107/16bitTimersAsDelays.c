// 16bitTimersAsDelays.c
// Generate MCC so that the FOSC = 32 MHZ and Delays
// TMR0 and LED on RD2 (led_RD2) 

#include "mcc_generated_files/mcc.h"
#include <stdio.h>    // C Library for printf() 
#include <math.h>     // C Library for pow(x,n) 
#include "buttons.h"
#include "putty.h"
#include "myUART.h"

extern volatile uint16_t timer0ReloadVal16bit;

int main(void) 
{ 
    // Initialize the device
    SYSTEM_Initialize();
    
    unsigned int n = 0, m = 0;
    float T, f;
    led_RD2_SetLow();
    clearPuTTY();
    printf("16-BIT TMR0 Delays \n\n\r");    
    
    timer0ReloadVal16bit = 10000u;
    T0CON1bits.CKPS = 1;   // N = 2^1 = 2 
    T0CON0bits.OUTPS = 0;  // M = 2 + 1 = 3
    n = T0CON1bits.CKPS;   // prescaler setting
    m = T0CON0bits.OUTPS;  // postscaler setting
    
    printf("timer0ReloadVal16bit %u = 0x%x, n = %u, N = %f, m = %u, M = %u \n\n\r",
            timer0ReloadVal16bit, timer0ReloadVal16bit, n, pow(2,n), m, m+1);    

    T = (65536.0 - (float)timer0ReloadVal16bit)*pow(2.0,n)*(m+1.0)/32.0E6;
    f = 1/(2.0*T); 
    printf("RD2 ON - OFF times %f seconds, frequency = %f Hz\n\n\r",T, f);
   
    while(1) 
    { 
        /*
        led_RD2_SetHigh(); // on
        DELAY_microseconds(1200);
        led_RD2_SetLow();  // off
        DELAY_microseconds(1200);
         */

       
        led_RD2_SetHigh();// on
        TMR0IF = 0;       // clear flag
        TMR0_Reload();    // start counting from timer0ReloadVal16bit
        while(!TMR0IF);   // wait for rollover and flag set
        led_RD2_SetLow(); // off
        TMR0IF = 0;       // clear flag
        TMR0_Reload();    // wait for rollover and flag set
        while(!TMR0IF) ;  // wait for rollover and flag set

         /*
        led_RD2_SetHigh();// on
        TMR0IF = 0;       // clear flag
        TMR0_WriteTimer(timer0ReloadVal16bit);
        while(!TMR0IF);   // wait for rollover and flag set
        led_RD2_SetLow(); //off
        TMR0IF = 0;       // clear flag
        TMR0_WriteTimer(timer0ReloadVal16bit);
        while(!TMR0IF);   // wait for rollover and flag set
        */
        
    } 
} 

// end program
