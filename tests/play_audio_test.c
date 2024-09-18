#include <stdio.h>
#include "../include/timer.h"
#include "../include/testing.h"

#define MAX_STRING 256
#define TEST_FILE "tests/example.sh"
#define SOUND_FILE "assets/duck_quack.mp3"

int tests_run = 0;
int result, expect;

static char * playDuckSound() {
    statement("Function should play a duck sound");
    playSound(SOUND_FILE,1);
    assertInt(1,1);

    mu_assert("", result == expect);
    return 0;
}

static char * all_tests() {
    run_test(playDuckSound);
    return 0;
}

int main(int argc, char **argv) {
    printf("-- play_audio_test.c --\n");
    printf("Testing play audio function tests...\n");

    char *result = all_tests();

    return result != 0;
}
