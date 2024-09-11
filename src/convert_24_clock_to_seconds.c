// Needs refactoring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/timer.h"

int convert24ClockToSeconds(char* input){
    if (strlen(input) != 5 || input[2] != ':'){
        printf("Format needs to be 24 hour time - 00:00\n");
        exit(1);
    }
    struct tm *nowTime;
    time_t currentTime = time(NULL);

    nowTime = localtime(&currentTime);

    int hourInt = getHour(input);
    int minuteInt = getMinutes(input);
    int seconds = 0;

    if (nowTime->tm_hour > hourInt)
        hourInt = 24 + hourInt;

    int minDifference = minuteInt - nowTime->tm_min;

    if (minDifference < 0){
        minDifference += 60;
        hourInt--;
    }

    int hourDifference =  hourInt - nowTime->tm_hour;
    seconds = convertHoursMinsToSeconds(hourDifference, minDifference, 0);

    return seconds;
}

int convertHoursMinsToSeconds(int hours, int minutes, int seconds){
    hours = hours * 60 * 60;
    minutes = minutes * 60;

    return seconds = hours + minutes + seconds;
}
