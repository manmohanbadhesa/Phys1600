// buttonLED.c 
// MMC: RA2 as output. RA0 as input

#include "mcc_generated_files/mcc.h"  // library for SYSTEM_Initialize()

int main(void)
{
 // Initialize the device – MCC file configures clock and DIO
 SYSTEM_Initialize();

 while(1)  // monitor and read pins and light LED forever
   {
     // whatever the value of input at RA0 use that value to turn RA2 on/off
    if( IO_RA0_GetValue())
		IO_RA2_SetHigh();
    else	
		IO_RA2_SetLow();
   }
}
// end program
