#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/timer.h"

#define MAX_COMMAND_LENGTH 1024
#define WINDOWS_NULL_OUTPUT " > nul 2>&1"
#define UNIX_NULL_OUTPUT " >/dev/null 2>&1"

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
