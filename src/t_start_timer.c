#include "../include/timer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/play_audio.h"

int t_start_timer(int argc, char **argv){
  int quiet_mode = 0, dry_run_mode = 0, program_mode = 0;
  int seconds = 0;
  char time_string[MAX_STRING] = "";
  char arg_switch[MAX_STRING] = "";

  if (argc <= 1 || argc > 5) {
    t_usage(1);
    return 1;
  }

  if (strstr(argv[argc - 1], "--") != 0 || strstr(argv[argc - 1], ".") != 0) {
    size_t arg_len = strlen(argv[argc - 1]);
    if (arg_len >= MAX_STRING) {
      fprintf(stderr, "Error: argument too long (max %d bytes)\n", MAX_STRING - 1);
      return 1;
    }
    strncpy(arg_switch, argv[argc - 1], MAX_STRING - 1);
    arg_switch[MAX_STRING - 1] = '\0';
    t_set_mode_switch(arg_switch, &quiet_mode, &dry_run_mode, &program_mode);
    argc = argc - 1;
  }

  if (program_mode)
    check_file_exists(arg_switch);

  for (int i = 1; i < argc; i++) {
    size_t remaining = MAX_STRING - strlen(time_string) - 1;
    size_t arg_len = strlen(argv[i]);
    if (arg_len >= remaining) {
      fprintf(stderr, "Error: arguments too long (max %d bytes total)\n", MAX_STRING - 1);
      return 1;
    }
    strncat(time_string, argv[i], remaining);
    if (i < argc - 1)
      strncat(time_string, " ", MAX_STRING - strlen(time_string) - 1);
  }
  seconds = t_convert_args_to_seconds(time_string);
  t_print_timer_end_time(seconds);

  int cancelled = 0;
  if (dry_run_mode == 0)
    cancelled = t_seconds_countdown(seconds);

  if (cancelled == 0) {
    if (quiet_mode == 0)
      play_sound(ALERT_TIMES);

    if (program_mode)
      run_program(arg_switch, DISPLAY_OUTPUT);
  }



  return EXIT_SUCCESS;
}
