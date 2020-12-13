// SMT-HighAndLow.c
// FOSC at 4 MHz, External Oscillator for accuracy
// UART at 9600 bps
// TMR2 using FOSC/4 at Prescaler = 128, period = 32 ms
// PWM5 at 249*128/4*4/FOSC = 7.968 ms (DC = 25%), output pin is RA7
// PWM5 is signal we wish to capture. Connect to RC5
// Start button on RD1
// LED on RD2
// 
// SMT1 using FOSC/4, Prescaler = 1, period = 16,000,000 us = 16 seconds
// WARNING! period must be bigger than expected signal time.
// High and Low Time Mode, SMT1SIG on RC5, start on rising edge
//
// Measure period and pulse width three times
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

    uint32_t time1=1, time2=2, time3=3, time4=4;
    uint32_t time5=5, time6=6;

    while(IO_RD1_GetValue() == 0); //wait for button press;
    IO_RD2_SetHigh(); // LED on show capture in progress 

    clearPuTTY();
           
    printf("SMT1 High and Low Time Test - SMT1SIG on RC1\n\r");
   
    printf("SMT Mode = %u \n\n\r",SMT1CON1bits.MODE);

    //codes to control operation. Not needed. Already set in Easy Setup  
    SMT1CON0bits.EN = 1;             // enable SMT peripheral
    SMT1_DataAcquisitionEnable();    // allows acquisitions/captures    
    SMT1_RepeatDataAcquisition();    // allow repeated measurements
            
    SMT1PRAIF = 0;          // clear period (RE) interrupt flag
    SMT1PWAIF = 0;          // clear pulse width (FE) interrupt flag
    while(SMT1PRAIF == 0 || SMT1PWAIF == 0 ); // wait for both buffers to fill
    time2 = SMT1_GetCapturedPulseWidth(); // RE to FE - high time
    time1 = SMT1_GetCapturedPeriod();     // FE to RE - low time, not period
    
    SMT1PRAIF = 0;          // clear period (RE) interrupt flag
    SMT1PWAIF = 0;          // clear pulse width (FE) interrupt flag
    while(!SMT1PRAIF || !SMT1PWAIF );  // wait for both buffers to fill
    time4 = SMT1_GetCapturedPulseWidth();  // RE to FE - high time
    time3 = SMT1_GetCapturedPeriod();      // FE to RE - low time, not period
    
    SMT1PRAIF = 0;          // clear period (RE) interrupt flag
    SMT1PWAIF = 0;          // clear pulse width (FE) interrupt flag
    while(!SMT1PRAIF || !SMT1PWAIF );  // wait for both buffers to fill
    time6 = SMT1_GetCapturedPulseWidth();  // RE to FE - high time
    time5 = SMT1_GetCapturedPeriod();      // FE to RE - low time, not period
    
    printf("High = %lu musec, Low = %lu musec \n\r", time2, time1);
    printf("High = %lu musec, Low = %lu musec \n\r", time4, time3);
    printf("High = %lu musec, Low = %lu musec \n\r", time6, time5);
    
    IO_RD2_SetLow(); // LED off, capture finished 
    
    while (1)
    {
        // Add your application code
    }
}
/**
 End of File
*/