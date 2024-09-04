#include <stdio.h>
#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 100

int tests_run = 0;
int result;
int expect;
char inputString[MAX_STRING];
char resultString[MAX_STRING];
char expectString[MAX_STRING];

void assertInt(int expect, int result);
void assertString(char *expect, char* result);

// convertHoursMinsToSeconds
static char * hourMinsSeconds() {
    printf("Convert hours, mins, seconds parameters to just seconds...\t\t");
    expect = 10921;
    result = convertHoursMinsToSeconds(3, 2, 1);
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
 }

// convertArgstoSeconds
static char * argsSecToSeconds() {
    printf("Convert 50 seconds string argument to seconds...\t\t\t");
    expect = 50;
    result = convertArgsToSeconds("50");
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}

static char * argsMinToSeconds() {
    char minArgs[] = "2 50";
    printf("Convert 2 minutes and 50 seconds string argument to seconds...\t\t");
    expect = 170;
    result = convertArgsToSeconds(minArgs);
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}

static char * argsHourToSeconds() {
    char hourArgs[] = "1 12 50";
    printf("Convert 1 hour, 12 minutes and 50 seconds string argument to seconds...\t");
    expect = 4370;
    result = convertArgsToSeconds(hourArgs);
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    mu_run_test(hourMinsSeconds);
    mu_run_test(argsSecToSeconds);
    mu_run_test(argsMinToSeconds);
    mu_run_test(argsHourToSeconds);
    return 0;
}

//------------------main-----------------------------
int main(int argc, char **argv) {
    printf("Running convert_args.c function tests...\n");
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
