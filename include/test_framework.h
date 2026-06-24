#ifndef TESTING_H
#define TESTING_H

#include <math.h>
#include <stdio.h>
#include <string.h>

#define RED "\x1B[0;31m"
#define GREEN "\x1B[0;32m"
#define RESET "\033[0m"

static int TESTS_PASSED = 0;
static int TESTS_FAILED = 0;

#define TEST_START(name)                                                       \
  do {                                                                         \
    const char *file = __FILE__;                                               \
    const char *filename = strrchr(file, '/');                                 \
    filename = filename ? filename + 1 : file;                                 \
    printf("[ %s ] Testing %s... ", filename, name);                           \
  } while (0)

#define TESTS_HEADER(name)                                                     \
  do {                                                                         \
    printf("Running %s tests...\n", name);                                     \
  } while (0)

#define ASSERT_INT(actual, expected)                                           \
  do {                                                                         \
    if ((actual) == (expected)) {                                              \
      printf("%sPASS%s\n", GREEN, RESET);                                      \
      TESTS_PASSED++;                                                          \
    } else {                                                                   \
      printf("%sFAIL (line %d): expected %d, got %d%s\n", RED, __LINE__,       \
             (expected), (actual), RESET);                                     \
      TESTS_FAILED++;                                                          \
    }                                                                          \
  } while (0)

#define ASSERT_FLOAT(actual, expected, tolerance)                              \
  do {                                                                         \
    if (fabs((actual) - (expected)) < (tolerance)) {                           \
      printf("%sPASS%s\n", GREEN, RESET);                                      \
      TESTS_PASSED++;                                                          \
    } else {                                                                   \
      printf("%sFAIL (line %d): expected %f, got %f (tolerance: %f)%s\n", RED, \
             __LINE__, (expected), (actual), (tolerance), RESET);              \
      TESTS_FAILED++;                                                          \
    }                                                                          \
  } while (0)

#define ASSERT_STRING(actual, expected)                                        \
  do {                                                                         \
    if (strcmp((actual), (expected)) == 0) {                                   \
      printf("%sPASS%s\n", GREEN, RESET);                                      \
      TESTS_PASSED++;                                                          \
    } else {                                                                   \
      printf("%sFAIL (line %d): expected \"%s\", got \"%s\"%s\n", RED,         \
             __LINE__, (expected), (actual), RESET);                           \
      TESTS_FAILED++;                                                          \
    }                                                                          \
  } while (0)

#define PRINT_RESULTS()                                                        \
  do {                                                                         \
    printf("Tests Passed: %d/%d\n", TESTS_PASSED,                              \
           TESTS_PASSED + TESTS_FAILED);                                       \
    printf("\n");                                                              \
    return (TESTS_FAILED == 0) ? 0 : 1;                                        \
  } while (0)

#define TEST_LIST void run_tests(void)

#define RUN_TESTS                                                              \
  int main(void) {                                                             \
    run_tests();                                                               \
    PRINT_RESULTS();                                                           \
  }
#endif
