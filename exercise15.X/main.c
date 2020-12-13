// 1ChannelADCvaryingSignal.c
// system at 4 MHz
// UART2 at 9,600 bps
// RA4 is ADC input
// DC = 25% PWM5, TMR2 = 32 ms PS = 128 pin RC6
// MPLAB Data Visualizer
// button on RD1


#include "mcc_generated_files/mcc.h"
#include "putty.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define vrefplus 3856
#define vrefminus 1286

unsigned int convertADCtoMillivolts(unsigned int adcValue);
/*
                         Main application
*/
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    unsigned int ADCvoltage1, ADCvoltage2;
    adc_result_t convertedValue; 
    /*
    while(IO_RD1_GetValue() == 0); //wait for button press;
    //clearPuTTY();
    IO_RD2_SetHigh(); // led on
     */

    while (1)
    {
       // Add your application code
        
       convertedValue = ADCC_GetSingleConversion(channel_ANA4);
       //ADCvoltage1 = convertADCtoMillivolts(convertedValue);
       //printf("ANA4: %u = %u mV \n\r", 
       //convertedValue, ADCvoltage1);

       // unsigned int value as two 8bit pieces to Data Visualizer
       UART2_Write(0x5F);                // frame start Decimal 95
       UART2_Write(convertedValue & 0x00FF); // send lower 8 bits first
       UART2_Write(convertedValue >> 8);     // send upper 8 bits seconds
       UART2_Write(0xA0);                // frame end Decimal 160 (Note 160 + 95 = 255)  
       DELAY_milliseconds(200);
    }
}

unsigned int convertADCtoMillivolts(unsigned int adcValue)
{
    return ((unsigned int)((adcValue + 0.5)*(vrefplus - vrefminus)/4096 + vrefminus));
}
/**
 End of File
*/