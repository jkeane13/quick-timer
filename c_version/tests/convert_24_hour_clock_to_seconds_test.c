#include <stdio.h>
#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 100
#define TEST_FILE "tests/example.sh"

int tests_run = 0;
int result;
int expect;
char inputString[MAX_STRING];
char resultString[MAX_STRING];
char expectString[MAX_STRING];

static char * convert321HoursMinsToSeconds(){
    printf("Convert 3 Hours, 2 mins and 1 second to seconds\t\t\t\t");
    result = convertHoursMinsToSeconds(3,2,1);
    expect = 10921;

    assertInt(result, expect);

    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    mu_run_test(convert321HoursMinsToSeconds);
    return 0;
}

int main(int argc, char **argv) {
    printf("-- convert_24_hour_clock_to_seconds.c --\n");
    printf("Testing 24 hour clock to seconds functions...\n");
    char *result = all_tests();

    return result != 0;
}

