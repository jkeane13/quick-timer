#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include "timer.h"

#define FILENAME "assets/duck_quack.mp3"
#define MAC_PLAYER "afplay"
#define LINUX_PLAYER "mpg123"
#define MAX_COMMAND_LENGTH 100

int checkArgument(char* input);
int promptTimer();
int convertToSeconds(char* input);
int convertHoursMinsToSeconds(char* hoursString, char* minutesString, char* secondsString);
void runTimer (int seconds);
void alert(int times, bool quietMode);
void convert12to24(char* timeInput);
void checkforEndSwitch(char* argument, bool* quietMode, bool* dryRun);

void checkforEndSwitch(char* argument, bool* quietMode, bool* dryRun){
    if (strcmp(argument, "--quiet") == 0){
        *quietMode = true;
    }
    if (strcmp(argument, "--dry-run") == 0){
        *quietMode = true;
        *dryRun = true;
    }
}

int convertHoursMinsToSeconds(char* hoursString, char* minutesString, char* secondsString){
    int hours = atoi(hoursString) * 60 * 60;
    int minute = atoi(minutesString) * 60;
    int seconds = atoi(secondsString);

    if (hours == 0 | minute == 0){
       seconds = checkArgument(secondsString);
    }

    return seconds = hours + minute + seconds;
}

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

    //12:** (am for now, need to go to the next one, if timer is run after 12pm)
    if (timeInputLength == 5 & timeInput[0] == '1' &timeInput[1] == '2'){
        strcat(clock24Time, timeInput);
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
        strncat(hourString, &timeInput[0], 1);
        strncat(hourString, &timeInput[1], 1);
        if (strcmp(hourString,"12") != 0){
            strcpy(clock24Time, "1");
            strncat(clock24Time, &timeInput[1], 1);
        }else {
            strcpy(clock24Time, "00");
        }
        strcat(clock24Time, ":00");
    }

    // 1*pm
    if (timeInputLength == 4 & secondLastChar == 'p'){
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
        strcpy(clock24Time, "1");
        strncat(clock24Time, &timeInput[1], 1);
        strncat(clock24Time, &timeInput[2], 1);
        strncat(clock24Time, &timeInput[3], 1);
        strncat(clock24Time, &timeInput[4], 1);
    }

    // **:**pm
    if (timeInputLength == 7 & secondLastChar == 'p'){
        strncat(hourString, &timeInput[0], 1);
        strncat(hourString, &timeInput[1], 1);
        int prefix_int = atoi(hourString);
        convertToPM = prefix_int + 12;
        sprintf(convertPMToString,"%d",convertToPM);
        strcpy(clock24Time, convertPMToString);
        strncat(clock24Time, &timeInput[2], 1);
        strncat(clock24Time, &timeInput[3], 1);
        strncat(clock24Time, &timeInput[4], 1);
    }

    strcpy(timeInput,clock24Time);

    printf("24 Time: %s\n", timeInput);
}

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

int promptTimer(){
    char entry[10];
    printf("Enter seconds or time: ");
    scanf("%s", entry);
    int seconds = checkArgument(entry);
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

void runTimer(int seconds){
   struct tm *endTimeInfo;
   time_t endTime = time(NULL) + seconds;

   endTimeInfo = localtime(&endTime);

   char minString[3];
   char hourString[3];
   char time24String[6];

   convertIntToDoubleString(endTimeInfo->tm_min, minString);
   convertIntToDoubleString(endTimeInfo->tm_hour, hourString);

   strcpy(time24String,hourString);
   strcat(time24String,":");
   strcat(time24String,minString);

   printf("Timer ends at %s\n", time24String);

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

void alert(int times, bool quietMode){
    int i;
    char soundCommand[MAX_COMMAND_LENGTH];

    printf("\rTime's up!\n");
    if (quietMode == true)
        exit(0);

    for (i = 0; i < times; i++){
        #if defined(__APPLE__)
            strcpy (soundCommand, MAC_PLAYER);
            strcat (soundCommand," ");
            strcat (soundCommand,FILENAME);
            system(soundCommand);
        #elif defined(__linux__)
            strcpy (soundCommand, LINUX_PLAYER);
            strcat (soundCommand," ");
            strcat (soundCommand,FILENAME);
            strcat (soundCommand," >/dev/null 2>&1");
            system(soundCommand);
        #elif defined(_WIN32)
            system("mpg123 assets\\duck_quack.mp3 >NUL 2>&1");
        #endif
    }
}

