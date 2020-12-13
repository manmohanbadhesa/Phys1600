#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "geometric_shapes.h"

float volume_sphere(float radius)
{
    float volumes;    
    volumes= 4*pi*pow(radius,3)/3;    
    return volumes;
}

float volume_cylinder(float radius, float height)
{
    float volumec;
    volumec=pi*height*pow(radius,2);
    return volumec;
}

float volume_ellipsoid(float a, float b, float c)
{
    float volumee;
    volumee= 4*pi*a*b*c/3;
    return volumee;
}
