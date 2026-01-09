#include <string.h>
#include <stdlib.h>
#include "../include/timer.h"
#include "../include/get_timer_config.h"
#include "../include/complete_home_folder_path.h"

int main(int argc, char *argv[]){
    char soundFilePath[MAX_STRING], alertTimes[MAX_STRING];
    int quietMode = 0, dryRunMode = 0, programMode = 0;
    int seconds = 0;
    char timeString[20] = "";
    char argSwitch[MAX_STRING] = "";
    char configFile[MAX_STRING] = "~/.local/config/timer.cfg";

    completeHomeFolderPath(configFile);
    getConfigFromfileFile(configFile, soundFilePath, alertTimes);
    completeHomeFolderPath(soundFilePath);

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
        playSound(soundFilePath, atoi(alertTimes));

    if (programMode)
        runProgram(argSwitch, DISPLAY_OUTPUT);
}
