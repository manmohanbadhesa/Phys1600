// testDIO.c
// MCC to configure RA3 and RA1 as digital output

#include "mcc_generated_files/mcc.h"  // library for SYSTEM_Initialize()

int main(void)
{
  // Initialize the device – MCC file configures clock and DIO
  SYSTEM_Initialize();

  IO_RA3_SetHigh();
  IO_RA1_SetLow();  
  
  while(1);  // run forever
}
// end program
