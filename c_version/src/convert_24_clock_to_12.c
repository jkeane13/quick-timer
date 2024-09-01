#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/timer.h"

void convert24ClockTo12(char* clockTime){
    char timerSuffix[4];

    int lastCharPostition = strlen(clockTime) - 1;
    int secondLastCharPostition = strlen(clockTime) - 2;

    char hourString[] = {clockTime[0], clockTime[1],'\0'};
    char minString[] = {clockTime[secondLastCharPostition],
                        clockTime[lastCharPostition],'\0'};

    char separator = ':';
    int hour;
    int minute;;

    hour = atoi(hourString);

    if (hour < 12)
        strcpy(timerSuffix,"am");
    else{
        hour -= 12;
        strcpy(timerSuffix,"pm");
    }

    if (hour == 0)
        hour +=12;

    sprintf(hourString, "%d", hour);
    strcpy(clockTime, hourString);
    minute = atoi(minString);

    if (minute > 0){
        strncat(clockTime, &separator,1);
        strcat(clockTime, minString);
    }

    strcat(clockTime, timerSuffix);
}
