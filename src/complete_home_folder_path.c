#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/timer.h"
#define MAX_COMMAND_LENGTH 1024

void completeHomeFolderPath(char* filePath){
    if (filePath[0] == '~'){
        char fullPath[MAX_COMMAND_LENGTH];

        #if defined(__linux__) || defined(__APPLE__)
            snprintf(fullPath, MAX_COMMAND_LENGTH, "%s", getenv("HOME"));
        #elif defined(_WIN32)
            snprintf(fullPath, MAX_COMMAND_LENGTH, "%s%s",
                    getenv("HOMEDRIVE"),
                    getenv("HOMEPATH"));
        #endif

        strcat(fullPath, filePath);
        removeChar(fullPath,'~');
        strcpy(filePath,fullPath);
    }
}
