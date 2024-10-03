#include <string.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 100
char inputString[MAX_STRING];

void replaceCharactersInAString() {
    statement("Replace characters in a string");
    strcpy(inputString,"Testing123");
    replaceChar(inputString,'g','e');
    assertString(inputString, "Testine123");
}

void removesCharactersInAString() {
    statement("Remove characters in a string");
    strcpy(inputString,"Testing123");
    removeChar(inputString,'e');
    assertString(inputString, "Tsting123");
}

void run_tests() {
    replaceCharactersInAString();
    removesCharactersInAString();
}

int main(int argc, char **argv) {
    testTitle("Testing run application function tests",__FILE__);
    run_tests();

    return 0;
}
