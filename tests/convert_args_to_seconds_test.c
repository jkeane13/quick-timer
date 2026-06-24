#include "../include/test_framework.h"
#include "../include/timer.h"

void test_hour_mins_seconds(void) {
  int actual = convert_hours_mins_to_seconds(3, 2, 1);
  TEST_START("convert hours, minutes, seconds to seconds");
  ASSERT_INT(actual, 10921);
}

void test_args_sec_to_seconds(void) {
  int actual = t_convert_args_to_seconds("50");
  TEST_START("convert 50 seconds string argument to seconds");
  ASSERT_INT(actual, 50);
}

void test_args_min_to_seconds(void) {
  char min_args[] = "2 50";
  int actual = t_convert_args_to_seconds(min_args);
  TEST_START("convert 2 minutes and 50 seconds string argument to seconds");
  ASSERT_INT(actual, 170);
}

void test_args_hour_to_seconds(void) {
  char hour_args[] = "1 12 50";
  int actual = t_convert_args_to_seconds(hour_args);
  TEST_START("convert 1 hour, 12 minutes and 50 seconds to seconds");
  ASSERT_INT(actual, 4370);
}

TEST_LIST {
  TESTS_HEADER("convert arguments to seconds");
  test_hour_mins_seconds();
  test_args_sec_to_seconds();
  test_args_min_to_seconds();
  test_args_hour_to_seconds();
}

RUN_TESTS
