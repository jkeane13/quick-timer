#include "../include/testing.h"
#include "../include/timer.h"

#define TEST_FILE "tests/example.sh"

void executeUsage() {
  statement("Usage should be able to activate");
  t_usage(0);
  assertInt(1, 1);
}

int main(int argc, char **argv) {
  testTitle("Testing t_usage function tests", __FILE__);
  executeUsage();

  return 0;
}
