// 8bitTimersAsDelays.c
// Generate MCC so that the FOSC = 32 MHZ and Delays
// TMR2 at FOSC/4 and LED on RD2 (led_RD2) 

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
    
    unsigned int n = 0, m = 0;
    float T_on, T_off, f;
    led_RD2_SetLow();
    clearPuTTY();
    printf("\n\r8-BIT TMR2 Delays \n\n\r");    
    
    //PR2 = 199;               // do not exceed 255
    //T2TMR = 0;               //must timer after setting PR2
    //T2CONbits.CKPS = 7;   // N = 2^1 = 2    0 <= n <= 7
    //T2CONbits.OUTPS = 9;  // M = 2 + 1 = 3  0 <= m <= 15
    n = T2CONbits.CKPS;     // prescaler setting
    m = T2CONbits.OUTPS;    // postscaler setting
    
    printf("8bitPeriod %u = 0x%x, n = %u, N = %.0f, m = %u, M = %u \n\n\r", 
            PR2, PR2, n, pow(2,n), m, m+1);    

    T_on = ((float)PR2 + 1.0)*pow(2.0,n)*(m+1.0)*4.0/_XTAL_FREQ;
    T_off = ((float)PR2 + 1.0)*pow(2.0,n)*(m+1.0)*4.0/_XTAL_FREQ;
    f = 1/(T_on + T_off); 
    printf("RD2 On time = %f seconds, Off time = %f, frequency = %.2f Hz\n\n\r",
            T_on, T_off, f);
   
    while(1) 
    { 
         
        led_RD2_SetHigh();// on
        TMR2IF = 0;       // clear flag
        TMR2_WriteTimer(0);
        while(!TMR2IF);   // wait for rollover and flag set
        led_RD2_SetLow(); //off
        TMR2IF = 0;       // clear flag
        TMR2_WriteTimer(0);
        while(!TMR2IF);   // wait for rollover and flag set
        
    } 
} 

// end program
