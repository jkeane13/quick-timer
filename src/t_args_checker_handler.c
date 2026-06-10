#include <stdlib.h>
#include <string.h>
#include "../include/timer.h"

int t_check_argument(char* input){
  if (strcmp(input,PROMPT_TIME_SWITCH) == 0 ){
    return promptTimeEnd(0);
  }

  if (strchr(input, AM_PM_ARGUMENT) != NULL || strchr(input, TIME_SEPARATOR_ARGUMENT) != NULL){
    convertInputClockto24(input);
    return convert24ClockToSeconds(input);
  }

  if (strchr(input, TEST_CHARACTER) != NULL){
    return RANDOM_TEST_VALUE;
  }

  return atoi(input);
}
