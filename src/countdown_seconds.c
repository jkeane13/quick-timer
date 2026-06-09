#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "../include/timer.h"

void secondsCountdown (int seconds){
   time_t endTime = time(NULL) + seconds;

   int timeDifference = endTime - time(NULL);

   while(timeDifference > 0){
       timeDifference = endTime - time(NULL);
       int h = timeDifference / 3600;
       int m = (timeDifference % 3600) / 60;
       int s = timeDifference % 60;

       printf("\r%02d:%02d:%02d", h, m, s);
       fflush(stdout);
       sleep(1);
   }
   printf("\rTime's up!\n");
}

