#include "array_functions.h"
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    float A[] = {1.0, 2.2, 3.3, 4.4}, B[] = {0.5, -0.37, 6.25, -3.33}, NewArray[4];
    
    int i;
    

    printf("\n\rnorm = %f",norm(A,4));
    printf("\n\rdot product of A and B is %f",dot_product(A,B,4));
    
    sign_change(A,4);
    for(i=0;i<4;i++)
    {
        printf("\n\r sign flipped of A is %f",A[i]);
    }
    
    
    printf("\n\rNew Negative array of A is: ");
    negative_array(A,NewArray,4);
    for(i=0;i<4;i++)
    {
        printf(" %f",NewArray[i]);
    }
   
    printf("\n\rReverse array of A is: ");
    reverse_array(A,NewArray,4);
    for(i=0;i<4;i++)
    {
        printf(" %f",NewArray[i]);
    }
    while (1);
    

}
/**
 End of File
*/