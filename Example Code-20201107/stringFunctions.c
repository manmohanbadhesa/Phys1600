// stringFunctions.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 = 9600

// Functions don't return strings (unlike int or float). However you can
// change your string in a function which is sometimes dangerous. Or you can
// use one string as an input and another as an output. In each case the
// strlen() function from <string.h> is helpful. Again you usually need
// to manipulate the strings using a for loop. Examples below. 

#include "mcc_generated_files/mcc.h"
#include <stdio.h> // library that has printf()
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "putty.h"
#include "myUART.h"       // Our library to make UART simpler

void strRotation(char string[], char shiftnumber);
void strInvertCaps(char string_in[], char string_out[]);

int main(void) {
	// Initialize the device
	SYSTEM_Initialize();

    char string1[20] = "Physics 1600"; 
    char string2[20] = ""; // empty string
    char string3[] = "Hello World!";

    clearPuTTY();

    printf("\n\n\rTest of strRotation() \n\r");
    printf("\n\rWe start with {%s}", string1);

    strRotation(string1,2);

    printf("\n\rWe have changed the string to {%s}", string1);
  
    strRotation(string1,-2);
    printf("\n\rReversing the function, we now have {%s} again \n\n\r", string1);
  
 
    wait_for_ENTER();
    
    printf("\n\n\rTest of strInvertCaps() \n\r");

    printf("\n\rWe start with two strings {%s} and {%s} (empty) \n\r", string3, string2);
    strInvertCaps(string3,string2);

    printf("{%s} \n\r",string2); 
    printf("{%s} \n\r",string3); 
 
    while(1);
    return 0;
}  // end program

// shifts the ascii value of each character by shiftnumber
void strRotation(char string[], char shiftnumber)
{
    int i;
    int length = strlen(string);
    for(i=0; i<length; i++)
      {
        string[i] += shiftnumber; 
      }
   return;
}

//converts lowercase letters to upper case and vice versa
void strInvertCaps(char string_in[], char string_out[])
{
    int i, length = strlen(string_in);
    for(i=0; i<length; i++){ 
	    if(isupper(string_in[i])) 
        {
            string_out[i] = tolower(string_in[i]); 
        }
        else
        {
            string_out[i] = toupper(string_in[i]); 
        }
    }
    string_out[length] = '\0'; // turn array into string
    return;
}
