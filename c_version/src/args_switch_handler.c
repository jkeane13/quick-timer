#include <string.h>
#include "../include/timer.h"

void runEndSwitch(char* arg, int *quietMode, int *dryRunMode, int *executeMode)
{
    if (strcmp(arg, "--quiet") == 0){
        *quietMode = 1;
    } else if (strcmp(arg, "--dry-run") == 0){
        *quietMode = 1;
        *dryRunMode = 1;
    } else if (strstr(arg, ".") != 0){
        *quietMode = 1;
        *executeMode = 1;
    }
}

