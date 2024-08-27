#include <stdio.h>
#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 100

int tests_run = 0;
int result;
int expect;
char inputString[MAX_STRING];
char resultString[MAX_STRING];
char expectString[MAX_STRING];

void assertInt(int expect, int result);
void assertString(char *expect, char* result);

static char * convertIntToDoublestring08() {
    printf("Convert integer 8 to double string \"08\"\t\t\t\t\t");
    strcpy(inputString,"9");
    convertIntToDoubleString(9,inputString);
    strcpy(expectString,"09");

    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}
static char * convertIntToDoublestring12() {
    printf("Convert integer 12 to double string \"12\"\t\t\t\t");
    strcpy(inputString,"12");
    convertIntToDoubleString(12,inputString);
    strcpy(expectString,"12");

    strcpy(resultString, inputString);
    assertString(expectString, resultString);

    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    mu_run_test(convertIntToDoublestring08);
    mu_run_test(convertIntToDoublestring12);
    return 0;
}

int main(int argc, char **argv) {
    printf("Running function tests...\n");
    char *result = all_tests();

    return result != 0;
}

