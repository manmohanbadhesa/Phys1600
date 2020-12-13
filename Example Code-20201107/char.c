// comparisons.c
// Generate MCC so that the FOSC = 32 MHZ and UART2 = 9600

#include "mcc_generated_files/mcc.h"
#include <stdio.h> // library that has printf()
#include "putty.h"

void main(void)
{
	// Initialize the device
	SYSTEM_Initialize();

	char a = 'A', b = 'b', c, d;  // 8 bit integers
								// can only hold 0 to 255
								// often used with ASCII table
							
	clearPuTTY();  // erases or resets the PuTTY display
	
	c = a - 11;
	d = b - a + 3;
	
    if (c == 6) {} //false c = 54 != 6
    
    if (c == '6') {} //true c = 54 != char 6
    
    switch(a){
        case 'A': 
            break;
        case 'a':
            break;
    }
    
	printf(" a = %u, b = %u, c = %u, d = %u \n\r", a, b, c, d);
	printf(" a = %c, b = %c, c = %c, d = %c \n\r", a, b, 7, 7);
	
	while(1)
	;
	return;
}