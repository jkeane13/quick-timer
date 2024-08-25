#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include "../include/timer.h"

void checkforEndSwitch(char* argument, bool* quietMode, bool* dryRun);
int convertHoursMinsToSeconds(int hours, int minutes, int seconds);
int convertArgsToSeconds(char* hoursString,
                         char* minutesString,
                         char* secondsString);
void convertIntToDoubleString(int number, char stringNumber[]);
int checkArgument(char* input);
int promptTimer();
int convertToSeconds(char* input);
void printSecondsEndAsClock(int seconds, char* clockType);
void runTimer (int seconds, bool dryRunMode);


void checkforEndSwitch(char* argument, bool* quietMode, bool* dryRun){
    if (strcmp(argument, "--quiet") == 0){
        *quietMode = true;
    }
    if (strcmp(argument, "--dry-run") == 0){
        *quietMode = true;
        *dryRun = true;
    }
}

int convertHoursMinsToSeconds(int hours, int minutes, int seconds){
    hours = hours  * 60 * 60;
    minutes = minutes * 60;

    return seconds = hours + minutes + seconds;
}

int convertArgsToSeconds(char* hoursString,
                         char* minutesString,
                         char* secondsString){
    int hours = atoi(hoursString);
    int minutes = atoi(minutesString);
    int seconds = atoi(secondsString);

    if (hours == 0 | minutes == 0){
       seconds = checkArgument(secondsString);
    }
    seconds = convertHoursMinsToSeconds(hours, minutes, seconds);

    return seconds;
}

// Bad function name, will send back the difference in seconds, thus can't be
// tested other than being triggered with ?. Needs to be refactored
int checkArgument(char* input){
    int seconds;

    if (strcmp(input,"-p") == 0 ){
        seconds = promptTimer();
    }else if (strchr(input, 'm') != 0){
        convert12to24(input);
        seconds = convertToSeconds(input);
    }else if (strchr(input, ':') != 0){
        convert12to24(input);
        seconds = convertToSeconds(input);
    }else if (strchr(input, '?') != 0){ // ? is used just for testing
        seconds = 42;
    }else{
        seconds = atoi(input);
    }
    return seconds;
}

// Not Tested
int convertToSeconds(char* input){
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

// Not Tested
int promptTimer(){
    char entry[10];
    printf("Enter seconds or time: ");
    scanf("%s", entry);
    int seconds = checkArgument(entry);
    return seconds;
}

// Not Tested
void convertIntToDoubleString(int number, char stringNumber[]){
    if (number < 10){
        stringNumber[0] = '0';
        stringNumber[1] = number + '0';
        stringNumber[2] = '\0';
    } else{
        sprintf(stringNumber, "%d", number);
    }
}

// Not Tested
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

   printf("%s", outputString);
}

//Not Tested
void runTimer (int seconds, bool dryRunMode){
   struct tm *endTimeInfo;
   time_t endTime = time(NULL) + seconds;
   printf("Timer ends at ");
   printSecondsEndAsClock(seconds,"12Hour");
   printf("\n");

   if (dryRunMode == false){
       int timeDifference =  endTime - time(NULL);

       while(timeDifference > 1){
           timeDifference =  endTime - time(NULL);
           int h = seconds / 3600;
           int m = (seconds  % 3600) / 60;
           int s = seconds  % 60;

           printf ("\r%02d:%02d:%02d", h, m, s);
           fflush(stdout);
           sleep(1);
           seconds--;
       }
   }
}

