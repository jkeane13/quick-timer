#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/timer.h"

int t_get_current_hour_number(){
  struct tm *now_time;
  time_t current_time = time(NULL);
  now_time = localtime(&current_time);

  return now_time->tm_hour;
}

int t_get_current_minute_number(){
  struct tm *now_time;
  time_t current_time = time(NULL);
  now_time = localtime(&current_time);

  return now_time->tm_min;
}

void t_convert_quick_clock_to_24(char* input_time){
  int current_hour = t_get_current_hour_number();
  int current_minute = t_get_current_minute_number();
  int end_hour = t_get_hour(input_time);
  int end_minute = t_get_minutes(input_time);

  if (current_hour > end_hour && current_hour < (end_hour + 12))
    end_hour += 12;

  if (current_hour == end_hour || current_hour == (end_hour + 12 )
      && current_minute < end_minute)
    end_hour += 12;

  if (end_hour == 24)
    end_hour = 0;

  snprintf(input_time, CLOCK_24_SIZE, "%02d:%02d", end_hour, end_minute);
}
