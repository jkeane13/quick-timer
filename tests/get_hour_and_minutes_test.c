#include <stdio.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define ENTRIES 6

char entryString[ENTRIES][7] = {"3:30", "4am", "10am",
                                "12:30", "5:30am", "12am"};
int expectInt[ENTRIES] = {3, 4, 10, 12, 5, 12};

char entryMinString[ENTRIES][7] = {"6:09", "7:30", "12:23am",
                                   "12am", "11:34", "3pm"};
int expectMinInt[ENTRIES] = {9, 30, 23, 0, 34, 0};

void getHourofEntry() {
    for (int i = 0; i < ENTRIES; i++){
        printf("Get the hour %d from %s\n", expectInt[i], entryString[i]);
        assertInt(expectInt[i], getHour(entryString[i]));
    }
}

void getMinuteofEntry() {
    for (int i = 0; i < ENTRIES; i++){
        printf("Get the minute %d from %s\n",
                expectMinInt[i], entryMinString[i]);
        assertInt(expectMinInt[i], getMinutes(entryMinString[i]));
    }
}

void run_tests() {
    getHourofEntry();
    getMinuteofEntry();
}

int main(int argc, char **argv) {
    testTitle("Testing hour and minutes functions", __FILE__);
    run_tests();

    return 0;
}
