#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "putty.h"
#include <ctype.h>
#include "buttons.h"
#include "myUART.h"

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    clearPuTTY();
    
    unsigned int n = 0, m = 0, counter = 0, has_switch1_changed = 0;
    float T, f;
    
    unsigned int j=45536;
    T0CON1bits.CKPS = 2;   // N = 2^n, n < 16
    T0CON0bits.OUTPS = 0;  // M = m + 1, m < 16
    
    n = T0CON1bits.CKPS;   
    m = T0CON0bits.OUTPS;
    T = ((m+1.0)*65536.0 - j)*pow(2.0,n)*4.0/ _XTAL_FREQ;
    printf("RD2 On Time %f\n\n\r",T);
    
    
    //Duty cycle value stored in SFRs PWMxDCH:PWMxDCL  (or PWM5_INITIALIZE_DUTY_VALUE)
    printf("\n\rEasy Setup value of PWM5DC is %u  PR2 is %u\n\r", PWM5_INITIALIZE_DUTY_VALUE,PR2);
    //printf("%DC = %.1f \n\n\r", (float)PWM5_INITIALIZE_DUTY_VALUE*100.0/(PR2+1)/4.0);
    
    printf("\n\rEasy Setup value of PWM6DC is %u  PR4 is %u\n\r", PWM6_INITIALIZE_DUTY_VALUE,PR4);
    //printf("%DC = %.1f \n\n\r", (float)PWM6_INITIALIZE_DUTY_VALUE*100.0/(PR4+1)/4.0);
    

    while (1)
    {
        has_switch1_changed = poll_switch1_for_edges(button_RD1_GetValue());
        DELAY_milliseconds(10);
        if ( has_switch1_changed == 1 )
        {
            DELAY_milliseconds(10);
            counter++;
            if (counter > 9) counter = 0;
            printf("State = %u \n\r",counter);           
            
        }
        
        
        switch(counter)
        {
            case 1: 
                    
                    PWM5_LoadDutyValue(1000);
                    PWM6_LoadDutyValue(1023);
                    
                    break;
            case 2: 
                
                    PWM5_LoadDutyValue(100);
                    PWM6_LoadDutyValue(1023);
                    
                    break;
            case 3: 
                    PWM5_LoadDutyValue(1000);
                    PWM6_LoadDutyValue(1023);
                    //DELAY_milliseconds(100);
                    TMR0IF = 0;       // clear flag
                    TMR0_WriteTimer(j);
                    while(!TMR0IF);
                    PWM5_LoadDutyValue(0);
                    PWM6_LoadDutyValue(1023);
                    //DELAY_milliseconds(100);
                    TMR0IF = 0;       // clear flag
                    TMR0_WriteTimer(j);
                    while(!TMR0IF);
                    break;
            case 4: 
                    PWM5_LoadDutyValue(300);
                    PWM6_LoadDutyValue(900);
                    
                    break;
            case 5: 
                    PWM5_LoadDutyValue(311);
                    PWM6_LoadDutyValue(1023);
                    
                    break;
            case 6: 
                    PWM5_LoadDutyValue(311);
                    PWM6_LoadDutyValue(1023);
                    
                    break;
            case 7: PWM5_LoadDutyValue(249);
                    PWM6_LoadDutyValue(1023);
                    
                    break;
            case 8: PWM5_LoadDutyValue(311);
                    PWM6_LoadDutyValue(1023);
                    break;
            case 9: PWM5_LoadDutyValue(0);
                    PWM6_LoadDutyValue(1023);
                    break;
            default:
                    break;
        }
        
        n = T2CONbits.CKPS;     // prescaler setting
        T = ((float)PR2 + 1.0)*pow(2.0,n)*4.0/_XTAL_FREQ;
        f = 1/T;
        //printf("TMR2 settings: %u = 0x%x, N = %.0f, T = %f s, f = %f Hz \n\r",PR2, PR2,pow(2,n), T, f);
        
        n = T4CONbits.CKPS;     // prescaler setting
        T = ((float)PR4 + 1.0)*pow(2.0,n)*4.0/_XTAL_FREQ;
        f = 1/T;
        //printf("TMR4 settings: %u = 0x%x, N = %.0f, T = %f s, f = %f Hz \n\r",PR4, PR4,pow(2,n), T, f);

    }
}
/**
 End of File
*/