#include "buttons.h"
#include "read_keypad.h"

void readKeypad()
{
        col_RC1_SetHigh();
        col_RC2_SetLow();
        col_RC3_SetLow();
        //printf("\n\rcol 1 powered\n\r");
        has_switch1_changed = poll_switch1_for_edges(row_RC4_GetValue());
        DELAY_milliseconds(10);
        if(has_switch1_changed==1)
        {
            printf("\n\rbutton 1");
        }
        
        has_switch1_changed = poll_switch1_for_edges(row_RC5_GetValue());
        DELAY_milliseconds(10);
        if(has_switch1_changed==1)
        {
            printf("\n\rbutton 4");
        }
        
        has_switch1_changed = poll_switch1_for_edges(row_RC6_GetValue());
        DELAY_milliseconds(10);
        if(has_switch1_changed==1)
        {
            printf("\n\rbutton 7");
        }
        has_switch1_changed = poll_switch1_for_edges(row_RC7_GetValue());
        DELAY_milliseconds(10);
        if(has_switch1_changed==1)
        {
            printf("\n\rbutton *");
        }
        
        DELAY_milliseconds(1);
        
        col_RC2_SetHigh();
        col_RC1_SetLow();
        col_RC3_SetLow();
        //printf("\n\rcol 2 powered\n\r");
        
        has_switch1_changed = poll_switch1_for_edges(row_RC4_GetValue());
        DELAY_milliseconds(10);
        if(has_switch1_changed==1)
        {
            printf("\n\rbutton 2");
        }
        
        has_switch1_changed = poll_switch1_for_edges(row_RC5_GetValue());
        DELAY_milliseconds(10);
        if(has_switch1_changed==1)
        {
            printf("\n\rbutton 5");
        }
        
        has_switch1_changed = poll_switch1_for_edges(row_RC6_GetValue());
        DELAY_milliseconds(10);
        if(has_switch1_changed==1)
        {
            printf("\n\rbutton 8");
        }
        has_switch1_changed = poll_switch1_for_edges(row_RC7_GetValue());
        DELAY_milliseconds(10);
        if(has_switch1_changed==1)
        {
            printf("\n\rbutton 0");
        }
        
        DELAY_milliseconds(1);
        
        col_RC2_SetLow();
        col_RC1_SetLow();
        col_RC3_SetHigh();
        //printf("\n\rcol 3 powered");
        
        has_switch1_changed = poll_switch1_for_edges(row_RC4_GetValue());
        DELAY_milliseconds(10);
        if(has_switch1_changed==1)
        {
            printf("\n\rbutton 3");
        }
        
        has_switch1_changed = poll_switch1_for_edges(row_RC5_GetValue());
        DELAY_milliseconds(10);
        if(has_switch1_changed==1)
        {
            printf("\n\rbutton 6");
        }
        
        has_switch1_changed = poll_switch1_for_edges(row_RC6_GetValue());
        DELAY_milliseconds(10);
        if(has_switch1_changed==1)
        {
            printf("\n\rbutton 9");
        }
        has_switch1_changed = poll_switch1_for_edges(row_RC7_GetValue());
        DELAY_milliseconds(10);
        if(has_switch1_changed==1)
        {
            printf("\n\rbutton #");
        }
        
}
