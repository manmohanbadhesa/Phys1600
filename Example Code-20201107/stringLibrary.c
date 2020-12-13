// stringLibrary.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 = 9600

#include "mcc_generated_files/mcc.h"
#include <stdio.h> // library that has printf()
#include <string.h>
#include <stdlib.h>
#include "putty.h"
#include "myUART.h"       // Our library to make UART simpler


int main(void)
{
  // Initialize the device
  SYSTEM_Initialize();
 
  unsigned int i;
  size_t length;  // could use unsigned int
  
  char str1[20] = "Physics "; // leaves extra room for additional character
  char str2[] = "1600";   // will assign correct amount of space
  char str4[50] = ""; // blank string
  char str5[] = "Kwantlen Polytechnic";
  
  char *substring;  // this is a pointer to characters already in memory
                    // acts like a string for most purposes but isn't pointing at
                    // anything yet
  
  clearPuTTY();
  printf("\n\r Press Enter to Start Program>");
  wait_for_ENTER();
  
  length = strlen(str1);
  printf("\n\n\r str1 = {%s} length = %u \n\r", str1,length);

  printf(" str2 = {%s} length = %u \n\r", str2,(unsigned int)strlen(str2));
  
  printf(" str4 = {%s} length = %u \n\r", str4,strlen(str4));

  printf(" str5 = {%s} length = %u \n\r", str5,strlen(str5));
  
  printf("\n\r Press Enter to continue>");
  wait_for_ENTER();

  printf(" Adding a second string to first string - make sure first string has enough space! \n\r");
  strcat(str1,str2); // just use names of strings no [number]
  printf(" str1 = {%s} length = %u \n\r", str1,strlen(str1));

  printf("\n\r Press Enter to Continue>");
  wait_for_ENTER();

  printf(" Overwriting first string with second string - make sure first string has enough space! \n\r");
  strcpy(str4,str1);
  printf(" str4, formerly blank , is now {%s} length = %u  \n\r", str4, strlen(str4));
  
  printf("\n\r Press Enter to Continue>");
  wait_for_ENTER();

  printf(" Shortening a sting by inserting a NULL. \n\r");  
  str1[4]='\0';     // overwriting 'i' with a NULL shortens string
  printf(" str1 is now {%s} length = %u \n\n\r", str1,strlen(str1));

  printf("\n\r Press Enter to Continue>");
  wait_for_ENTER();
  
  printf(" But characters are still in memory \n\r");
  printf("\n\r -------------\n\r");
  for(i=5; i<12; i++){
     printf(" %c \n\r", str1[i]);
  }
  printf(" -------------\n\r");
  
  printf("\n\r Press Enter to Continue>");
  wait_for_ENTER();
 
  printf(" Find first stretch of str5 that starts with an n \n\r");
  substring = strchr(str5,'n');  // find first stretch of string that starts with an n
  printf(" Piece of {%s} after first n is {%s} . It has length %u. \n\r", str5, substring, strlen(substring));
 
  printf("\n\r Press Enter to Continue>");
  wait_for_ENTER();
  printf(" Same as above but with string not pointer \n\r");
  strcpy(str2, strchr(str5,'n'));  // find first stretch of string that starts with an n
  printf(" Piece of {%s} after first n is {%s} . It has length %u. \n\r", str5, str2, strlen(str2));
  
  printf("\n\r Press Enter to Continue>");
  wait_for_ENTER();
  
  printf(" Find last stretch of str5 that starts with an n \n\r");
  substring = strrchr(str5,'n'); // find last stretch of string that starts with an n
  printf(" Piece of {%s} after last n is {%s}. It has length %u. \n\r", str5, substring, strlen(substring));
  
  printf("\n\r Press Enter to Continue>");
  wait_for_ENTER();
  
  printf(" Once a pointer has an address (target), you can change it and anything that contains the pointer \n\r");  
  strcpy(substring,"AB");
  printf(" Substring is now {%s} and has first character {%c}. str5 is now {%s}. \n\r", substring, substring[0], str5);
 

 while(1); // wait forever
} // end program

