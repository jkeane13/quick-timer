#include "../include/testing.h"
#include "../include/timer.h"

void hour_mins_seconds() {
  statement("Convert hours, mins, seconds to just seconds...");
  assertInt(10921, convert_hours_mins_to_seconds(3, 2, 1));
}

void args_sec_to_seconds() {
  statement("Convert 50 seconds string argument to seconds...");
  assertInt(50, t_convert_args_to_seconds("50"));
}

void args_min_to_seconds() {
  char min_args[] = "2 50";
  statement("Convert 2 minutes and 50 seconds string argument to seconds...");
  assertInt(170, t_convert_args_to_seconds(min_args));
}

void args_hour_to_seconds() {
  char hour_args[] = "1 12 50";
  statement("Convert 1 hour, 12 mins and 50 seconds args to just seconds...");
  assertInt(4370, t_convert_args_to_seconds(hour_args));
}

void run_tests() {
  hour_mins_seconds();
  args_sec_to_seconds();
  args_min_to_seconds();
  args_hour_to_seconds();
}

int main(int argc, char **argv) {
  testTitle("Testing convert args to seconds functions", __FILE__);
  run_tests();

  return 0;
}
