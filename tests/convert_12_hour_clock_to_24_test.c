#include "../include/test_framework.h"
#include "../include/timer.h"

#define STR 8

char entryString[STR][STR] = {"7am",    "12am",    "12pm",   "7pm",
                              "7:30am", "12:30am", "7:30pm", "12:30pm"};
char expectString[STR][STR] = {"07:00", "00:00", "12:00", "19:00",
                               "07:30", "00:30", "19:30", "12:30"};

void test_convert_time_am_pm_to_24(void) {
  for (int i = 0; i < STR; i++) {
    t_convert_input_clock_to_24(entryString[i]);
    TEST_START("convert 12 hour clock to 24 hour");
    ASSERT_STRING(entryString[i], expectString[i]);
  }
}

TEST_LIST {
  TESTS_HEADER("convert 12 hour clock to 24 hour");
  test_convert_time_am_pm_to_24();
}

RUN_TESTS
