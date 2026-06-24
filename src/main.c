#include "../include/complete_home_folder_path.h"
#include "../include/timer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/play_audio.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main(int argc, char *argv[]) {
#ifdef _WIN32
  SetConsoleCP(65001);
  SetConsoleOutputCP(65001);
#endif
  char sound_file_path[MAX_STRING], alert_times[MAX_STRING];
  int quiet_mode = 0, dry_run_mode = 0, program_mode = 0;
  int seconds = 0;
  char time_string[MAX_STRING] = "";
  char arg_switch[MAX_STRING] = "";
  char config_file[MAX_STRING] = TIMER_CONFIGURATION_FILE;

  complete_home_folder_path(config_file);
  t_get_config_from_file(config_file, sound_file_path, alert_times);
  complete_home_folder_path(sound_file_path);

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

  check_file_exists(sound_file_path);

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
      play_sound(sound_file_path, atoi(alert_times));

    if (program_mode)
      run_program(arg_switch, DISPLAY_OUTPUT);
  }

  return EXIT_SUCCESS;
}
