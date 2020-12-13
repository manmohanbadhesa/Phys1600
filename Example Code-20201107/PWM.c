// PWM.c
// FOSC = 1 MHz
// CCP1 using TMR2, DC = 50%, RC5 and RC4
// TMR2 uses FOSC/4. N = 128, M = 1, use maximum period
// PWM5 using TMR4, DC = 30%, RC7
// TMR4 uses FOSC/4. N = 64, M = 1, use maximum period
// button on RD1, LED on RD2 

#include "mcc_generated_files/mcc.h"
#include <stdio.h>    // C Library for printf() 
#include <math.h>     // C Library for pow(x,n) 
#include "buttons.h"
#include "putty.h"

/*
                         Main application
 */
void main(void)
{
    SYSTEM_Initialize();
    clearPuTTY();
    
    unsigned int n = 0, m = 0, counter = 0, has_switch1_changed = 0;
    float T, f;
    
    n = T2CONbits.CKPS;     // prescaler setting
    T = ((float)PR2 + 1.0)*pow(2.0,n)*4.0/_XTAL_FREQ;
    f = 1/T;
    printf("TMR2 settings: %u = 0x%x, N = %.0f, T = %f s, f = %f Hz \n\r", 
            PR2, PR2,pow(2,n), T, f);    

    //Duty cycle value stored in SFRs CCPR1H:CCPRxL
    printf("Easy Setup value of CCPR1 is %4.0f \n\r", CCPR1H*256.0+CCPR1L);
    printf("%DC = %.1f \n\n\r",(CCPR1H*256.0+CCPR1L)*100.0/(PR2+1)/4.0);


    n = T4CONbits.CKPS;     // prescaler setting
    T = ((float)PR4 + 1.0)*pow(2.0,n)*4.0/_XTAL_FREQ;
    f = 1/T;
    printf("TMR4 settings: %u = 0x%x, N = %.0f, T = %f s, f = %f Hz \n\r", 
            PR4, PR4,pow(2,n), T, f);    

    //Duty cycle value stored in SFRs PWMxDCH:PWMxDCL  (or PWM5_INITIALIZE_DUTY_VALUE)
    printf("Easy Setup value of PWM5DC is %u \n\r", PWM5_INITIALIZE_DUTY_VALUE);
    printf("%DC = %.1f \n\n\r", (float)PWM5_INITIALIZE_DUTY_VALUE*100.0/(PR4+1)/4.0);


    printf("counter = %u OFF\n\r",counter);

    while (1)     
    {
      has_switch1_changed = poll_switch1_for_edges(IO_RD1_GetValue());
      if ( has_switch1_changed == 1 )
      {
          counter++;
          if (counter > 5) counter = 0;
          printf("counter = %u \n\r",counter);
      }
     
    switch(counter){
        case 0: PWM1_LoadDutyValue(0);
                PWM5_LoadDutyValue(0);
                break;
        case 1: PWM1_LoadDutyValue(128);
                PWM5_LoadDutyValue(128);
                break;
        case 2: PWM1_LoadDutyValue(256);
                PWM5_LoadDutyValue(256);
                break;
        case 3: PWM1_LoadDutyValue(511);
                PWM5_LoadDutyValue(511);
                break;
        case 4: PWM1_LoadDutyValue(768);
                PWM5_LoadDutyValue(768);
                break;
        case 5: PWM1_LoadDutyValue(1023);
                PWM5_LoadDutyValue(1023);
        default:
                break;
    }
      
    }
}
