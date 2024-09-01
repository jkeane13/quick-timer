#include <stdio.h>
#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 100

int tests_run = 0;
int result, expect;
char inputString[MAX_STRING];
char resultString[MAX_STRING];
char expectString[MAX_STRING];

int quietMode = 0, dryRunMode = 0, executeMode = 0;
char argString[MAX_STRING];

// runEndSwitch
static char * checkQuietMode() {
    printf("Quiet Mode can be turned on\t\t\t\t\t\t");
    strcpy(argString, "--quiet");
    runEndSwitch(argString, &quietMode, &dryRunMode, &executeMode);
    expect = 1;
    result = quietMode;
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
 }

static char * checkDryRunMode() {
    printf("Dry run mode to be turned on with --dry-run switch is used \t\t");
    strcpy(argString,  "--dry-run");
    runEndSwitch(argString, &quietMode, &dryRunMode, &executeMode);
    expect = 2; // both Quiet Mode and Dry Run Mode turned on
    result = quietMode + dryRunMode;
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
 }

static char * checkExecuteMode() {
    printf("Execute mode to be turned on with files with '.' in them\t\t");
    strcpy(argString,  ".");
    runEndSwitch(argString, &quietMode, &dryRunMode, &executeMode);
    expect = 2; // both Quiet Mode and Execute Mode turned on
    result = quietMode + dryRunMode;
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
 }

// checkArgument
static char * checkArgumentActivated() {
    printf("Check argument function can be activated using the ? argument\t\t");
    expect = 42;
    result = convertArgsToSeconds("?");
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}
//
// promptTimeEnd
static char * testTimePrompt() {
    printf("Time prompt function can be triggered\t\t\t\t\t");
    expect = -1;
    result = promptTimeEnd(-1);
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    mu_run_test(checkQuietMode);
    mu_run_test(checkDryRunMode);
    mu_run_test(checkExecuteMode);
    mu_run_test(checkArgumentActivated);
    mu_run_test(testTimePrompt);
    return 0;
}

//------------------main-----------------------------
int main(int argc, char **argv) {
    printf("Testing args_handler.c...\n");
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
