#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../include/timer.h"

void printSecondsEndAsClock(int seconds, char* clockType){
   struct tm *endTimeInfo;
   time_t endTime = time(NULL) + seconds;

   endTimeInfo = localtime(&endTime);

   char output[7];

   sprintf(output,"%02d:%02d", endTimeInfo->tm_hour, endTimeInfo->tm_min);

   if (strcmp(clockType,"24Hour") != 0)
       convert24ClockTo12(output);

   printf("%s\n", output);

}

void printTimerEndTime (int seconds){
   printf("Timer ends at ");
   printSecondsEndAsClock(seconds,"12Hour");
}

