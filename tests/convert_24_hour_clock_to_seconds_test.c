#include "../include/test_framework.h"
#include "../include/timer.h"

void test_convert_321_hours_mins_to_seconds(void) {
  int actual = convert_hours_mins_to_seconds(3, 2, 1);
  TEST_START("convert 3 hours, 2 mins and 1 second to seconds");
  ASSERT_INT(actual, 10921);
}

TEST_LIST {
  TESTS_HEADER("24 hour clock to seconds conversion");
  test_convert_321_hours_mins_to_seconds();
}

RUN_TESTS
