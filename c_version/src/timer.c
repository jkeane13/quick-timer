#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <time.h>
#include "../include/timer.h"

#define UNIX_NULL_OUTPUT " >/dev/null 2>&1"

int convert24ClockToSeconds(char* input){
    if (strlen(input) > 5 || input[2] != ':'){
        printf("Format needs to be 24 hour time - 00:00\n");
        exit(1);
    }
    char hourInput[] = {input[0], input[1], '\0'};
    char minInput[] = {input[3], input[4], '\0'};
    struct tm *nowTime;
    time_t currentTime = time(NULL);

    nowTime = localtime(&currentTime);

    int hourInt = atoi(hourInput);
    int minuteInt = atoi(minInput);
    int seconds = 0;

    if (nowTime->tm_hour > hourInt)
        hourInt = 24 + hourInt;

    int minDifference = minuteInt - nowTime->tm_min;

    if (minDifference < 0){
        minDifference += 60;
        hourInt--;
    }

    int hourDifference =  hourInt - nowTime->tm_hour;

    seconds = convertHoursMinsToSeconds(hourDifference,
                                        minDifference,
                                        0);

    return seconds;
}

void convertIntToDoubleString(int number, char stringNumber[]){
    if (number < 10){
        stringNumber[0] = '0';
        stringNumber[1] = number + '0';
        stringNumber[2] = '\0';
    } else{
        sprintf(stringNumber, "%d", number);
    }
}

void printSecondsEndAsClock(int seconds, char* clockType){
   struct tm *endTimeInfo;
   time_t endTime = time(NULL) + seconds;

   endTimeInfo = localtime(&endTime);

   char minString[3];
   char hourString[3];
   char outputString[10];

   convertIntToDoubleString(endTimeInfo->tm_hour, hourString);
   convertIntToDoubleString(endTimeInfo->tm_min, minString);

   strcpy(outputString,hourString);
   strcat(outputString,":");
   strcat(outputString,minString);

   if (strcmp(clockType,"24Hour") != 0 )
       convert24ClockTo12(outputString);

   printf("%s\n", outputString);
}

void printTimerEndTime (int seconds){
   printf("Timer ends at ");
   printSecondsEndAsClock(seconds,"12Hour");
}

