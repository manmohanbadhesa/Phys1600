// DAC.c
// system at 32 MHz
// UART2 at 9600 bps
// DAC using VDD & VSS
// DAC1OUT/RA2
// delays

#include "mcc_generated_files/mcc.h"
#include "putty.h"
#include <stdio.h>

#define vrefplus  4816
#define vrefminus 0

unsigned int DACsettingtoMillivolts(unsigned int DACsetting);

int main(void) {
    // Initialize the device
    SYSTEM_Initialize();
    int i;
    
    clearPuTTY();
    
    printf("DAC out on RA2 \n\n\r");
 
    printf("DAC Settings\n\n\r");
    printf("Is DAC1OUT1/RA2 used = %u (0 = N, 1 = Y) \n\r", DAC1CON0bits.OE1);
    printf("Is DAC1OUT2/RB7 used = %u (0 = N, 1 = Y) \n\r", DAC1CON0bits.OE2);
    printf("Positive Source = %u (0 = VDD, 1 = external, 2 = FVR) \n\r", DAC1CON0bits.PSS);    
    printf("Negative Source = %u (0 = VSS, 1 = external) \n\n\r", DAC1CON0bits.NSS);    

    printf("FVR Settings\n\n\r");
    printf("Is FVR used = %u (0 = N, 1 = Y) \n\r", FVRCONbits.RDY);
    printf("Buffer_2 = %u (0 = Off, 1 = 1.024 V, 2 = 2.048 V, 3 = 4.096 V) \n\n\r", FVRCONbits.CDAFVR);

    printf("vref+ = %u mV, vref- = %u \n\n\r", vrefplus, vrefminus);
    
    while(1){
        i = 0;
        for(i=0; i < 32; i++)
        {
         DAC1_SetOutput(i);
         printf("i = %2u, V_out = %4u mV \n\r", i, DACsettingtoMillivolts(i) );
         DELAY_milliseconds(5000);               
        }    
    }
}

unsigned int DACsettingtoMillivolts(unsigned int DACsetting)
{
    return ((unsigned int)(DACsetting*(float)(vrefplus - vrefminus)/32.0 + vrefminus));
}