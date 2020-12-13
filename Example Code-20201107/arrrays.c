// arrays.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 = 9600

#include "mcc_generated_files/mcc.h"
#include <stdio.h> // library that has printf()

int main(void)
{
 // Initialize the device
 SYSTEM_Initialize();
 
 int i,j;
 int a[5] = {10, 20, 30, 40, 50} ; // initialized 1D array
 int b[5];                         // uninitialized 1D array
 
 int c[2][4] = { {10, 11, 12, 13}, {20, 21, 22, 23 } };  // 2D 2 x 4 array
    

 for(i=0; i<5; i++) {
   b[i] = 3*a[i] + 2;  
   printf("a[%u] = %u b[%u] = %u \n\r", i, a[i], i ,b[i]);
   // arrays count from 0
 }
 
 for(i=0; i<2; i++) {
     
     for (j=0; j<4; j++) 
     {
         printf("c[%u][%u] = %u \t ", i, j, c[i][j]);
     }
     printf("\n\r");
 }

 
 while(1);
 return 0;
}
