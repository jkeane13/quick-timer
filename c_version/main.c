#include <stdio.h>
#include <stdbool.h>
#include "timer.h"

#define ALERT_TIMES 1

void usage();

int main(int argc, char *argv[]){
    bool quietMode = false;
    bool dryRunMode = false;
    int seconds = 0;
    if (argc <= 1){
        usage();
        return 1;
    }

    switch (argc){
        case 2:
            seconds = convertHoursMinsToSeconds("", "", argv[1]);
            break;
        case 3:
            checkforEndSwitch(argv[2], &quietMode, &dryRunMode);
            if (quietMode == true || dryRunMode == true)
                seconds = convertHoursMinsToSeconds("", "", argv[1]);
            else
                seconds = convertHoursMinsToSeconds("", argv[1], argv[2]);
            break;
        case 4:
            checkforEndSwitch(argv[3], &quietMode, &dryRunMode);
            if (quietMode == true || dryRunMode == true)
                seconds = convertHoursMinsToSeconds("", argv[1], argv[2]);
            else
                seconds = convertHoursMinsToSeconds(argv[1], argv[2], argv[3]);
            break;
        case 5:
            checkforEndSwitch(argv[4], &quietMode, &dryRunMode);
            if (quietMode == true || dryRunMode == true)
                seconds = convertHoursMinsToSeconds(argv[1], argv[2], argv[3]);
            else{
                usage();
                return 1;
            }
            break;
        default:
            usage();
            return 1;
    }
    runTimer(seconds, dryRunMode);
    alert(ALERT_TIMES, quietMode);
}

void usage(void){
    printf("usage: timer [number code] [switch]                \n"
           "                                                   \n"
           "Enter in time code in \'hour minute second\' format\n"
           "                                                   \n"
           "                                                   \n"
           "-p              prompt time input                  \n"
           "--quiet         Doesn't play the alert             \n"
           "                                                   \n"
           "Example: One hour, 2 minutes and 3 seconds timer   \n"
           "timer 1 2 3                                        \n");
}

