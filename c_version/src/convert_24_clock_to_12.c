#include <stdio.h>
#include <string.h>
#include "../include/timer.h"

void convert24ClockTo12(char* clockTime){
    char clockSuffix;
    int hour, minutes;

    hour = getHour(clockTime);
    minutes = getMinutes(clockTime);

    if (hour < 12)
        clockSuffix = 'a';
    else{
        hour -= 12;
        clockSuffix = 'p';
    }

    if (hour == 0)
        hour +=12;

    if (minutes == 0)
        sprintf(clockTime,"%d%cm", hour, clockSuffix);
    else
        sprintf(clockTime,"%d:%02d%cm", hour, minutes, clockSuffix);
}
