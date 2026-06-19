#include "../include/timer.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int t_get_hour(char *time_input) {
  char hour_string[3];
  int i = 0;
  for (; isdigit(time_input[i]); i++)
    hour_string[i] = time_input[i];

  if (i == 1)
    hour_string[1] = '\0';
  else
    hour_string[2] = '\0';

  return atoi(hour_string);
}

int t_get_minutes(char *time_input) {
  if (strchr(time_input, ':') == 0)
    return 0;

  char min_string[3];
  for (size_t i = 0; i < strlen(time_input); i++) {
    if (time_input[i] == ':') {
      min_string[0] = time_input[i + 1];
      min_string[1] = time_input[i + 2];
      min_string[2] = '\0';
    }
  }
  return atoi(min_string);
}
