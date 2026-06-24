#include "../include/test_framework.h"
#include "../include/timer.h"

#define STR 10

char entryString[STR][STR] = {"13:30", "00:30", "08:00", "07:00", "07:30",
                              "19:30", "00:00", "00:30", "12:00", "12:30"};
char expectString[STR][STR] = {"1:30pm", "12:30am", "8am",  "7am",
                               "7:30am", "7:30pm",  "12am", "12:30am",
                               "12pm",   "12:30pm"};

void test_convert_24_hour_to_12_hour(void) {
  for (int i = 0; i < STR; i++) {
    t_convert_24_hour_clock_to_12(entryString[i]);
    TEST_START("convert 24 hour clock to 12 hour");
    ASSERT_STRING(entryString[i], expectString[i]);
  }
}

TEST_LIST {
  TESTS_HEADER("convert 24 hour clock to 12 hour");
  test_convert_24_hour_to_12_hour();
}

RUN_TESTS
