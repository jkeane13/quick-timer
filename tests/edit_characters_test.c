#include <stdio.h>
#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 256
#define TEST_FILE "tests/example.sh"
#define SOUND_FILE "assets/duck_quack.mp3"

int tests_run = 0;
int result, expect;
char inputString[20];
char expectString[20];

static char * replaceCharactersInAString() {
    statement("Replace characters in a string");
    strcpy(inputString,"Testing123");
    replaceChar(inputString,'g','e');
    strcpy(expectString, "Testine123");
    assertString(inputString, expectString);

    mu_assert("", result == expect);
    return 0;
}
static char * RemovesCharactersInAString() {
    statement("Remove characters in a string");
    strcpy(inputString,"Testing123");
    removeChar(inputString,'e');
    strcpy(expectString, "Tsting123");
    assertString(inputString, expectString);

    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    run_test(replaceCharactersInAString);
    run_test(RemovesCharactersInAString);
    return 0;
}

int main(int argc, char **argv) {
    printf("-- run_application.c --\n");
    printf("Testing run application function tests...\n");

    char *result = all_tests();

    return result != 0;
}
