#include "../include/timer.h"
#include "../include/testing.h"

void checkArg() {
    statement("Check if an argument can be added");
    assertInt(42, t_check_argument("?"));
}

int main() {
    testTitle("Testing argument handler",__FILE__);
    checkArg();

    return 0;
}
