#include "myUART.h"
#include "uart2.h"

// Check for ENTER/CR key press
void wait_for_ENTER(void)
{
 unsigned int i;
 while (UART2_DataReady == true)
 ;  // wait until there is a byte to read
 while( UART2_Read() != 13 )  for(i=0; i<10000ul; i++);
 // ASCII code 13 is the Carriage Return (ENTER) key  
}

// reads N characters + CR from keyboard and put results into a string
//          
// Make sure your string can hold N + 1 characters, need room for NULL
//
// ===========================example====================
// char yourString[21];  // room for 20 characters + NULL
// printf("\n\r>");      // > to ask for user input
// ReadNUART1(5,yourString);
// ======================================================
//
// ahould get at most 5 characters + CR from keyboard and put in yourString
//

void ReadNUART2(char holds_string[], unsigned int length_N)
{
    unsigned int i = 0, last; 
    unsigned int letter;
	
	do {
	                
	    while(UART2_DataReady == true)
        ;   // polls receive buffer for available data
	    letter = UART2_Read();     // read 1 character from buffer
	    
            if( 127 == letter )
              {
                // bksp - delete last key entry
                i--;
                if (i==65535)
                {
                     i = 0;
                }
              }
            else
              {          
	       holds_string[i] = letter; //add character to string one character at a time
	       i++;
               }
	         
	    } while ( (letter != 13) && (i <= length_N) );  //stop at CR or N characters

     holds_string[i-1] = '\0'; // replace last character, usually CR, with NULL		 

}

    // strcat(str1,str2);  // just use banes if strings no [number] 
                  // takes str2 first char to null of str1
    
    //strcpy(str4,str1);  // overright str4 with str1
    
    //str1[4]='\0'; //shortens str1 to the fourth character by adding null there
    
    // strchr(str5,'n'); // finds first stretch of string that starts with n
    // strrchr();  //same as strchr except searches from end of string

    // atoi function returns integer representation of string 
    // skips all white space at beginning of string
    // and stops when encounters first character that isnt a number

    // strtok();  // use to catch spaces or commas or other characters to seperate words