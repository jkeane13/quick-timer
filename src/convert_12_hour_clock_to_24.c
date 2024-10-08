#include <stdio.h>
#include <string.h>
#include "../include/timer.h"

#define CLOCK_24_SIZE 6

int convertHourToAm(int hour){
    if (hour == 12)
        return 0;
    else
        return hour;
}

int convertHourToPm(int hour){
    if (hour == 12)
        return hour;
    else
        return hour+=12;
}

void convert12HourClockto24( char *timeInput){
    int hour = getHour(timeInput);
    int minutes = getMinutes(timeInput);
    char secondLastChar = timeInput[strlen(timeInput)-2];

    if (secondLastChar == 'a')
        hour = convertHourToAm(hour);
    else if (secondLastChar == 'p')
        hour = convertHourToPm(hour);

    snprintf(timeInput,CLOCK_24_SIZE,"%02d:%02d",hour,minutes);
}

void convertInputClockto24(char* timeInput){
    char thirdLastChar = timeInput[strlen(timeInput)-3];
    if (thirdLastChar == ':')
        convertQuickClockto24(timeInput);
    else
        convert12HourClockto24(timeInput);
}

