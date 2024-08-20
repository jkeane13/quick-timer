
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "minunit.h"
#include "timer.h"
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
    strcpy(inputString, "7pm");
    strcpy(expectString, "19:00");
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

static char * convertHourMinPmTime7to24() {
    printf("Convert Single Hour Time String of 7:30pm to 19:30 24 clock...\t\t");
    strcpy(inputString, "7:30pm");
    strcpy(expectString, "19:30");
    convert12to24(inputString);
    strcpy(resultString, inputString);
    assertString(expectString, resultString);

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
    mu_run_test(convertDoubleHourTime10to24);
    mu_run_test(convertDoubleHourTime21to24);
    mu_run_test(convertSingleHourAmTime7to24);
    mu_run_test(convertSingleHourPmTime7to24);
    mu_run_test(convertHourMinAmTime7to24);
    mu_run_test(convertHourMinPmTime7to24);
    return 0;
}

int main(int argc, char **argv) {
    printf("Running function tests...\n");
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL FUNCTION TESTS PASSED\n");
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

