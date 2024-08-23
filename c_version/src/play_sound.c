#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
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

void alert(int times, bool quietMode);

// Not Tested
void alert(int times, bool quietMode){
    int i;
    char soundCommand[MAX_COMMAND_LENGTH];
    char homeFolder[MAX_COMMAND_LENGTH];
    char unixSeparator = '/';
    char winSeparator = '\\';

    printf("\rTime's up!\n");
    if (quietMode == true)
        exit(0);

    for (i = 0; i < times; i++){
        #if defined(__APPLE__)
            strcpy (soundCommand, MAC_PLAYER);
            strcat (soundCommand," ");
            strcat (soundCommand, HOME_FOLDER_UNIX);
            strncat (soundCommand, &unixSeparator, 1);
            strcat (soundCommand,UNIX_FILENAME);
            strcat (soundCommand,UNIX_NULL_OUTPUT);
            system(soundCommand);
        #elif defined(__linux__)
            strcpy (soundCommand, LINUX_PLAYER);
            strcat (soundCommand," ");
            strcat (soundCommand, HOME_FOLDER_UNIX);
            strncat (soundCommand, &unixSeparator, 1);
            strcat (soundCommand,UNIX_FILENAME);
            strcat (soundCommand,UNIX_NULL_OUTPUT);
            system(soundCommand);
        #elif defined(_WIN32)
            strcpy (soundCommand, WIN_PLAYER);
            strcat (soundCommand," ");
            strcat (soundCommand, HOME_FOLDER_WINDOWS);
            strncat (soundCommand, &winSeparator, 1);
            strcat (soundCommand,WIN_FILENAME);
            strcat (soundCommand,WIN_NULL_OUTPUT);
            system(soundCommand);
        #endif
    }
}

