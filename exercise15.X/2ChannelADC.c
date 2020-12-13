// 2ChannelADC.c
// system at 32 MHz
// UART2 at 9600 bps
// RA4 and RA5 as ADC inputs
// delays

#include "mcc_generated_files/mcc.h"
#include "putty.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define vrefplus 4096
#define vrefminus 0

unsigned int convertADCtoMillivolts(unsigned int adcValue);

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    unsigned int ADCvoltage1, ADCvoltage2;
    adc_result_t convertedValue1, convertedValue2; 

    clearPuTTY();
    
    printf("ADC testing \n\n\r");

    while (1)
    {

       convertedValue1 = ADCC_GetSingleConversion(channel_ANA4);
       ADCvoltage1 = convertADCtoMillivolts(convertedValue1);
       printf("ANA4: %u = %u mV \n\r", 
       convertedValue1, ADCvoltage1);
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