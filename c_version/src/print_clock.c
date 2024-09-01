#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <time.h>
#include "../include/timer.h"

#define UNIX_NULL_OUTPUT " >/dev/null 2>&1"


void printSecondsEndAsClock(int seconds, char* clockType){
   struct tm *endTimeInfo;
   time_t endTime = time(NULL) + seconds;

   endTimeInfo = localtime(&endTime);

   char minString[3];
   char hourString[3];
   char outputString[10];

   convertIntToDoubleString(endTimeInfo->tm_hour, hourString);
   convertIntToDoubleString(endTimeInfo->tm_min, minString);

   strcpy(outputString,hourString);
   strcat(outputString,":");
   strcat(outputString,minString);

   if (strcmp(clockType,"24Hour") != 0 )
       convert24ClockTo12(outputString);

   printf("%s\n", outputString);
}

void printTimerEndTime (int seconds){
   printf("Timer ends at ");
   printSecondsEndAsClock(seconds,"12Hour");
}

