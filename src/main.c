#include <string.h>
#include "../include/timer.h"
#include "../include/read_sound_config_file.h"

#define CONFIG_FILE "config/timer.cfg"
#define ALERT_TIMES 3
#define DISPLAY_OUTPUT 0
#define MAX_STRING 1024
#define MAX_PATH_STRING 1024

int main(int argc, char *argv[]){
    char soundFile[MAX_STRING];
    int quietMode = 0, dryRunMode = 0, programMode = 0;
    int seconds = 0;
    char timeString[20] = "";
    char argSwitch[MAX_PATH_STRING] = "";
    char soundFilePath[MAX_PATH_STRING];

    readSoundConfigFile(CONFIG_FILE, soundFile);
    strcpy(soundFilePath,soundFile);
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
