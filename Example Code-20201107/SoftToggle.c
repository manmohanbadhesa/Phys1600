// SoftToggle.c 
// button_RD1 to act like a switch or toggle for LED on RD2
// MCC digital input button_RD1, digital output led_RD2

#include "mcc_generated_files/mcc.h"
#include "buttons.h"

void switch1_risingedge_action(void);
void switch1_fallingedge_action(void);

int main(void) 
{ 
    // Initialize the device
    SYSTEM_Initialize();
  
    unsigned int has_switch1_changed = 0;

    while(1) 
    { 
      has_switch1_changed = poll_switch1_for_edges(button_RD1_GetValue());
      if ( has_switch1_changed == 1 ) switch1_risingedge_action();
      if ( has_switch1_changed == 2 ) switch1_fallingedge_action();
    } 
    return 0;
} 


void switch1_risingedge_action(void) 
{ 
   led_RD2_Toggle();      // flip LED status
}

void switch1_fallingedge_action(void) 
{ 
   // not used in this example
}

// end program
