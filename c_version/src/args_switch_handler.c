#include <string.h>
#include "../include/timer.h"

void runEndSwitch(char* argument, 
                  int *quietMode,
                  int *dryRunMode,
                  int *executeMode)
{
    if (strcmp(argument, "--quiet") == 0){
        *quietMode = 1;
    } else if (strcmp(argument, "--dry-run") == 0){
        *quietMode = 1;
        *dryRunMode = 1;
    } else if (strstr(argument, ".") != 0){
        *quietMode = 1;
        *executeMode = 1;
    }
}

