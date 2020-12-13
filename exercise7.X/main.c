#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "myUART.h"
#include "putty.h"
#include <ctype.h>
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    /*
    int i;
    printf("\n\r\n\r #Char \t #Char \t #Char \t #Char \t #Char \t #Char");
    for(i=32;i<48;i++)
    {
        printf("\n\r\n\r %d %c \t %d %c \t %d %c \t %d %c \t %d %c \t %d %c",i,i,i+16,i+1,i+32,i+32,i+48,i+48,i+64,i+64,i+80,i+80);
    }
    */
    int i;
    printf("\n\r\n\r #Char \t #Char \t #Char \t #Char \t #Char \t #Char \t #Char \t #Char");
    for(i=128;i<144;i++)
    {
        printf("\n\r\n\r %d %c \t %d %c \t %d %c \t %d %c \t %d %c \t %d %c \t %d %c \t %d %c",i,i,i+16,i+1,i+32,i+32,i+48,i+48,i+64,i+64,i+80,i+80,i+96,i+96,i+112,i+112);
    }
     
    //int i=0;
    printf("\n\rWelcome to the Physics 1600 menu. \n\r Select from the following:\n\r0- Play the Bell Sound\n\r1-Blink an LED\n\r2-Measure a Voltage\n\r3-Clear screen and reprint menu\n\r >");
    
    // UART2_DataReady  //makes you press a key?
    // while(!UART2_DataReady);  //waits forever until key is pressed
    // UART2_Read();  //reads the key pressed, reads ascii value maybe?
    while (1)
    {
        // Add your application code
        
        if(UART2_DataReady)
        {
            i=UART2_Read();
            switch(i)
            {
                case '0': printf("SOUND! %c \n\r> ",7);
                          break;
                case '1': printf("Blind an LED\n\r>");
                          break;
                case '2': printf("Measuring a Voltage\n\r>");
                          break;
                case '3': clearPuTTY();
                          printf("Welcome to the Physics 1600 menu. \n\r Select from the following:\n\r0- Play the Bell Sound\n\r1-Blink an LED\n\r2-Measure a Voltage\n\r3-Clear screen and reprint menu\n\r >");
                          break;
                default: printf("That is not a valid selection. Try again.\n\r>");
                         break;
            }
            
            
        }
        
        // wait_for_ENTER();  // waits till user presses enter
        // Delay_milliseconds(80); 
        // clearPuTTY(); clears Putty screen, need the putty.h library!!
    }
}
/**
 End of File
*/