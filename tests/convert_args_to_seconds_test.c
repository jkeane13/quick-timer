#include "../include/timer.h"
#include "../include/testing.h"

void hourMinsSeconds() {
    statement("Convert hours, mins, seconds to just seconds...");
    assertInt(10921, convertHoursMinsToSeconds(3,2,1));
 }

void argsSecToSeconds() {
    statement("Convert 50 seconds string argument to seconds...");
    assertInt(50, convertArgsToSeconds("50"));
}

void argsMinToSeconds() {
    char minArgs[] = "2 50";
    statement("Convert 2 minutes and 50 seconds string argument to seconds...");
    assertInt(170, convertArgsToSeconds(minArgs));
}

void argsHourToSeconds() {
    char hourArgs[] = "1 12 50";
    statement("Convert 1 hour, 12 mins and 50 seconds args to just seconds...");
    assertInt(4370, convertArgsToSeconds(hourArgs));
}

void run_tests() {
    hourMinsSeconds();
    argsSecToSeconds();
    argsMinToSeconds();
    argsHourToSeconds();
}

int main(int argc, char **argv) {
    testTitle("Testing convert args to seconds functions",__FILE__);
    run_tests();

    return 0;
}
