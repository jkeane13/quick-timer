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
int promptTimer(char *input);
void runTimer (int seconds);
void alert(int times);
void usage();

int main(int argc, char *argv[]){
    int seconds = 0;

    if (argc <= 1){
        usage();
        return 1;
    }

    if (argc == 2){
        seconds = checkArgument(argv[1]);
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

int checkArgument(char* input){
    int seconds = atoi(input);
    if (strcmp(input,"-p") == 0 )
        seconds = promptTimer(input);
    else
        seconds = atoi(input);

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

