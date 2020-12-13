#include "dates.h"
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    int y,z;
    int u;
    
    int year=2020,month=6, day=21;
    y= leap_year(year);
    printf("\n\r\n\r%d",y);
    z=day_number(year,month,day);
    printf("\n\r The %d day of %d month is the day %d in the year %d",day,month,z,year);
    
    int y1=1867,m1=07,d1=1,y2=2018,m2=2,d2=5;
    u=day_difference(y1,m1,d1,y2,m2,d2);
    printf("\n\r\n\rThe difference between %d month %d day %d and %d month %d day %d is %u ",y1,m1,d1,y2,m2,d2,u);
    while (1)
    {
        // Add your application code
    }
}
/**
 End of File
*/