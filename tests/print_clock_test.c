#include "../include/timer.h"
#include "../include/testing.h"

void print24HourClockHourLater() {
    statement("Print 24 hour clock end time an hour ahead");
    printSecondsEndAsClock(3600, "24Hour");
    assertInt(1, 1);
}

void print12HourClockHourLater() {
    statement("Print 12 hour clock end time an hour ahead");
    printSecondsEndAsClock(3600, "12Hour");
    assertInt(1, 1);
}

void printDefaultEndTime() {
    statement("Print 12 hour clock default timer 30 mins ahead");
    printSecondsEndAsClock(1800, "12Hour");
    assertInt(1, 1);
}

void run_tests() {
    print24HourClockHourLater();
    print12HourClockHourLater();
    printDefaultEndTime();
}

int main(int argc, char **argv) {
    testTitle("Testing countdown_seconds function tests",__FILE__);
    run_tests();

    return 0;
}
