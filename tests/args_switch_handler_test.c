#include "../include/timer.h"
#include "../include/testing.h"

int quiet_mode = 0, dry_run_mode = 0, execute_mode = 0;

void checkQuietMode() {
    statement("Quiet Mode can be turned on");
    quiet_mode = 0;
    dry_run_mode = 0;
    execute_mode = 0;
    t_set_mode_switch("--quiet", &quiet_mode, &dry_run_mode, &execute_mode);
    assertInt(1, quiet_mode);
 }

void checkDryRunMode() {
    statement("Dry run mode turned on with quiet mode as well");
    quiet_mode = 0;
    dry_run_mode = 0;
    execute_mode = 0;
    t_set_mode_switch("--dry-run", &quiet_mode, &dry_run_mode, &execute_mode);
    assertInt(2, quiet_mode + dry_run_mode);
 }

void checkExecuteMode() {
    statement("Execute mode to be turned on with files with '.' in them");
    quiet_mode = 0;
    dry_run_mode = 0;
    execute_mode = 0;
    t_set_mode_switch(".", &quiet_mode, &dry_run_mode, &execute_mode);
    assertInt(2, quiet_mode + execute_mode);
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
