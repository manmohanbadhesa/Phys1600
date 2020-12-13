// random.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 @9600 and any TIMR0 setting

#include "mcc_generated_files/mcc.h"
#include <stdio.h>    // C Library for printf()
#include <ctype.h>    // C Library for strcpy()
#include <stdlib.h>   // C Library for rand() and srand())
#include "putty.h"    
#include "myUART.h"    

int main (void)
{
  // Initialize the device
  SYSTEM_Initialize();	
  int number;
 
  //starts a clock
  TMR0_StartTimer();
  
  clearPuTTY(); // Clear PuTTY Window
  printf("\n\rRandom Number Test\n\n\r"); //welcome message

  printf("Press Enter to start> ");    
  wait_for_ENTER(); // waits for you to hit ENTER */

  //since it waits for you to hit ENTER, and it is very unlikely that you will 
  //hit ENTER at the same microsecond each time, TMR0_ReadTimer() will be 
  //different from run to run. So using this as a seed randomizes the rand() 
  //function 
  //
  //Comment out the next line and see that you always get the same sequence of 
  //"random" numbers 
  srand(TMR0_ReadTimer());  // we won't know exactly what value seeds srand()       
  
  
  //srand(3679); //seed for random number generator
  
while(1)
   {
       number = rand();  //0 and 32765 - 16 bit
       printf("Your random number is %u     \n\r",number);       
       printf("Normalized to 0 to 9: number is %u\n\n\r",number % 10); 
       
       printf("Press Enter to continue> ");    
       wait_for_ENTER(); // waits for you to hit ENTER*/
   }
 return 0;
}  // end program
