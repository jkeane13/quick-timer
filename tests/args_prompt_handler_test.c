#include "../include/testing.h"
#include "../include/timer.h"

int main() {
  testTitle("Testing argument prompt", __FILE__);
  statement("t_prompt_time_input requires interactive stdin - not suitable for "
            "unit testing");

  return 0;
}
