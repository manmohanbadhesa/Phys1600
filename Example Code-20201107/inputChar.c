// inputChar.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 = 9600

#include "mcc_generated_files/mcc.h"
#include <stdio.h> // library that has printf()
#include <ctype.h>    
#include "myUART.h"       // Our library to make UART simpler
#include "putty.h"    

int main (void){
  // Initialize the device
  SYSTEM_Initialize();
  unsigned char i = 0, j = 0, letter;

  clearPuTTY(); // clears PuTTY screen 
  
  // How to get a keystroke from the keybofard
  printf(" Press a key\n\r >");
  while(!UART2_DataReady); // will wait forever for keystroke
  letter = UART2_Read();    // read a single character
  printf(" You typed {%c}, ascii #%u \n\r",letter, letter);
  
  printf("\n\r Press CR to continue\n\r >");
  wait_for_ENTER();
 
  // how to read keystrokes one at a time forever
  printf("\n\n\r Continuous single character input from the keyboard\n\n\r");
  printf(" Enter a single character to learns its ASCII code.\n\n\r"); 
  printf(" Waiting for input >  ");

  while(1){
  
      if(UART2_DataReady)     // polls receive buffer for available data
	  {
		i = UART2_Read();          // read a single character from buffer
        printf("\b\b   ");   // back up twice and overwrite with blanks
        if ( i < 32 )
            printf("\n\n\r ASCII code = %i : Non printing character\n\r",i); 
        else
            printf("\n\n\r ASCII code = %i : Symbol is {%c}\n\r",i,i); 

        if ( isupper(i) ) printf(" That was an uppercase letter.\n\r");
        if ( islower(i) ) printf(" That was a lowercase letter.\n\r");
        if ( isdigit(i) ) printf(" That was a digit.\n\r");
        if ( iscntrl(i) ) printf(" That was a control character.\n\r");
        if ( ispunct(i) ) printf(" That was a punctuation character.\n\r");
        if ( isspace(i) ) printf(" That was a space or blank character.\n\r");
        printf("\n\r Waiting for input >  ");
      } 

     printf("\b|");
     DELAY_milliseconds(80);
     printf("\b/"); // \b is backspace
     DELAY_milliseconds(80);
     printf("\b-"); 
     DELAY_milliseconds(80);
     printf("\b");
     printf("\\");  // how to get a backslash
     DELAY_milliseconds(80);
  }
 
} // end program