#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "putty.h"
#include "myUART.h"
#include <ctype.h>
#include "buttons.h"


#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    clearPuTTY();
    int i;
    unsigned int newcount=0, oldcount=0,k=0;
    unsigned char button;
    unsigned int has_switch1_changed=0, counter=0;
    clearPuTTY();
    
       
    printf("Ready\n\r>");   
    printf("press button on breadboard\n\r");

    while (1)
    {
        // Add your application code
        button = RA4_GetValue();
        has_switch1_changed = poll_switch1_for_edges(button);
        if(has_switch1_changed==1){ 
           counter++; 
           if(counter<=3)
           {
           printf(" Count = %u \n\r", counter);
           } 
          } 
        if(counter>=4)
        {
            counter=1;
            printf(" Count = %u \n\r", counter);
            
        }
        
        switch(counter)
        {
        case 1: redB_RD2_SetHigh();
                greenB_RD1_SetLow();
                break;
        case 2: greenB_RD1_SetHigh();
                redB_RD2_SetLow();
                break;
        case 3: redB_RD2_SetLow();
                greenB_RD1_SetLow();
                break;
        }
    }
    
}
/**
 End of File
*/