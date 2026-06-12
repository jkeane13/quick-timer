#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/timer.h"

static int read_time_input(char* time_input){
  fgets(time_input, MAX_STRING, stdin);
  if (time_input[0] == '\n'){
    return 0;
  }

  return atoi(time_input);
}

int t_prompt_time_input(int seconds){
  char input[MAX_STRING];
  int hours, minutes;

  printf("Enter hours or clock time: ");
  hours = read_time_input(input);

  if (strchr(input, TIME_SEPARATOR_ARGUMENT) != NULL || strchr(input, AM_PM_ARGUMENT) != NULL){
    return t_check_argument(input);
  }

  printf("Enter minutes: ");
  minutes = read_time_input(input);
  printf("Enter seconds: ");
  seconds = read_time_input(input);

  if (hours != 0 && minutes != 0 && seconds != 0){
    printf("No time input\n");
    exit(EXIT_FAILURE);
  }

  return convert_hours_mins_to_seconds(hours, minutes, seconds);
}

