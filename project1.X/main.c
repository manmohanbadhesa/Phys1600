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
    int i;
    char input[10];
    int digit=0,has_switch1_changed;
    clearPuTTY();
    printf("LED Excercise Menu\n\r\n\r 1. Turn Red LED on\n\r\n\r2. Turn Green LED on\n\r\n\r3. Turn Bicolour amber\n\r\n\r4. Turn All LEDs Off\n\r>");
   
    while (1)
    {
        if(UART2_DataReady)     // polls receive buffer for available data
	    {
		i = UART2_Read();          // read a single character from buffer
                digit=i-48;
        if(digit<1 || digit>=5)
        {
            printf("Please type a number between 1 and 5 only.\n\r");
        }
        }
        
        has_switch1_changed = poll_switch1_for_edges(button_RA4_GetValue());
        if(has_switch1_changed==1){ 
           digit++;   
           
           if(digit>4)
           {
               digit=1;
           }
           printf(" Count = %u \n\r", digit);
          }      
        
        
            switch(digit)
            {
                case 1:     redLED_SetHigh(); //RD0 pin
                            greenLED_SetLow();
                            bicolourLEDG_SetLow(); //RD2 pin
                            bicolourLEDR_SetLow(); //RD3 pin
                            break;
                case 2:     greenLED_SetHigh(); //RD1 pin
                            redLED_SetLow();
                            bicolourLEDG_SetLow(); //RD2 pin
                            bicolourLEDR_SetLow(); //RD3 pin
                            break;
                case 3:     redLED_SetLow();
                            greenLED_SetLow();
                            bicolourLEDG_SetLow(); //RD2 pin
                            bicolourLEDR_SetHigh(); //RD3 pin
                            bicolourLEDG_Toggle(); //RD2 pin
                            bicolourLEDR_Toggle(); //RD3 pin
                            DELAY_milliseconds(5);
                            bicolourLEDG_Toggle(); //RD2 pin
                            bicolourLEDR_Toggle(); //RD3 pin
                            DELAY_milliseconds(25);
                            break;

                case 4:     redLED_SetLow(); //RD0 pin
                            greenLED_SetLow(); //RD1 pin
                            bicolourLEDG_SetLow(); //RD2 pin
                            bicolourLEDR_SetLow(); //RD3 pin
                            break;
            }
    }

}



/**
 End of File
*/