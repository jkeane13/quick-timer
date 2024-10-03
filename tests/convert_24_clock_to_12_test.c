#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 256

char inputString[MAX_STRING];

void convert1330to12Hour() {
    statement("Should convert 13:30 to 1:30pm");
    strcpy(inputString, "13:30");
    convert24ClockTo12(inputString);
    assertString("1:30pm", inputString);
}

void convert0030to12Hour() {
    statement("Should convert 00:30 to 12:30am");
    strcpy(inputString, "00:30");
    convert24ClockTo12(inputString);
    assertString("12:30am", inputString);
}

void convert0800to12Hour() {
    statement("Should convert 08:00 to 8am");
    strcpy(inputString, "08:00");
    convert24ClockTo12(inputString);
    assertString("8am", inputString);
}

void all_tests() {
    convert1330to12Hour();
    convert0030to12Hour();
    convert0800to12Hour();
}

int main() {
    testTitle("Testing convert 24 clock to 12 tests...",__FILE__);
    all_tests();

    return 0;
}

