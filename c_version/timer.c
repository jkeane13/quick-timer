#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define FILENAME "assets/duck_quack.mp3"
#define MAC_PLAYER "afplay"
#define LINUX_PLAYER "mpg123"
#define MAX_COMMAND_LENGTH 100
#define ALERT_TIMES 1

int checkArgument(char* input);
int promptTimer(char* input);
int convertToSeconds(char* input);
void runTimer (int seconds);
void alert(int times);
void usage();

void convert12to24(char* timeInput);

int main(int argc, char *argv[]){
    int seconds = 0;
    char input[6];

    if (argc <= 1){
        usage();
        return 1;
    }

    if (argc == 2){
        strcpy(input,argv[1]);
        seconds = checkArgument(input);
    }

    if (argc == 3){
        seconds = atoi(argv[1]) * 60;
        seconds += atoi(argv[2]);
    }

    if (argc == 4){
        seconds = atoi(argv[1]) * 60 * 60;
        seconds += atoi(argv[2]) * 60;
        seconds += atoi(argv[3]);
    }

    if (argc > 4){
        usage();
        return 1;
    }

    runTimer(seconds);
    alert(ALERT_TIMES);
}

void convert12to24(char* timeInput){
    // Only does 1-9 am and pm for now */
    int timeInputLength = strlen(timeInput);

    char defaultFormat[6];
    char secondLastChar = timeInput[timeInputLength-2];
    char lastChar = timeInput[timeInputLength-1];

    if (timeInputLength == 3 & secondLastChar == 'a'){
        strcpy(defaultFormat, "0");
        strncat(defaultFormat, &timeInput[0], 1);
    }

    int convertToPM;
    char convertPMToString[3];
    if (timeInputLength == 3 & secondLastChar == 'p'){
        int time_int = timeInput[0] - '0';
        convertToPM = time_int + 12;
        sprintf(convertPMToString,"%d",convertToPM);

        strcpy(defaultFormat, convertPMToString);
    }
    strcat(defaultFormat, ":00");
    strcpy(timeInput,defaultFormat);
}

int checkArgument(char* input){
    int seconds = atoi(input);

    if (strcmp(input,"-p") == 0 ){
        seconds = promptTimer(input);
    }
    if (strchr(input, 'm') != NULL){
        convert12to24(input);
        seconds = convertToSeconds(input);
    }

    if (strchr(input, ':') != NULL)
        seconds = convertToSeconds(input);

    return seconds;
}

int convertToSeconds(char* input){
    if (strlen(input) != 5){
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

int promptTimer(char* input){
    int seconds;
    printf("Enter countdown time in seconds: ");
    scanf("%d", &seconds);
    return seconds;
}

void runTimer(int seconds){
   struct tm *endTimeInfo;
   time_t endTime = time(NULL) + seconds; // calculate the end time

   endTimeInfo = localtime(&endTime);
   printf("Timer ends at %.2d:%.2d\n",
            endTimeInfo->tm_hour,
            endTimeInfo->tm_min);

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

void alert(int times){
    int i;
    char soundCommand[MAX_COMMAND_LENGTH];

    printf("\rTime's up!\n");
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

void usage(void){
    printf("usage: timer [number code] [switch]                \n"
           "                                                   \n"
           "Enter in time code in \'hour minute second\' format\n"
           "                                                   \n"
           "                                                   \n"
           "-p              prompt time input                  \n"
           "                                                   \n"
           "Example: One hour, 2 minutes and 3 seconds timer   \n"
           "timer 1 2 3                                        \n");
}

