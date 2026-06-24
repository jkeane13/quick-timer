#include "../include/test_framework.h"
#include "../include/timer.h"

#define ENTRIES 6

char entryString[ENTRIES][7] = {"3:30",  "4am",    "10am",
                                "12:30", "5:30am", "12am"};
int expectInt[ENTRIES] = {3, 4, 10, 12, 5, 12};

char entryMinString[ENTRIES][7] = {"6:09", "7:30",  "12:23am",
                                   "12am", "11:34", "3pm"};
int expectMinInt[ENTRIES] = {9, 30, 23, 0, 34, 0};

void test_get_hour_of_entry(void) {
  for (int i = 0; i < ENTRIES; i++) {
    TEST_START("get hour from entry");
    ASSERT_INT(t_get_hour(entryString[i]), expectInt[i]);
  }
}

void test_get_minute_of_entry(void) {
  for (int i = 0; i < ENTRIES; i++) {
    TEST_START("get minute from entry");
    ASSERT_INT(t_get_minutes(entryMinString[i]), expectMinInt[i]);
  }
}

TEST_LIST {
  TESTS_HEADER("hour and minutes function");
  test_get_hour_of_entry();
  test_get_minute_of_entry();
}

RUN_TESTS
