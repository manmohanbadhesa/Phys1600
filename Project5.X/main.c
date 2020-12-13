//Bicolour LED at pins RD1 and RD2 with long leg at the pin you want to me make
//Connect pins of keypad in increasing order and group rows and columns seperately 
//to make it easier to remember as follows:
//Column pins RC1, RC2, RC3 in chronological order for convenience 
//Row pins at RC4, RC5, RC6, RC7
//PWM5 at 50% using Timer2
//TMR2 using clock source FOSC/4, prescaler 1:128, and period of 4 ms
//Optional for Non-Blocking Delays:
//TMR0 16 bit, prescaler 1:32, FOSC/4 and 600 ms period


#include <stdio.h>    // C Library for printf() 

#include <string.h>  // C Libary for strcmp function
#include "buttons.h" //contains function for detecting rising/falling edges for button presses
#include "putty.h"  // Library for clearPuTTY

#include "mcc_generated_files/mcc.h"

//Globally defined strings for passwords and string to store human attempt 
char password_attempt[6];
char alarmset[]="1357*";
char alarmoff[]="1357#";
int alarm_status=0;  //integer used as a status to alternate between conditions

//Function for using photo gate as a button on PIC microcontroller
//has_switchN_changed used as global vairbale to detect button presses
void buttonResponse(void);
int has_switch1_changed=0,has_switch2_changed=0, has_switch3_changed=0, has_switch4_changed=0;
int has_switch_changed=0;

//Function for scanning the keypad for button presses
int scan_keypad();
unsigned int k;
int i=0;    //output from scan_keypad
int j=0;    //int used to start code when button pressed    

//Code for adding beeps using Non-Blocking Delays
void beeps(void); 
unsigned int g=55536;

