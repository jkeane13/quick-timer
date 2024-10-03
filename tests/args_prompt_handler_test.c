#include "../include/timer.h"
#include "../include/testing.h"

void testTimePrompt() {
    statement("Time prompt function can be triggered");
    assertInt(-1, promptTimeEnd(-1));
}

int main() {
    testTitle("Testing argument prompt", __FILE__);
    testTimePrompt();

    return 0;
}
