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

void assertInt(int expect, int result);
void assertString(char *expect, char* result);

// checkArgument
// PromptTimeEnd

// runEndSwitch
static char * checkQuietMode() {
    printf("Quiet mode to be turned on with --quiet switch is used \t\t\t");
    char argString[] = "--quiet";
    int quietMode = 0;
    int dryRunMode = 0;
    int executeMode = 0;
    runEndSwitch(argString, &quietMode, &dryRunMode, &executeMode);
    expect = 1;
    result = quietMode;
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
 }

static char * checkDryRunMode() {
    printf("Dry run mode to be turned on with --dry-run switch is used \t\t");
    char argString[] = "--dry-run";
    int quietMode = 0;
    int dryRunMode = 0;
    int executeMode = 0;
    runEndSwitch(argString, &quietMode, &dryRunMode, &executeMode);
    expect = 2; // both quietmode and dryRunMode turned on
    result = quietMode + dryRunMode;
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
 }

static char * checkExecuteMode() {
    printf("Execute mode to be turned on with files with '.' in them\t\t");
    char argString[] = "--dry-run";
    int quietMode = 0;
    int dryRunMode = 0;
    int executeMode = 0;
    runEndSwitch(argString, &quietMode, &dryRunMode, &executeMode);
    expect = 2; // both quietmode and ExecuteMode turned on
    result = quietMode + dryRunMode;
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
 }

// convertHoursMinsToSeconds
static char * hourMinsSeconds() {
    printf("Convert hours, mins, seconds parameters to just seconds...\t\t");
    expect = 10921;
    result = convertHoursMinsToSeconds(3, 2, 1);
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
 }

// convertArgstoSeconds
static char * argsSecToSeconds() {
    printf("Convert 50 seconds string argument to seconds...\t\t\t");
    expect = 50;
    result = convertArgsToSeconds("50");
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    mu_run_test(checkQuietMode);
    mu_run_test(checkDryRunMode);
    mu_run_test(checkExecuteMode);
    mu_run_test(hourMinsSeconds);
    mu_run_test(argsSecToSeconds);
    return 0;
}

//------------------main-----------------------------
int main(int argc, char **argv) {
    printf("Running convert_arg.c function tests...\n");
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
