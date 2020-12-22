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
unsigned int last_switch_value = 0;    // switch for gate input


unsigned int last_switch1_value = 0;    // last button value, initalized to low 
 unsigned int last_switch2_value = 0;        // global variable
unsigned int last_switch3_value = 0;
unsigned int last_switch4_value = 0;
unsigned int last_switch5_value = 0;
unsigned int last_switch6_value = 0;
unsigned int last_switch7_value = 0;
unsigned int last_switch8_value = 0;
unsigned int last_switch9_value = 0;
unsigned int last_switch10_value = 0;
unsigned int last_switch11_value = 0;
unsigned int last_switch12_value = 0;

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


unsigned int poll_switch2_for_edges(unsigned int digitalinputpin) 
{ 

    unsigned int has_switch2_changed = 0;  // 0 = no change; 1 = rising edge; 1 = falling edge

    if (last_switch2_value == 0 && digitalinputpin >> 0) 
    {                // rising edge detected if digitalinputpin is 1 (on) 
        last_switch2_value = 1;   // save current switch value (on)
        has_switch2_changed = 1;  // found a rising edge
    } 
    if (last_switch2_value == 1 && digitalinputpin == 0) 
    {                // falling edge detected if digitalinputpin is 0 (off) 
        last_switch2_value = 0;   // save current switch value (off)
        has_switch2_changed = 2;  // found a falling edge
    } 
        

    return has_switch2_changed; 
}

unsigned int poll_switch3_for_edges(unsigned int digitalinputpin) 
{ 

    unsigned int has_switch3_changed = 0;  // 0 = no change; 1 = rising edge; 1 = falling edge

    if (last_switch3_value == 0 && digitalinputpin >> 0) 
    {                // rising edge detected if digitalinputpin is 1 (on) 
        last_switch3_value = 1;   // save current switch value (on)
        has_switch3_changed = 1;  // found a rising edge
    } 
    if (last_switch3_value == 1 && digitalinputpin == 0) 
    {                // falling edge detected if digitalinputpin is 0 (off) 
        last_switch3_value = 0;   // save current switch value (off)
        has_switch3_changed = 2;  // found a falling edge
    } 
        

    return has_switch3_changed; 
}

unsigned int poll_switch4_for_edges(unsigned int digitalinputpin) 
{ 

    unsigned int has_switch4_changed = 0;  // 0 = no change; 1 = rising edge; 1 = falling edge

    if (last_switch4_value == 0 && digitalinputpin >> 0) 
    {                // rising edge detected if digitalinputpin is 1 (on) 
        last_switch4_value = 1;   // save current switch value (on)
        has_switch4_changed = 1;  // found a rising edge
    } 
    if (last_switch4_value == 1 && digitalinputpin == 0) 
    {                // falling edge detected if digitalinputpin is 0 (off) 
        last_switch4_value = 0;   // save current switch value (off)
        has_switch4_changed = 2;  // found a falling edge
    } 
        

    return has_switch4_changed; 
}
unsigned int poll_switch5_for_edges(unsigned int digitalinputpin) 
{ 

    unsigned int has_switch5_changed = 0;  // 0 = no change; 1 = rising edge; 1 = falling edge

    if (last_switch5_value == 0 && digitalinputpin >> 0) 
    {                // rising edge detected if digitalinputpin is 1 (on) 
        last_switch5_value = 1;   // save current switch value (on)
        has_switch5_changed = 1;  // found a rising edge
    } 
    if (last_switch5_value == 1 && digitalinputpin == 0) 
    {                // falling edge detected if digitalinputpin is 0 (off) 
        last_switch5_value = 0;   // save current switch value (off)
        has_switch5_changed = 2;  // found a falling edge
    } 
        

    return has_switch5_changed; 
}

unsigned int poll_switch6_for_edges(unsigned int digitalinputpin) 
{ 

    unsigned int has_switch6_changed = 0;  // 0 = no change; 1 = rising edge; 1 = falling edge

    if (last_switch6_value == 0 && digitalinputpin >> 0) 
    {                // rising edge detected if digitalinputpin is 1 (on) 
        last_switch6_value = 1;   // save current switch value (on)
        has_switch6_changed = 1;  // found a rising edge
    } 
    if (last_switch6_value == 1 && digitalinputpin == 0) 
    {                // falling edge detected if digitalinputpin is 0 (off) 
        last_switch6_value = 0;   // save current switch value (off)
        has_switch6_changed = 2;  // found a falling edge
    } 
        

    return has_switch6_changed; 
}

