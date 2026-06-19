#include "../include/testing.h"
#include "../include/timer.h"
#include <string.h>

char input_string[MAX_STRING], expect_string[MAX_STRING];

void convert7quickClockTo24() {
  statement("Convert 7 quick clock to 7:00 or 19:00");
  strcpy(input_string, "7:00");
  t_convert_quick_clock_to_24(input_string);
  if (t_get_current_hour_number() <= 7)
    strcpy(expect_string, "19:00");
  if (t_get_current_hour_number() >= 19)
    strcpy(expect_string, "07:00");
  if (t_get_current_hour_number() >= 7 && t_get_current_minute_number() > 1)
    strcpy(expect_string, "19:00");
  if (t_get_current_hour_number() >= 19 && t_get_current_minute_number() > 1)
    strcpy(expect_string, "07:00");

  assertString(expect_string, input_string);
}

void convert12quickClockTo24() {
  statement("Convert 12 quick clock to 12:00 or 00:00");
  strcpy(input_string, "12:00");
  t_convert_quick_clock_to_24(input_string);
  if (t_get_current_hour_number() > 12 && t_get_current_hour_number() < 24)
    strcpy(expect_string, "00:00");
  if (t_get_current_hour_number() < 12)
    strcpy(expect_string, "12:00");
  if (t_get_current_hour_number() == 12 && t_get_current_minute_number() > 1)
    strcpy(expect_string, "00:00");
  if (t_get_current_hour_number() == 12 && t_get_current_minute_number() > 1)
    strcpy(expect_string, "12:00");

  assertString(expect_string, input_string);
}

int main(int argc, char **argv) {
  testTitle("Testing convert quickclock to 24 hour functions", __FILE__);
  convert7quickClockTo24();
  convert12quickClockTo24();

  return 0;
}
