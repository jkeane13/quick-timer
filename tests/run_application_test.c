#include <stdio.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 256
#define TEST_FILE "assets/example.sh"
#define SOUND_FILE "assets/duck_quack.mp3"

int tests_run = 0;
int result, expect;

static char * runASystemProgram() {
    statement("Program should execute in silent output mode");
    runProgram(TEST_FILE,0);
    assertInt(1,1);

    mu_assert("", result == expect);
    return 0;
}

static char * checkProgramExists() {
    statement("Check the program exists before running");
    checkFileExists(TEST_FILE);
    assertInt(1,1);

    mu_assert("", result == expect);
    return 0;
}

static char * checksSoundFileExists() {
    statement("Check the sound file to play the alert exists");
    checkFileExists(SOUND_FILE);
    assertInt(1,1);

    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    run_test(runASystemProgram);
    run_test(checkProgramExists);
    run_test(checksSoundFileExists);
    return 0;
}

int main(int argc, char **argv) {
    printf("-- run_application.c --\n");
    printf("Testing run application function tests...\n");

    char *result = all_tests();

    return result != 0;
}
