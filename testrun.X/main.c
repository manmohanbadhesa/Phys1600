#include "putty.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "mcc_generated_files/mcc.h"

// Modes                                 input pin
// 0 Timer                               none      
// 1 Gated Timer                         SMT1SIG
// 2 Period and Duty-Cycle Acquisition   SMT1SIG
// 3 High and low time measurement       SMT1SIG
// 6 Time of flight                      SMT1WIN & SMT1SIG
// 7 Capture                             SMT1WIN  
// 8 Counter                             SMT1SIG

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
        RC3_SetDigitalInput();
    
    double time1=1, time, s_ratio=1000000, sound=340, distance_r=5,distance, time2=2, time3=3;
    int PRtwo=0, DC=0,status=0;
    //int timeData[5],i=0;

    clearPuTTY();

    printf("SMT1 Capture Test - SMT1WIN on RC0\n\r");
   
    printf("SMT Mode = %u \n\n\r",SMT1CON1bits.MODE);

    //codes to control operation 
    SMT1CON0bits.EN = 1;             // enable SMT peripheral
    SMT1_DataAcquisitionEnable();  
    //SMT1_SingleDataAcquisition();
    SMT1_RepeatDataAcquisition();
    SMT1_ManualTimerReset();         // zero SMT1 counter/timer  
    printf("start\n\r");
    
        PIR1bits.SMT1PRAIF = 0;          // clear period (RE) interrupt flag
    while(!PIR1bits.SMT1PRAIF);
    time1 = SMT1_GetCapturedPeriod();     // In capture mode holds rising edge time 

    
    PIR1bits.SMT1PRAIF = 0;          // clear period (RE) interrupt flag
    while(!PIR1bits.SMT1PRAIF);
    time2 = SMT1_GetCapturedPeriod();      // In capture mode holds rising edge time 

    
    PIR1bits.SMT1PRAIF = 0;          // clear period (RE) interrupt flag
    while(!PIR1bits.SMT1PRAIF);
    time3 = SMT1_GetCapturedPeriod();      // In capture mode holds rising edge time 
    
    printf("Captured sequence is RE, FE, RE \n\r");  
    printf("time1 = %lu, time2 = %lu, time3 = %lu \n\r", time1, time2, time3 );
    while (1)
    {
        // Add your application code
                        //SMT1_ManualTimerReset();
        /*
                        PIR1bits.SMT1PRAIF = 0;          // clear period (RE) interrupt flag
                        while(!PIR1bits.SMT1PRAIF);
                        time1 = SMT1_GetCapturedPeriod();     // In capture mode holds rising edge time 
                        printf("\n\rtime is %lu",time1);
                        //DELAY_milliseconds(10);
                        //timeData[i]=time1;
                        //printf("\n\rtime is %lu",timeData);
                                        
                        //DELAY_milliseconds(5000);
*/
    }
}
/**
 End of File
*/