// Use the MCC to setup
// 1. uart2
// 2. TMR0
// 3. configure RA4 as the T0CKI input pin
// Then wire a button to RA4

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>    
#include "putty.h"
#include "buttons.h"

void main(void) {
    // Initialize the device
    SYSTEM_Initialize();
    unsigned char button;
    unsigned int has_switch1_changed=0, counter=0;
    clearPuTTY();                // clear display
    printf(" Count button presses \n\r");
    
    while(1){ 
        button = RA4_GetValue();
        has_switch1_changed = poll_switch1_for_edges(button);
        if(has_switch1_changed==1){ 
           counter++;   
           printf(" Count = %u \n\r", counter); 	 
          } 
        
    } 
}
