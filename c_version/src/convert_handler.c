#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/timer.h"

#define QUICK_CLOCK 1
#define CLOCK_24 0

int convert24ClockToSeconds(char* input);

void runEndSwitch(char* argument, int *quietMode,  int *dryRunMode, int *executeMode){
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

int convertHoursMinsToSeconds(int hours, int minutes, int seconds){
    hours = hours * 60 * 60;
    minutes = minutes * 60;

    return seconds = hours + minutes + seconds;
}

int convertArgsToSeconds(char* arg){
    int hourminsec[] = {0,0,0};
    int i = 0;
    char commandString[10];
    int seconds = 0;
    int temp;

    char *token = strtok(arg, " ");
    while (token){
        hourminsec[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }

    if (i == 1){
        hourminsec[2] = hourminsec[0];
        hourminsec[0] = 0;
        sprintf(commandString, "%d", hourminsec[2]);
        hourminsec[2] = checkArgument(arg);
    }
    if (i == 2){
        temp = hourminsec[0];
        hourminsec[0] = 0;
        hourminsec[2] = hourminsec[1];
        hourminsec[1] = temp;
    }

    seconds = convertHoursMinsToSeconds(hourminsec[0], hourminsec[1], hourminsec[2]);
    return seconds;
}

int checkArgument(char* input){
    int seconds;

    if (strcmp(input,"-p") == 0 ){
        seconds = promptTimeEnd(0);
    }else if (strchr(input, 'm') != 0){
        convert12to24(input, QUICK_CLOCK);
        seconds = convert24ClockToSeconds(input);
    }else if (strchr(input, ':') != 0){
        convert12to24(input, QUICK_CLOCK);
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
