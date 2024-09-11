#include <stdio.h>
#include "../include/timer.h"
#include "../include/testing.h"

int result, expect;
int tests_run = 0;

static char * getSingleHour() {
    statement("Get the single hour of 3:30...");
    expect = 3;
    result = getHour("3:30");
    assertInt(expect, result);
    mu_assert("", result == expect);

    return 0;
}

static char * getSingleHourFromAmPm() {
    statement("Get the single hour of 4am...");
    expect = 4;
    result = getHour("4am");
    assertInt(expect, result);
    mu_assert("", result == expect);

    return 0;
}

static char * getDoubleHourFromAmPm() {
    statement("Get the single hour of 10am...");
    expect = 10;
    result = getHour("10am");
    assertInt(expect, result);
    mu_assert("", result == expect);

    return 0;
}

static char * getDoubleHour() {
    statement("Get the double hour of 12:30...");
    expect = 12;
    result = getHour("12:30");
    assertInt(expect, result);
    mu_assert("", result == expect);

    return 0;
}

static char * getSingleMinutes() {
    statement("Get the single minute of 6:09...");
    expect = 9;
    result = getMinutes("6:09");
    assertInt(expect, result);
    mu_assert("", result == expect);

    return 0;
}

static char * getDoubleMinutes() {
    statement("Get the double minutes of 7:30...");
    expect = 30;
    result = getMinutes("7:30");
    assertInt(expect, result);
    mu_assert("", result == expect);

    return 0;
}

static char * getDoubleFullHour() {
    statement("Get the single hour of full time 5:30am...");
    expect = 5;
    result = getHour("5:30am");
    assertInt(expect, result);
    mu_assert("", result == expect);

    return 0;
}

static char * getDoubleFullMinute() {
    statement("Get the double minutes of a full time 12:24am...");
    expect = 24;
    result = getMinutes("12:24am");
    assertInt(expect, result);
    mu_assert("", result == expect);

    return 0;
}

static char * all_tests() {
    mu_run_test(getSingleHour);
    mu_run_test(getDoubleHour);
    mu_run_test(getSingleHourFromAmPm);
    mu_run_test(getDoubleHourFromAmPm);
    mu_run_test(getSingleMinutes);
    mu_run_test(getDoubleMinutes);
    mu_run_test(getDoubleFullHour);
    mu_run_test(getDoubleFullMinute);

    return 0;
}

int main(int argc, char **argv) {
    printf("-- get_hour_and_minutes.c --\n");
    printf("Testing hour and minutes functions...\n");
    char *result = all_tests();

    if (result != 0)
        printf("%s\n", result);

    printf("Tests run: %d\n", tests_run);
    return result != 0;
}
