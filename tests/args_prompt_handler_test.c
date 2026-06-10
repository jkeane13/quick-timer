#include "../include/timer.h"
#include "../include/testing.h"

int main() {
    testTitle("Testing argument prompt", __FILE__);
    statement("t_prompt_time_input requires interactive stdin - not suitable for unit testing");

    return 0;
}
