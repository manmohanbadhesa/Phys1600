#include "myLibrary.h"
#include <stdio.h>

// new function
void P1600Message(void)
{
 printf("====================================================\n\r");
 printf("=                 Physics 1600                     =\n\r");
 printf("====================================================\n\r");
 return;
} 

unsigned int SumSeries(unsigned int start,unsigned int end,unsigned int increment)
{
 unsigned int i; 
 unsigned int sum = 0;
 for ( i=start; i <= end; i += increment ) 
 {
    sum = sum + i;  // could write sum += i; 
 }
 return sum;  
}
