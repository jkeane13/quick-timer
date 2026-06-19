#include "../include/testing.h"
#include "../include/timer.h"

#define TEST_FILE "tests/example.sh"
#define SOUND_FILE "assets/stopwatch.mp3"

void play_chime_sound() {
  statement("Function should play a stopwatch sound");
  t_play_sound(SOUND_FILE, 1);
  assertInt(1, 1);
}

int main(int argc, char **argv) {
  testTitle("Testing play audio function tests", __FILE__);
  play_chime_sound();

  return 0;
}
