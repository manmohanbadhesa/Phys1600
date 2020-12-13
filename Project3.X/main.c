#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "putty.h"
#include <ctype.h>
#include "buttons.h"
#include "read_keypad.h"

#include "mcc_generated_files/mcc.h"
extern volatile uint16_t timer0ReloadVal16bit;
int readKeypad();
float T, f;
unsigned int n = 0, m = 0;
/*
                         Main application
 */


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    clearPuTTY();
    //unsigned int n = 0, m = 0;
    //float T, f;
    unsigned int has_switch1_changed=0,has_switch2_changed=0,has_switch3_changed=0,has_switch4_changed=0;
    int k;
    //col_RC2_SetHigh(); 
    printf("Press buttons\n\r");
    char password[5];
    

    printf("\n\rEasy Setup value of PWM5DC is %u \n\r", PWM5_INITIALIZE_DUTY_VALUE);
    printf("%DC = %.1f \n\n\r", (float)PWM5_INITIALIZE_DUTY_VALUE*100.0/(PR2+1)/4.0);        
    
    
    while (1)
    {
        // Add your application code
        //readKeypad();
        k=readKeypad();
        //printf("\n\rk = %u",k);
        musical_note(k);
       
        
    }
}

 //End of File



int readKeypad()
{
    int i=0;
    
        col_RC1_SetHigh();
        col_RC2_SetLow();
        col_RC3_SetLow();
        //printf("\n\rcol 1 powered\n\r");
        if(row_RC4_GetValue()==1)
        {
            printf("\n\rbutton 1");
            i=1;
            //printf("i = %u",i);
        }
        

        
        if(row_RC5_GetValue()==1)
        {
            printf("\n\rbutton 4");
            i=2;
        }
        
        
        if(row_RC6_GetValue()==1)
        {
            //printf("\n\rbutton 7");
            i=3;
        }

        if(row_RC7_GetValue()==1)
        {
            //printf("\n\rbutton *");
            i=4;
        }

        
        DELAY_milliseconds(1);
        
        col_RC2_SetHigh();
        col_RC1_SetLow();
        col_RC3_SetLow();
        //printf("\n\rcol 2 powered\n\r");
        
        if(row_RC4_GetValue()==1)
        {
            //printf("\n\rbutton 2");
            i=5;
        }

        
        if(row_RC5_GetValue()==1)
        {
            //printf("\n\rbutton 5");
            i=6;
        }

        
        if(row_RC6_GetValue()==1)
        {
            //printf("\n\rbutton 8");
            i=7;
        }

        if(row_RC7_GetValue()==1)
        {
            //printf("\n\rbutton 0");
            i=8;
        }

        
        DELAY_milliseconds(1);
        
        col_RC2_SetLow();
        col_RC1_SetLow();
        col_RC3_SetHigh();
        //printf("\n\rcol 3 powered");
        
        if(row_RC4_GetValue()==1)
        {
            //printf("\n\rbutton 3");
            i=9;
        }

        
        if(row_RC5_GetValue()==1)
        {
            //printf("\n\rbutton 6");
            i=10;
        }

        
        if(row_RC6_GetValue()==1)
        {
            //printf("\n\rbutton 9");
            i=11;
        }

        if(row_RC7_GetValue()==1)
        {
            //printf("\n\rbutton #");
            i=12;
        }

        return i;
}

int musical_note(i)
{
    switch(i)
        {
        case 0: PWM5_LoadDutyValue(0);
                break;
        case 1: PR2=117;
                PWM5_LoadDutyValue(236);
                break;
        case 2: PR2=112;
                
                PWM5_LoadDutyValue(226);
                break;
        case 3: PR2=105;
                
                PWM5_LoadDutyValue(212);
                break;
        case 4: PR2=98;
                
                PWM5_LoadDutyValue(198);
                break;
        case 5: PR2=93;
                
                PWM5_LoadDutyValue(188);
                break;
        case 6: PR2=88;
                
                PWM5_LoadDutyValue(178);
                break;
        case 7: PR2=83;
                
                PWM5_LoadDutyValue(168);
                break;
        case 8: PR2=78;
                
                PWM5_LoadDutyValue(158);
                break;
        case 9: PR2=73;
                
                PWM5_LoadDutyValue(148);
                break;
        case 10: PR2=69;
                
                PWM5_LoadDutyValue(140);
                break;
        case 11: PR2=66;
                
                PWM5_LoadDutyValue(134);
                break;
        case 12: PR2=62;
                
                PWM5_LoadDutyValue(126);
                break;
        default:
                break;
        }
        
        n = T2CONbits.CKPS;     // prescaler setting
        T = ((float)PR2 + 1.0)*pow(2.0,n)*4.0/_XTAL_FREQ;
        f = 1/T;
        //printf("TMR2 settings: %u = 0x%x, N = %.0f, T = %f s, f = %f Hz \n\r",PR2, PR2,pow(2,n), T, f);
        
        
}
 