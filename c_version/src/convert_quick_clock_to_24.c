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

void convertQuickClockto24Hour(char* inputTime){
    int currentHour = getCurrentHourNumber();
    char separator = ':';
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

    // This will need to be fixed to be able to do time of the same hour and
    // measure minutes as well
    if (currentHour >= (endHour + 1) && currentHour < (endHour + 12) )
        endHour += 12;

    if (endHour == 24)
        endHour = 0;

    convertIntToDoubleString(endHour, endHourString);
    strcpy(inputTime, endHourString);
    strncat(inputTime, &separator,1);
    strcat(inputTime,endMinutesString);
}
