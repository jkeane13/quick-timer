#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "../include/timer.h"

void secondsCountdown (int seconds){
   struct tm *endTimeInfo;
   time_t endTime = time(NULL) + seconds;
   printf("\n");

   int timeDifference =  endTime - time(NULL);

   while(timeDifference > 1){
       timeDifference =  endTime - time(NULL);
       int h = seconds / 3600;
       int m = (seconds  % 3600) / 60;
       int s = seconds  % 60;

       printf ("\r%02d:%02d:%02d", h, m, s);
       fflush(stdout);
       sleep(1);
       seconds--;
   }
   printf("Time's up!\n");
}

