#include "../include/timer.h"
#include "../include/testing.h"

void timerExecutes() {
    statement("Seconds countdown executes");
    secondsCountdown(1);
    assertInt(1, 1);
}

int main(int argc, char **argv) {
    testTitle("Testing countdown_seconds function tests", __FILE__);
    timerExecutes();

    return 0;
}
