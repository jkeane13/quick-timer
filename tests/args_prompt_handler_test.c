#include "../include/timer.h"
#include "../include/testing.h"

void testTimePrompt() {
    statement("Time prompt function can be triggered");
    assertInt(-1, promptTimeEnd(-1));
}

void run_tests() {
    testTimePrompt();
}

int main() {
    testTitle("Testing argument prompt", __FILE__);
    run_tests();

    return 0;
}
