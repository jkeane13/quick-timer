#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 100

char inputString[MAX_STRING];

void convertSingleHourAmTime7to24() {
    statement("Convert Single Hour Time String of 7am to 07:00 24 clock...");
    strcpy(inputString, "7am");
    convertInputClockto24(inputString);
    assertString("07:00", inputString);
}

void convertSingleHourAmTime12to24() {
    statement("Convert Single Hour Time String of 12am to 00:00 24 clock...");
    strcpy(inputString, "12am");
    convertInputClockto24(inputString);
    assertString("00:00", inputString);
}

void convertHourPmTime12to24() {
    statement("Convert Single Hour Time String of 12pm to 12:00 24 clock...");
    strcpy(inputString, "12pm");
    convertInputClockto24(inputString);
    assertString("12:00", inputString);
}

void convertSingleHourPmTime7to24() {
    statement("Convert Single Hour Time String of 7pm to 19:00 24 clock...");
    strcpy(inputString, "7pm");
    convertInputClockto24(inputString);
    assertString("19:00", inputString);
}

void convertHourMinAmTime7to24() {
    statement("Convert Single Hour Time String of 7:30am to 07:30 24 clock...");
    strcpy(inputString, "7:30am");
    convertInputClockto24(inputString);
    assertString("07:30", inputString);
}

void convertHourMinAmTime12to24() {
    statement("Convert Double 12th Hour Time String of 12:30am to 00:30 24 clock...");
    strcpy(inputString, "12:30am");
    convertInputClockto24(inputString);
    assertString("00:30", inputString);
}

void convertHourMinPmTime7to24() {
    statement("Convert Double Hour Time String of 7:30pm to 19:30 24 clock...");
    strcpy(inputString, "7:30pm");
    convertInputClockto24(inputString);
    assertString("19:30", inputString);
}

void convertHourMinPmTime12to24() {
    statement("Convert Double 12th Hour Time String of 12:30pm to 12:30 24 clock...");
    strcpy(inputString, "12:30pm");
    convertInputClockto24(inputString);
    assertString("12:30", inputString);
}

void convert24HourClockto12Hour7am() {
    statement("Convert 24 Clock 07:00 to 7am clock...");
    strcpy(inputString, "07:00");
    convert24ClockTo12(inputString);
    assertString("7am", inputString);
}

void convert24HourClockto12Hour730am() {
    statement("Convert 24 Clock 07:30 to 7:30am clock...");
    strcpy(inputString, "07:30");
    convert24ClockTo12(inputString);
    assertString("7:30am", inputString);
}

void convert24HourClockto12Hour730pm() {
    statement("Convert 24 Clock 19:30 to 7:30pm clock...");
    strcpy(inputString, "19:30");
    convert24ClockTo12(inputString);
    assertString("7:30pm", inputString);
}

void convert24HourClockto12Hour12am() {
    statement("Convert 24 Clock 00:00 to 12am clock...");
    strcpy(inputString, "00:00");
    convert24ClockTo12(inputString);
    assertString("12am", inputString);
}

void convert24HourClockto12Hour1230am() {
    statement("Convert 24 Clock 00:30 to 12:30am clock...");
    strcpy(inputString, "00:30");
    convert24ClockTo12(inputString);
    assertString("12:30am", inputString);
}

void convert24HourClockto12Hour12pm() {
    statement("Convert 24 Clock 12:00 to 12pm clock...");
    strcpy(inputString, "12:00");
    convert24ClockTo12(inputString);
    assertString("12pm", inputString);
}

void convert24HourClockto12Hour1230pm() {
    statement("Convert 24 Clock 12:30 to 12:30pm clock...");
    strcpy(inputString, "12:30");
    convert24ClockTo12(inputString);
    assertString("12:30pm", inputString);
}

void run_tests() {
    convertSingleHourAmTime12to24();
    convertSingleHourPmTime7to24();
    convertHourMinAmTime7to24();
    convertHourMinAmTime12to24();
    convertHourMinPmTime7to24();
    convert24HourClockto12Hour7am();
    convert24HourClockto12Hour730am();
    convert24HourClockto12Hour730pm();
    convert24HourClockto12Hour12am();
    convert24HourClockto12Hour1230am();
    convert24HourClockto12Hour12pm();
    convert24HourClockto12Hour1230pm();
}

int main() {
    testTitle("Testing convert 12 clock to 24 tests", __FILE__);
    run_tests();

    return 0;
}

