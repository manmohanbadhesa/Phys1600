
# 1 "buttons.c"

# 9 "buttons.h"
unsigned int poll_switch1_for_edges(unsigned int digitalinputpin);

# 16 "buttons.c"
unsigned int last_switch1_value = 0;

# 22
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
