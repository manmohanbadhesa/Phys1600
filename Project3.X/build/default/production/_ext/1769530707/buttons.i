# 1 "../exercise13.X/buttons.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files (x86)/Microchip/MPLABX/v5.40/packs/Microchip/PIC18F-K_DFP/1.4.87/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "../exercise13.X/buttons.c" 2



# 1 "../exercise13.X/buttons.h" 1








unsigned int poll_switch1_for_edges(unsigned int digitalinputpin);
# 4 "../exercise13.X/buttons.c" 2
# 16 "../exercise13.X/buttons.c"
unsigned int last_switch1_value = 0;





unsigned int poll_switch1_for_edges(unsigned int digitalinputpin)
{

    unsigned int has_switch1_changed = 0;

    if (last_switch1_value == 0 && digitalinputpin >> 0)
    {
        last_switch1_value = 1;
        has_switch1_changed = 1;
    }
    if (last_switch1_value == 1 && digitalinputpin == 0)
    {
        last_switch1_value = 0;
        has_switch1_changed = 2;
    }

    return has_switch1_changed;
}
