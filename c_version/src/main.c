#include <stdio.h>
#include <string.h>
#include "../include/timer.h"

#define ALERT_TIMES 1
#define DISPLAY_OUTPUT 0

int main(int argc, char *argv[]){
    int quietMode = 0;
    int dryRunMode = 0;
    int programMode = 0;
    int quickClock = 0;
    int seconds = 0;
    char timeString[20] = "";
    char argSwitch[256] = "";
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
        secondsCountdown(seconds, quickClock);

    if (quietMode == 0)
        playSound(ALERT_TIMES);

    if (programMode)
        runProgram(argSwitch, DISPLAY_OUTPUT);
}

