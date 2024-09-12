#include <stdio.h>
#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 256

int tests_run = 0;
int result, expect;
char inputString[MAX_STRING];

static char * convert1330to12Hour() {
    statement("Should convert 13:30 to 1:30pm");
    strcpy(inputString, "13:30");
    convert24ClockTo12(inputString);
    assertString(inputString, "1:30pm");
    mu_assert("", result == expect);
    return 0;
}

static char * convert0030to12Hour() {
    statement("Should convert 00:30 to 12:30am");
    strcpy(inputString, "00:30");
    convert24ClockTo12(inputString);
    assertString(inputString, "12:30am");
    mu_assert("", result == expect);
    return 0;
}

static char * convert0800to12Hour() {
    statement("Should convert 08:00 to 8:00am");
    strcpy(inputString, "08:00");
    convert24ClockTo12(inputString);
    assertString(inputString, "8am");
    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    run_test(convert1330to12Hour);
    run_test(convert0030to12Hour);
    run_test(convert0800to12Hour);
    return 0;
}

int main(int argc, char **argv) {
    printf("-- convert_24_hour_clock_to_12.c --\n");
    printf("Testing convert 24 clock to 12 tests...\n");
    char *result = all_tests();
    if (result != 0)
        printf("%s\n", result);

    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

