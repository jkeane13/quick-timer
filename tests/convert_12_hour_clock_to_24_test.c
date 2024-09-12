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

static char * convertSingleHourAmTime7to24() {
    statement("Convert Single Hour Time String of 7am to 07:00 24 clock...");
    strcpy(inputString, "7am");
    strcpy(expectString, "07:00");
    convertInputClockto24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);
    mu_assert("", result == expect);
    return 0;
}

static char * convertSingleHourAmTime12to24() {
    statement("Convert Single Hour Time String of 12am to 00:00 24 clock...");
    strcpy(inputString, "12am");
    strcpy(expectString, "00:00");
    convertInputClockto24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourPmTime12to24() {
    strcpy(inputString, "");
    statement("Convert Single Hour Time String of 12pm to 12:00 24 clock...");
    strcpy(inputString, "12pm");
    strcpy(expectString, "12:00");
    convertInputClockto24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertSingleHourPmTime7to24() {
    statement("Convert Single Hour Time String of 7pm to 19:00 24 clock...");
    strcpy(inputString, "7pm");
    strcpy(expectString, "19:00");
    convertInputClockto24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourMinAmTime7to24() {
    statement("Convert Single Hour Time String of 7:30am to 07:30 24 clock...");
    strcpy(inputString, "7:30am");
    strcpy(expectString, "07:30");
    convertInputClockto24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourMinAmTime12to24() {
    statement("Convert Double 12th Hour Time String of 12:30am to 00:30 24 clock...");
    strcpy(inputString, "12:30am");
    strcpy(expectString, "00:30");
    convertInputClockto24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);
    mu_assert("", result == expect);
    return 0;
}

static char * convertHourMinPmTime7to24() {
    statement("Convert Double Hour Time String of 7:30pm to 19:30 24 clock...");
    strcpy(inputString, "7:30pm");
    strcpy(expectString, "19:30");
    convertInputClockto24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourMinPmTime12to24() {
    statement("Convert Double 12th Hour Time String of 12:30pm to 12:30 24 clock...");
    strcpy(inputString, "12:30pm");
    strcpy(expectString, "12:30");
    convertInputClockto24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convert24HourClockto12Hour7am() {
    statement("Convert 24 Clock 07:00 to 7am clock...");
    strcpy(inputString, "07:00");
    strcpy(expectString, "7am");
    char time12String[10];
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);
    mu_assert("", result == expect);
    return 0;
}

static char * convert24HourClockto12Hour730am() {
    statement("Convert 24 Clock 07:30 to 7:30am clock...");
    strcpy(inputString, "07:30");
    strcpy(expectString, "7:30am");
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);
    mu_assert("", result == expect);
    return 0;
}

static char * convert24HourClockto12Hour730pm() {
    statement("Convert 24 Clock 19:30 to 7:30pm clock...");
    strcpy(inputString, "19:30");
    strcpy(expectString, "7:30pm");
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);
    mu_assert("", result == expect);
    return 0;
}

static char * convert24HourClockto12Hour12am() {
    statement("Convert 24 Clock 00:00 to 12am clock...");
    strcpy(inputString, "00:00");
    strcpy(expectString, "12am");
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}
static char * convert24HourClockto12Hour1230am() {
    statement("Convert 24 Clock 00:30 to 12:30am clock...");
    strcpy(inputString, "00:30");
    strcpy(expectString, "12:30am");
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convert24HourClockto12Hour12pm() {
    statement("Convert 24 Clock 12:00 to 12pm clock...");
    strcpy(inputString, "12:00");
    strcpy(expectString, "12pm");
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}
static char * convert24HourClockto12Hour1230pm() {
    statement("Convert 24 Clock 12:30 to 12:30pm clock...");
    strcpy(inputString, "12:30");
    strcpy(expectString, "12:30pm");
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    run_test(convertSingleHourAmTime12to24);
    run_test(convertSingleHourPmTime7to24);
    run_test(convertHourMinAmTime7to24);
    run_test(convertHourMinAmTime12to24);
    run_test(convertHourMinPmTime7to24);
    run_test(convert24HourClockto12Hour7am);
    run_test(convert24HourClockto12Hour730am);
    run_test(convert24HourClockto12Hour730pm);
    run_test(convert24HourClockto12Hour12am);
    run_test(convert24HourClockto12Hour1230am);
    run_test(convert24HourClockto12Hour12pm);
    run_test(convert24HourClockto12Hour1230pm);
    return 0;
}

int main(int argc, char **argv) {
    printf("-- convert_12_hour_clock_to_24.c --\n");
    printf("Testing convert 12 clock to 24 tests...\n");
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

