#include "../include/test_framework.h"
#include "../include/timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char test_config_file[] = "/tmp/test_timer_config.cfg";
char sound_file[MAX_STRING];
char alert_times[MAX_STRING];

void setup_test_config(void) {
  FILE *f = fopen(test_config_file, "w");
  fprintf(f, "sound_file=/path/to/sound.mp3\n");
  fprintf(f, "alert_times=5,10,60\n");
  fclose(f);
}

void cleanup_test_config(void) {
  unlink(test_config_file);
}

void test_read_sound_file_from_config(void) {
  setup_test_config();

  t_get_config_from_file(test_config_file, sound_file, alert_times);

  TEST_START("config file parses sound file path");
  ASSERT_STRING(sound_file, "/path/to/sound.mp3");

  cleanup_test_config();
}

void test_read_alert_times_from_config(void) {
  setup_test_config();

  t_get_config_from_file(test_config_file, sound_file, alert_times);

  TEST_START("config file parses alert times");
  ASSERT_STRING(alert_times, "5,10,60");

  cleanup_test_config();
}

TEST_LIST {
  TESTS_HEADER("config file parsing");
  test_read_sound_file_from_config();
  test_read_alert_times_from_config();
}

RUN_TESTS
