#include <string.h>
#include "../include/timer.h"

#define ALERT_TIMES 3
#define DISPLAY_OUTPUT 0
#define SOUND_FILE "~/.local/assets/stopwatch.mp3"
#define MAX_PATH_STRING 1024

int main(int argc, char *argv[]){
    int quietMode = 0, dryRunMode = 0, programMode = 0;
    int seconds = 0;
    char timeString[20] = "";
    char argSwitch[MAX_PATH_STRING] = "";
    char soundFilePath[MAX_PATH_STRING];
    strcpy(soundFilePath,SOUND_FILE);
    checkForHomeFolderPath(soundFilePath);

    if (argc <= 1 || argc > 5){
        usage(1);
        return 1;
    }

    if (strstr(argv[argc-1],"--") != 0 || strstr(argv[argc-1],".") !=0){
        strcat(argSwitch,argv[argc-1]);
        runEndSwitch(argSwitch, &quietMode, &dryRunMode, &programMode);
        argc = argc - 1;
    }

    if (programMode)
        checkFileExists(argSwitch);

    checkFileExists(soundFilePath);

    for (int i = 1; i < argc; i++){
        strcat(timeString, argv[i]);
        strcat(timeString, " ");
    }

    seconds = convertArgsToSeconds(timeString);

    printTimerEndTime(seconds);
    if (dryRunMode == 0)
        secondsCountdown(seconds);

    if (quietMode == 0)
        playSound(soundFilePath,ALERT_TIMES);

    if (programMode)
        runProgram(argSwitch, DISPLAY_OUTPUT);
}
