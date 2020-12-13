// UnresponsiveButton.c
// Generate MCC so that the FOSC = 32 MHZ and Delays
// Button on RD1 (button_RD1), LED on RD2 (led_RD2) 

#include "mcc_generated_files/mcc.h"
#include <stdio.h>    // C Library for printf() 
#include "buttons.h"
#include "putty.h"

int main(void) 
{ 
    unsigned int has_switch1_changed = 0;
    unsigned char blinkrate = 0;

    clearPuTTY();
        
    while(1) 
    { 
        has_switch1_changed = poll_switch1_for_edges(button_RD1_GetValue());
        //happens every cycle of while loop 

        if (has_switch1_changed == 1)
           {  
             DELAY_milliseconds(10);  // debouncing delay
             //anything that should happen occasionally should be in here 
             blinkrate++;                      //increment counter 
             if (blinkrate > 3) blinkrate = 0; //cycle back to 0
             printf("blinkrate = %u \n\r",blinkrate);
            }
            //happens every cycle of while loop 
			switch(blinkrate) // switch between blink rates
				{
				   case 0: // off
					   led_RD2_SetLow();// off
					   break; 
					case 1: // fast blink
					   led_RD2_SetHigh();; //on
					   DELAY_milliseconds(25);
					   led_RD2_SetLow();; //off
					   DELAY_milliseconds(25);
					   break; 
					case 2: // slow blink
					   led_RD2_SetLow(); //on
					   DELAY_milliseconds(2000);
					   led_RD2_SetHigh(); //off
					   DELAY_milliseconds(2000);
					   break; 
					case 3: // full on
					   led_RD2_SetLow(); //on
					   break; 
				}
    } 
} 

// end program
