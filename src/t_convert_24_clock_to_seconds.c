#include "../include/timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. STRUCTURAL PATTERN CHECK ONLY
static void validate_24_clock_format(const char *input) {
  if (input[0] < '0' || input[0] > '2' || input[1] < '0' || input[1] > '9' ||
      input[2] != ':' || input[3] < '0' || input[3] > '5' || input[4] < '0' ||
      input[4] > '9' || input[5] != '\0') {
    fprintf(stderr, "Format needs to be 24 hour time - HH:MM\n");
    exit(1);
  }
}

// 2. PURE PARSING ONLY (Assumes input format is already verified)
static void parse_time_chars(const char *input, int *hour, int *minute) {
  *hour = (input[0] - '0') * 10 + (input[1] - '0');
  *minute = (input[3] - '0') * 10 + (input[4] - '0');
}

// 3. PURE VALUE VALIDATION ONLY
static int is_valid_time_range(int hour, int minute) {
  if (hour > 23 || minute > 59) {
    return INVALID;
  }
  return VALID;
}

static void get_current_local_time(struct tm *result) {
  time_t current_time = time(NULL);
  struct tm *tmp = localtime(&current_time);
  *result = *tmp;
}

int t_convert_24_clock_to_seconds(const char *input) {
  int target_hour, target_minute;
  struct tm now_time;

  validate_24_clock_format(input);
  parse_time_chars(input, &target_hour, &target_minute);
  if (is_valid_time_range(target_hour, target_minute) == INVALID) {
    fprintf(stderr, "Invalid hour or minute range\n");
    exit(EXIT_FAILURE);
  }

  get_current_local_time(&now_time);

  int current_day_seconds = (now_time.tm_hour * SECONDS_IN_HOUR) +
                            (now_time.tm_min * SECONDS_IN_MINUTE) +
                            now_time.tm_sec;

  int target_day_seconds =
      (target_hour * SECONDS_IN_HOUR) + (target_minute * SECONDS_IN_MINUTE);

  int seconds_difference = target_day_seconds - current_day_seconds;
  if (seconds_difference < 0) {
    seconds_difference += SECONDS_IN_DAY;
  }
  return seconds_difference;
}
