#include "exercise5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float Range(float initialVelocity, float angle)
{
    float Range;
    Range= 2*initialVelocity*sinf(angle*pi/180.0)*cosf(angle*pi/180.0)/g;
    
    return Range;
}

float MaxHeight(float initialVelocity, float angle)
{
        float MaxHeight;
 
        MaxHeight= powf(initialVelocity*sinf(angle*pi/180.0),2)/2.0/g;
 
        return MaxHeight;        
}

float TimeinAir(float initialVelocity, float angle)
{
    float TimeinAir;
    
    TimeinAir= 2*initialVelocity*sinf(angle*pi/180.0)/g;
    
    return TimeinAir;
}
