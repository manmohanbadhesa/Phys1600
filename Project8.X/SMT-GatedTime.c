// SMT-GatedTime.c
// FOSC at 4 MHz, External Oscillator for accuracy
// UART at 9600 bps
// TMR2 using FOSC/4 at Prescaler = 128, period = 32 ms
// PWM5 at 249*128/4*4/FOSC = 7.968 ms (DC = 25%), output pin is RC4
// PWM5 is signal we wish to capture. Connect to RC5
//
// SMT1 using FOSC/4, Prescaler = 1, period = 16,000,000 us = 16 seconds
// WARNING! period must be bigger than expected signal time.
// Gated Timer Mode, RE to FE on SMT1SIG (RC5)  Pulse Width
//
// Reads 3 pulse widths
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
#include "putty.h"
#include <stdbool.h>

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    uint32_t time1=1, time2=2, time3=3;

    clearPuTTY();
           
    printf("SMT1 Gated Timer - RE to FE on SMT1SIG (RC5)\n\n\r");
   
    printf("SMT Mode = %u \n\n\r",SMT1CON1bits.MODE);

    //codes to control operation. Not needed. Already set in Easy Setup  
    SMT1CON0bits.EN = 1;             // enable SMT peripheral
    SMT1_DataAcquisitionEnable();    // allows acquisitions/captures    
    SMT1_RepeatDataAcquisition();    // allow repeated measurements
    
    // capture 3 pulse widths
    SMT1_ManualTimerReset();  // zero SMT1 counter/timer  
    SMT1PWAIF = 0;            // clear pulse width (FE) interrupt flag
    while(SMT1PWAIF == 0);    // wait for pulse width buffer to fill
    time1 = SMT1_GetCapturedPulseWidth();  // read buffer
    
    SMT1_ManualTimerReset();  // zero SMT1 counter/timer  
                              // remove for cumulative timing  
    SMT1PWAIF = 0;            // clear pulse width (FE) interrupt flag
    while(SMT1PWAIF == 0);    // wait for pulse width buffer to fill
    time2 = SMT1_GetCapturedPulseWidth();  // read buffer
    
    SMT1_ManualTimerReset();  // zero SMT1 counter/timer  
                              // remove for cumulative timing  
    SMT1PWAIF = 0;            // clear pulse width (FE) interrupt flag
    while(SMT1PWAIF == 0);    // wait for pulse width buffer to fill
    time3 = SMT1_GetCapturedPulseWidth();
    
    printf("Pulse width = %lu musec\n\r", time1);
    printf("Pulse width = %lu musec\n\r", time2);    
    printf("Pulse width = %lu musec\n\r", time3);
    
    while (1);
}
/**
 End of File
*/