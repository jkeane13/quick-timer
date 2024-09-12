#include <stdio.h>
#include "../include/timer.h"
#include "../include/testing.h"

int tests_run = 0;
int result, expect;

void printSecondsEndAsClock(int seconds, char* clockType);

static char * print24HourClockHourLater() {
    statement("Print 24 hour clock end time an hour ahead");
    printSecondsEndAsClock(3600, "24Hour");
    assertInt(1, 1);

    mu_assert("", result == expect);
    return 0;
}

static char * print12HourClockHourLater() {
    statement("Print 12 hour clock end time an hour ahead");
    printSecondsEndAsClock(3600, "12Hour");
    assertInt(1, 1);

    mu_assert("", result == expect);
    return 0;
}

static char * printDefaultEndTime() {
    statement("Print 12 hour clock default timer 30 mins ahead");
    printSecondsEndAsClock(1800, "12Hour");
    assertInt(1, 1);

    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    run_test(print24HourClockHourLater);
    run_test(print12HourClockHourLater);
    run_test(printDefaultEndTime);

    return 0;
}

int main(int argc, char **argv) {
    printf("-- countdown_seconds.c --\n");
    printf("Testing countdown_seconds function tests...\n");

    char *result = all_tests();

    return result != 0;
}
