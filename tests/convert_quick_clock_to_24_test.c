#include "../include/test_framework.h"
#include "../include/timer.h"
#include <string.h>

char input_string[MAX_STRING], expect_string[MAX_STRING];

void test_convert_7_quick_clock_to_24(void) {
  strcpy(input_string, "7:00");
  t_convert_quick_clock_to_24(input_string);
  if (t_get_current_hour_number() <= 7)
    strcpy(expect_string, "19:00");
  if (t_get_current_hour_number() >= 19)
    strcpy(expect_string, "07:00");
  if (t_get_current_hour_number() >= 7 && t_get_current_minute_number() > 1)
    strcpy(expect_string, "19:00");
  if (t_get_current_hour_number() >= 19 && t_get_current_minute_number() > 1)
    strcpy(expect_string, "07:00");

  TEST_START("convert 7 quick clock to 7:00 or 19:00");
  ASSERT_STRING(input_string, expect_string);
}

void test_convert_12_quick_clock_to_24(void) {
  strcpy(input_string, "12:00");
  t_convert_quick_clock_to_24(input_string);
  if (t_get_current_hour_number() > 12 && t_get_current_hour_number() < 24)
    strcpy(expect_string, "00:00");
  if (t_get_current_hour_number() < 12)
    strcpy(expect_string, "12:00");
  if (t_get_current_hour_number() == 12 && t_get_current_minute_number() > 1)
    strcpy(expect_string, "00:00");
  if (t_get_current_hour_number() == 12 && t_get_current_minute_number() == 0)
    strcpy(expect_string, "12:00");

  TEST_START("convert 12 quick clock to 12:00 or 00:00");
  ASSERT_STRING(input_string, expect_string);
}

TEST_LIST {
  TESTS_HEADER("convert quick clock to 24 hour");
  test_convert_7_quick_clock_to_24();
  test_convert_12_quick_clock_to_24();
}

RUN_TESTS
