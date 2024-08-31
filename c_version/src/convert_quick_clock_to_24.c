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
    int timeInputLength = strlen(inputTime);
    int firstMinutePosition = strlen(inputTime) - 2;
    int secondMinutePosition = strlen(inputTime) - 1;
    char endHourString[] = {inputTime[0], inputTime[1],'\0'};
    char endMinutesString[] = {inputTime[firstMinutePosition],
                               inputTime[secondMinutePosition],
                               '\0'};
    int endHour = atoi(endHourString);

    if (currentHour >= 12 || currentHour > (endHour + 12) )
        endHour += 12;

    convertIntToDoubleString(endHour, endHourString);
    strcpy(inputTime, endHourString);
    strncat(inputTime, &separator,1);
    strcat(inputTime,endMinutesString);
}

