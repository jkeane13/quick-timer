#include <stdio.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define STR 10

char entryString[STR][STR] = {"13:30", "00:30", "08:00", "07:00", "07:30",
                              "19:30","00:00", "00:30", "12:00", "12:30" };
char expectString[STR][STR] = {"1:30pm", "12:30am", "8am", "7am","7:30am",
                               "7:30pm", "12am", "12:30am", "12pm", "12:30pm" };

void convertTime24TimetoAmPm() {
    for (int i = 0; i < STR; i++){
        printf("Convert %s to %s 12 hour clock\n",
                entryString[i], expectString[i]);
        convert24ClockTo12(entryString[i]);
        assertString(expectString[i], entryString[i]);
    }
}

void run_tests() {
    convertTime24TimetoAmPm();
}

int main() {
    testTitle("Testing convert 24 clock to 12 tests...",__FILE__);
    run_tests();

    return 0;
}

