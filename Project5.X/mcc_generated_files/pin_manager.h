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

// get/set gate_RA7 aliases
#define gate_RA7_TRIS                 TRISAbits.TRISA7
#define gate_RA7_LAT                  LATAbits.LATA7
#define gate_RA7_PORT                 PORTAbits.RA7
#define gate_RA7_WPU                  WPUAbits.WPUA7
#define gate_RA7_OD                   ODCONAbits.ODCA7
#define gate_RA7_ANS                  ANSELAbits.ANSELA7
#define gate_RA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define gate_RA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define gate_RA7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define gate_RA7_GetValue()           PORTAbits.RA7
#define gate_RA7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define gate_RA7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define gate_RA7_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define gate_RA7_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define gate_RA7_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define gate_RA7_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define gate_RA7_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define gate_RA7_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

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

// get/set col_RC1 aliases
#define col_RC1_TRIS                 TRISCbits.TRISC1
#define col_RC1_LAT                  LATCbits.LATC1
#define col_RC1_PORT                 PORTCbits.RC1
#define col_RC1_WPU                  WPUCbits.WPUC1
#define col_RC1_OD                   ODCONCbits.ODCC1
#define col_RC1_ANS                  ANSELCbits.ANSELC1
#define col_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define col_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define col_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define col_RC1_GetValue()           PORTCbits.RC1
#define col_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define col_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define col_RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define col_RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define col_RC1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define col_RC1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define col_RC1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define col_RC1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set col_RC2 aliases
#define col_RC2_TRIS                 TRISCbits.TRISC2
#define col_RC2_LAT                  LATCbits.LATC2
#define col_RC2_PORT                 PORTCbits.RC2
#define col_RC2_WPU                  WPUCbits.WPUC2
#define col_RC2_OD                   ODCONCbits.ODCC2
#define col_RC2_ANS                  ANSELCbits.ANSELC2
#define col_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define col_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define col_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define col_RC2_GetValue()           PORTCbits.RC2
#define col_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define col_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define col_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define col_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define col_RC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define col_RC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define col_RC2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define col_RC2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set col_RC3 aliases
#define col_RC3_TRIS                 TRISCbits.TRISC3
#define col_RC3_LAT                  LATCbits.LATC3
#define col_RC3_PORT                 PORTCbits.RC3
#define col_RC3_WPU                  WPUCbits.WPUC3
#define col_RC3_OD                   ODCONCbits.ODCC3
#define col_RC3_ANS                  ANSELCbits.ANSELC3
#define col_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define col_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define col_RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define col_RC3_GetValue()           PORTCbits.RC3
#define col_RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define col_RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define col_RC3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define col_RC3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define col_RC3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define col_RC3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define col_RC3_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define col_RC3_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set row1_RC4 aliases
#define row1_RC4_TRIS                 TRISCbits.TRISC4
#define row1_RC4_LAT                  LATCbits.LATC4
#define row1_RC4_PORT                 PORTCbits.RC4
#define row1_RC4_WPU                  WPUCbits.WPUC4
#define row1_RC4_OD                   ODCONCbits.ODCC4
#define row1_RC4_ANS                  ANSELCbits.ANSELC4
#define row1_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define row1_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define row1_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define row1_RC4_GetValue()           PORTCbits.RC4
#define row1_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define row1_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define row1_RC4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define row1_RC4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define row1_RC4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define row1_RC4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define row1_RC4_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define row1_RC4_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set row2_RC5 aliases
#define row2_RC5_TRIS                 TRISCbits.TRISC5
#define row2_RC5_LAT                  LATCbits.LATC5
#define row2_RC5_PORT                 PORTCbits.RC5
#define row2_RC5_WPU                  WPUCbits.WPUC5
#define row2_RC5_OD                   ODCONCbits.ODCC5
#define row2_RC5_ANS                  ANSELCbits.ANSELC5
#define row2_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define row2_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define row2_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define row2_RC5_GetValue()           PORTCbits.RC5
#define row2_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define row2_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define row2_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define row2_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define row2_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define row2_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define row2_RC5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define row2_RC5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set row3_RC6 aliases
#define row3_RC6_TRIS                 TRISCbits.TRISC6
#define row3_RC6_LAT                  LATCbits.LATC6
#define row3_RC6_PORT                 PORTCbits.RC6
#define row3_RC6_WPU                  WPUCbits.WPUC6
#define row3_RC6_OD                   ODCONCbits.ODCC6
#define row3_RC6_ANS                  ANSELCbits.ANSELC6
#define row3_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define row3_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define row3_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define row3_RC6_GetValue()           PORTCbits.RC6
#define row3_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define row3_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define row3_RC6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define row3_RC6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define row3_RC6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define row3_RC6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define row3_RC6_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define row3_RC6_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set row4_RC7 aliases
#define row4_RC7_TRIS                 TRISCbits.TRISC7
#define row4_RC7_LAT                  LATCbits.LATC7
#define row4_RC7_PORT                 PORTCbits.RC7
#define row4_RC7_WPU                  WPUCbits.WPUC7
#define row4_RC7_OD                   ODCONCbits.ODCC7
#define row4_RC7_ANS                  ANSELCbits.ANSELC7
#define row4_RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define row4_RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define row4_RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define row4_RC7_GetValue()           PORTCbits.RC7
#define row4_RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define row4_RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define row4_RC7_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define row4_RC7_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define row4_RC7_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define row4_RC7_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define row4_RC7_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define row4_RC7_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set green_RD1 aliases
#define green_RD1_TRIS                 TRISDbits.TRISD1
#define green_RD1_LAT                  LATDbits.LATD1
#define green_RD1_PORT                 PORTDbits.RD1
#define green_RD1_WPU                  WPUDbits.WPUD1
#define green_RD1_OD                   ODCONDbits.ODCD1
#define green_RD1_ANS                  ANSELDbits.ANSELD1
#define green_RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define green_RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define green_RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define green_RD1_GetValue()           PORTDbits.RD1
#define green_RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define green_RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define green_RD1_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define green_RD1_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define green_RD1_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define green_RD1_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define green_RD1_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define green_RD1_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

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