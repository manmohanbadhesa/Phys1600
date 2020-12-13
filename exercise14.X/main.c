#include <stdio.h>    // C Library for printf() 
#include <math.h>     // C Library for pow(x,n) 
#include "buttons.h"
#include "putty.h"


#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    unsigned int counter = 0, buttonpress = 0, flag = 0,value=0,n, final_time;
    float time; 
    unsigned char has_switch1_changed = 0;
    n=T0CON1bits.CKPS;
    clearPuTTY();
    printf("\n\rBlock photogate whenever ready \n\n\r");
    printf("\n\r n= %u \n\r xtal= %f\n\r",n,(float)_XTAL_FREQ);

    while (1)
    {
        // Add your application code
            
           has_switch1_changed = poll_switch1_for_edges(button_RD1_GetValue());

            if ( has_switch1_changed == 1 ) //rising edge
                {
                printf("\n\rphotogate blocked");
                 TMR0_WriteTimer(0);     // reset counter 
                 TMR0IF = 0;             // clear flag
                 led_RD2_SetHigh();
                }
            if (has_switch1_changed == 2)         // read the timer on 10th press
                {  
                led_RD2_SetLow();
                printf("\n\rphotogate unblocked");
                value=TMR0_ReadTimer();
                time = (float)value*4.0*pow(2,n)/(float)_XTAL_FREQ;
                flag = TMR0IF;
                //final_time=(flag*4.0)+time;
                printf("\n\rt = %f s (incorrect if overflow occurred) flag = %u \n\r",time,flag);
                }
     } //end if
        
}

/**
 End of File
*/