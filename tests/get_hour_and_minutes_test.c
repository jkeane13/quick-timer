#include "../include/timer.h"
#include "../include/testing.h"

void getSingleHour() {
    statement("Get the single hour of 3:30...");
    assertInt(3, getHour("3:30"));
}

void getSingleHourFromAmPm() {
    statement("Get the single hour of 4am...");
    assertInt(4, getHour("4am"));
}

void getDoubleHourFromAmPm() {
    statement("Get the single hour of 10am...");
    assertInt(10, getHour("10am"));
}

void getDoubleHour() {
    statement("Get the double hour of 12:30...");
    assertInt(12, getHour("12:30"));
}

void getSingleMinutes() {
    statement("Get the single minute of 6:09...");
    assertInt(9, getMinutes("6:09"));
}

void getDoubleMinutes() {
    statement("Get the double minutes of 7:30...");
    assertInt(30, getMinutes("7:30"));
}

void getDoubleFullHour() {
    statement("Get the single hour of full time 5:30am...");
    assertInt(5, getHour("5:30am"));
}

void getDoubleFullMinute() {
    statement("Get the double minutes of a full time 12:24am...");
    assertInt(24, getMinutes("12:24am"));
}

void run_tests() {
    getSingleHour();
    getDoubleHour();
    getSingleHourFromAmPm();
    getDoubleHourFromAmPm();
    getSingleMinutes();
    getDoubleMinutes();
    getDoubleFullHour();
    getDoubleFullMinute();
}

int main(int argc, char **argv) {
    testTitle("Testing hour and minutes functions", __FILE__);
    run_tests();

    return 0;
}
