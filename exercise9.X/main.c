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
    /*
    redLED_SetHigh(); //RD1 pin
    greenLED_SetHigh(); //RD2 pin
    bicolourLEDG_SetHigh(); //RD0 pin
    bicolourLEDR_SetLow(); //RD3 pin
    */
    char input[10],i;
    int digit=0,has_switch1_changed;
    printf("LED Excercise Menu\n\r\n\r 1. Turn Red LED on\n\r\n\r2. Turn Green LED on\n\r\n\r3. Turn Bicolour LED Red\n\r\n\r4.Turn Bicolour LED Green\n\r\n\r5. Turn All LEDs Off\n\r>");
    while (1)
    {
        // Add your application code
        //printf("LED Excercise Menu\n\r\n\r 1. Turn Red LED on\n\r\n\r2. Turn Green LED on\n\r\n\r3. Turn Bicolour LED Red\n\r\n\r4.Turn Bicolour LED Green\n\r\n\r5. Turn All LEDs Off\n\r>");
        if(UART2_DataReady)     // polls receive buffer for available data
	    {
		i = UART2_Read();          // read a single character from buffer
                digit=i-48;
        if(digit<=0 || digit>=6)
        {
            printf("Please type a number between 1 and 5 only.\n\r");
        }
        }
        /*
        has_switch1_changed = poll_switch1_for_edges(button_RA4_GetValue());
        if(has_switch1_changed==1){ 
           digit++;   
           
           if(digit>5)
           {
               digit=0;
           }
           printf(" Count = %u \n\r", digit);
          }      
        */
        
            switch(digit)
            {
                case 1:     redLED_SetHigh(); //RD1 pin
                            break;
                case 2:     greenLED_SetHigh(); //RD2 pin
                            break;
                case 3:     bicolourLEDG_SetLow(); //RD0 pin
                            bicolourLEDR_SetHigh(); //RD3 pin
                            break;
                case 4:    bicolourLEDG_SetHigh(); //RD0 pin
                           bicolourLEDR_SetLow(); //RD3 pin
                           break;
                case 5:     redLED_SetLow(); //RD1 pin
                            greenLED_SetLow(); //RD2 pin
                            bicolourLEDG_SetLow(); //RD0 pin
                            bicolourLEDR_SetLow(); //RD3 pin
                            break;
            }
        
        
    }
}
/**
 End of File
*/

// IO_RDn_SetHigh(); //turns on pin
// IO_RDn_SetLow(); //turns pin ground
// IO_RDn_Toggle(); //toggle between high and low each time you call it