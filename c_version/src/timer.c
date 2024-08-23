#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include "../include/timer.h"

void checkforEndSwitch(char* argument, bool* quietMode, bool* dryRun);
int convertHoursMinsToSeconds(int hours, int minutes, int seconds);
int convertArgsToSeconds(char* hoursString, char* minutesString, char* secondsString);
void convertIntToDoubleString(int number, char stringNumber[]);
int checkArgument(char* input);
int promptTimer();
int convertToSeconds(char* input);
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

int convertArgsToSeconds(char* hoursString, char* minutesString, char* secondsString){
    int hours = atoi(hoursString);
    int minutes = atoi(minutesString);
    int seconds = atoi(secondsString);

    if (hours == 0 | minutes == 0){
       seconds = checkArgument(secondsString);
    }
    seconds = convertHoursMinsToSeconds(hours, minutes, seconds);

    return seconds;
}

// Not Tested
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
    int seconds;
    char hourInput[] = {input[0], input[1], '\0'};
    char minInput[] = {input[3], input[4], '\0'};
    struct tm *nowTime;
    time_t currentTime = time(NULL);

    nowTime = localtime(&currentTime);

    int hour_int = atoi(hourInput);

    int minute_int = atoi(minInput);

    if (nowTime->tm_hour > hour_int)
        hour_int = 24 + hour_int;

    int min_difference = minute_int - nowTime->tm_min;

    if (min_difference < 0){
        min_difference += 60;
        hour_int--;
    }

    int hour_difference =  hour_int - nowTime->tm_hour;

    seconds = hour_difference * 60 * 60 + min_difference * 60;

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

//Not Tested
void runTimer (int seconds, bool dryRunMode){
   struct tm *endTimeInfo;
   time_t endTime = time(NULL) + seconds;

   endTimeInfo = localtime(&endTime);

   char minString[3];
   char hourString[3];
   char time24String[6];
   char time12String[10];

   convertIntToDoubleString(endTimeInfo->tm_min, minString);
   convertIntToDoubleString(endTimeInfo->tm_hour, hourString);

   strcpy(time24String,hourString);
   strcat(time24String,":");
   strcat(time24String,minString);

   strcpy(time12String,time24String);

   convert24ClockTo12(time12String);

   printf("Timer ends at %s\n", time12String);
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


