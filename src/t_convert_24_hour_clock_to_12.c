#include "../include/timer.h"
#include <stdio.h>
#include <string.h>

void t_convert_24_hour_clock_to_12(char *clock_time) {
  char clock_suffix;
  int hour, minutes;
  char temp_buffer[MAX_CLOCK_12H];

  hour = t_get_hour(clock_time);
  minutes = t_get_minutes(clock_time);

  if (hour < HOURS_IN_HALF_DAY)
    clock_suffix = 'a';
  else {
    clock_suffix = 'p';
  }

  hour = hour % HOURS_IN_HALF_DAY;

  if (hour == 0)
    hour = HOURS_IN_HALF_DAY;

  if (minutes == 0)
    snprintf(temp_buffer, sizeof(temp_buffer), "%d%cm", hour, clock_suffix);
  else
    snprintf(temp_buffer, sizeof(temp_buffer), "%d:%02d%cm", hour, minutes,
             clock_suffix);

  strncpy(clock_time, temp_buffer, MAX_CLOCK_12H - 1);
  clock_time[MAX_CLOCK_12H - 1] = '\0';
}
