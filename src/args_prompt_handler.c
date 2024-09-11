#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/timer.h"

int checkArgument(char* input){
    int seconds;

    if (strcmp(input,"-p") == 0 ){
        seconds = promptTimeEnd(0);
    }else if (strchr(input, 'm') != 0){
        convertInputClockto24(input);
        seconds = convert24ClockToSeconds(input);
    }else if (strchr(input, ':') != 0){
        convertInputClockto24(input);
        seconds = convert24ClockToSeconds(input);
    }else if (strchr(input, '?') != 0){ // ? is used just for testing
        seconds = 42;
    }else{
        seconds = atoi(input);
    }

    return seconds;
}

int promptTimeEnd(int seconds){
    char input[10];
    int hours, minutes;

    if (seconds == -1)
        return seconds;

    printf("Enter hours or time: ");
    scanf("%s",input);

    if (strchr(input,':') != 0 || strchr(input, 'm') != 0)
        seconds = checkArgument(input);
    else{
        hours = atoi(input);
        printf("Enter minutes: ");
        scanf("%d", &minutes);
        printf("Enter seconds: ");
        scanf("%d", &seconds);
        seconds = convertHoursMinsToSeconds(hours, minutes, seconds);
    }

    return seconds;
}
