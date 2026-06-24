#include "../include/test_framework.h"
#include "../include/timer.h"

void test_execute_usage(void) {
  t_usage(0);
  TEST_START("usage can be activated");
  ASSERT_INT(1, 1);
}

TEST_LIST {
  TESTS_HEADER("usage function");
  test_execute_usage();
}

RUN_TESTS
