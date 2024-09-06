#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/timer.h"

void runEndSwitch(char* argument, int *quietMode,  int *dryRunMode,
                  int *executeMode)
{
    if (strcmp(argument, "--quiet") == 0){
        *quietMode = 1;
    } else if (strcmp(argument, "--dry-run") == 0){
        *quietMode = 1;
        *dryRunMode = 1;
    } else if (strstr(argument, ".") != 0){
        *quietMode = 1;
        *executeMode = 1;
    }
}

int checkArgument(char* input){
    int seconds;

    if (strcmp(input,"-p") == 0 ){
        seconds = promptTimeEnd(0);
    }else if (strchr(input, 'm') != 0){
        convert12to24(input);
        seconds = convert24ClockToSeconds(input);
    }else if (strchr(input, ':') != 0){
        convert12to24(input);
        seconds = convert24ClockToSeconds(input);
    }else if (strchr(input, '?') != 0){ // ? is used just for testing
        seconds = 42;
    }else{
        seconds = atoi(input);
    }
    return seconds;
}

int promptTimeEnd(int seconds){
    char firstInput[10];
    int hoursInput, minutesInput, secondsInput;

    if (seconds == -1)
        return seconds;
    printf("Enter hours or time: ");
    scanf("%s", firstInput);
    if (strchr(firstInput,':') !=0 || strchr(firstInput, 'm') !=0)
        seconds = checkArgument(firstInput);
    else{
        hoursInput = atoi(firstInput);
        printf("Enter mintues: ");
        scanf("%d", &minutesInput);
        printf("Enter seconds: ");
        scanf("%d", &secondsInput);
        seconds = convertHoursMinsToSeconds(hoursInput, minutesInput,
                secondsInput);
    }
    return seconds;
}
