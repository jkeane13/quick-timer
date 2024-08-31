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

/*convert12to24 */
// 24 Clock will not work in relative time, will need to put in a switch in
// place to fix
static char * convertSingleHourTime7to24() {
    printf("Convert Single Hour Time String of 7:00 to 07:00 24 clock...\t\t");
    strcpy(inputString, "7:00");
    strcpy(expectString, "07:00");
    convert12to24(inputString,1);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertDoubleHourTime10to24() {
    printf("Convert Double Hour Time String of 10:00 to 10:00 24 clock...\t\t");
    strcpy(inputString, "10:00");
    strcpy(expectString, "10:00");
    convert12to24(inputString,1);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convert12HourTime12to24() {
    printf("Convert Double Hour Time String of 12:00 to 12:00 24 clock...\t\t");
    strcpy(inputString, "12:00");
    strcpy(expectString, "12:00");
    convert12to24(inputString,1);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertDoubleHourTime21to24() {
    printf("Convert Double Hour Time String of 21:00 to 21:00 24 clock...\t\t");
    strcpy(inputString, "21:00");
    strcpy(expectString, "21:00");
    convert12to24(inputString,1);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertSingleHourAmTime7to24() {
    printf("Convert Single Hour Time String of 7am to 07:00 24 clock...\t\t");
    strcpy(inputString, "7am");
    strcpy(expectString, "07:00");
    convert12to24(inputString,1);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourAmTime12to24() {
    printf("Convert Single Hour Time String of 12am to 00:00 24 clock...\t\t");
    strcpy(inputString, "12am");
    strcpy(expectString, "00:00");
    convert12to24(inputString,1);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourPmTime12to24() {
    printf("Convert Single Hour Time String of 12pm to 12:00 24 clock...\t\t");
    strcpy(inputString, "12pm");
    strcpy(expectString, "12:00");
    convert12to24(inputString,1);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertSingleHourPmTime7to24() {
    printf("Convert Single Hour Time String of 7pm to 19:00 24 clock...\t\t");
    strcpy(inputString, "7pm");
    strcpy(expectString, "19:00");
    convert12to24(inputString,1);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourMinAmTime7to24() {
    printf("Convert Single Hour Time String of 7:30am to 07:30 24 clock...\t\t");
    strcpy(inputString, "7:30am");
    strcpy(expectString, "07:30");
    convert12to24(inputString,1);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourMinAmTime12to24() {
    printf("Convert Double 12th Hour Time String of 12:30am to 00:30 24 clock...\t");
    strcpy(inputString, "12:30am");
    strcpy(expectString, "00:30");
    convert12to24(inputString,1);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourMinPmTime7to24() {
    printf("Convert Double Hour Time String of 7:30pm to 19:30 24 clock...\t\t");
    strcpy(inputString, "7:30pm");
    strcpy(expectString, "19:30");
    convert12to24(inputString,1);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourMinPmTime12to24() {
    printf("Convert Double 12th Hour Time String of 12:30pm to 12:30 24 clock...\t");
    strcpy(inputString, "12:30pm");
    strcpy(expectString, "12:30");
    convert12to24(inputString,1);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

/* convert24ClockTo12 */
static char * convert24HourClockto12Hour7am() {
    printf("Convert 24 Clock 07:00 to 7am clock...\t\t\t\t\t");
    strcpy(inputString, "07:00");
    strcpy(expectString, "7am");
    char time12String[10];
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convert24HourClockto12Hour7pm() {
    printf("Convert 24 Clock 19:00 to 7pm clock...\t\t\t\t\t");
    strcpy(inputString, "19:00");
    strcpy(expectString, "7pm");
    char time12String[10];
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convert24HourClockto12Hour730am() {
    printf("Convert 24 Clock 07:30 to 7:30am clock...\t\t\t\t");
    strcpy(inputString, "07:30");
    strcpy(expectString, "7:30am");
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convert24HourClockto12Hour730pm() {
    printf("Convert 24 Clock 19:30 to 7:30pm clock...\t\t\t\t");
    strcpy(inputString, "19:30");
    strcpy(expectString, "7:30pm");
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convert24HourClockto12Hour12am() {
    printf("Convert 24 Clock 00:00 to 12am clock...\t\t\t\t\t");
    strcpy(inputString, "00:00");
    strcpy(expectString, "12am");
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}
static char * convert24HourClockto12Hour1230am() {
    printf("Convert 24 Clock 00:30 to 12:30am clock...\t\t\t\t");
    strcpy(inputString, "00:30");
    strcpy(expectString, "12:30am");
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convert24HourClockto12Hour12pm() {
    printf("Convert 24 Clock 12:00 to 12pm clock...\t\t\t\t\t");
    strcpy(inputString, "12:00");
    strcpy(expectString, "12pm");
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}
static char * convert24HourClockto12Hour1230pm() {
    printf("Convert 24 Clock 12:30 to 12:30pm clock...\t\t\t\t");
    strcpy(inputString, "12:30");
    strcpy(expectString, "12:30pm");
    convert24ClockTo12(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    mu_run_test(convertSingleHourTime7to24);
    mu_run_test(convertHourAmTime12to24);
    mu_run_test(convertHourPmTime12to24);
    mu_run_test(convertDoubleHourTime10to24);
    /* mu_run_test(convert12HourTime12to24); */
    /* mu_run_test(convertDoubleHourTime21to24); */
    mu_run_test(convertSingleHourAmTime7to24);
    mu_run_test(convertSingleHourPmTime7to24);
    mu_run_test(convertHourMinAmTime7to24);
    mu_run_test(convertHourMinAmTime12to24);
    mu_run_test(convertHourMinPmTime7to24);
    mu_run_test(convert24HourClockto12Hour7am);
    mu_run_test(convert24HourClockto12Hour7pm);
    mu_run_test(convert24HourClockto12Hour730am);
    mu_run_test(convert24HourClockto12Hour730pm);
    mu_run_test(convert24HourClockto12Hour12am);
    mu_run_test(convert24HourClockto12Hour1230am);
    mu_run_test(convert24HourClockto12Hour12pm);
    mu_run_test(convert24HourClockto12Hour1230pm);
    return 0;
}

int main(int argc, char **argv) {
    printf("Running function tests...\n");
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