//Globally defined counter 
int counter=0;

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    //to check if human input matches either defined passwords alarmset or alarmoff
    unsigned int compare,compare2;
    
    clearPuTTY();
    
    //Speaker should be quiet at the beginning of program which it isn't sometimes
    PWM5_LoadDutyValue(0);
     
    while (1)
    {
        // Add your application code

        //Most of printf statements can be used by the developer to find errors in code 
        //and see what is actually outputting, so will keep them in code
        
        
        buttonResponse();  //start looking for rising/falling edge at photo gate
        k=scan_keypad();   //start keypad scan every cycle in the while loop
        //printf("\n\r%u",j);
        if(j == 1)          //only starts when button is pressed
        {
            //printf("\n\r counter %u",counter);
            
            password_attempt[counter]=i;    //stores int value in a string each
                                            //time button pressed on keypad    
                                            
            
            counter++;                      //increments counter every time button pressed
            if(counter == 5) password_attempt[counter]= '\0';  //used to end string
               
            if(counter>4 )                  //starts only when input as enough characters
                {
                    counter=0;              //resets counter for successive attempts to continue
                    //printf("\n\rInput characters: %u %u %u %u %u ",password_attempt[0],password_attempt[1],
                                    //password_attempt[2],password_attempt[3],password_attempt[4],password_attempt[5]);
                    //printf("\n\ralarm set %u %u %u %u %u",alarmset[0],alarmset[1],alarmset[2],alarmset[3],alarmset[4]);   
                    //printf("\n\ralarm off %u %u %u %u %u",alarmoff[0],alarmoff[1],alarmoff[2],alarmoff[3],alarmoff[4]);
                    
                    compare=strncmp(password_attempt,alarmset,5);       //compres string 
                                                                        //with predefined
                                                                        //password alarmset
                    //printf("\n\rcompare= %u",compare);
                    
                    if(compare == 0)                 //starts when input matches password attempt 
                                                     //alarmset only
                    {
                        alarm_status=1;              //changes the alarm status to turn on alarm
                        printf("\n\ralarm on %u",alarm_status);
                        PR2=100;                    //used to create buzz sound of around 600 Hz 
                        PWM5_LoadDutyValue(202);    //to make the PWM5 at 50% for the correct frequency
                        DELAY_milliseconds(500);    //runs sound for 500 milliseconds                     
                        PWM5_LoadDutyValue(0);      //then turns off sound, resulting in single beep
                    }
                    
                   
                    compare2=strncmp(password_attempt,alarmoff,5);       //compres string 
                                                                        //with predefined
                                                                        //password alarmoff
                    //printf("\n\rcompare2= %u",compare2);
                    //printf("\n\rpassword %s  %u ",password,strlen(password_attempt));
                    
                    if(compare2 == 0)                       //starts only if input matches with predefined
                                                            //alarm off password
                        {
                            alarm_status=0;                 //changes, alarm status to off
                            printf("\n\ralarm off %u",alarm_status);
                            //below is similar to the code above to create buzz beep but two beeps this time
                            PR2=100;
                            PWM5_LoadDutyValue(202);
                            DELAY_milliseconds(180);                            
                            PWM5_LoadDutyValue(0);
                            DELAY_milliseconds(180);
                            PWM5_LoadDutyValue(202);
                            DELAY_milliseconds(180);
                            PWM5_LoadDutyValue(0);
                            
                        }
                    if(compare != 0 && compare2 != 0)       //only if the input password attempt does not 
                                                            //match with either predefined passwords
                    {
                        printf("\n\rwrong password");
                        //below is a longer buzz sound of 2 seconds to notify user of
                        //wrong password
                        PR2=100;
                        PWM5_LoadDutyValue(202);
                        DELAY_milliseconds(2000);
                        PWM5_LoadDutyValue(0);
                    }
                    }
                    
        }
                    
                    if(i == 35 || i == 42)                  //if user inputs "*" or "#"
                                                            //the string coounter goes to zero
                    {
                        counter=0;
                    }
        
        //Switch acts as if statement with multiple conditions 
        //Used for alarm status conditions
        switch(alarm_status)
        {
            case 0: PWM5_LoadDutyValue(0);      //alarm is off and Red LED on
                    
                    red_RD2_SetHigh();
                    green_RD1_SetLow();
                    
                    break;
            case 1: green_RD1_SetHigh();        //Alarm is on and Green LED on
                    red_RD2_SetLow();
                    
                    break;
            case 2:                             //Alarm triggered and LED flashes Red
                    green_RD1_SetLow();
                    red_RD2_SetHigh();
                    DELAY_milliseconds(225);
                    red_RD2_SetLow();
                    green_RD1_SetLow();
                    DELAY_milliseconds(175);
                    break;
        }
        
    }
    }

//function for photo gate trigger response same as button 
void buttonResponse(void)
{
        has_switch_changed = poll_switch1_for_gate(gate_RA7_GetValue());
        if ( has_switch_changed == 2 && alarm_status == 1)
            //detects falling edge first and then rising edge
        {
            alarm_status=2;             //changes alarm status to triggered ie. flash Red
            PR2=100;  //buzz frequency continously until alarm deactivated or reset
            PWM5_LoadDutyValue(202);
            
            k=scan_keypad();
        }
}


