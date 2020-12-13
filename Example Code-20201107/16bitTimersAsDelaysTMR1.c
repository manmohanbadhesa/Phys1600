// 16bitTimersAsDelaysTMR1.c
// Generate MCC so that the FOSC = 32 MHZ and Delays
// TMR1 uses FOSC and LED on RD2 (led_RD2) 

#include "mcc_generated_files/mcc.h"
#include <stdio.h>    // C Library for printf() 
#include <math.h>     // C Library for pow(x,n) 
#include "buttons.h"
#include "putty.h"
#include "myUART.h"

extern volatile uint16_t timer1ReloadVal;  // counter TMRxH:TMRxL from tmrx.c

int main(void) 
{ 
    // Initialize the device
    SYSTEM_Initialize();
    
    unsigned int n = 0, m = 0;
    float T_on, T_off, f;
    led_RD2_SetLow();
    clearPuTTY();
    printf("16-BIT TMR1 Delays \n\n\r");    
    
    //timer1ReloadVal = 20000u;
    //T1CONbits.CKPS = 2;   // N = 2^1 = 2 
    n = T1CONbits.CKPS;     // prescaler setting
    
    printf("timer1ReloadVal %u = 0x%x, n = %u, N = %.0f \n\n\r",
            timer1ReloadVal, timer1ReloadVal, n, pow(2,n));    

    T_on = (65536.0 - (float)timer1ReloadVal)*pow(2.0,n)/_XTAL_FREQ;
    T_off= (65536.0 - (float)timer1ReloadVal)*pow(2.0,n)/_XTAL_FREQ;
    f = 1/(T_on + T_off); 
    printf("RD2 Time On = %f seconds, Time Off = %f, frequency = %f Hz\n\n\r",T_on, T_off, f);
   
    while(1) 
    { 
        led_RD2_SetHigh();// on
        TMR1IF = 0;       // clear flag
        TMR1_WriteTimer(timer1ReloadVal);
        while(!TMR1IF);   // wait for rollover and flag set
        led_RD2_SetLow(); //off
        TMR1IF = 0;       // clear flag
        TMR1_WriteTimer(timer1ReloadVal);
        while(!TMR1IF);   // wait for rollover and flag set
        
    } 
} 

// end program
