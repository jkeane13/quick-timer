#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define UNIX_NULL_OUTPUT " >/dev/null 2>&1"

void check_file_exists(char* program_location){
    if (access(program_location, F_OK) != 0) {
        printf("Error: File %s does not exist\n", program_location);
        exit(1);
    }
}

void run_program(char* program_location, int silent_output){
    char command[MAX_COMMAND_LENGTH];
    strcpy(command,program_location);
    if (silent_output)
        strcat(command,UNIX_NULL_OUTPUT);
    system(command);
}
