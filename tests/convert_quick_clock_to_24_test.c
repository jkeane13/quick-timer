#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

char inputString[MAX_STRING], expectString[MAX_STRING];

void convert7quickClockTo24() {
    statement("Convert 7 quick clock to 7:00 or 19:00");
    strcpy(inputString,"7:00");
    convertQuickClockto24(inputString);
    if (getCurrentHourNumber() <= 7)
        strcpy(expectString,"19:00");
    if (getCurrentHourNumber() >= 19)
        strcpy(expectString,"07:00");
    if (getCurrentHourNumber() >= 7 && getCurrentMinuteNumber() > 1)
        strcpy(expectString,"19:00");
    if (getCurrentHourNumber() >= 19 && getCurrentMinuteNumber() > 1)
        strcpy(expectString,"07:00");

    assertString(expectString, inputString);
}

void convert12quickClockTo24() {
    statement("Convert 12 quick clock to 12:00 or 00:00");
    strcpy(inputString,"12:00");
    convertQuickClockto24(inputString);
    if (getCurrentHourNumber() > 12 && getCurrentHourNumber() < 24)
        strcpy(expectString,"00:00");
    if (getCurrentHourNumber() < 12 )
        strcpy(expectString,"12:00");
    if (getCurrentHourNumber() == 12 && getCurrentMinuteNumber() > 1)
        strcpy(expectString,"00:00");
    if (getCurrentHourNumber() == 12 && getCurrentMinuteNumber() > 1)
        strcpy(expectString,"12:00");

    assertString(expectString, inputString);
}

int main(int argc, char **argv) {
    testTitle("Testing convert quickclock to 24 hour functions", __FILE__);
    convert7quickClockTo24();
    convert12quickClockTo24();

    return 0;
}

