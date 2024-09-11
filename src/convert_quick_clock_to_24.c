#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/timer.h"

#define CLOCK_24_SIZE 6

int getCurrentHourNumber(){
    struct tm *nowTime;
    time_t currentTime = time(NULL);
    nowTime = localtime(&currentTime);

    return nowTime->tm_hour;
}

int getCurrentMinuteNumber(){
    struct tm *nowTime;
    time_t currentTime = time(NULL);
    nowTime = localtime(&currentTime);

    return nowTime->tm_min;
}

void convertQuickClockto24(char* inputTime){
    int currentHour = getCurrentHourNumber();
    int currentMinute = getCurrentMinuteNumber();
    int endHour = getHour(inputTime);
    int endMinute = getMinutes(inputTime);

    if (currentHour > endHour && currentHour < (endHour + 12))
        endHour += 12;

    if (currentHour == endHour || currentHour == (endHour + 12 )
                               && currentMinute < endMinute)
        endHour += 12;

    if (endHour == 24)
        endHour = 0;

    snprintf(inputTime,CLOCK_24_SIZE, "%02d:%02d", endHour, endMinute);
}
