// comparisonsyntax.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 = 9600

#include "mcc_generated_files/mcc.h"
#include <stdio.h> // library that has printf()
#include <stdbool.h> // library defines true and false

int main(void)
{
// Initialize the device
SYSTEM_Initialize();

unsigned int a = 0, b = 12;
bool mike_is_great = true;

//in C, 'true' is represented by the number 1. 'false' is usually shown 
//as 0 but in fact is any number other than 1
//The C library stdbool.h defines the keywords true and false and bool

// comparison syntax
// a < 100
// a > 100
// a <= 50
// a >= b             Can compare variables
// a == 10            equivalent (people often just say equal) 
// a != 0             Negation (not equal)

// more complex combinations
// (a > 8) && (b%2 == 1)      && is AND
// (a > 8) || (b%2 == 0)      || is OR
// !(a > 8) && (b%2 == 1)     ! Negation

// if test
if (a < 100)
{
	// code here execute only if comparison is TRUE
    printf("a is less than 100 \n\r");
}   	

// if-else test
if (a > b)
{
	// code here execute if comparison is TRUE
    printf("a is greater than or equal to b \n\r");
}
else
{
	// code here execute if comparison is FALSE
    printf("a is not greater than or equal to b \n\r");
}   	

// nested if-else test
if (a < 100)
{
    if (a < 50)
	{
	// code here execute if comparison1 and comparison2 are TRUE
        printf(" a is less than 50 \n\r");
	}
	else
	{
	// code here execute if comparison1 is TRUE and comparison2 is FALSE
        printf(" a is greater than 49 but less than 100\n\r");
	}   	
}
else
{
    if (a > 200)
	{
	// code here execute if comparison1 is FALSE and comparison3 is TRUE
        printf(" a is greater than 200 \n\r");	}
	else
	{
	// code here execute if comparison1 is FALSE and comparison3 is FALSE
        printf(" a is greater than 99 but less than 200\n\r");
	}   	
}   	

while(1);
return 0;
}  // end program
