
#include "exercise5.h"   //where protoypes are
#include "geometric_shapes.h"
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main()

{
    // Initialize the device
    SYSTEM_Initialize();
    
     /*
     float distance, MHeight, Time, initialVelocity = 10.0, angle = 30.0;
     distance = Range(initialVelocity,angle);
     MHeight = MaxHeight(initialVelocity,angle);
     Time = TimeinAir(initialVelocity,angle);
     printf("\n\r\n\r Range = %10.3f, MAx Height = %10.3f, Time in air =  %10.3f \n\r", distance, MHeight, Time);          
     */
    
     float sphere_radius=3.5, cylinder_radius=5, height =10, a=3, b=4, c=6;
     float vsphere, vcylinder, vellipsoid;
     
     vsphere= volume_sphere(sphere_radius);
     vcylinder= volume_cylinder(cylinder_radius, height);
     vellipsoid= volume_ellipsoid(a, b, c);
     printf("\n\r\n\r volume of sphere is %f \n\r volume of cylinder is %f \n\r volume of ellipsoid is %f",vsphere, vcylinder, vellipsoid);
     //printf("\n\r pi is %f",pi);
     
    while (1);
      
}




/*
 End oF File
*/