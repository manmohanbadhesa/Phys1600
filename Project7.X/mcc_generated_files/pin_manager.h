/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC18F46K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.30 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSELA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSELB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSELB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set button_RD1 aliases
#define button_RD1_TRIS                 TRISDbits.TRISD1
#define button_RD1_LAT                  LATDbits.LATD1
#define button_RD1_PORT                 PORTDbits.RD1
#define button_RD1_WPU                  WPUDbits.WPUD1
#define button_RD1_OD                   ODCONDbits.ODCD1
#define button_RD1_ANS                  ANSELDbits.ANSELD1
#define button_RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define button_RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define button_RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define button_RD1_GetValue()           PORTDbits.RD1
#define button_RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define button_RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define button_RD1_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define button_RD1_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define button_RD1_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define button_RD1_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define button_RD1_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define button_RD1_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set red_RD2 aliases
#define red_RD2_TRIS                 TRISDbits.TRISD2
#define red_RD2_LAT                  LATDbits.LATD2
#define red_RD2_PORT                 PORTDbits.RD2
#define red_RD2_WPU                  WPUDbits.WPUD2
#define red_RD2_OD                   ODCONDbits.ODCD2
#define red_RD2_ANS                  ANSELDbits.ANSELD2
#define red_RD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define red_RD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define red_RD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define red_RD2_GetValue()           PORTDbits.RD2
#define red_RD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define red_RD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define red_RD2_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define red_RD2_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define red_RD2_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define red_RD2_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define red_RD2_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define red_RD2_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set green_RD3 aliases
#define green_RD3_TRIS                 TRISDbits.TRISD3
#define green_RD3_LAT                  LATDbits.LATD3
#define green_RD3_PORT                 PORTDbits.RD3
#define green_RD3_WPU                  WPUDbits.WPUD3
#define green_RD3_OD                   ODCONDbits.ODCD3
#define green_RD3_ANS                  ANSELDbits.ANSELD3
#define green_RD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define green_RD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define green_RD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define green_RD3_GetValue()           PORTDbits.RD3
#define green_RD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define green_RD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define green_RD3_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define green_RD3_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define green_RD3_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define green_RD3_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define green_RD3_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define green_RD3_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/