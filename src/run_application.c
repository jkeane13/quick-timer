#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../include/timer.h"

#define AF_PLAYER "afplay"
#define MPG_PLAYER "mpg123"
#define MAX_COMMAND_LENGTH 1024
#define WINDOWS_NULL_OUTPUT " > nul 2>&1"
#define UNIX_NULL_OUTPUT " >/dev/null 2>&1"

void replaceChar(char* str, char find, char replace){
    char *current_pos = strchr(str,find);
    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
}

void removeChar(char *str, char keyCharacter) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != keyCharacter) dst++;
    }
    *dst = '\0';
}

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
