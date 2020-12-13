// DigitalOutput.c
// Generate MCC so that the FOSC = 32 MHZ and delays.h
// red LED on RD1
// green LED on RD2

#include "mcc_generated_files/mcc.h"

void main(void)
{
	
 // Initialize the device
 SYSTEM_Initialize();	
 
 redLED_SetHigh(); 
 
 while(1)
 {
	greenLED_Toggle();
	DELAY_milliseconds(200);
 }
 return;
}
