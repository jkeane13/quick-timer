#include "../include/timer.h"
#include "../include/testing.h"

int quietMode = 0, dryRunMode = 0, executeMode = 0;

void checkQuietMode() {
    statement("Quiet Mode can be turned on");
    runEndSwitch("--quiet", &quietMode, &dryRunMode, &executeMode);
    assertInt(1, quietMode);
 }

void checkDryRunMode() {
    statement("Dry run mode turned on with quiet mode as well");
    runEndSwitch("--dry-run", &quietMode, &dryRunMode, &executeMode);
    assertInt(2, quietMode + dryRunMode);
 }

void checkExecuteMode() {
    statement("Execute mode to be turned on with files with '.' in them");
    runEndSwitch(".", &quietMode, &dryRunMode, &executeMode);
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
