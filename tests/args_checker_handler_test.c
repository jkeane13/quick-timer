#include "../include/timer.h"
#include "../include/testing.h"

void checkArg() {
    statement("Check if an argument can be added");
    assertInt(42, checkArgument("?"));
}

void run_tests() {
    checkArg();
}

int main() {
    testTitle("Testing argument handler",__FILE__);
    run_tests();

    return 0;
}
