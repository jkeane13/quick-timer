#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../include/minunit.h"
#include "../include/timer.h"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define RESET   "\x1B[0m"

#define MAX_STRING 100

int tests_run = 0;
int result;
int expect;
bool resultBool;
bool expectBool;
char inputString[MAX_STRING];
char resultString[MAX_STRING];
char expectString[MAX_STRING];

void assertInt(int expect, int result);
void assertBool(bool expect, bool result);
void assertString(char *expect, char* result);

static char * correctQuietSwitch() {
     printf("Correct quiet switch entered...\t\t\t\t\t\t");
     char* switchEnd = "--quiet";

     bool quietMode = false;
     bool dryRun = false;
     checkforEndSwitch(switchEnd, &quietMode, &dryRun);

     expectBool = true;
     resultBool = quietMode;
     assertBool(expectBool, resultBool);
     mu_assert("", resultBool == expectBool);
     return 0;
 }

static char * correctDrySwitch() {
     printf("Correct dry switch entered...\t\t\t\t\t\t");
     char* switchEnd = "--dry-run";

     bool quietMode = false;
     bool dryRun = false;
     checkforEndSwitch(switchEnd, &quietMode, &dryRun);

     expectBool = true;
     resultBool = dryRun;
     assertBool(expectBool, resultBool);
     mu_assert("", resultBool == expectBool);
     return 0;
 }

 static char * hourMinsSeconds() {
     printf("Convert hours, mins, seconds parameters to just seconds...\t\t");
     expect = 10921;
     result = convertHoursMinsToSeconds(3, 2, 1);
     assertInt(expect, result);
     mu_assert("", result == expect);
     return 0;
 }

static char * argsSecToSeconds() {
    printf("Convert 50 seconds string argument to seconds...\t\t\t");
    expect = 50;
    result = convertArgsToSeconds("","", "50");
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}

static char * argsMinSecToSeconds() {
    printf("Convert 2 minutes and 50 second string argument to seconds...\t\t");
    expect = 170;
    result = convertArgsToSeconds("","2", "50");
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}

static char * argsHourMinSecToSeconds() {
    printf("Convert 1 hour, 2 minutes and 50 seconds string argument to seconds...\t");
    expect = 3770;
    result = convertArgsToSeconds("1","2", "50");
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}

static char * convertSingleHourTime7to24() {
    printf("Convert Single Hour Time String of 7:00 to 07:00 24 clock...\t\t");
    strcpy(inputString, "7:00");
    strcpy(expectString, "07:00");
    convert12to24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertDoubleHourTime10to24() {
    printf("Convert Double Hour Time String of 10:00 to 10:00 24 clock...\t\t");
    strcpy(inputString, "10:00");
    strcpy(expectString, "10:00");
    convert12to24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convert12HourTime12to24() {
    printf("Convert Double Hour Time String of 12:00 to 12:00 24 clock...\t\t");
    strcpy(inputString, "12:00");
    strcpy(expectString, "12:00");
    convert12to24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertDoubleHourTime21to24() {
    printf("Convert Double Hour Time String of 21:00 to 21:00 24 clock...\t\t");
    strcpy(inputString, "21:00");
    strcpy(expectString, "21:00");
    convert12to24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertSingleHourAmTime7to24() {
    printf("Convert Single Hour Time String of 7am to 07:00 24 clock...\t\t");
    strcpy(inputString, "7am");
    strcpy(expectString, "07:00");
    convert12to24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourAmTime12to24() {
    printf("Convert Single Hour Time String of 12am to 12:00 24 clock...\t\t");
    strcpy(inputString, "12am");
    strcpy(expectString, "00:00");
    convert12to24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourPmTime12to24() {
    printf("Convert Single Hour Time String of 12pm to 12:00 24 clock...\t\t");
    strcpy(inputString, "12pm");
    strcpy(expectString, "12:00");
    convert12to24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertSingleHourPmTime7to24() {
    printf("Convert Single Hour Time String of 7pm to 19:00 24 clock...\t\t");
    strcpy(inputString, "7pm");
    strcpy(expectString, "19:00");
    convert12to24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourMinAmTime7to24() {
    printf("Convert Single Hour Time String of 7:30am to 07:30 24 clock...\t\t");
    strcpy(inputString, "7:30am");
    strcpy(expectString, "07:30");
    convert12to24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourMinAmTime12to24() {
    printf("Convert Double 12th Hour Time String of 12:30am to 00:30 24 clock...\t");
    strcpy(inputString, "12:30am");
    strcpy(expectString, "00:30");
    convert12to24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourMinPmTime7to24() {
    printf("Convert Double Hour Time String of 7:30pm to 19:30 24 clock...\t\t");
    strcpy(inputString, "7:30pm");
    strcpy(expectString, "19:30");
    convert12to24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * convertHourMinPmTime12to24() {
    printf("Convert Double 12th Hour Time String of 12:30pm to 12:30 24 clock...\t");
    strcpy(inputString, "12:30pm");
    strcpy(expectString, "12:30");
    convert12to24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

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

//Hard to test, due to being time dependant for seconds
static char * checkArgumentFunctionTriggered() {
    printf("Check argument function for check is triggered\t\t\t\t");
    strcpy(inputString, "?"); // ? is used just for testing
    expect = 42;
    result = checkArgument(inputString);
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    mu_run_test(hourMinsSeconds);
    mu_run_test(correctQuietSwitch);
    mu_run_test(correctDrySwitch);
    mu_run_test(argsSecToSeconds);
    mu_run_test(argsMinSecToSeconds);
    mu_run_test(argsHourMinSecToSeconds);
    mu_run_test(convertSingleHourTime7to24);
    mu_run_test(convertHourAmTime12to24);
    mu_run_test(convertHourPmTime12to24);
    mu_run_test(convertDoubleHourTime10to24);
    mu_run_test(convert12HourTime12to24);
    mu_run_test(convertDoubleHourTime21to24);
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
    mu_run_test(checkArgumentFunctionTriggered);
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

void assertInt(int expect, int result){
     if (result != expect){
         printf(RED "[ FAIL ] expected %d, ", expect);
         printf("got %d\n", result);
         printf(RESET);
     }else
        printf(GREEN "[ PASS ]\n");
         printf(RESET);
}

void assertBool(bool expect, bool result){
     if (result != expect){
         printf(RED "[ FAIL ] expected %s, ", expect ? "true" : "false");
         printf("got %s\n", result ? "true": "false");
         printf(RESET);
     }else
        printf(GREEN "[ PASS ]\n");
         printf(RESET);
}

void assertString(char* expect, char* result){
     if (strcmp(expect,result) != 0){
         printf(RED "[ FAIL ] expected %s, ", expect);
         printf("got %s\n", result);
         printf(RESET);
     }else
        printf(GREEN "[ PASS ]\n");
         printf(RESET);
}

