#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dates.h"

int leap_year(int year)
{
    int y;
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0)
            {
                y=1;
            }
            else
            {
                y=0;
            }
        }
        else
        {
            y=1;
        }
    }
    else
    {
        y=0;
    }
    return y;
}

int day_number(int year, int month, int day)
{
    int x;
    x=leap_year(year);
    //array for number of days in month according to leap year
    int k;
    if(x==0)
    {
        k=28;
    }
    else
    {
        k=29;
    }
    int number[13]={0,31,k,31,30,31,30,31,31,30,31,30,31};
    int days=0;
    int i;
    
    for(i=0;i<month;i++)
    {
        days += number[i];
    }
    return days+day;   
}

int day_difference(int year1,int month1,int day1,int year2,int month2,int day2)
{
    int i,k,sum1=0,sum2=0;
    if(year1!=year2 && year1<year2) // to check if the year is same because I used seperate code for same year and different years.
    {
    for(i=year1;i<year2;i++)        // counts full year number of days of leap and non leap years
    {
        k=leap_year(i);
        if(k==1)
        {
            sum1 += 366;
        }
        else
        {
            sum2 += 365;
        }
    }
    }
    
    // below is subtracts or adds to the above sum according to the math i used to calculate the number of days
    int j,m;
    j=leap_year(year1);
    if(j==1)
    {
        m=day_number(year1,month1,day1);
    }
    else
    {
        m=day_number(year1,month1,day1);       
    }
    int o,p;
    o=leap_year(year2);
    if(o==1)
    {
        p=day_number(year2,month2,day2);
    }
    else
    {
        p=day_number(year2,month2,day2);       
    }
    int h;
    h=p-m;
    
    return sum1+sum2+h;
    
}
        
