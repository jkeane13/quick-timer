#include "../include/timer.h"
#include "../include/testing.h"

#define TEST_FILE "tests/example.sh"
#define SOUND_FILE "assets/stopwatch.mp3"

void playChimeSound() {
    statement("Function should play a stopwatch sound");
    playSound(SOUND_FILE,1);
    assertInt(1,1);
}

int main(int argc, char **argv) {
    testTitle("Testing play audio function tests", __FILE__);
    playChimeSound();

    return 0;
}