//scans keypad for button presses
//be sure to wire accordingly as mentioned at beginning of file
//Need different has_switchN_changed for each button on keypad, added in Buttons.c file
//where N is an int used to differ the statements
//view Buttons.c for more details
int scan_keypad()
{
    j=0;  
    i=0;
    //Cycles through powering each column with a very small delay in between
    // each of has_switch_changed statements wait for change in voltage at the row pins
    //Outputs i as a character to allow string comparison for passwords
    //printf statements can be changed to increase privacy, 
    //did not alter printf for the developer to use
        col_RC1_SetHigh();
        col_RC2_SetLow();
        col_RC3_SetLow();
       
        has_switch1_changed = poll_switch1_for_edges(row1_RC4_GetValue());
        //printf("\n\rcol 1 powered\n\r");
        if ( has_switch1_changed == 1 )
        {
            printf("\n\rbutton 1");
            i='1';
            j=1;
            //printf("i = %u",i);
        }
        
        has_switch2_changed = poll_switch2_for_edges(row2_RC5_GetValue());
        
        if(has_switch2_changed == 1)
        {
            printf("\n\rbutton 4");
            i='4';
            j=1;
        }
        
        has_switch3_changed = poll_switch3_for_edges(row3_RC6_GetValue());
        
        if(has_switch3_changed==1)
        {
            printf("\n\rbutton 7");
            i='7';
            j=1;
        }

        has_switch4_changed = poll_switch4_for_edges(row4_RC7_GetValue());
        
        if(has_switch4_changed==1)
        {
            printf("\n\rbutton *");
            i='*';
            j=1;
        }

        
        DELAY_milliseconds(1);
        
        col_RC2_SetHigh();
        col_RC1_SetLow();
        col_RC3_SetLow();
        //printf("\n\rcol 2 powered\n\r");
        
        has_switch1_changed = poll_switch5_for_edges(row1_RC4_GetValue());
        //printf("\n\rcol 1 powered\n\r");
        if ( has_switch1_changed == 1 )
        {
            printf("\n\rbutton 2");
            i='2';
            j=1;
            //printf("i = %u",i);
        }
        
        has_switch2_changed = poll_switch6_for_edges(row2_RC5_GetValue());
        
        if(has_switch2_changed == 1)
        {
            printf("\n\rbutton 5");
            i='5';
            j=1;
        }
        
        has_switch3_changed = poll_switch7_for_edges(row3_RC6_GetValue());
        
        if(has_switch3_changed==1)
        {
            printf("\n\rbutton 8");
            i='8';
            j=1;
        }

        has_switch4_changed = poll_switch8_for_edges(row4_RC7_GetValue());
        
        if(has_switch4_changed==1)
        {
            printf("\n\rbutton 0");
            i='0';
            j=1;
        }

        
        DELAY_milliseconds(1);
        
        col_RC2_SetLow();
        col_RC1_SetLow();
        col_RC3_SetHigh();
        //printf("\n\rcol 3 powered");
        
        has_switch1_changed = poll_switch9_for_edges(row1_RC4_GetValue());
        //printf("\n\rcol 1 powered\n\r");
        if ( has_switch1_changed == 1 )
        {
            printf("\n\rbutton 3");
            i='3';
            j=1;
            //printf("i = %u",i);
        }
        
        has_switch2_changed = poll_switch10_for_edges(row2_RC5_GetValue());
        
        if(has_switch2_changed == 1)
        {
            printf("\n\rbutton 6");
            i='6';
            j=1;
        }
        
        has_switch3_changed = poll_switch11_for_edges(row3_RC6_GetValue());
        
        if(has_switch3_changed==1)
        {
            printf("\n\rbutton 9");
            i='9';
            j=1;
        }

        has_switch4_changed = poll_switch12_for_edges(row4_RC7_GetValue());
        
        if(has_switch4_changed==1)
        {
            printf("\n\rbutton #");
            i='#';
            j=1;
            
        }
        
        return i,j;
}


//Can use non-blocking delays but would need to do calculations for time period
void beeps(void)
{
    PR2=100;
    PWM5_LoadDutyValue(202);
    TMR0IF = 0;       // clear flag
    TMR0_WriteTimer(g);
    while(!TMR0IF)
    {
        buttonResponse();
    }
                            
    PWM5_LoadDutyValue(0);
    TMR0IF = 0;       // clear flag
    TMR0_WriteTimer(g);
    while(!TMR0IF)
    {
        buttonResponse();
    }
                            
    PWM5_LoadDutyValue(202);
    TMR0IF = 0;       // clear flag
    TMR0_WriteTimer(g);
    while(!TMR0IF)
    {
        buttonResponse();
    }
                            
    PWM5_LoadDutyValue(0);                            
}
/**
 End of File
*/