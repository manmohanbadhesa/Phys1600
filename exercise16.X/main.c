// SMT-Timer.c
// FOSC at 4 MHz, External Oscillator for accuracy
// UART at 9600 bps
// LED on RD2
// 
// SMT1 using FOSC/4, Prescaler = 1, period = 16,000,000 us = 16 seconds
// WARNING! period must be bigger than expected signal time.
// Timer Mode, Timing code execution & non-blocking delay
//
// Modes                                 input pin
// 0 Timer                               none      
// 1 Gated Timer                         SMT1SIG
// 2 Period and Duty-Cycle Acquisition   SMT1SIG
// 3 High and low time measurement       SMT1SIG
// 6 Time of flight                      SMT1WIN & SMT1SIG
// 7 Capture                             SMT1WIN  
// 8 Counter                             SMT1SIG


#include "putty.h"
#include <stdbool.h>
#include <stdio.h>     // has printf()
#include <math.h>
#include "myUART.h"

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    uint32_t time_1 = 0ul, time_2 = 0ul;
    float time;
    unsigned char letter;

    //IO_RD2_SetHigh(); // LED on show capture in progress 
    
    clearPuTTY();
      
    printf("SMT1 Timer\n\n\r");
    
    SMT1CON0bits.EN = 1;          // enables SMT peripheral       
    SMT1_DataAcquisitionEnable(); // start SMT peripheral
    
    printf("SMT Mode = %u (0 is timer)\n\r",SMT1CON1bits.MODE);
    printf("SMT enabled = %u (0 is no, 1 is yes)\n\r",SMT1CON0bits.EN);
    printf("SMT timer incrementing = %u (0 is no, 1 is yes)\n\r",SMT1_IsTimerIncrementing());
    printf("SMT prescaler setting = %u , N = %u \n\r",SMT1CON0bits.PS,1 << SMT1CON0bits.PS);
    printf("SMT period %lu \n\n\r",SMT1_GetPeriod());


    
    while(1)
    {
    SMT1_ManualTimerReset();       // zero SMT1 counter/timer  
    time_1 = SMT1_GetTimerValue(); // just to check if zeroed
    DELAY_milliseconds(3100);
    time_2 = SMT1_GetTimerValue();
    //printf("SMT start = %lu musec (should be very small number)\n\r", time_1);
    //printf("SMT end = %lu musec\n\r", time_2);
    time = (float)(time_2 - time_1) * (1 << SMT1CON0bits.PS) * 4.0/_XTAL_FREQ;
    //printf("elapsed time = %f seconds\n\n\r", time);
    }

}
    

/**
 End of File
*/