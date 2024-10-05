#include <stdio.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define STR 8

char entryString[STR][STR] = {"7am", "12am", "12pm", "7pm", "7:30am",
                            "12:30am","7:30pm", "12:30pm" };
char expectString[STR][STR] = {"07:00", "00:00", "12:00", "19:00","07:30",
                             "00:30", "19:30", "12:30" };

void convertTimeAmPmTimeto24() {
    for (int i = 0; i < STR; i++){
        printf("Convert %s to %s 24 hour clock\n",
                entryString[i],
                expectString[i]);
        convertInputClockto24(entryString[i]);
        assertString(expectString[i], entryString[i]);
    }
}

void run_tests() {
    convertTimeAmPmTimeto24();
}

int main() {
    testTitle("Testing convert 12 clock to 24 tests", __FILE__);
    run_tests();

    return 0;
}

