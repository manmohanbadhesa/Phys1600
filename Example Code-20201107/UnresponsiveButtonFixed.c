// UnresponsiveButton.c
// Generate MCC so that the FOSC = 32 MHZ and Delays
// Button on RD1 (button_RD1), LED on RD2 (led_RD2) 

#include "mcc_generated_files/mcc.h"
#include <stdio.h>    // C Library for printf() 
#include <math.h>    // C Library for pow() 
#include "buttons.h"
#include "putty.h"

void buttonResponse(void);
unsigned int has_switch1_changed = 0;
unsigned char blinkrate = 0;

extern volatile uint16_t timer0ReloadVal16bit;  // TMR0H:TMR0L value in tmr0.c

int main(void) 
{ 
    // Initialize the device
    SYSTEM_Initialize();
    
    unsigned int n = 0, m = 0;
    float T_on, T_off, f;
    
    led_RD2_SetLow();
    clearPuTTY();
    printf("Unresponsive Button \n\n\r");    
    
    //you can control the counter start value, prescaler N, and postscaler M
    //timer0ReloadVal16bit = 32768u;
    //T0CON1bits.CKPS = 2;   // N = 2^n, n < 16
    //T0CON0bits.OUTPS = 2;  // M = m + 1, m < 16
    n = T0CON1bits.CKPS;   // prescaler setting n - prescaler is N = 2^n
    m = T0CON0bits.OUTPS;  // postscaler setting m - postscaler is M = m + 1
    
    printf("timer0ReloadVal16bit %u = 0x%x, n = %u, N = %.0f, m = %u, M = %u \n\n\r",
            timer0ReloadVal16bit, timer0ReloadVal16bit, n, pow(2,n), m, m+1);    
    
    // FOSC can be found from variable _XTAL_FREQ
    
    T_on = ((m+1.0)*65536.0 - (float)timer0ReloadVal16bit)*pow(2.0,n)*4.0/ _XTAL_FREQ;
    T_off = ((m+1.0)*65536.0 - (float)timer0ReloadVal16bit)*pow(2.0,n)*4.0/ _XTAL_FREQ;
    f = 1/(T_on + T_off); 
    printf("RD2 On Time %f, Off Time %f seconds, frequency = %f Hz\n\n\r",T_on, T_off, f);
    
    while(1) 
    { 
 
        buttonResponse();
        //happens every cycle of while loop 
		switch(blinkrate) // switch between blink rates
			{
		  	    case 0: // off
                        led_RD2_SetHigh();// on
                        break; 
				case 1: // fast blink
                        led_RD2_SetHigh(); //on
                        DELAY_milliseconds(25);
                        led_RD2_SetLow(); //off
                        DELAY_milliseconds(25);
                        break; 
				case 2: // slow blink
                        led_RD2_SetLow(); //on
                        //DELAY_milliseconds(2000);
                        TMR0IF = 0;       // clear flag
                        TMR0_WriteTimer(timer0ReloadVal16bit);
                        while(!TMR0IF){   // wait for rollover M times and then set flag
                            buttonResponse();
                        }
                        led_RD2_SetHigh(); //off
						//DELAY_milliseconds(2000);
                        TMR0IF = 0;       // clear flag
                        TMR0_WriteTimer(timer0ReloadVal16bit);
                        while(!TMR0IF){   // wait for rollover M times and then set flag
                           buttonResponse(); 
                        }
                        break; 
				case 3: // full on
                        led_RD2_SetLow(); //off
                        break; 
				}
    
    } 
} 

void buttonResponse(void){
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
        
}
// end program
