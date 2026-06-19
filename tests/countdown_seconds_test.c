#include "../include/testing.h"
#include "../include/timer.h"

void timerExecutes() {
  statement("Seconds countdown executes");
  t_seconds_countdown(1);
  assertInt(1, 1);
}

int main(int argc, char **argv) {
  testTitle("Testing countdown_seconds function tests", __FILE__);
  timerExecutes();

  return 0;
}
