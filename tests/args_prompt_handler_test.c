#include <stdio.h>
#include "../include/timer.h"
#include "../include/testing.h"

int result, expect;
int tests_run = 0;

static char * testTimePrompt() {
    statement("Time prompt function can be triggered");
    expect = -1;
    result = promptTimeEnd(-1);
    assertInt(expect, result);
    mu_assert("", result == expect);

    return 0;
}

static char * timeInputIsRead() {
    statement("The Input for null string is 0");
    expect = 0;
    result = readTimeInput("\n");
    assertInt(expect, result);
    mu_assert("", result == expect);

    return 0;
}

static char * all_tests() {
    run_test(testTimePrompt);
    /* run_test(timeInputIsRead); // stdin based: to be toggled */

    return 0;
}

int main(int argc, char **argv) {
    printf("-- args_prompt_handler_test.c --\n");
    printf("Testing argument prompt...\n");
    char *result = all_tests();

    if (result != 0)
        printf("%s\n", result);

    printf("Tests run: %d\n", tests_run);
    return result != 0;
}
