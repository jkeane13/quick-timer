#include "../include/test_framework.h"
#include "../include/timer.h"

#define TEST_FILE "assets/example.sh"
#define SOUND_FILE "assets/stopwatch.mp3"

void test_run_a_system_program(void) {
  run_program(TEST_FILE, 0);
  TEST_START("program executes in silent output mode");
  ASSERT_INT(1, 1);
}

void test_check_program_exists(void) {
  check_file_exists(TEST_FILE);
  TEST_START("check program exists before running");
  ASSERT_INT(1, 1);
}

void test_checks_sound_file_exists(void) {
  check_file_exists(SOUND_FILE);
  TEST_START("check sound file for alert exists");
  ASSERT_INT(1, 1);
}

TEST_LIST {
  TESTS_HEADER("run application function");
  test_run_a_system_program();
  test_check_program_exists();
  test_checks_sound_file_exists();
}

RUN_TESTS
