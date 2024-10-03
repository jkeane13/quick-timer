#include "../include/timer.h"
#include "../include/testing.h"

void timerExecutes() {
    statement("Seconds countdown executes");
    secondsCountdown(1);
    assertInt(1, 1);
}

void run_tests() {
    timerExecutes();
}

int main(int argc, char **argv) {
    testTitle("Testing countdown_seconds function tests", __FILE__);
    run_tests();

    return 0;
}
