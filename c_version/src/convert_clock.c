#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/timer.h"

void convert12to24(char* timeInput);
void convert24ClockTo12(char* clockTime);

void convert12to24(char* timeInput){
    int timeInputLength = strlen(timeInput);
    char convertPMToString[3];
    int convertToPM;
    char hourString[3];

    int time_int;
    int prefix_int;
    char clock24Time[6];
    char secondLastChar = timeInput[timeInputLength-2];
    char thirdLastChar = timeInput[timeInputLength-3];

    // *:**
    if (timeInputLength == 4 & thirdLastChar == ':'){
        strcpy(clock24Time, "0");
        strcat(clock24Time, timeInput);
    }

    // **:**
    if (timeInputLength == 5 & thirdLastChar == ':'){
        strcpy(clock24Time,timeInput);
    }

    // *am
    if (timeInputLength == 3 & secondLastChar == 'a'){
        strcpy(clock24Time, "0");
        strncat(clock24Time, &timeInput[0], 1);
        strcat(clock24Time, ":00");
    }

    // *pm
    if (timeInputLength == 3 & secondLastChar == 'p'){
        time_int = timeInput[0] - '0';
        convertToPM = time_int + 12;
        sprintf(convertPMToString,"%d",convertToPM);
        strcpy(clock24Time, convertPMToString);
        strcat(clock24Time, ":00");
    }

    // **am
    if (timeInputLength == 4 & secondLastChar == 'a'){
        strcpy(hourString,"");
        strncat(hourString, &timeInput[0], 1);
        strncat(hourString, &timeInput[1], 1);
        if (strcmp(hourString,"12") == 0){
            strcpy(clock24Time, "00");
        }else {
            strcpy(clock24Time, hourString);
        }
        strcat(clock24Time, ":00");
    }

    // 1*pm
    if (timeInputLength == 4 & secondLastChar == 'p'){
        strcpy(hourString,"");
        strncat(hourString, &timeInput[0], 1);
        strncat(hourString, &timeInput[1], 1);
        prefix_int = atoi(hourString);
        if (strcmp(hourString,"12") != 0){
            convertToPM = prefix_int + 12;
            sprintf(convertPMToString,"%d",convertToPM);
            strcpy(clock24Time, convertPMToString);
        }else {
            strcpy(clock24Time, "12");
        }
        strcat(clock24Time, ":00");
    }

    // *:**am
    if (timeInputLength == 6 & secondLastChar == 'a'){
        strcpy(clock24Time, "0");
        strncat(clock24Time, &timeInput[0], 1);
        strncat(clock24Time, &timeInput[1], 1);
        strncat(clock24Time, &timeInput[2], 1);
        strncat(clock24Time, &timeInput[3], 1);
    }

    // *:**pm
    if (timeInputLength == 6 & secondLastChar == 'p'){
        int time_int = timeInput[0] - '0';
        convertToPM = time_int + 12;
        sprintf(convertPMToString,"%d",convertToPM);
        strcpy(clock24Time, convertPMToString);
        strncat(clock24Time, &timeInput[1], 1);
        strncat(clock24Time, &timeInput[2], 1);
        strncat(clock24Time, &timeInput[3], 1);
    }

    // **:**am
    if (timeInputLength == 7 & secondLastChar == 'a'){
        if(timeInput[0] == '1' & timeInput[1] == '2'){
            strcpy(clock24Time, "00:");
        }
        else{
            strcpy(clock24Time, "");
            strncat(clock24Time, &timeInput[1], 1);
            strncat(clock24Time, &timeInput[2], 1);
        }
        strncat(clock24Time, &timeInput[3], 1);
        strncat(clock24Time, &timeInput[4], 1);
    }

    // **:**pm
    if (timeInputLength == 7 & secondLastChar == 'p'){
        if(timeInput[0] == '1' & timeInput[1] == '2'){
            strcpy(clock24Time, "12:");
        }else{
            strncat(hourString, &timeInput[0], 1);
            strncat(hourString, &timeInput[1], 1);
            int prefix_int = atoi(hourString);
            convertToPM = prefix_int + 12;
            sprintf(convertPMToString,"%d",convertToPM);
            strcpy(clock24Time, convertPMToString);
            strncat(clock24Time, &timeInput[2], 1);
        }
        strncat(clock24Time, &timeInput[3], 1);
        strncat(clock24Time, &timeInput[4], 1);
    }

    strcpy(timeInput,clock24Time);
}

void convert24ClockTo12(char* clockTime){
    char timerSuffix[4];

    int lastCharPostition = strlen(clockTime) - 1;
    int secondLastCharPostition = strlen(clockTime) - 2;

    char hourString[] = {clockTime[0], clockTime[1],'\0'};
    char minString[] = {clockTime[secondLastCharPostition], clockTime[lastCharPostition],'\0'};
    char separator = ':';
    int hour;
    int minute;;

    hour = atoi(hourString);

    if (hour < 12){
        strcpy(timerSuffix,"am");
    }else{
        hour -= 12;
        strcpy(timerSuffix,"pm");
    }

    if (hour == 0){
        hour +=12;
    }

    sprintf(hourString, "%d", hour);
    strcpy(clockTime, hourString);
    minute = atoi(minString);

    if (minute > 0){
        strncat(clockTime, &separator,1);
        strcat(clockTime, minString);
    }

    strcat(clockTime, timerSuffix);
}
