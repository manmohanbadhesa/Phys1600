
# 1 "buttons.c"

# 10 "buttons.h"
unsigned int poll_switch1_for_gate(unsigned int digitalinputpin);


unsigned int poll_switch1_for_edges(unsigned int digitalinputpin);
unsigned int poll_switch2_for_edges(unsigned int digitalinputpin);
unsigned int poll_switch3_for_edges(unsigned int digitalinputpin);
unsigned int poll_switch4_for_edges(unsigned int digitalinputpin);
unsigned int poll_switch5_for_edges(unsigned int digitalinputpin);
unsigned int poll_switch6_for_edges(unsigned int digitalinputpin);
unsigned int poll_switch7_for_edges(unsigned int digitalinputpin);
unsigned int poll_switch8_for_edges(unsigned int digitalinputpin);
unsigned int poll_switch9_for_edges(unsigned int digitalinputpin);
unsigned int poll_switch10_for_edges(unsigned int digitalinputpin);
unsigned int poll_switch11_for_edges(unsigned int digitalinputpin);
unsigned int poll_switch12_for_edges(unsigned int digitalinputpin);

# 15 "buttons.c"
unsigned int last_switch_value = 0;


unsigned int last_switch1_value = 0;
unsigned int last_switch2_value = 0;
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

# 35
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


unsigned int poll_switch2_for_edges(unsigned int digitalinputpin)
{

unsigned int has_switch2_changed = 0;

if (last_switch2_value == 0 && digitalinputpin >> 0)
{
last_switch2_value = 1;
has_switch2_changed = 1;
}
if (last_switch2_value == 1 && digitalinputpin == 0)
{
last_switch2_value = 0;
has_switch2_changed = 2;
}


return has_switch2_changed;
}

unsigned int poll_switch3_for_edges(unsigned int digitalinputpin)
{

unsigned int has_switch3_changed = 0;

if (last_switch3_value == 0 && digitalinputpin >> 0)
{
last_switch3_value = 1;
has_switch3_changed = 1;
}
if (last_switch3_value == 1 && digitalinputpin == 0)
{
last_switch3_value = 0;
has_switch3_changed = 2;
}


return has_switch3_changed;
}

unsigned int poll_switch4_for_edges(unsigned int digitalinputpin)
{

unsigned int has_switch4_changed = 0;

if (last_switch4_value == 0 && digitalinputpin >> 0)
{
last_switch4_value = 1;
has_switch4_changed = 1;
}
if (last_switch4_value == 1 && digitalinputpin == 0)
{
last_switch4_value = 0;
has_switch4_changed = 2;
}


return has_switch4_changed;
}
unsigned int poll_switch5_for_edges(unsigned int digitalinputpin)
{

unsigned int has_switch5_changed = 0;

if (last_switch5_value == 0 && digitalinputpin >> 0)
{
last_switch5_value = 1;
has_switch5_changed = 1;
}
if (last_switch5_value == 1 && digitalinputpin == 0)
{
last_switch5_value = 0;
has_switch5_changed = 2;
}


return has_switch5_changed;
}

unsigned int poll_switch6_for_edges(unsigned int digitalinputpin)
{

unsigned int has_switch6_changed = 0;

if (last_switch6_value == 0 && digitalinputpin >> 0)
{
last_switch6_value = 1;
has_switch6_changed = 1;
}
if (last_switch6_value == 1 && digitalinputpin == 0)
{
last_switch6_value = 0;
has_switch6_changed = 2;
}


return has_switch6_changed;
}

unsigned int poll_switch7_for_edges(unsigned int digitalinputpin)
{

unsigned int has_switch7_changed = 0;

if (last_switch7_value == 0 && digitalinputpin >> 0)
{
last_switch7_value = 1;
has_switch7_changed = 1;
}
if (last_switch7_value == 1 && digitalinputpin == 0)
{
last_switch7_value = 0;
has_switch7_changed = 2;
}


return has_switch7_changed;
}
unsigned int poll_switch8_for_edges(unsigned int digitalinputpin)
{

unsigned int has_switch8_changed = 0;

if (last_switch8_value == 0 && digitalinputpin >> 0)
{
last_switch8_value = 1;
has_switch8_changed = 1;
}
if (last_switch8_value == 1 && digitalinputpin == 0)
{
last_switch8_value = 0;
has_switch8_changed = 2;
}


return has_switch8_changed;
}

unsigned int poll_switch9_for_edges(unsigned int digitalinputpin)
{

unsigned int has_switch9_changed = 0;

if (last_switch9_value == 0 && digitalinputpin >> 0)
{
last_switch9_value = 1;
has_switch9_changed = 1;
}
if (last_switch9_value == 1 && digitalinputpin == 0)
{
last_switch9_value = 0;
has_switch9_changed = 2;
}


return has_switch9_changed;
}

unsigned int poll_switch10_for_edges(unsigned int digitalinputpin)
{

unsigned int has_switch10_changed = 0;

if (last_switch10_value == 0 && digitalinputpin >> 0)
{
last_switch10_value = 1;
has_switch10_changed = 1;
}
if (last_switch10_value == 1 && digitalinputpin == 0)
{
last_switch10_value = 0;
has_switch10_changed = 2;
}


return has_switch10_changed;
}

unsigned int poll_switch11_for_edges(unsigned int digitalinputpin)
{

unsigned int has_switch11_changed = 0;

if (last_switch11_value == 0 && digitalinputpin >> 0)
{
last_switch11_value = 1;
has_switch11_changed = 1;
}
if (last_switch11_value == 1 && digitalinputpin == 0)
{
last_switch11_value = 0;
has_switch11_changed = 2;
}


return has_switch11_changed;
}

unsigned int poll_switch12_for_edges(unsigned int digitalinputpin)
{

unsigned int has_switch12_changed = 0;

if (last_switch12_value == 0 && digitalinputpin >> 0)
{
last_switch12_value = 1;
has_switch12_changed = 1;
}
if (last_switch12_value == 1 && digitalinputpin == 0)
{
last_switch12_value = 0;
has_switch12_changed = 2;
}


return has_switch12_changed;
}

unsigned int poll_switch1_for_gate(unsigned int digitalinputpin)
{

unsigned int has_switch_changed = 0;

if (last_switch_value == 0 && digitalinputpin >> 0)
{
last_switch_value = 1;
has_switch_changed = 1;
}
if (last_switch_value == 1 && digitalinputpin == 0)
{
last_switch_value = 0;
has_switch_changed = 2;
}


return has_switch_changed;
}
