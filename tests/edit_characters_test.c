#include "../include/edit_characters.h"
#include "../include/test_framework.h"
#include "../include/timer.h"
#include <string.h>

char inputString[MAX_STRING];

void test_replace_characters_in_a_string(void) {
  strcpy(inputString, "Testing123");
  replace_char(inputString, 'g', 'e');
  TEST_START("replace characters in a string");
  ASSERT_STRING(inputString, "Testine123");
}

void test_removes_characters_in_a_string(void) {
  strcpy(inputString, "Testing123");
  remove_char(inputString, 'e');
  TEST_START("remove characters in a string");
  ASSERT_STRING(inputString, "Tsting123");
}

TEST_LIST {
  TESTS_HEADER("edit characters function");
  test_replace_characters_in_a_string();
  test_removes_characters_in_a_string();
}

RUN_TESTS
