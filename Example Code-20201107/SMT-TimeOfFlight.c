// SMT-TimeOfFlight.c
// FOSC at 4 MHz, External Oscillator for accuracy
// UART at 9600 bps
// 
// LED on RD2
// 
// SMT1 using FOSC/4, Prescaler = 1, period = 16,000,000 us = 16 seconds
// WARNING! period must be bigger than expected signal time.
// 
// Time of flight Mode, RE on SMT1WIN (RC4) to RE on SMT1SIG (RC5)
// Single measurement. Connect RC4 and RC5 together.
// Use to time between different buttons on RC4 and RC5
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

    uint32_t time1=1, time2 = 2;

    clearPuTTY();
    IO_RD2_SetLow();         // LED off, capture finished 
    
    printf("SMT1 Time of Flight Test - RE on SMT1WIN (RC4) to RE on SMT1SIG (RC5)\n\r");
   
    printf("SMT Mode = %u \n\n\r",SMT1CON1bits.MODE);

    //codes to control operation. Not needed. Already set in Easy Setup  
    SMT1CON0bits.EN = 1;             // enable SMT peripheral
    SMT1_DataAcquisitionEnable();    // allows acquisitions/captures    
    SMT1_SingleDataAcquisition();    // allow one set of measurements
    
    while (1)
    {
    SMT1_DataAcquisitionEnable(); // allow next measurement
    SMT1_ManualTimerReset();      // clear timer
    SMT1PRAIF = 0;                // clear interrupt flags
    SMT1PWAIF = 0;
    while(SMT1PRAIF == 0 && SMT1PWAIF == 0) // wait for one buffer to fill
    {
     if(SMT1_GetTimerValue() > 0)
        {
         // timer is incrementing, so first RE on SMT1WIN has been found
         IO_RD2_SetHigh();       // LED on show capture in progress 
        }
    }
         
    if (SMT1PRAIF == 1) // good measurement
        {
         time1 = SMT1_GetCapturedPeriod();   // Time of Flight
         SMT1PWAIF = 0;    // reset 
         printf("ToF = %lu musec \n\r", time1);
        }
    if (SMT1PWAIF == 1) // bad measurement
        {
         SMT1_DataAcquisitionDisable(); // don't collect more edges
         printf("Two successive button1 presses - no measurement \n\r");
        }
    IO_RD2_SetLow();         // LED off, capture finished     
    }
}
/**
 End of File
*/