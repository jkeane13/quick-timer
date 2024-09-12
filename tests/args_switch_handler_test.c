#include <stdio.h>
#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 256

int tests_run = 0;
int result, expect;
int quietMode = 0, dryRunMode = 0, executeMode = 0;
char argString[MAX_STRING];

static char * checkQuietMode() {
    statement("Quiet Mode can be turned on");
    strcpy(argString, "--quiet");
    runEndSwitch(argString, &quietMode, &dryRunMode, &executeMode);
    expect = 1;
    result = quietMode;
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
 }

static char * checkDryRunMode() {
    statement("Dry run mode to be turned on with --dry-run switch is used");
    strcpy(argString,  "--dry-run");
    runEndSwitch(argString, &quietMode, &dryRunMode, &executeMode);
    expect = 2; // both Quiet Mode and Dry Run Mode turned on
    result = quietMode + dryRunMode;
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
 }

static char * checkExecuteMode() {
    statement("Execute mode to be turned on with files with '.' in them");
    strcpy(argString,  ".");
    runEndSwitch(argString, &quietMode, &dryRunMode, &executeMode);
    expect = 2; // both Quiet Mode and Execute Mode turned on
    result = quietMode + dryRunMode;
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
 }

static char * checkArgumentActivated() {
    statement("Check argument function can be activated using the ? argument");
    expect = 42;
    result = convertArgsToSeconds("?");
    assertInt(expect, result);
    mu_assert("", result == expect);
    return 0;
}


static char * all_tests() {
    run_test(checkQuietMode);
    run_test(checkDryRunMode);
    run_test(checkExecuteMode);
    run_test(checkArgumentActivated);
    return 0;
}

int main(int argc, char **argv) {
    printf("-- args_switch handler_test.c --\n");
    printf("Testing argument switches...\n");
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
