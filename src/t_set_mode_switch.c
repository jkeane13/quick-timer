#include "../include/timer.h"
#include <string.h>

void t_set_mode_switch(const char *arg, int *quiet_mode, int *dry_run_mode,
                       int *execute_mode) {
  *quiet_mode = 1;
  if (strcmp(arg, DRY_RUN_MODE_SWITCH) == 0) {
    *dry_run_mode = 1;
  } else if (strchr(arg, FILE_DIVIDER) != NULL) {
    *execute_mode = 1;
  }
}
