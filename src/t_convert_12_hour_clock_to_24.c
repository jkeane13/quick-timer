#include <stdio.h>
#include <string.h>
#include "../include/timer.h"

#define CLOCK_24_SIZE 6

static int convert_hour_am(int hour){
  if (hour == 12)
    return 0;
  else
    return hour;
}

static int convert_hour_pm(int hour){
  if (hour == 12)
    return 12;
  else
    return hour + 12;
}

void t_convert_12_hour_clock_to_24(char *time_input){
  int hour = t_get_hour(time_input);
  int minutes = t_get_minutes(time_input);
  size_t time_length = strlen(time_input);

  if (time_length < 2){
    return;
  }

  char suffix = time_input[time_length - 2];

  if (suffix == 'a')
    hour = convert_hour_am(hour);
  else if (suffix == 'p')
    hour = convert_hour_pm(hour);

  snprintf(time_input, MAX_STRING,"%02d:%02d", hour, minutes);
}

void t_convert_input_clock_to_24(char* time_input){
  size_t time_length = strlen(time_input);
  if (time_length < 3){
    return;
  }
  if (time_input[time_length -3] == TIME_SEPARATOR_ARGUMENT){
    t_convert_quick_clock_to_24(time_input);
  }else {
    t_convert_12_hour_clock_to_24(time_input);
  }
}

