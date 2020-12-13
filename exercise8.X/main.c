#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "myUART.h"
#include "putty.h"
#include <ctype.h>

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

void switch_Caps(char string[], char shiftnumber);
void strInvertCaps(char string_in[], char string_out[]);
void Caps(char string_in[], char string_out[]);
void Reverse_String(char string_in[], char string_out[]);


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    int i, intnumber;
    clearPuTTY();
    char string[]="hello", string2[20]="", inputstring[51],outputstring[51],reversefirst[51],reverselast[51];
    char FirstName[20], LastName[20], capfirst[51],caplast[51];
    char *token;
    /*
    printf("\n\r the original string is {%s} ",string);
    switch_Caps(string,-32);
    printf("and capitalized is {%s}",string);
    
    strInvertCaps(string,string2);
    printf("string 1 of {%s} is inverted caps to {%s}",string,string2);
    */
    

    
    while (1)
    {
        // Add your application code
        //clearPuTTY();
        printf("\n\r\n\rEnter Your Name:\n\r>");
        ReadNUART2(inputstring,20);
        //intnumber=atoi(inputstring);
                 
        token=strtok(inputstring," ");
        if(token != NULL) strcpy(FirstName,token);
        token=strtok(NULL,"\0");
        if(token != NULL) strcpy(LastName,token);
        
        printf("\n\rFirst Name: %s\n\rLast Name: %s",FirstName,LastName);
        Caps(FirstName,capfirst);
        Caps(LastName,caplast);
        printf("\n\rFirst Name: %s\n\rLast Name: %s",capfirst,caplast);
        Reverse_String(capfirst,reversefirst);
        Reverse_String(caplast,reverselast);
        printf("\n\rReversed: %s %s",reversefirst,reverselast);
               
        wait_for_ENTER();
                     
    }
}
/**
 End of File
*/
void Reverse_String(char string_in[], char string_out[])
{
    int i, length= strlen(string_in);
     for(i=0;i<length;i++)
    {
         string_out[i]=string_in[length-1-i];
    }
    string_out[length]= '\0'; // turn array into string
    return;
    
}


void Caps(char string_in[], char string_out[])
{
    int i, length=strlen(string_in);
    for(i=0;i<length;i++)
    {
        if(islower(string_in[i]))
        {
            string_out[i]=toupper(string_in[i]);
        }
        else
        {
            string_out[i]=string_in[i];
        }
    }
    string_out[length]= '\0'; // turn array into string
    return;
}

void switch_Caps(char string[], char shiftnumber)
{
    int i;
    int length=strlen(string);
    for(i=0;i<length;i++)
    {
        string[i] += shiftnumber;
    }
    return;
}

void strInvertCaps(char string_in[], char string_out[])
{
    int i, length=strlen(string_in);
    for(i=0;i<length;i++)
    {
        if(isupper(string_in[i]))
        {
            string_out[i]=tolower(string_in[i]);
        }
        else
        {
            string_out[i]=toupper(string_in[i]);
        }
    }
    string_out[length]= '\0'; // turn array into string
    return;
    
}