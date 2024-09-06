#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/timer.h"

int getHour(char* timeInput){
    char hourString[2];
    for(int i = 0; i< strlen(timeInput); i++)
        if (isdigit(timeInput[i]))
           hourString[i] = timeInput[i]; 

    return atoi(hourString);
}

int getMinutes(char* timeInput){
    char minString[2];
    for(int i = 0; i< strlen(timeInput); i++)
        if (timeInput[i] == ':'){
           minString[0] = timeInput[i+1]; 
           minString[1] = timeInput[i+2]; 
        }

    if (strlen(minString) == 0)
        return 0;
    else
        return atoi(minString);
}

