#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/timer.h"

#define MAX_COMMAND_LENGTH 1024
#define WINDOWS_NULL_OUTPUT " > nul 2>&1"
#define UNIX_NULL_OUTPUT " >/dev/null 2>&1"

void checkForHomeFolderPath(char* filePath){
    if (filePath[0] == '~'){
        char fullPath[MAX_COMMAND_LENGTH];

        #if defined(__linux__) || defined(__APPLE__)
            snprintf(fullPath, MAX_COMMAND_LENGTH, "%s", getenv("HOME"));
        #elif defined(_WIN32)
            snprintf(fullPath, MAX_COMMAND_LENGTH, "%s%s", getenv("HOMEDRIVE"), getenv("HOMEPATH"));
        #endif

        strcat(fullPath, filePath);
        removeChar(fullPath,'~');
        strcpy(filePath,fullPath);
    }
}

void checkFileExists(char* programLocation){
    if (access(programLocation, F_OK) != 0) {
        printf("Error: File %s does not exist\n", programLocation);
        exit(1);
    }
}

void runProgram(char* programLocation, int silentOutput){
    char command[MAX_COMMAND_LENGTH];
    strcpy(command,programLocation);
    if (silentOutput)
        strcat(command,UNIX_NULL_OUTPUT);
    system(command);
}
