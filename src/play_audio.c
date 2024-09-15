#include <stdlib.h>
#include <string.h>
#include "../include/timer.h"

#define AF_PLAYER "afplay"
#define MPG_PLAYER "mpg123"
#define MAX_COMMAND_LENGTH 1024
#define WINDOWS_NULL_OUTPUT " > nul 2>&1"
#define UNIX_NULL_OUTPUT " >/dev/null 2>&1"

void playSound(char *soundFile, int times){
    char soundCommand[MAX_COMMAND_LENGTH];

    #if defined(__APPLE__)
        strcpy (soundCommand, AF_PLAYER);
    #endif
    #if defined(__linux__) || (__WIN32)
        strcpy (soundCommand, MPG_PLAYER);
    #endif

    strcat (soundCommand, " ");
    strcat(soundCommand,soundFile);

    #if defined(__linux__) || defined(__APPLE__)
        strcat(soundCommand,UNIX_NULL_OUTPUT);
    #elif defined(_WIN32)
        strcat(soundCommand,WINDOWS_NULL_OUTPUT);
        replaceChar(soundCommand, '/', '\\');
    #endif

    for (int i = 0; i < times; i++)
        system(soundCommand);
}
