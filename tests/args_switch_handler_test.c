#include "../include/test_framework.h"
#include "../include/timer.h"

int quiet_mode = 0, dry_run_mode = 0, execute_mode = 0;

void test_quiet_mode(void) {
  quiet_mode = 0;
  dry_run_mode = 0;
  execute_mode = 0;
  t_set_mode_switch("--quiet", &quiet_mode, &dry_run_mode, &execute_mode);
  TEST_START("quiet mode can be turned on");
  ASSERT_INT(quiet_mode, 1);
}

void test_dry_run_mode(void) {
  quiet_mode = 0;
  dry_run_mode = 0;
  execute_mode = 0;
  t_set_mode_switch("--dry-run", &quiet_mode, &dry_run_mode, &execute_mode);
  TEST_START("dry run mode turned on with quiet mode");
  ASSERT_INT(quiet_mode + dry_run_mode, 2);
}

void test_execute_mode(void) {
  quiet_mode = 0;
  dry_run_mode = 0;
  execute_mode = 0;
  t_set_mode_switch(".", &quiet_mode, &dry_run_mode, &execute_mode);
  TEST_START("execute mode turned on for files with '.' in them");
  ASSERT_INT(quiet_mode + execute_mode, 2);
}

TEST_LIST {
  TESTS_HEADER("argument switches");
  test_quiet_mode();
  test_dry_run_mode();
  test_execute_mode();
}

RUN_TESTS
