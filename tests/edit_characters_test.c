#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"
#include "../include/edit_characters.h"

char inputString[MAX_STRING];

void replace_characters_in_a_string() {
    statement("Replace characters in a string");
    strcpy(inputString,"Testing123");
    replace_char(inputString,'g','e');
    assertString(inputString, "Testine123");
}

void removesCharactersInAString() {
    statement("Remove characters in a string");
    strcpy(inputString,"Testing123");
    remove_char(inputString,'e');
    assertString(inputString, "Tsting123");
}

void run_tests() {
    replace_characters_in_a_string();
    removesCharactersInAString();
}

int main(void) {
    testTitle("Testing run application function tests",__FILE__);
    run_tests();

    return 0;
}
