#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/timer.h"

#define AF_PLAYER "afplay"
#define MPG_PLAYER "mpg123"
#define MAX_COMMAND_LENGTH 256
#define UNIX_TAIL " ~/.local/assets/duck_quack.mp3 >/dev/null 2>&1"
#define WINDOWS_TAIL " \%userprofile\%\\.local\\assets\\duck_quack.mp3 >NUL 2>&1"
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
    #elif defined(_WIN32)
        strcat(soundCommand,WINDOWS_TAIL);
    #endif

    for (int i = 0; i < times; i++)
        system(soundCommand);
}

void runProgram(char* programLocation, int silentOutput){
    char command[MAX_COMMAND_LENGTH];
    if (access(programLocation, F_OK) != 0) {
        printf("Error: File doesn't exist");
        exit(1);
    }
    strcpy(command,programLocation);
    if (silentOutput)
        strcat(command,UNIX_NULL_OUTPUT);
    system(command);
}
