#include <stdio.h>
#include "putty.h"

void clearPuTTY(void)
{
printf("%c%c%c%c",27,'[','2','J'); // Clear PuTTY Window
printf("%c%c%c%c",27,'[','3','J'); // Clear ScrollBack
printf("%c%c%c",27,'[','H');       // Home (top left corner) PuTTY Cursor
}