unsigned int poll_switch7_for_edges(unsigned int digitalinputpin) 
{ 

    unsigned int has_switch7_changed = 0;  // 0 = no change; 1 = rising edge; 1 = falling edge

    if (last_switch7_value == 0 && digitalinputpin >> 0) 
    {                // rising edge detected if digitalinputpin is 1 (on) 
        last_switch7_value = 1;   // save current switch value (on)
        has_switch7_changed = 1;  // found a rising edge
    } 
    if (last_switch7_value == 1 && digitalinputpin == 0) 
    {                // falling edge detected if digitalinputpin is 0 (off) 
        last_switch7_value = 0;   // save current switch value (off)
        has_switch7_changed = 2;  // found a falling edge
    } 
        

    return has_switch7_changed; 
}
unsigned int poll_switch8_for_edges(unsigned int digitalinputpin) 
{ 

    unsigned int has_switch8_changed = 0;  // 0 = no change; 1 = rising edge; 1 = falling edge

    if (last_switch8_value == 0 && digitalinputpin >> 0) 
    {                // rising edge detected if digitalinputpin is 1 (on) 
        last_switch8_value = 1;   // save current switch value (on)
        has_switch8_changed = 1;  // found a rising edge
    } 
    if (last_switch8_value == 1 && digitalinputpin == 0) 
    {                // falling edge detected if digitalinputpin is 0 (off) 
        last_switch8_value = 0;   // save current switch value (off)
        has_switch8_changed = 2;  // found a falling edge
    } 
        

    return has_switch8_changed; 
}

unsigned int poll_switch9_for_edges(unsigned int digitalinputpin) 
{ 

    unsigned int has_switch9_changed = 0;  // 0 = no change; 1 = rising edge; 1 = falling edge

    if (last_switch9_value == 0 && digitalinputpin >> 0) 
    {                // rising edge detected if digitalinputpin is 1 (on) 
        last_switch9_value = 1;   // save current switch value (on)
        has_switch9_changed = 1;  // found a rising edge
    } 
    if (last_switch9_value == 1 && digitalinputpin == 0) 
    {                // falling edge detected if digitalinputpin is 0 (off) 
        last_switch9_value = 0;   // save current switch value (off)
        has_switch9_changed = 2;  // found a falling edge
    } 
        

    return has_switch9_changed; 
}

unsigned int poll_switch10_for_edges(unsigned int digitalinputpin) 
{ 

    unsigned int has_switch10_changed = 0;  // 0 = no change; 1 = rising edge; 1 = falling edge

    if (last_switch10_value == 0 && digitalinputpin >> 0) 
    {                // rising edge detected if digitalinputpin is 1 (on) 
        last_switch10_value = 1;   // save current switch value (on)
        has_switch10_changed = 1;  // found a rising edge
    } 
    if (last_switch10_value == 1 && digitalinputpin == 0) 
    {                // falling edge detected if digitalinputpin is 0 (off) 
        last_switch10_value = 0;   // save current switch value (off)
        has_switch10_changed = 2;  // found a falling edge
    } 
        

    return has_switch10_changed; 
}

unsigned int poll_switch11_for_edges(unsigned int digitalinputpin) 
{ 

    unsigned int has_switch11_changed = 0;  // 0 = no change; 1 = rising edge; 1 = falling edge

    if (last_switch11_value == 0 && digitalinputpin >> 0) 
    {                // rising edge detected if digitalinputpin is 1 (on) 
        last_switch11_value = 1;   // save current switch value (on)
        has_switch11_changed = 1;  // found a rising edge
    } 
    if (last_switch11_value == 1 && digitalinputpin == 0) 
    {                // falling edge detected if digitalinputpin is 0 (off) 
        last_switch11_value = 0;   // save current switch value (off)
        has_switch11_changed = 2;  // found a falling edge
    } 
        

    return has_switch11_changed; 
}

unsigned int poll_switch12_for_edges(unsigned int digitalinputpin) 
{ 

    unsigned int has_switch12_changed = 0;  // 0 = no change; 1 = rising edge; 1 = falling edge

    if (last_switch12_value == 0 && digitalinputpin >> 0) 
    {                // rising edge detected if digitalinputpin is 1 (on) 
        last_switch12_value = 1;   // save current switch value (on)
        has_switch12_changed = 1;  // found a rising edge
    } 
    if (last_switch12_value == 1 && digitalinputpin == 0) 
    {                // falling edge detected if digitalinputpin is 0 (off) 
        last_switch12_value = 0;   // save current switch value (off)
        has_switch12_changed = 2;  // found a falling edge
    } 
        

    return has_switch12_changed; 
}

unsigned int poll_switch1_for_gate(unsigned int digitalinputpin) 
{ 

    unsigned int has_switch_changed = 0;  // 0 = no change; 1 = rising edge; 1 = falling edge

    if (last_switch_value == 0 && digitalinputpin >> 0) 
    {                // rising edge detected if digitalinputpin is 1 (on) 
        last_switch_value = 1;   // save current switch value (on)
        has_switch_changed = 1;  // found a rising edge
    } 
    if (last_switch_value == 1 && digitalinputpin == 0) 
    {                // falling edge detected if digitalinputpin is 0 (off) 
        last_switch_value = 0;   // save current switch value (off)
        has_switch_changed = 2;  // found a falling edge
    } 
        

    return has_switch_changed; 
} 