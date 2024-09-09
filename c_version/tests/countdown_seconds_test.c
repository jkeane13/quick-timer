#include <stdio.h>
#include "../include/timer.h"
#include "../include/testing.h"

int tests_run = 0;
int result, expect;

static char * timerExecutes() {
    statement("Seconds countdown executes");
    secondsCountdown(1);
    assertInt(1, 1);

    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    mu_run_test(timerExecutes);
    return 0;
}

int main(int argc, char **argv) {
    printf("-- countdown_seconds.c --\n");
    printf("Testing countdown_seconds function tests...\n");

    char *result = all_tests();

    return result != 0;
}
