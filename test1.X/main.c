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
void buttonResponse(void);
unsigned int counter = 0, has_switch1_changed = 0;


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    clearPuTTY();
    
    unsigned int n = 0, m = 0;
    float T, f;
    
    // Initial value of Timer for blinking timers
    unsigned int j=45536;
    
    // Initial values for Ambulance timers of 0.4 and 0.6 seconds:
    unsigned int k=15536,h=28036;
    
    // Is also changed inside switch loop for the required time
    T0CON1bits.CKPS = 2;   // N = 2^n, n < 16
    T0CON0bits.OUTPS = 0;  // M = m + 1, m < 16
    
    
    // just to calculate the time period
    n = T0CON1bits.CKPS;   
    m = T0CON0bits.OUTPS;
    T = ((m+1.0)*65536.0 - j)*pow(2.0,n)*4.0/ _XTAL_FREQ;
    printf("RD2 On Time %f\n\n\r",T);
    
    
    //Duty cycle value stored in SFRs PWMxDCH:PWMxDCL  (or PWM5_INITIALIZE_DUTY_VALUE)
    printf("\n\rEasy Setup value of PWM5DC is %u  PR2 is %u\n\r", PWM5_INITIALIZE_DUTY_VALUE,PR2);
    //printf("%DC = %.1f \n\n\r", (float)PWM5_INITIALIZE_DUTY_VALUE*100.0/(PR2+1)/4.0);
    
    printf("\n\rEasy Setup value of PWM6DC is %u  PR4 is %u\n\r", PWM6_INITIALIZE_DUTY_VALUE,PR4);
    //printf("%DC = %.1f \n\n\r", (float)PWM6_INITIALIZE_DUTY_VALUE*100.0/(PR4+1)/4.0);
    
    
    printf("\n\rEasy Setup value of PWM6DC is %u  PR4 is %u\n\r", PWM7_INITIALIZE_DUTY_VALUE,PR4);
    //printf("%DC = %.1f \n\n\r", (float)PWW7_INITIALIZE_DUTY_VALUE*100.0/(PR4+1)/4.0);
    PWM7_LoadDutyValue(0);

    while (1)
    {
        // program beings with a buttonResponse function wrapped outside main at the bottom
        
        buttonResponse();
        
        switch(counter)
        {
            case 1: PR4=118;
                    PWM7_LoadDutyValue(238);
                    PWM5_LoadDutyValue(1000);
                    PWM6_LoadDutyValue(1000);
                    
                    break;
            case 2: PR4=102;
                    PWM7_LoadDutyValue(206);
                    PWM5_LoadDutyValue(350);
                    PWM6_LoadDutyValue(1023);
                    
                    break;           
            case 3: PR4=88;
                    PWM7_LoadDutyValue(178);
                    PWM5_LoadDutyValue(1000);
                    PWM6_LoadDutyValue(1000);

                    TMR0IF = 0;       // clear flag
                    TMR0_WriteTimer(j);
                    while(!TMR0IF)
                    {
                        buttonResponse();
                        //goto next case
                        if(counter ==4)break;
                                          
                    }
                    PWM5_LoadDutyValue(0);
                    PWM6_LoadDutyValue(1000);

                    TMR0IF = 0;       // clear flag
                    TMR0_WriteTimer(j);
                    while(!TMR0IF)
                    {
                        buttonResponse();
                        //goto next case
                        if(counter ==4)break;
                                          
                    }
                    break;
            case 4: PR4=76;
                    PWM7_LoadDutyValue(154);
                    PWM5_LoadDutyValue(300);
                    PWM6_LoadDutyValue(900);
                    
                    break;
            case 5: PR4=23;
                    PWM7_LoadDutyValue(48);
                    T0CON1bits.CKPS = 4;
                    PWM5_LoadDutyValue(1000);
                    PWM6_LoadDutyValue(1000);
                    TMR0IF = 0;       // clear flag
                    TMR0_WriteTimer(k);
                    while(!TMR0IF)
                    {
                        buttonResponse();
                        //goto next case
                        if(counter ==6)break;
                                          
                    }
                    PR4=16;
                    PWM7_LoadDutyValue(32);
                    T0CON1bits.CKPS = 5;
                    PWM5_LoadDutyValue(0);
                    PWM6_LoadDutyValue(0);                    
                    TMR0IF = 0;       // clear flag
                    TMR0_WriteTimer(h);
                    while(!TMR0IF)
                    {
                        buttonResponse();
                        //goto next case
                        if(counter ==6)break;
                                          
                    }
                    break;
            case 6: PR4=66;
                    PWM7_LoadDutyValue(134);
                    T0CON1bits.CKPS = 2;
                    PWM5_LoadDutyValue(0);
                    PWM6_LoadDutyValue(1000);

                    TMR0IF = 0;       // clear flag
                    TMR0_WriteTimer(j);
                    while(!TMR0IF)
                    {
                        buttonResponse();
                        //goto next case
                        if(counter ==7)break;
                                          
                    }
                    PWM5_LoadDutyValue(0);
                    PWM6_LoadDutyValue(0);

                    TMR0IF = 0;       // clear flag
                    TMR0_WriteTimer(j);
                    while(!TMR0IF)
                    {
                        buttonResponse();
                        //goto next case
                        if(counter ==7)break;
                                          
                    }
                    
                    break;
            case 7: PR4=52;
                    PWM7_LoadDutyValue(106);
                    PWM5_LoadDutyValue(0);
                    PWM6_LoadDutyValue(750);
                    
                    break;
            case 8: PR4=40;
                    PWM7_LoadDutyValue(82);
                    PWM5_LoadDutyValue(0);
                    PWM6_LoadDutyValue(100);
                    break;
            case 9: PWM7_LoadDutyValue(0);
                    PWM5_LoadDutyValue(0);
                    PWM6_LoadDutyValue(1000);
                    break;
                      
        }
    }
}

void buttonResponse(void)
{
        has_switch1_changed = poll_switch1_for_edges(button_RD1_GetValue());
        DELAY_milliseconds(10);
        if ( has_switch1_changed == 1 )
        {
            DELAY_milliseconds(10);
            counter++;
            
            if(counter > 9) 
            {
                counter = 1;
            }
                printf("State = %u \n\r",counter);
            
            
        }
}


/*
 End of File
 */ 
 