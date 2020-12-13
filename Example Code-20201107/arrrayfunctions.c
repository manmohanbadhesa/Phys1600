// arrayfunctions.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 = 9600

#include "mcc_generated_files/mcc.h"
#include <stdio.h> // library that has printf()
#include <math.h>

float norm(int array_in[], unsigned int array_size); // prototype
void scaleArray(int array_in[], unsigned int array_size, int scale);
void scaleArray2(int array_in[],int array_out[], unsigned int array_size, int scale);
void reverse(int array_in[],int array_out[], unsigned int array_size);

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

 printf("norm = %f \n\r", norm(a,5));

/* 
 scaleArray(a, 5, 3);
 for(i=0; i<5; i++) {
   printf("new a[%u] = %u \n\r", i, a[i]);

 }
 */
 scaleArray2(a,b, 5, 3);
 for(i=0; i<5; i++) {
   printf("a[%u] = %u b[%u] = %u \n\r", i, a[i], i ,b[i]);
   // arrays count from 0
 }
 
 reverse(a, b, 5);
 for(i=0; i<5; i++) {
   printf("a[%u] = %u b[%u] = %u \n\r", i, a[i], i ,b[i]);
   // arrays count from 0
 }
 while(1);
 return 0;
}


float norm(int array_in[], unsigned int array_size)
{
   int i;
   float normvalue = 0.0;
   for(i=0; i<array_size; i++) {
       normvalue += array_in[i]*array_in[i];
   }
   return sqrt(normvalue);
}

void scaleArray(int array_in[], unsigned int array_size, int scale)
{
   int i;
   for(i=0; i<array_size; i++) {
       array_in[i] = scale*array_in[i];
   }
   return;   
}

void scaleArray2(int array_in[],int array_out[], unsigned int array_size, int scale)
{
   int i;
   for(i=0; i<array_size; i++) {
       array_out[i] = scale*array_in[i];
   }
   return;   
}

void reverse(int array_in[],int array_out[], unsigned int array_size)
{
   int i;
   for(i=0; i<array_size; i++) {
       array_out[i] = array_in[array_size - 1 - i];
   }
   return;   
}