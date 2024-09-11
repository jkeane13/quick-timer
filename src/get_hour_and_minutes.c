#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/timer.h"

int getHour(char* timeInput){
   char hourString[3];
   int i = 0;
   for(; isdigit(timeInput[i]); i++)
          hourString[i] = timeInput[i];

   if (i == 1)
       hourString[1] = '\0';
   else
       hourString[2] = '\0';

   return atoi(hourString);
}

int getMinutes(char* timeInput){
   if (strchr(timeInput,':') == 0)
       return 0;

   char minString[3];
   for(int i = 0; i< strlen(timeInput); i++){
       if (timeInput[i] == ':'){
          minString[0] = timeInput[i+1];
          minString[1] = timeInput[i+2];
          minString[2] = '\0';
       }
   }
   return atoi(minString);
}

