#include "../include/timer.h"
#include <stdlib.h>
#include <string.h>

int t_check_argument(char *input) {
  if (strcmp(input, PROMPT_TIME_SWITCH) == 0) {
    return t_prompt_time_input(0);
  }

  if (strchr(input, AM_PM_ARGUMENT) != NULL ||
      strchr(input, TIME_SEPARATOR_ARGUMENT) != NULL) {
    t_convert_input_clock_to_24(input);
    return t_convert_24_clock_to_seconds(input);
  }

  if (strchr(input, TEST_CHARACTER) != NULL) {
    return RANDOM_TEST_VALUE;
  }

  return atoi(input);
}
