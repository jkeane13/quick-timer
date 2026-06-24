#include "../include/test_framework.h"
#include "../include/timer.h"

void test_timer_executes(void) {
  t_seconds_countdown(1);
  TEST_START("seconds countdown executes");
  ASSERT_INT(1, 1);
}

TEST_LIST {
  TESTS_HEADER("countdown seconds function");
  test_timer_executes();
}

RUN_TESTS
