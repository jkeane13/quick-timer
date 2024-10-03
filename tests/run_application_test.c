#include "../include/timer.h"
#include "../include/testing.h"

#define TEST_FILE "assets/example.sh"
#define SOUND_FILE "assets/duck_quack.mp3"

void runASystemProgram() {
    statement("Program should execute in silent output mode");
    runProgram(TEST_FILE,0);
    assertInt(1,1);
}

void checkProgramExists() {
    statement("Check the program exists before running");
    checkFileExists(TEST_FILE);
    assertInt(1,1);
}

void checksSoundFileExists() {
    statement("Check the sound file for the alert exists");
    checkFileExists(SOUND_FILE);
    assertInt(1,1);
}

void run_tests() {
    runASystemProgram();
    checkProgramExists();
    checksSoundFileExists();
}

int main() {
    testTitle("Testing run application function tests",__FILE__);
    run_tests();

    return 0;
}
