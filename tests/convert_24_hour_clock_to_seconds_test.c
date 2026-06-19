#include "../include/testing.h"
#include "../include/timer.h"

void convert321HoursMinsToSeconds() {
  statement("Convert 3 Hours, 2 mins and 1 second to seconds");
  assertInt(10921, convert_hours_mins_to_seconds(3, 2, 1));
}

int main(int argc, char **argv) {
  testTitle("Testing 24 hour clock to seconds functions", __FILE__);
  convert321HoursMinsToSeconds();

  return 0;
}
