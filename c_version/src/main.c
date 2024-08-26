#include <stdio.h>
#include <string.h>
#include "../include/timer.h"

#define ALERT_TIMES 1

void usage();

int main(int argc, char *argv[]){
    int quietMode = 0;
    int dryRunMode = 0;
    int programMode = 0;
    int seconds = 0;
    char timeString[20] = "";
    char argSwitch[20] = "";
    if (argc <= 1 || argc > 5){
        usage();
        return 1;
    }

    if (strstr(argv[argc-1],"--") != 0 || strstr(argv[argc-1],".") !=0){
        strcat(argSwitch,argv[argc-1]);
        runEndSwitch(argSwitch, &quietMode, &dryRunMode, &programMode);
        argc = argc - 1;
    }

    for (int i = 1; i < argc; i++){
        strcat(timeString, argv[i]);
        strcat(timeString, " ");
    }

    seconds = convertArgsToSeconds(timeString);

    printTimerEndTime(seconds);
    if (dryRunMode == 0)
        secondsCountdown(seconds);

    if (quietMode == 0)
        alert(ALERT_TIMES);

    if (programMode)
        runProgram(argSwitch);
}

void usage(void){
    printf("usage:\n"
           "Countdown to the second, minute or hour,  or by a clock time\n"
           "                                                            \n"
           "timer [seconds]                                             \n"
           "timer [minutes] [seconds]                                   \n"
           "timer [hours] [minutes] [seconds]                           \n"
           "timer [clockAM/PM]                                          \n"
           "timer -p                                                    \n"
           "                                                            \n"
           "Switches                                                    \n"
           "-p              prompt time input                           \n"
           "--quiet         Doesn't play the alert                      \n"
           "--dry-run         Doesn't play the alert                    \n"
           "                                                            \n"
           "EXAMPLE: 2 hours, 10 minutes, 1 second                      \n"
           "timer 2 10 1                                                \n"
           "                                                            \n"
           "EXAMPLE: Timer for 5:30 24 hours                            \n"
           "timer 5:30                                                  \n"
           "                                                            \n"
           "EXAMPLE: Timer for 5:30am 12 hour clock                     \n"
           "timer 5:30am                                                \n"
           "                                                            \n"
           "EXAMPLE: Timer for 5pm 12 hour clock                        \n"
           "timer 5pm                                                   \n"
           "                                                            \n"
           );
}
