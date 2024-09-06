#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/timer.h"

void addMinutesToClock(char* clock24Time, char* timeInput);

void convert12to24(char* timeInput){
    int timeInputLength = strlen(timeInput);
    char pmString[3];

    char clock24Time[6];
    char lastChar = timeInput[timeInputLength-1];
    char secondLastChar = timeInput[timeInputLength-2];
    char thirdLastChar = timeInput[timeInputLength-3];

    // *:** and **.**
    if (thirdLastChar == ':'){
        convertQuickClockto24Hour(timeInput);
        strcpy(clock24Time,timeInput);
    }

    // * am and pm
    if (timeInputLength == 3 & lastChar == 'm'){
        if (secondLastChar == 'p'){
            int hourNumber = timeInput[0] - '0';
            sprintf(pmString,"%d",hourNumber + 12);
            strcpy(clock24Time, pmString);
        }else{
            clock24Time[0] = '0';
            clock24Time[1] = timeInput[0];

        }
        strcat(clock24Time, ":00");
    }

    // ** am and pm
    if (timeInputLength == 4 & lastChar == 'm'){
        int addHours = 0;
        if (secondLastChar == 'p')
            addHours = 12;
        clock24Time[0] = timeInput[0];
        clock24Time[1] = timeInput[1];
        if (clock24Time[1] != '2'){
            sprintf(pmString,"%d",atoi(clock24Time) + addHours);
            strcpy(clock24Time, pmString);
        }
        if (clock24Time[1] != '2' || secondLastChar == 'a'){
            strcpy(clock24Time, "00");
        }
        strcat(clock24Time, ":00");
    }

    // *:** am and pm
    if (timeInputLength == 6 & lastChar == 'm'){
        if (secondLastChar == 'p'){
            int hourNumber = timeInput[0] - '0';
            sprintf(pmString,"%d", hourNumber + 12);
            strcpy(clock24Time, pmString);
        }
        else{
            clock24Time[0] = '0';
            clock24Time[1] = timeInput[0];
        }
        clock24Time[2] = timeInput[1];
        clock24Time[3] = timeInput[2];
        clock24Time[4] = timeInput[3];
        clock24Time[5] =  '\0';
    }

    // **:** am and pm
    if (timeInputLength == 7){
        clock24Time[0] = timeInput[0];
        clock24Time[1] = timeInput[1];
        int addHours = 0;

        if (secondLastChar == 'p'&& clock24Time[1] != '2' )
            addHours = 12;

        int hoursInt = atoi(clock24Time) + addHours;
        sprintf(clock24Time,"%d", hoursInt);

        if (hoursInt == 12 & secondLastChar =='a')
            strcpy(clock24Time, "00");

        addMinutesToClock(clock24Time, timeInput);
    }
    strcpy(timeInput,clock24Time);
}

void addMinutesToClock(char* clock24Time, char* timeInput){
        clock24Time[2] =  timeInput[2];
        clock24Time[3] =  timeInput[3];
        clock24Time[4] =  timeInput[4];
        clock24Time[5] =  '\0';
}
