#include "putty.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myUART.h"
#include "buttons.h"

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
    char gap1[3],length1[5];
    int gaps,i=0, j=0,k=0,h=0;
    uint32_t  timeData[9], dt[9], MidT[9], dT[9], micro2second=1000000; 
    float length,a[9],Vavg[9], dV[9], sum, accavg,accavg1;
    uint32_t time1=1, time2=2, time3=3, time4=4;
    uint32_t time5=5, time6=6;
    clearPuTTY();
           
    printf("SMT1 Capture Test - SMT1WIN on RC0\n\r");
   
    printf("SMT Mode = %u \n\n\r",SMT1CON1bits.MODE);

    //codes to control operation 
    SMT1CON0bits.EN = 1;             // enable SMT peripheral
    SMT1_DataAcquisitionEnable();  
    //SMT1_SingleDataAcquisition();
    SMT1_RepeatDataAcquisition();
    SMT1_ManualTimerReset();         // zero SMT1 counter/timer  
            /*
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
             */ 
    while (1)
    {
        // Add your application code
        /*
        SMT1_DataAcquisitionEnable(); 
        SMT1_ManualTimerReset();
        PIR1bits.SMT1PRAIF = 0;          // clear period (RE) interrupt flag
        while(!PIR1bits.SMT1PRAIF);
        time1 = SMT1_GetCapturedPeriod();     // In capture mode holds rising edge time 
        printf("\n\rtime is %lu",time1);
        */
        red_RD3_SetHigh();
        green_RD2_SetLow();
        sum=0;
        printf("\n\rEnter number of gaps\n\r>");
        ReadNUART2(gap1,3);
        gaps=atoi(gap1);
        if(gaps == 0)
        {
            printf("\n\rplease enter a number");
        }
        else
        {
            printf("\n\rEnter float or integer for length of edge to edge in mm\n\r>");
            ReadNUART2(length1,5);
            length=atof(length1);
            if(length == 0)
            {
                printf("\n\rplease enter a integer or float for length in mm");
            }
            else
            {
                printf("\n\n\rYou have entered the following:");
                printf("\n\rNumber of gaps is %u",gaps);
                printf("\n\rLength of picket is %f",length);
                printf("\n\rStart your data collection now\n\r>\n\r");
                red_RD3_SetLow();
                green_RD2_SetHigh();
                for(i=0;i<gaps;i++)
                {
                        //timeData[i] = 50*i;
                        
                        PIR1bits.SMT1PRAIF = 0;          // clear period (RE) interrupt flag
                        while(!PIR1bits.SMT1PRAIF);
                        timeData[i] = SMT1_GetCapturedPeriod();     // In capture mode holds rising edge time 
                        //printf("\n\rtime is %lu",time1);
                        //DELAY_milliseconds(10);
                        //timeData[i]=time1;
                        //printf("\n\rtime is %lu",time1);
                                            
                }
                //printf("\n\r the length of the time string is %u",strlen(timeData));
                
                for(h=0;h<gaps;h++)
                {
                    timeData[h]=timeData[h]/1000;
                }
                
                for(j=0;j<(gaps-1);j++)
                {
                    dt[j]= timeData[j+1]-timeData[j];
                    MidT[j]= timeData[j]+(dt[j]/2);
                    Vavg[j]= length/dt[j];

                }
                for(k=0;k<(gaps-2);k++)
                {
                    dV[k]=Vavg[k+1]-Vavg[k];
                    dT[k]=MidT[k+1]-MidT[k];
                    a[k]=dV[k]/dT[k];
                    //printf("\n\r%f",a[k]);
                }
                printf("\n\rtimeData  \t dt  \t MidT  \t  Vavg  \t dV  \t dT  \t a");
                for(h=0;h<gaps;h++)
                {
                    //printf("\n\r %lu",timeData[h]);
                    
                    printf("\n\r%lu\t%lu\t%lu\t%f\t%f\t%lu\t%f"
                            ,timeData[h],dt[h],MidT[h],Vavg[h],dV[h],dT[h],a[h]);
                }
                for(k=0;k<(gaps-2);k++)
                {
                    sum += a[k];
                }
                accavg=sum/(gaps-3);
                printf("\n\rsum %f",sum);
                accavg1=1000*accavg;
                printf("\n\rAverage acceleration due to gravity is %f",accavg1);
                
                
            }
        }
               
    }
}
/**
 End of File
                    dt[h+1]=dt[h];
                    MidT[h+1]=MidT[h];
                    Vavg[h+1]=Vavg[h];
                    dV[h+2]=dV[h];
                    dT[h+2]=dT[h];
*/