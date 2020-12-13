// stringinput.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 = 9600

#include "mcc_generated_files/mcc.h"
#include <stdio.h> // library that has printf()
#include <string.h>
#include <stdlib.h>
#include "putty.h"
#include "myUART.h"       // Our library to make UART simpler

int main(void) {
	// Initialize the device
	SYSTEM_Initialize();

    char inputstring[51]; // make sure this has enough room
    int intnumber,i, length;
    char day[5] = "?", year[5] = "?", weekday[20] = "?", month[20] = "?";
    long longnumber;
    float floatnumber;
    char *token;
    
    clearPuTTY();

    printf("\n\rPress Enter to Start Program>");
    wait_for_ENTER();
   
    printf("\n\rHow to acquire strings from PuTTY");
    printf("\n\n\rType stings of characters or digits, abc, 11, 1000000, 3.14159\n\r");
    printf("\n\n\rType your string>");  
   
    ReadNUART2(inputstring,20); //reads up to 19 characters or CR
    printf("\n\rYou typed { %s }",inputstring);
    length  = strlen(inputstring);
    printf("\n\rThe individual characters are:");
    for (i=0; i<length; i++){
         printf("\n\r i = %d char = %c ascii # = %u", i, inputstring[i],inputstring[i]);
        }
    
    //The atoi function returns the integer representation of a string. 
    //The atoi function skips all white-space characters at the beginning 
    //of the string, converts the subsequent characters as part of the 
    //number, and then stops when it encounters the first character that 
    //isn't a number. Returns 0 if there is no digits to return.
    intnumber=atoi(inputstring);
    if ( intnumber == 0)
        printf("\n\rThat didn't seem to be an integer string of digits");
    else
        printf("\n\rThe string is integer : %i",intnumber);
                
    longnumber=atol(inputstring);
    if ( longnumber == 0)
        printf("\n\rThat didn't seem to be an long string of digits");
    else
        printf("\n\rThe string is a long integer : %li",longnumber);
        
       
    floatnumber=atof(inputstring);
    if ( floatnumber == 0)
        printf("\n\rThat didn't seem to be an string of digits in decimal or e format");
    else
        printf("\n\rThe string is a decimal : %f or in scientific notation %e",floatnumber,floatnumber);
    
    printf("\n\n\rPress Enter to Continue>");
    wait_for_ENTER();
    
    printf("\n\n\rIf you enter structured or formatted data such as");
    printf("\n\r   'Friday, 19 June 2017'  ");
    printf("\n\rstrtok() can parse it for you looking for delimiters (spaces and comma or other symbols) \n\r");
    printf("\n\rEnter today's date>");  
    
    ReadNUART2(inputstring,50); //reads up to 49 characters or CR
    printf("\n\n\rYou typed { %s }\n\r",inputstring);
    
    /* get the first token */
   token = strtok(inputstring, " ,");  //delimiters are space and comma
   if (token != NULL) strcpy(weekday,token);
   
   token = strtok(NULL," ,"); // looks for spaces and commas
   if (token != NULL) strcpy(day,token);
   
   token = strtok(NULL," ,"); // looks for spaces and commas
   if (token != NULL) strcpy(month,token);
   
   token = strtok(NULL," ,"); // looks for spaces and commas
   if (token != NULL) strcpy(year,token);
   
   token = strtok(NULL," ,"); // looks for spaces and commas
   if (token != NULL)
       printf("Still a delimiter left in string \n\r");
   else
       printf("End of string reached \n\r");
   
   /* using strtok() with a while loop */
   /*
    char *token;
    token = strtok(inputstring, " ,");  //delimiters are space and comma 
    while( token != NULL ) {
      printf( " %s\n", token );
      token = strtok(NULL," ");
   }
   */

    printf("\n\rToday's date is %s %s %s which is a %s \n\r", year, month, day, weekday);
   
    while(1){
     }
    return 0;
}

