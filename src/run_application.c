#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/timer.h"

#define AF_PLAYER "afplay"
#define MPG_PLAYER "mpg123"
#define MAX_COMMAND_LENGTH 256
#define UNIX_TAIL " assets/duck_quack.mp3"
#define WINDOWS_TAIL " assets\\duck_quack.mp3"
#define WINDOWS_NULL_OUTPUT " > nul 2>&1"
#define UNIX_NULL_OUTPUT " >/dev/null 2>&1"

void playSound(int times){
    char soundCommand[MAX_COMMAND_LENGTH];

    #if defined(__APPLE__)
        strcpy (soundCommand, AF_PLAYER);
    #endif
    #if defined(__linux__) || (__WIN32)
        strcpy (soundCommand, MPG_PLAYER);
    #endif
    #if defined(__linux__) || defined(__APPLE__)
        strcat(soundCommand,UNIX_TAIL);
        strcat(soundCommand,UNIX_NULL_OUTPUT);
    #elif defined(_WIN32)
        strcat(soundCommand,WINDOWS_TAIL);
        strcat(soundCommand,WINDOWS_NULL_OUTPUT);
    #endif

    for (int i = 0; i < times; i++)
        system(soundCommand);
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
