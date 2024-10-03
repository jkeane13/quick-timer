#include "../include/timer.h"
#include "../include/testing.h"

#define TEST_FILE "tests/example.sh"
#define SOUND_FILE "assets/duck_quack.mp3"

void playDuckSound() {
    statement("Function should play a duck sound");
    playSound(SOUND_FILE,1);
    assertInt(1,1);
}

void run_tests() {
    playDuckSound();
}

int main(int argc, char **argv) {
    testTitle("Testing play audio function tests", __FILE__);
    run_tests();

    return 0;
}
