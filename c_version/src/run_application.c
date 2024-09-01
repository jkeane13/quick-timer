#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/timer.h"

#define HOME_FOLDER_UNIX "~"
#define HOME_FOLDER_WINDOWS "\%userprofile\%"
#define UNIX_FILENAME ".local/assets/duck_quack.mp3"
#define WIN_FILENAME ".local\\assets\\duck_quack.mp3"
#define MAC_PLAYER "afplay"
#define WIN_PLAYER "mpg123"
#define LINUX_PLAYER "mpg123"
#define MAX_COMMAND_LENGTH 100
#define UNIX_NULL_OUTPUT " >/dev/null 2>&1"
#define WIN_NULL_OUTPUT " >NUL 2>&1"

void playSound(int times){
    char soundCommand[MAX_COMMAND_LENGTH];
    char homeFolder[MAX_COMMAND_LENGTH];
    char unixSeparator = '/';
    char winSeparator = '\\';

    #if defined(__APPLE__)
        strcpy (soundCommand, MAC_PLAYER);
    #endif
    #if defined(__linux__)
        strcpy (soundCommand, LINUX_PLAYER);
    #endif

    #if defined(__linux__) || defined(__APPLE__)
        strcat (soundCommand," ");
        strcat (soundCommand, HOME_FOLDER_UNIX);
        strncat (soundCommand, &unixSeparator, 1);
        strcat (soundCommand,UNIX_FILENAME);
        strcat (soundCommand,UNIX_NULL_OUTPUT);
    #elif defined(_WIN32)
        strcpy (soundCommand, WIN_PLAYER);
        strcat (soundCommand," ");
        strcat (soundCommand, HOME_FOLDER_WINDOWS);
        strncat (soundCommand, &winSeparator, 1);
        strcat (soundCommand,WIN_FILENAME);
        strcat (soundCommand,WIN_NULL_OUTPUT);
    #endif

    for (int i = 0; i < times; i++)
        system(soundCommand);
}

void runProgram(char* programLocation, int silentOutput){
    char command[256];
    if (access(programLocation, F_OK) != 0) {
        printf("Error: File doesn't exist");
        exit(1);
    }
    strcpy(command,programLocation);
    if (silentOutput)
        strcat(command,UNIX_NULL_OUTPUT);
    system(command);
}
