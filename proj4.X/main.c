#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "putty.h"
#include "myUART.h"
#include <ctype.h>
#include "buttons.h"
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

//void buttonResponse(void);
unsigned int counter = 0, has_switch1_changed = 0;


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    clearPuTTY();
    
    

    while (1)
    {
        // Add your application code
        has_switch1_changed = poll_switch1_for_edges(button_RD1_GetValue());
        //DELAY_milliseconds(10);
        if ( has_switch1_changed == 1 )
        {
            DELAY_milliseconds(10);
            counter++;
            if(counter > 9) 
            {
                counter = 1;
                printf("State = %u \n\r",counter);           
            }
        }
        
    }
}



/**
 End of File
*/