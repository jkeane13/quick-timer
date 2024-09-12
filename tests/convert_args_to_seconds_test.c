#include <stdio.h>
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

static char * hourMinsSeconds() {
    statement("Convert hours, mins, seconds to just seconds...");
    expect = 10921;
    result = convertHoursMinsToSeconds(3, 2, 1);
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
 }

static char * argsSecToSeconds() {
    statement("Convert 50 seconds string argument to seconds...");
    expect = 50;
    result = convertArgsToSeconds("50");
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}

static char * argsMinToSeconds() {
    char minArgs[] = "2 50";
    statement("Convert 2 minutes and 50 seconds string argument to seconds...");
    expect = 170;
    result = convertArgsToSeconds(minArgs);
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}

static char * argsHourToSeconds() {
    char hourArgs[] = "1 12 50";
    statement("Convert 1 hour, 12 mins and 50 seconds args to just seconds...");
    expect = 4370;
    result = convertArgsToSeconds(hourArgs);
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    run_test(hourMinsSeconds);
    run_test(argsSecToSeconds);
    run_test(argsMinToSeconds);
    run_test(argsHourToSeconds);
    return 0;
}

int main(int argc, char **argv) {
    printf("-- convert_args_to_seconds.c --\n");
    printf("Testing convert args to seconds functions...\n");
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
