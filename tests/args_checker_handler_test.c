#include "../include/test_framework.h"
#include "../include/timer.h"

void test_check_if_argument_can_be_added(void) {
  int actual = t_check_argument("?");
  TEST_START("check if argument can be added");
  ASSERT_INT(actual, 42);
}

TEST_LIST {
  TESTS_HEADER("argument handler");
  test_check_if_argument_can_be_added();
}

RUN_TESTS
