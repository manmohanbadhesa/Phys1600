// stringbasics.c
#include "mcc_generated_files/mcc.h"
#include <stdio.h> // library that has printf()
#include <string.h>
#include <stdlib.h>
#include "putty.h"
#include "myUART.h"       // Our library to make UART simpler
                          // make sure compiler searches in mcc.h!

int main(void)
{
// Initialize the device
SYSTEM_Initialize();

int i;

//There are two ways to initalize a string
char string1[6] = {'1', '2', '3', '4', '5', '\0'};  //5 char + null = 6
char string2[] = "12345"; // size include null!! Compiler will count
//Strings can have extra room or be totally empty
char bigstring[50] = "Hello World!";  // you can leave room for growth
char blankstring[50]; // nothing yet

// strings and arrays are very similar
char array[5] = {'1', '2', '3', '4', '5'};  //5 char, no terminator

clearPuTTY();
printf("\n\rPress Enter to Start Program>");
wait_for_ENTER();

//Strings can be printed several ways 
printf("\n\n\rstring1 = %s or ",string1); // can use %s format specifier
printf("\n\r"); // newline

printf(string1);
printf("\n\r"); // newline

for (i=0; i<5;i++) printf("%c",string1[i]);
printf("\n\r"); // newline

printf("\n\rPress Enter to Continue>");
wait_for_ENTER();

//can't work on strings directly except using a for-loop
printf("\n\n\rUse for loops to change individual characters of a string"); 
for(i=0; i<5; i++)
    {	
     string2[i]=string2[i] + 3; //characters are just numbers in ascii table
    }
printf("\n\n\rYour new number is %s", string2);

while(1);
}