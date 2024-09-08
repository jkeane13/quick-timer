#include <stdio.h>
#include "../include/timer.h"
#include "../include/testing.h"

int result, expect;
int tests_run = 0;

static char * testTimePrompt() {
    printf("Time prompt function can be triggered\t\t\t\t\t");
    expect = -1;
    result = promptTimeEnd(-1);
    assertInt(expect, result);
    mu_assert("", result == expect);

    return 0;
}

static char * all_tests() {
    mu_run_test(testTimePrompt);

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
