// SMT-Capture.c
// FOSC at 4 MHz, External Oscillator for accuracy
// UART at 9600 bps
// TMR2 using FOSC/4 at Prescaler = 128, period = 32 ms
// PWM5 at 249*128/4*4/FOSC = 7.968 ms (DC = 25%), output pin is RC7
// PWM5 is signal we wish to capture
// Start button on RD1
// LED on RD2
// 
// SMT1 using FOSC/4, Prescaler = 1, period = 16,000,000 us = 16 seconds
// WARNING! period must be bigger than expected signal time.
// Capture Mode, SMT1WIN on RC4, start on rising edge
//
// Modes                                 input pin
// 0 Timer                                     
// 1 Gated Timer
// 2 Period and Duty-Cycle Acquisition   SMT1SIG  (RC5)
// 3 High and low time measurement
// 6 Time of flight
// 7 Capture                             SMT1WIN  (RC4)  
// 8 Counter

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
           
    printf("SMT1 Capture Test - SMT1WIN on RC4\n\r");
   
    printf("SMT Mode = %u \n\n\r",SMT1CON1bits.MODE);

    //codes to control operation 
    SMT1CON0bits.EN = 1;             // enable SMT peripheral
    SMT1_DataAcquisitionEnable();  
    //SMT1_SingleDataAcquisition();
    SMT1_RepeatDataAcquisition();
    SMT1_ManualTimerReset();         // zero SMT1 counter/timer  
            
    PIR1bits.SMT1PRAIF = 0;          // clear buffer interrupt flags
    PIR1bits.SMT1PWAIF = 0;
    while(PIR1bits.SMT1PRAIF == 0 || PIR1bits.SMT1PWAIF == 0 ); // wait for buffers to fill
    time1 = SMT1_GetCapturedPeriod();     // In capture mode holds rising edge time 
    time2 = SMT1_GetCapturedPulseWidth(); // In capture mode holds falling edge time
    
    PIR1bits.SMT1PRAIF = 0;         // clear buffer interrupt flags
    PIR1bits.SMT1PWAIF = 0;   
    while(!PIR1bits.SMT1PRAIF || !PIR1bits.SMT1PWAIF );  // wait for buffers to fill
    time3 = SMT1_GetCapturedPeriod();      // In capture mode holds rising edge time 
    time4 = SMT1_GetCapturedPulseWidth();  // In capture mode holds falling edge time
    
    PIR1bits.SMT1PRAIF = 0;         // clear buffer interrupt flags
    PIR1bits.SMT1PWAIF = 0;   
    while(!PIR1bits.SMT1PRAIF || !PIR1bits.SMT1PWAIF );  // wait for buffers to fill
    time5 = SMT1_GetCapturedPeriod();      // In capture mode holds rising edge time 
    time6 = SMT1_GetCapturedPulseWidth();  // In capture mode holds falling edge time
    
    printf("Captured sequence is RE, FE, RE \n\r");  
    printf("time1 = %lu, time2 = %lu, time3 = %lu \n\r", time1, time2, time3 );
    printf("time4 = %lu, time5 = %lu, time6 = %lu \n\n\r", time4, time5, time6 );
    printf("Period = %lu musec, Pulse width = %lu musec \n\r", time3 - time1, time2 - time1);
    printf("Period = %lu musec, Pulse width = %lu musec \n\r", time6 - time4, time6 - time5);
    
    IO_RD2_SetLow(); // LED off, capture finished 
    
    while (1)
    {
        // Add your application code
    }
}
/**
 End of File
*/