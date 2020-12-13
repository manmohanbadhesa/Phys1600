#include "array_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float norm(float A[], int array_size)
{
    int i;
    float normvalue=0.0;
    for(i=0;i<array_size;i++)
    {
        normvalue += A[i]*A[i];
    }
    return sqrt(normvalue);
}

float dot_product(float A[], float B[], int array_size)
{
    float dot_product=0;
    int i;
    for(i=0;i<array_size;i++)
    {
        dot_product += A[i]*B[i];
    }
    return dot_product;
}

void sign_change(float A[], int array_size)
{
    int i;
    for(i=0;i<array_size;i++)
    {
        A[i]=-1*A[i];
    }
    return;
}

void negative_array(float A[],float B[], int array_size)
{
    int i;
    for(i=0;i<array_size;i++)
    {
        B[i]=-1*A[i];
    }
    return;
}

void reverse_array(float A[],float B[], int array_size)
{
    int i;
    for(i=0;i<array_size;i++)
    {
        B[i]= A[array_size-1-i];
    }
    return;
}