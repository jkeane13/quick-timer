#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "../include/timer.h"

void secondsCountdown (int seconds, int quickClock){
   struct tm *endTimeInfo;
   time_t endTime = time(NULL) + seconds;

   int timeDifference =  endTime - time(NULL);
   if (quickClock == 1){
       int hours12 = (12 * 60 * 60);
       if (timeDifference > hours12)
           seconds -= hours12;
    }

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
   printf("\rTime's up!\n");
}

