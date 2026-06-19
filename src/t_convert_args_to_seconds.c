#include "../include/timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t_convert_args_to_seconds(char *arg) {
  int hourminsec[] = {0, 0, 0};
  int item_count = 0;
  char command_string[10];
  int temp;
  char *token = strtok(arg, " ");

  while (token) {
    hourminsec[item_count] = atoi(token);
    item_count++;
    token = strtok(NULL, " ");
  }

  if (item_count == 1) {
    hourminsec[2] = hourminsec[0];
    hourminsec[0] = 0;
    snprintf(command_string, sizeof(command_string), "%d", hourminsec[2]);
    hourminsec[2] = t_check_argument(arg);
  }

  if (item_count == 2) {
    temp = hourminsec[0];
    hourminsec[0] = 0;
    hourminsec[2] = hourminsec[1];
    hourminsec[1] = temp;
  }

  return convert_hours_mins_to_seconds(hourminsec[0], hourminsec[1],
                                       hourminsec[2]);
}
