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

// get/set button_RA4 aliases
#define button_RA4_TRIS                 TRISAbits.TRISA4
#define button_RA4_LAT                  LATAbits.LATA4
#define button_RA4_PORT                 PORTAbits.RA4
#define button_RA4_WPU                  WPUAbits.WPUA4
#define button_RA4_OD                   ODCONAbits.ODCA4
#define button_RA4_ANS                  ANSELAbits.ANSELA4
#define button_RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define button_RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define button_RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define button_RA4_GetValue()           PORTAbits.RA4
#define button_RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define button_RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define button_RA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define button_RA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define button_RA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define button_RA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define button_RA4_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define button_RA4_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

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

// get/set bicolourLEDG aliases
#define bicolourLEDG_TRIS                 TRISDbits.TRISD0
#define bicolourLEDG_LAT                  LATDbits.LATD0
#define bicolourLEDG_PORT                 PORTDbits.RD0
#define bicolourLEDG_WPU                  WPUDbits.WPUD0
#define bicolourLEDG_OD                   ODCONDbits.ODCD0
#define bicolourLEDG_ANS                  ANSELDbits.ANSELD0
#define bicolourLEDG_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define bicolourLEDG_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define bicolourLEDG_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define bicolourLEDG_GetValue()           PORTDbits.RD0
#define bicolourLEDG_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define bicolourLEDG_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define bicolourLEDG_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define bicolourLEDG_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define bicolourLEDG_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define bicolourLEDG_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define bicolourLEDG_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define bicolourLEDG_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set redLED aliases
#define redLED_TRIS                 TRISDbits.TRISD1
#define redLED_LAT                  LATDbits.LATD1
#define redLED_PORT                 PORTDbits.RD1
#define redLED_WPU                  WPUDbits.WPUD1
#define redLED_OD                   ODCONDbits.ODCD1
#define redLED_ANS                  ANSELDbits.ANSELD1
#define redLED_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define redLED_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define redLED_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define redLED_GetValue()           PORTDbits.RD1
#define redLED_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define redLED_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define redLED_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define redLED_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define redLED_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define redLED_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define redLED_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define redLED_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set greenLED aliases
#define greenLED_TRIS                 TRISDbits.TRISD2
#define greenLED_LAT                  LATDbits.LATD2
#define greenLED_PORT                 PORTDbits.RD2
#define greenLED_WPU                  WPUDbits.WPUD2
#define greenLED_OD                   ODCONDbits.ODCD2
#define greenLED_ANS                  ANSELDbits.ANSELD2
#define greenLED_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define greenLED_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define greenLED_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define greenLED_GetValue()           PORTDbits.RD2
#define greenLED_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define greenLED_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define greenLED_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define greenLED_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define greenLED_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define greenLED_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define greenLED_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define greenLED_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set bicolourLEDR aliases
#define bicolourLEDR_TRIS                 TRISDbits.TRISD3
#define bicolourLEDR_LAT                  LATDbits.LATD3
#define bicolourLEDR_PORT                 PORTDbits.RD3
#define bicolourLEDR_WPU                  WPUDbits.WPUD3
#define bicolourLEDR_OD                   ODCONDbits.ODCD3
#define bicolourLEDR_ANS                  ANSELDbits.ANSELD3
#define bicolourLEDR_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define bicolourLEDR_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define bicolourLEDR_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define bicolourLEDR_GetValue()           PORTDbits.RD3
#define bicolourLEDR_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define bicolourLEDR_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define bicolourLEDR_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define bicolourLEDR_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define bicolourLEDR_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define bicolourLEDR_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define bicolourLEDR_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define bicolourLEDR_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

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