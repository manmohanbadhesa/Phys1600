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
#include "buttons.h"

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    //uint32_t time, time1=1, time2=2, time3=3, s_ratio=1000000;
    double time, time1=1, time2=2, time3=3, s_ratio=1000000;
    
    clearPuTTY();
           
    printf("SMT1 Gated Timer - RE to FE on SMT1SIG (RC5)\n\n\r");
   
    printf("SMT Mode = %u",SMT1CON1bits.MODE);

    //codes to control operation. Not needed. Already set in Easy Setup  
    SMT1CON0bits.EN = 1;             // enable SMT peripheral
    SMT1_DataAcquisitionEnable();    // allows acquisitions/captures    
    //SMT1_RepeatDataAcquisition();    // allow repeated measurements
        while(1)
        {
            // Add your application code
            // capture 3 pulse widths
            SMT1_ManualTimerReset();  // zero SMT1 counter/timer  
            SMT1PWAIF = 0;            // clear pulse width (FE) interrupt flag
            while(SMT1PWAIF == 0);    // wait for pulse width buffer to fill
            time1 = SMT1_GetCapturedPulseWidth();  // read buffer
            time=time1/s_ratio;             //convert musec to seconds 
            
            printf("\n\n\rPulse width = %f musec\n\r", time1);            
            printf("Pulse width = %f seconds\n\r", time);

        }

}
    

/**
 End of File
*/