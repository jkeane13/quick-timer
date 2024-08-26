#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "../include/timer.h"

void runEndSwitch(char* argSwitch, int *quietMode, int *dryRunMode, int *executeMode);
int convertHoursMinsToSeconds(int hours, int minutes, int seconds);
int convertArgsToSeconds(char* args);
void convertIntToDoubleString(int number, char stringNumber[]);
int checkArgument(char* input);
int promptTimeEnd();
int convert24ClockToSeconds(char* input);
void printSecondsEndAsClock(int seconds, char* clockType);
void printTimerEndTime (int seconds);

void runEndSwitch(char* argument, int *quietMode,  int *dryRunMode, int *executeMode){
    if (strcmp(argument, "--quiet") == 0){
        *quietMode = 1;
    }
    if (strcmp(argument, "--dry-run") == 0){
        *quietMode = 1;
        *dryRunMode = 1;
    }
    if (strstr(argument, ".") != 0){
        *quietMode = 1;
        *executeMode = 1;
    }
}

void runProgram(char* programLocation){
    system(programLocation);
}

int convertHoursMinsToSeconds(int hours, int minutes, int seconds){
    hours = hours  * 60 * 60;
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

// Bad function name, will send back the difference in seconds, thus can't be
// tested other than being triggered with ?. Needs to be refactored
int checkArgument(char* input){
    int seconds;

    if (strcmp(input,"-p") == 0 ){
        seconds = promptTimeEnd();
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

int convert24ClockToSeconds(char* input){
    if (strlen(input) > 5){
        printf("Format needs to be 00:00, or single digit am or pm\n");
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

int promptTimeEnd(){
    char firstInput[10];
    int hoursInput;
    int minutesInput;
    int secondsInput;
    int seconds;
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

