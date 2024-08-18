#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "timer.h"

#define ALERT_TIMES 1
#define NOISY true

void usage();

int main(int argc, char *argv[]){
    int seconds = 0;
    char* input = argv[1];
    if (argc <= 1){
        usage();
        return 1;
    }

    if (argc == 2){
        seconds = checkArgument(input);
    }

    if (argc == 3){
        seconds = convertArgsToSeconds("", argv[1], argv[2]);
    }

    if (argc == 4){
        seconds = convertArgsToSeconds(argv[1], argv[2], argv[3]);
    }

    if (argc > 4){
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

