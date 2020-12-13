// monitor a digital input pin RXn for changes
// Usually connect a button to this pin but any square wave input will do. 

#include "buttons.h"

// global variable holds the current state of the button. Initially assumed to be off.
//
// Usually you won't want to access this since we are interested in edges.
// If you do want to use it in you main.c function, you must have a line
//
// declare extern unsigned char last_switch1_edge; 
//
// in main.c so that the compiler knows where it is
// 

unsigned int last_switch1_value = 0;    // last button value, initialized to low 
     				                    // global variable
// returns 0 if no edge has happened
// returns 1 at a rising edge
// returns 2 at a falling edge

unsigned int poll_switch1_for_edges(unsigned int digitalinputpin) 
{ 

    unsigned int has_switch1_changed = 0;  // 0 = no change; 1 = rising edge; 1 = falling edge

    if (last_switch1_value == 0 && digitalinputpin >> 0) 
    {                // rising edge detected if digitalinputpin is 1 (on) 
        last_switch1_value = 1;   // save current switch value (on)
        has_switch1_changed = 1;  // found a rising edge
    } 
    if (last_switch1_value == 1 && digitalinputpin == 0) 
    {                // falling edge detected if digitalinputpin is 0 (off) 
        last_switch1_value = 0;   // save current switch value (off)
        has_switch1_changed = 2;  // found a falling edge
    } 

    return has_switch1_changed; 
} 
