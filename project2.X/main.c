#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "putty.h"
#include "myUART.h"
#include <ctype.h>
#include "buttons.h"

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    clearPuTTY();
    int number1,number,guess,counter=0,ascii[5], k=5;
    unsigned int timer;
    char *token;
    char input[10], integer[5],comparison[5];
    
    TMR0_StartTimer();
    printf("Press Enter to Start Game:\n\r"); 
    wait_for_ENTER();//starts a clock to use for different set of random numbers
    srand(TMR0_ReadTimer());   // seed for random number generator
        

    printf("I have a number between 1 and 100. Can you guess that number?\n\r");
    

    while (1)
    {
        number1=rand();   // 0 to 32765   16 bit
        
        printf("\n\r random number is %u\n\r",number1);
        number = number1 %100+1;
        printf("\n\r random number between 1-100 %u\n\r:",number);
        counter=0;
        k=5;
        do
        {
        counter +=1;
        ReadNUART2(input,20);
        token=strtok(input," ");
        if(token != NULL) strcpy(comparison,token);
        token=strtok(NULL,"\0");
        if(token != NULL) strcpy(integer,token);
        //printf("\n\rcomparison is %s\n\r",comparison);
        //printf("\n\rinteger is %s\n\r",integer);
        
        guess=atoi(integer);
        //printf("\n\rguess is %u\n\r",guess);
        
        if(guess == number && comparison[0]== '=')
        {
            printf("\n\rCongrats you won! The number was %u",number);
            printf("\n\rIt took you %u tries to guess the number, Great Job!",counter);
            k=7;
            break;
        }
        else
            {
                if(comparison[0]== '>' && number>guess)
                {
                    printf("\n\ryes\n\r");
                }
                else
                {
                    if(comparison[0]== '<' && number<guess)
                    {
                        printf("\n\rYes\n\r:");
                    }
                    else
                    {
                    printf("\n\rNo, try again");
                    printf("\n\r:");
                    }
                }
                //printf("\n\r No, Try again\n\r:");
            }

        }
        while(k != 7);
                   
    }
}











/*
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
 
    int number1,number,guess,counter=0;
    char token;
    char input[10], integer[5],comparison[5];
    
    TMR0_StartTimer(); //starts a clock to use for different set of random numbers
    clearPuTTY();
    printf("Press Enter to Start Game:\n\r");    
    wait_for_ENTER();
    printf("I have a number between 1 and 100. Can you guess that number?\n\r");
    
    srand(1011);   // seed for random number generator
    
    while (1)
    {
        // Add your application code
        
        number1=rand();   // 0 to 32765   16 bit
        
        printf("\n\r random number is %u\n\r",number1);
        number = number1 %100+1;
        printf("\n\r random number between 1-100 %u\n\r:",number);
        
        do
        {
        counter +=1;
        ReadNUART2(input,20);
        
        token=strtok(input," ");
        if(token != NULL) strcpy(comparison,token);
        token=strtok(NULL,"\0");
        if(token != NULL) strcpy(integer,token);
        
        printf("comparison is %s\n\r",comparison);
        printf("integer is %s\n\r",integer);
        guess=atoi(integer);
        printf("\n\rguess is %u",guess);
        
        if(token != NULL)
        {
            //guess=atoi(integer);
            //printf("\n\rguess is %u",guess);
            
            if(guess == number)
            {
                printf("\n\rCongrats you won! The number was %u",number);
                break;
            }
            else
            {
                if(comparison == ">" && number>guess)
                {
                    printf("yes");
                }
                else
                {
                    if(comparison== "<" && number<guess)
                    {
                        printf("Yes");
                    }
                    printf("\n\rNo");
                    printf("\n\r>");
                }
            }

        }
        if(counter ==5)
        {
            printf("Guesses are up, you lose :( The number was %u",number);
            break;
        }
        }
        while(guess != number);
    }
}

 End of File




            do
            {                
            if(guess>number)
            {
                printf("yes");
            }
            else
            {
                printf("No, Try again");
            }
            }
            while(guess != number);
 */ 
 