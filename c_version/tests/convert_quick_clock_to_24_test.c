#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/timer.h"
#include "../include/testing.h"

void convertQuickClockto24Hour(char* inputTime);
int getCurrentHourNumber();

#define MAX_STRING 100

int tests_run = 0;
int result, expect;
char inputString[MAX_STRING];
char resultString[MAX_STRING];
char expectString[MAX_STRING];

// convertIntToDoubleString
static char * convert7quickClockTo24() {
    printf("Convert 7 quick clock to 7:00 or 19:00\t\t\t\t\t");
    strcpy(inputString,"7:00");
    convertQuickClockto24Hour(inputString);
    strcpy(resultString, inputString);
    if (getCurrentHourNumber() > 7 && getCurrentHourNumber() < 19)
        strcpy(expectString,"19:00");
    if (getCurrentHourNumber() <= 8 && getCurrentHourNumber() > 19)
        strcpy(expectString,"07:00");

    assertString(expectString, resultString);
    mu_assert("", result == expect);
    return 0;
}

static char * convert12quickClockTo24() {
    printf("Convert 12 quick clock to 12:00 or 00:00\t\t\t\t");
    strcpy(inputString,"12:00");
    convertQuickClockto24Hour(inputString);
    strcpy(resultString, inputString);
    if (getCurrentHourNumber() >= 12 && getCurrentHourNumber() < 24)
        strcpy(expectString,"00:00");
    if (getCurrentHourNumber() < 12 )
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
    printf("Running function tests...\n");
    char *result = all_tests();

    return result != 0;
}

