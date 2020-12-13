// Readbuttons.c
// set FOSC to any value
// button_RD1, led_RD2

#include "mcc_generated_files/mcc.h"

int main(void){ 
 // Initialize the device
 SYSTEM_Initialize();
  
 while(1){  
   // have LED respond to button
   if( button_RD1_GetValue() == 1)
      led_RD2_SetHigh();
   else
      led_RD2_SetLow();	   
 }
}  //end program
