#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/timer.h"

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

    seconds = convertHoursMinsToSeconds(hourminsec[0],
                                        hourminsec[1],
                                        hourminsec[2]);
    return seconds;
}

