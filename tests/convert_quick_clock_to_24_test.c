#include <stdio.h>
#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

void convertQuickClockto24(char* inputTime);
int getCurrentHourNumber();
int getCurrentMinuteNumber();

#define MAX_STRING 100

int tests_run = 0;
int result, expect;
char inputString[MAX_STRING];
char resultString[MAX_STRING];
char expectString[MAX_STRING];

static char * convert7quickClockTo24() {
    statement("Convert 7 quick clock to 7:00 or 19:00");
    strcpy(inputString,"7:00");
    convertQuickClockto24(inputString);
    strcpy(resultString, inputString);
    if (getCurrentHourNumber() <= 7)
        strcpy(expectString,"19:00");
    if (getCurrentHourNumber() >= 19)
        strcpy(expectString,"07:00");
    if (getCurrentHourNumber() >= 7 && getCurrentMinuteNumber() > 1)
        strcpy(expectString,"19:00");
    if (getCurrentHourNumber() >= 19 && getCurrentMinuteNumber() > 1)
        strcpy(expectString,"07:00");

    assertString(expectString, resultString);
    mu_assert("", result == expect);
    return 0;
}

static char * convert12quickClockTo24() {
    statement("Convert 12 quick clock to 12:00 or 00:00");
    strcpy(inputString,"12:00");
    convertQuickClockto24(inputString);
    strcpy(resultString, inputString);
    if (getCurrentHourNumber() > 12 && getCurrentHourNumber() < 24)
        strcpy(expectString,"00:00");
    if (getCurrentHourNumber() < 12 )
        strcpy(expectString,"12:00");
    if (getCurrentHourNumber() == 12 && getCurrentMinuteNumber() > 1)
        strcpy(expectString,"00:00");
    if (getCurrentHourNumber() == 12 && getCurrentMinuteNumber() > 1)
        strcpy(expectString,"12:00");

    assertString(expectString, resultString);
    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    mu_run_test(convert7quickClockTo24);
    mu_run_test(convert12quickClockTo24);
    return 0;
}

int main(int argc, char **argv) {
    printf("-- convert_quick_clock_to_24.c --\n");
    printf("Testing convert quickclock to 24 hour functions...\n");
    char *result = all_tests();

    return result != 0;
}

