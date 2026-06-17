#include <string.h>
#include <stdlib.h>
#include "../include/timer.h"
#include "../include/get_timer_config.h"
#include "../include/complete_home_folder_path.h"

int main(int argc, char *argv[]){
    char soundFilePath[MAX_STRING], alertTimes[MAX_STRING];
    int quietMode = 0, dryRunMode = 0, programMode = 0;
    int seconds = 0;
    char timeString[MAX_STRING] = "";
    char argSwitch[MAX_STRING] = "";
    char configFile[MAX_STRING] = "~/.local/config/timer.cfg";

    complete_home_folder_path(configFile);
    getConfigFromfileFile(configFile, soundFilePath, alertTimes);
    complete_home_folder_path(soundFilePath);

    if (argc <= 1 || argc > 5){
        usage(1);
        return 1;
    }

    if (strstr(argv[argc-1],"--") != 0 || strstr(argv[argc-1],".") !=0){
        strncpy(argSwitch,argv[argc-1], MAX_STRING - 1);
        argSwitch[MAX_STRING - 1] = '\0';
        t_set_mode_switch(argSwitch, &quietMode, &dryRunMode, &programMode);
        argc = argc - 1;
    }

    if (programMode)
        checkFileExists(argSwitch);

    checkFileExists(soundFilePath);

    for (int i = 1; i < argc; i++){
        strncat(timeString, argv[i], MAX_STRING - strlen(timeString) - 1);
        strncat(timeString, " ", MAX_STRING - strlen(timeString) - 1);
    }
    seconds = t_convert_args_to_seconds(timeString);
    printTimerEndTime(seconds);

    int cancelled = 0;
    if (dryRunMode == 0)
        cancelled = t_seconds_countdown(seconds);

    if (cancelled == 0) {
        if (quietMode == 0)
            playSound(soundFilePath, atoi(alertTimes));

        if (programMode)
            runProgram(argSwitch, DISPLAY_OUTPUT);
    }

    return 0;
}
