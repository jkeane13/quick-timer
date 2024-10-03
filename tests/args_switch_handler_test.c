#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 256

int quietMode = 0, dryRunMode = 0, executeMode = 0;
char argString[MAX_STRING];

void checkQuietMode() {
    statement("Quiet Mode can be turned on");
    strcpy(argString, "--quiet");
    runEndSwitch(argString, &quietMode, &dryRunMode, &executeMode);
    assertInt(1, quietMode);
 }

void checkDryRunMode() {
    statement("Dry run mode turned on with quiet mode as well");
    strcpy(argString,  "--dry-run");
    runEndSwitch(argString, &quietMode, &dryRunMode, &executeMode);
    assertInt(2, quietMode + dryRunMode);
 }

void checkExecuteMode() {
    statement("Execute mode to be turned on with files with '.' in them");
    strcpy(argString,  ".");
    runEndSwitch(argString, &quietMode, &dryRunMode, &executeMode);
    assertInt(2, quietMode + dryRunMode);
 }

void run_tests() {
    checkQuietMode();
    checkDryRunMode();
    checkExecuteMode();
}

int main() {
    testTitle("Testing argument switches", __FILE__);
    run_tests();

    return 0;
}
