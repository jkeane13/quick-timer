#include <stdio.h>
#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 100
#define TEST_FILE "tests/example.sh"

int tests_run = 0;
int result;
int expect;
char inputString[MAX_STRING];
char resultString[MAX_STRING];
char expectString[MAX_STRING];

// runProgram
static char * runASystemProgram() {
    runProgram(TEST_FILE,0);
    printf("Program should execute in silent output mode \t\t\t\t");
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

// convert24ClockToSeconds
static char * convert1530ClocktoSeconds() {
    printf("Convert a 24 Hour clock entry into seconds for countdown\t\t");
    strcpy(inputString,"15:30");
    result = convert24ClockToSeconds(inputString) > 0;
    expect = 1 > 0;
    assertInt(expect, result);

    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    mu_run_test(runASystemProgram);
    mu_run_test(convert1530ClocktoSeconds);
    return 0;
}

int main(int argc, char **argv) {
    printf("Running function tests...\n");
    char *result = all_tests();

    return result != 0;
}

