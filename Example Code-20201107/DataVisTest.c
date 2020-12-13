// DataVisTest.c
// system at 1 MHz
// UART2 at 9,600 bps

#include "mcc_generated_files/mcc.h"
#include <math.h>
#include <stdio.h>

#define _PI_  4.0*atan(1.0)

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    int i = 0 , Data1;  // signed 16-bit integer
    unsigned char Data2; // unsigned 8-bit int
     
    printf("Data Vis Test\n\r");
    IO_RD2_SetHigh();
    DELAY_milliseconds(200);
    IO_RD2_SetLow();
    DELAY_milliseconds(200);

    while (1)
    {  
       // create some data to plot  
       Data1 = (int)(1000.0*sin(_PI_ * i/10.0));
       Data2 = (unsigned char)(100.0*(cos(_PI_ * i/10.0) + 1.0));
       i++;
       if (i == 100) i = 0;  // reset i

       UART2_Write(0x5F);           // frame start Decimal 95

       // unsigned int value as two 8bit pieces to Data Visualizer
       UART2_Write(Data1 & 0x00FF); // First data set, send lower 8 bits first
       UART2_Write(Data1 >> 8);     // send upper 8 bits second
       UART2_Write(Data2);          // Second data set
	   
       UART2_Write(0xA0);           // frame end Decimal 160 (Note 160 + 95 = 255)
       
       DELAY_milliseconds(50);
    }
}