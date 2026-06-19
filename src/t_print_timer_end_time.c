#include "../include/timer.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

static void print_seconds_end_as_clock(int seconds, char *clock_type) {
  struct tm *endTimeInfo;
  time_t endTime = time(NULL) + seconds;

  endTimeInfo = localtime(&endTime);

  char output[MAX_CLOCK_12H];

  sprintf(output, "%02d:%02d", endTimeInfo->tm_hour, endTimeInfo->tm_min);

  if (strcmp(clock_type, "24Hour") != 0)
    t_convert_24_hour_clock_to_12(output);

  printf("%s\n", output);
}

void t_print_timer_end_time(int seconds) {
  printf("Timer ends at ");
  print_seconds_end_as_clock(seconds, "12Hour");
}
