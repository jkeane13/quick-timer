#include <stdio.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 256
#define TEST_FILE "tests/example.sh"

int tests_run = 0;
int result, expect;
char inputString[MAX_STRING];
char resultString[MAX_STRING];
char expectString[MAX_STRING];

static char * executeUsage() {
    statement("Usage should be able to activate");
    usage(0);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    run_test(executeUsage);
    return 0;
}

int main(int argc, char **argv) {
    printf("-- usage.c --\n");
    printf("Testing usage function tests...\n");

    char *result = all_tests();

    return result != 0;
}
