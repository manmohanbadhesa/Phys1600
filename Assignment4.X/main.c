#include "Library4.h"
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    float originala, originalb, originalc, originald, originale, originalf, originalg;
    float x=2.25,y=3.72,A=4.27,beta=35.0,D=6.85,alpha=33.0,R1=2.15,g=9.81,theta=43.0,a=0.5,k=20,k2=100,a2=0,b=2,n=200;
    originala= z(x,y);
    originalb= R(A,beta);
    originalc= X(D,alpha);
    originald= v(R1,g,theta);
    originale= e(a,k);
    originalf= f(k2);
    originalg= integral(a2,b,n);
    printf("\n\r\n\r original answers in order are as follows: \n\r %f  %f  %f  %f %f  %f  %f",originala, originalb, originalc, originald, originale, originalf, originalg);
    
    
    float newa,newb,newc,newd,newe,newf,newg;
    float x1=4.13,y1=2.72, A1=17.25,beta1=15.0,D1=1.26,alpha1=19.0,R2=15.13,theta1=21.0,a1=0.75,k3=25,k4=50,a3=1,b1=3.2,n2=140;
    newa=z(x1,y1);
    newb=R(A1,beta1);
    newc=X(D1,alpha1);
    newd=v(R2,g,theta1);
    newe=e(a1,k3);
    newf=f(k4);
    newg=integral(a3,b1,n2);
    printf("\n\r The new values calculated are as follows: \n\r %f  %f  %f  %f  %f  %f  %f",newa,newb,newc,newd,newe,newf,newg);


    while (1)
    {
        // Add your application code
    }
}
/**
 End of File
*/