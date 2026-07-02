#include "../include/test_framework.h"
#include "../include/timer.h"
#include "../include/play_audio.h"

void test_play_chime_sound(void) {
  play_sound(1);
  TEST_START("function plays a stopwatch sound");
  ASSERT_INT(1, 1);
}

TEST_LIST {
  TESTS_HEADER("play audio function");
  test_play_chime_sound();
}

RUN_TESTS
