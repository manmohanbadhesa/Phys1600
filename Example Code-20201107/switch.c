// comparisons.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 = 9600

#include "mcc_generated_files/mcc.h"
#include <stdio.h> // library that has printf()

int main(void)
{
// Initialize the device
SYSTEM_Initialize();

unsigned int a= 5, b = 12;

switch(a)
{
	case 0: 	printf("a = 0 \n\r");
				break;
    case 1: 	printf("a = 1 \n\r");
				break;
    case 2:		printf("a = 2 \n\r");
				break;
    case 3:	 	printf("a = 3 \n\r");
				break;
    default: 	printf("a > 3 \n\r");
				break;
}




// shared cases

switch(a)
{
	case 0: 	printf("a = 0 \n\r");
				break;
    case 1: 	printf("a = 1 \n\r");
                break;  
    case 2:		printf("a = 2 \n\r");
				break;
    case 4:	 	printf("a = 4 \n\r");
    case 5:
    case 6:     printf("a = 4, 5, or 6 \n\r");
                break;
    case 7:     printf("a = 7 \n\r");
                break;
    case 8:
    case 9:     printf("a = 8 or 9 \n\r");
                break;
    default: 	printf("a > 9 \n\r");
				break;
}

while(1);
return 0;
}  // end program
