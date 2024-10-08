#include "../include/timer.h"
#include "../include/testing.h"

#define TEST_FILE "tests/example.sh"

void executeUsage() {
    statement("Usage should be able to activate");
    usage(0);
    assertInt(1,1);
}

int main(int argc, char **argv) {
    testTitle("Testing usage function tests",__FILE__);
    executeUsage();

    return 0;
}
