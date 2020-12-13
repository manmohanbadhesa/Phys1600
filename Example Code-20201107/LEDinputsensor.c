//  LEDinputsensor.c Use MMC RA3 and RA2 as output (LEDs) and RA1 and RA0
//                as input (buttons)    
#include "mcc_generated_files/mcc.h"  // library for SYSTEM_Initialize()

int main(void)
{
 // Initialize the device – MCC file configures clock and DIO
 SYSTEM_Initialize();


 while(1)  // monitor and read pins and light LEDs forever
   {
    // whatever the value of input at RA1 use that value to turn RA3 on/off
    if( IO_RA1_GetValue())
	 IO_RA3_SetHigh();
    else	
	 IO_RA3_SetLow();

    // whatever the value of input at RA0 use that value to turn RA2 on/off
    if( IO_RA0_GetValue())
	 IO_RA2_SetHigh();
    else	
	 IO_RA2_SetLow();
   }
}
// end program
