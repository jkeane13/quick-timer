#include "../include/test_framework.h"
#include "../include/timer.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char result_string[MAX_STRING];

void test_edge_case_zero_hours_minutes_seconds(void) {
  int seconds = convert_hours_mins_to_seconds(0, 0, 0);

  TEST_START("convert 0 hours, 0 minutes, 0 seconds edge case");
  ASSERT_INT(seconds, 0);
}

void test_edge_case_0_hours_0_minutes_59_seconds(void) {
  int seconds = convert_hours_mins_to_seconds(0, 0, 59);

  TEST_START("convert 0 hours, 0 minutes, 59 seconds boundary");
  ASSERT_INT(seconds, 59);
}

void test_edge_case_0_hours_1_minute_0_seconds(void) {
  int seconds = convert_hours_mins_to_seconds(0, 1, 0);

  TEST_START("convert 0 hours, 1 minute, 0 seconds");
  ASSERT_INT(seconds, 60);
}

void test_edge_case_59_minutes_59_seconds(void) {
  int result = convert_hours_mins_to_seconds(0, 59, 59);

  TEST_START("convert 59 minutes 59 seconds");
  ASSERT_INT(result, 3599);
}

void test_edge_case_1_hour(void) {
  int result = convert_hours_mins_to_seconds(1, 0, 0);

  TEST_START("convert 1 hour");
  ASSERT_INT(result, 3600);
}

void test_edge_case_23_hours_59_minutes_59_seconds(void) {
  int result = convert_hours_mins_to_seconds(23, 59, 59);

  TEST_START("convert 23:59:59 boundary");
  ASSERT_INT(result, 86399);
}

void test_large_input_value(void) {
  int result = convert_hours_mins_to_seconds(100, 0, 0);

  TEST_START("convert large hour value (100 hours)");
  ASSERT_INT(result, 360000);
}

void test_file_not_found(void) {
  char non_existent_file[] = "/tmp/this_file_definitely_does_not_exist_12345.mp3";

  unlink(non_existent_file);

  int result = access(non_existent_file, F_OK);

  TEST_START("file does not exist check");
  ASSERT_INT(result, -1);
}

void test_file_exists(void) {
  char test_file[] = "/tmp/test_file_exists_12345.txt";

  FILE *f = fopen(test_file, "w");
  fprintf(f, "test");
  fclose(f);

  int result = access(test_file, F_OK);

  TEST_START("file exists check");
  ASSERT_INT(result, 0);

  unlink(test_file);
}

void test_large_seconds_value(void) {
  int seconds = convert_hours_mins_to_seconds(24, 0, 0);

  TEST_START("convert very large seconds value (24 hours)");
  ASSERT_INT(seconds, 86400);
}

void test_large_combined_values(void) {
  int seconds = convert_hours_mins_to_seconds(99, 59, 59);

  TEST_START("convert very large combined time value");
  ASSERT_INT(seconds, 359999);
}

TEST_LIST {
  TESTS_HEADER("edge cases and large values");
  test_edge_case_zero_hours_minutes_seconds();
  test_edge_case_0_hours_0_minutes_59_seconds();
  test_edge_case_0_hours_1_minute_0_seconds();
  test_edge_case_59_minutes_59_seconds();
  test_edge_case_1_hour();
  test_edge_case_23_hours_59_minutes_59_seconds();
  test_large_input_value();
  test_file_not_found();
  test_file_exists();
  test_large_seconds_value();
  test_large_combined_values();
}

RUN_TESTS
