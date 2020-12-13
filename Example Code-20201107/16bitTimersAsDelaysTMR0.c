// 16bitTimersAsDelaysTMR0.c
// Generate MCC so that:
// FOSC = 32 MHZ 
// Delays
// TMR0 on FOSC/4 and output to RC0
// LED on RD2 (led_RD2) 

#include "mcc_generated_files/mcc.h"
#include <stdio.h>    // C Library for printf() 
#include <math.h>     // C Library for pow(x,n) 
#include "putty.h"
#include "myUART.h"

extern volatile uint16_t timer0ReloadVal16bit;  // TMR0H:TMR0L value in tmr0.c

int main(void) 
{ 
    // Initialize the device
    SYSTEM_Initialize();
    
    unsigned int n = 0, m = 0;
    float T_on, T_off, f;
    
    led_RD2_SetLow();
    clearPuTTY();
    printf("16-BIT TMR0 Delays \n\n\r");    
    
    //you can control the counter start value, prescaler N, and postscaler M
    //timer0ReloadVal16bit = 32768u;
    //T0CON1bits.CKPS = 2;   // N = 2^n, n < 16
    //T0CON0bits.OUTPS = 2;  // M = m + 1, m < 16
    n = T0CON1bits.CKPS;   // prescaler setting n - prescaler is N = 2^n
    m = T0CON0bits.OUTPS;  // postscaler setting m - postscaler is M = m + 1
    
    printf("timer0ReloadVal16bit %u = 0x%x, n = %u, N = %.0f, m = %u, M = %u \n\n\r",
            timer0ReloadVal16bit, timer0ReloadVal16bit, n, pow(2,n), m, m+1);    
    
    // FOSC can be found from variable _XTAL_FREQ
    
    T_on = ((m+1.0)*65536.0 - (float)timer0ReloadVal16bit)*pow(2.0,n)*4.0/ _XTAL_FREQ;
    T_off = ((m+1.0)*65536.0 - (float)timer0ReloadVal16bit)*pow(2.0,n)*4.0/ _XTAL_FREQ;
    f = 1/(T_on + T_off); 
    printf("RD2 On Time %f, Off Time %f seconds, frequency = %f Hz\n\n\r",T_on, T_off, f);
   
    while(1) 
    { 
       
        led_RD2_SetHigh();// on
        TMR0IF = 0;       // clear flag
        TMR0_WriteTimer(timer0ReloadVal16bit);
        while(!TMR0IF);   // wait for rollover M times and then set flag
        led_RD2_SetLow(); //off
        TMR0IF = 0;       // clear flag
        TMR0_WriteTimer(timer0ReloadVal16bit);
        while(!TMR0IF);   // wait for rollover M times and then set flag
         
    } 
} 

// end program
