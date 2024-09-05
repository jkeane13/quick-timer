#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/timer.h"

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

void convertQuickClockto24Hour(char* inputTime){
    int currentHour = getCurrentHourNumber();
    int currentMinute = getCurrentMinuteNumber();
    char endHourString[3];
    int timeInputLength = strlen(inputTime);
    int firstMinutePosition = strlen(inputTime) - 2;
    int secondMinutePosition = strlen(inputTime) - 1;

    endHourString[0] = inputTime[0];

    if (strlen(inputTime) == 4)
        endHourString[1] = '\0';
    else if (strlen(inputTime) == 5){
        endHourString[1] = inputTime[1],
        endHourString[2] = '\0';
    }

    char endMinutesString[] = {inputTime[firstMinutePosition],
                               inputTime[secondMinutePosition],
                               '\0'};
    int endHour = atoi(endHourString);
    int endMinute = atoi(endMinutesString);

    if (currentHour >= (endHour + 1) && currentHour < (endHour + 12))
        endHour += 12;

    if (currentHour == endHour || currentHour == (endHour + 12 )
                               && currentMinute < endMinute)
        endHour += 12;

    if (endHour == 24)
        endHour = 0;

    sprintf(inputTime, "%02d:%s", endHour, endMinutesString);
}
