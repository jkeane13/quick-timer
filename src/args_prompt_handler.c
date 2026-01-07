#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/timer.h"

int promptTimeEnd(int seconds){
    char input[MAX_STRING], minutesInput[MAX_STRING], secondsInput[MAX_STRING];
    int hours, minutes;

    if (seconds == -1)
        return seconds;

    printf("Enter hours or clock time: ");
    hours = readTimeInput(input);

    if (strchr(input,':') != 0 || strchr(input, 'm') != 0)
        seconds = checkArgument(input);
    else{
        printf("Enter minutes: ");
        minutes = readTimeInput(minutesInput);
        printf("Enter seconds: ");
        seconds = readTimeInput(secondsInput);

        if (hours != 0 || minutes != 0 || seconds != 0)
            seconds = convertHoursMinsToSeconds(hours, minutes, seconds);
        else{
            printf("No time input\n");
            exit(1);
        }
    }

    return seconds;
}

int readTimeInput(char* timeInput){
    fgets(timeInput, sizeof timeInput+1, stdin);
    if (timeInput[0] == '\n')
        return 0;

    return atoi(timeInput);
}
