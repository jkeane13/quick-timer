#include <stdio.h>
#include <stdbool.h>
#include "timer.h"

#define ALERT_TIMES 1
#define NOISY true

void usage();

int main(int argc, char *argv[]){
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
            seconds = convertHoursMinsToSeconds("", argv[1], argv[2]);
            break;
        case 4:
            seconds = convertHoursMinsToSeconds(argv[1], argv[2], argv[3]);
            break;
        default:
            usage();
            return 1;
    }

    runTimer(seconds);
    alert(ALERT_TIMES, NOISY);
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

