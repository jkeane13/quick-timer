#include <stdlib.h>
#include <stdio.h>

#define MAX_STRING 1024

void readSoundConfigFile(char* filename, char* soundFile){
    FILE *file = fopen(filename, "r");
    char configType[MAX_STRING];

    if (file == NULL) {
        perror("Error opening configuration file");
        exit(-1);
    }

    fscanf(file, "%101[^=]=%101s", configType, soundFile);
    fclose(file);
}

void readAlertConfigFile(char* filename, char* alertTimes){
    FILE *file = fopen(filename, "r");
    char configType[MAX_STRING];

    if (file == NULL) {
        perror("Error opening configuration file");
        exit(-1);
    }

    char line[MAX_STRING];

    fgets(line, sizeof(line), file);

    fscanf(file, "%101[^=]=%101s", configType, alertTimes);
    printf("Alert Times: %s\n", alertTimes);
    fclose(file);
}

