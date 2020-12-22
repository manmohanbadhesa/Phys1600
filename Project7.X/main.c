#include "putty.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myUART.h"
#include "buttons.h"

#include "mcc_generated_files/mcc.h"
int has_switch_changed=0;
int counter=0;
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    RC3_SetDigitalInput();
    
    double time1=1, time, s_ratio=1000000, sound=340, distance_r=50,distance;
    int PRtwo=0, DC=0,status=0;

    clearPuTTY();
           
    printf("SMT1 Gated Timer - RE to FE on SMT1SIG (RC5)\n\n\r");
   
    printf("SMT Mode = %u \n\n\r",SMT1CON1bits.MODE);

    //codes to control operation. Not needed. Already set in Easy Setup  
    SMT1CON0bits.EN = 1;             // enable SMT peripheral
    SMT1_DataAcquisitionEnable();    // allows acquisitions/captures    
    SMT1_SingleDataAcquisition();    // allow repeated measurements
    PWM5_LoadDutyValue(0);
    while (1)
    {
        // Add your application code
        
        
        has_switch_changed = poll_switch1_for_edges(button_RD1_GetValue());
        if ( has_switch_changed == 1)
        {
            counter++;
            printf("\n\rcounter = %u",counter);
            
            if(counter ==1)printf("\n\rSystem is Off, Press Button to start");
            if(counter ==2)printf("\n\rSystem is On");
            //PR2=100;  //buzz frequency continously until alarm deactivated or reset
            //PWM5_LoadDutyValue(202);
            if(counter>2)counter=0;
        }
        if(counter == 1)
        {
            red_RD2_SetLow();
            PWM5_LoadDutyValue(0);
            green_RD3_SetHigh();
            DELAY_milliseconds(50);
            green_RD3_SetLow();
            DELAY_milliseconds(50);
            green_RD3_SetHigh();
            DELAY_milliseconds(50);
        }
        if(counter == 2)
        {
            //printf("\n\rhere");
            
            RC3_SetDigitalOutput();
            RC3_SetHigh();
            DELAY_milliseconds(10);
            RC3_SetDigitalInput();
            SMT1_DataAcquisitionEnable();    // allows acquisitions/captures  
            SMT1_ManualTimerReset();  // zero SMT1 counter/timer  
        
            PIR1bits.SMT1PWAIF = 0;
            while(PIR1bits.SMT1PWAIF == 0);
            if(PIR1bits.SMT1PWAIF == 1)
            {
                time1 = SMT1_GetCapturedPulseWidth();  // read buffer
                time= time1/s_ratio;
                //printf("Pulse width = %f musec\n\r", time1);
                //printf("Pulse width = %f seconds\n\r", time);
                //SMT1_DataAcquisitionDisable();
            }
            distance=time*sound*distance_r;
            printf("Distance is = %f cm\n\r", distance);
            DELAY_milliseconds(120);
            if(distance > 60)status=1;
            if(20 < distance && distance <= 30)status=2;
            if(30 < distance && distance <= 40)status=3;
            if(40 < distance && distance <= 50)status=4;
            if(50 < distance && distance <= 60)status=5;
            if(distance <= 20)status=6;
            //printf("\n\r status %u",status);
            //PRtwo=60+distance;
            //DC=200*PRtwo/100;
        
        switch(status)
        {
            case 1:                         green_RD3_SetHigh();
                                            red_RD2_SetLow();
                                            PWM5_LoadDutyValue(0);
                                            break;
            case 2:                         green_RD3_SetLow();
                                            red_RD2_SetHigh();
                                            PR2=30;
                                            PWM5_LoadDutyValue(35);
                                            break;
            case 3:                         green_RD3_SetLow();
                                            red_RD2_SetHigh();
                                            PR2=30;
                                            PWM5_LoadDutyValue(25);
                                            break;
            case 4:                         green_RD3_SetLow();
                                            red_RD2_SetHigh();
                                            PR2=20;
                                            PWM5_LoadDutyValue(18);
                                            break;
            case 5:                         green_RD3_SetLow();
                                            red_RD2_SetHigh();
                                            PR2=30;
                                            PWM5_LoadDutyValue(12);
                                            break;
            case 6:                         PR2=30;
                                            PWM5_LoadDutyValue(62);
                                            green_RD3_SetLow();
                                            red_RD2_SetHigh();
                                            DELAY_milliseconds(50);
                                            red_RD2_SetLow();
                                            DELAY_milliseconds(50);
                                            red_RD2_SetHigh();
                                            DELAY_milliseconds(50);
                                            break;
        }
          
        }
         
    }
}
/*
 End of File
*/