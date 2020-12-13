// 16bitCapture.c
// FOSC at 4 MHz, External Oscillator for accuracy
// UART at 9600 bps
// TMR2 using FOSC/4 at Prescaler = 128, period = 32 ms
// PWM5 at 249 / 4*128*4/FOSC = 7.986 ms (DC = 25%), output pin is RC5
// PWM5 is signal we wish to capture
// Start button on RD1
// LED on RD2
// TMR1 using FOSC/4, Prescaler = 1, 16bit period = 65 ms
// CCP1 in Capture Mode, every rising edge, using TMR1, input pin is RBO
//
// Want to capture T_ON and T_PWM
// Note:
// CCP1CONbits.Mode 7 Every 16th rising edge
//                  6 Every 4th rising edge
//                  5 Every rising edge
//                  4 Every falling edge
//                  3 Every edge

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
    uint16_t capture1, capture2, capture3;
    unsigned int flag;
    float T_ON, T_PWM;
    
    while(IO_RD1_GetValue() == 0); //wait for button press;
    IO_RD2_SetHigh(); // LED on show capture in progress 
    clearPuTTY();
    
    printf("Capture test \n\n\r"); 

    TMR1_WriteTimer(0);   // we want small numbers if possible
    TMR1IF = 0;           // reset overflow flag  
    CCP1IF = 0;           // reset capture flag
    while(!CCP1_IsCapturedDataReady());   //Used only for polling method
    capture1 = CCP1_CaptureRead();  // First rising edge
    
    CCP1CONbits.MODE = 4;  // switch mode to catch Falling Edge next
    while(!CCP1_IsCapturedDataReady());   //Used only for polling method
    capture2 = CCP1_CaptureRead();  // First falling edge 
    
    CCP1CONbits.MODE = 5;  // switch mode to catch Rising Edge next
    while(!CCP1_IsCapturedDataReady());   //Used only for polling method
    capture3 = CCP1_CaptureRead();  // Second rising edge
    
    // check if TMR1 has overflowed
    flag = TMR1_HasOverflowOccured();
   
    printf("T1 = %u , T2 = %u, T3 = %u \n\r",capture1, capture2, capture3);
    printf("flag = %u (if = 1, TMR1 overflowed, timing will be off)\n\r",flag);
    T_ON = (capture2 - capture1)*1.0*4.0/_XTAL_FREQ;  // convert to seconds     
    T_PWM = (capture3 - capture1)*1.0*4.0/_XTAL_FREQ;  // convert to seconds
    printf("T_ON = %f s, T_PWM = %f s\n\r",T_ON, T_PWM);
    IO_RD2_SetLow(); // LED off, capture finished 

    while (1)
    {
        // Add your application code
    }
}
/*
 End of File
*/