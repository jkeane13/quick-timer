#include <stdlib.h>
#include <stdio.h>
#include "../include/timer.h"

void getConfigFromfileFile(char* filename,
                           char* soundFilePath,
                           char* alertTimes){
    FILE *file = fopen(filename, "r");
    char configType[MAX_STRING];
    char line[MAX_STRING];

    if (file == NULL) {
        perror("Error opening configuration file");
        exit(-1);
    }

    fscanf(file, "%101[^=]=%101s", configType, soundFilePath);
    fgets(line, sizeof(line), file);
    fscanf(file, "%101[^=]=%101s", configType, alertTimes);
    fclose(file);
}
