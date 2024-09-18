#include <stdio.h>
#include "../include/timer.h"
#include "../include/testing.h"

int result, expect;
int tests_run = 0;

static char * checkArg() {
    statement("Check if the argument has been added");
    expect = 42;
    result = checkArgument("?");
    assertInt(expect, result);
    mu_assert("", result == expect);

    return 0;
}

static char * all_tests() {
    run_test(checkArg);

    return 0;
}

int main(int argc, char **argv) {
    printf("-- args_checker_handler_test.c --\n");
    printf("Testing argument prompt...\n");
    char *result = all_tests();

    if (result != 0)
        printf("%s\n", result);

    printf("Tests run: %d\n", tests_run);
    return result != 0;
}
