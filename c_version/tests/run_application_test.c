#include <stdio.h>
#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 256
#define TEST_FILE "tests/example.sh"

int tests_run = 0;
int result, expect;
char inputString[MAX_STRING];
char resultString[MAX_STRING];
char expectString[MAX_STRING];

static char * runASystemProgram() {
    runProgram(TEST_FILE,0);
    printf("Program should execute in silent output mode \t\t\t\t");
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    mu_run_test(runASystemProgram);
    return 0;
}

int main(int argc, char **argv) {
    printf("-- run_application.c --\n");
    printf("Testing run application function tests...\n");

    char *result = all_tests();

    return result != 0;
}