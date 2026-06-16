#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "../include/timer.h"

void t_seconds_countdown (int seconds){
   time_t end_time = time(NULL) + seconds;

   int time_difference = end_time - time(NULL);

   while(time_difference > 0){
       time_difference = end_time - time(NULL);
       int h = time_difference / SECONDS_IN_HOUR;
       int m = (time_difference % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;
       int s = time_difference % SECONDS_IN_MINUTE;

       printf("\r%02d:%02d:%02d", h, m, s);
       fflush(stdout);
       sleep(1);
   }
   printf("\rTime's up!\n");
}

