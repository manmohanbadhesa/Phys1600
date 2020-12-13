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

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSELC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSELC2 = 0; } while(0)

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

// get/set redB_RD2 aliases
#define redB_RD2_TRIS                 TRISDbits.TRISD2
#define redB_RD2_LAT                  LATDbits.LATD2
#define redB_RD2_PORT                 PORTDbits.RD2
#define redB_RD2_WPU                  WPUDbits.WPUD2
#define redB_RD2_OD                   ODCONDbits.ODCD2
#define redB_RD2_ANS                  ANSELDbits.ANSELD2
#define redB_RD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define redB_RD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define redB_RD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define redB_RD2_GetValue()           PORTDbits.RD2
#define redB_RD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define redB_RD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define redB_RD2_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define redB_RD2_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define redB_RD2_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define redB_RD2_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define redB_RD2_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define redB_RD2_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

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