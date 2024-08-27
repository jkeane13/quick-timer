#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

// ../src/timer.c
int checkArgument(char* input);
int promptTimeEnd(int seconds);
int convertToSeconds(char* input);
int convertArgsToSeconds(char* args);
int convertHoursMinsToSeconds(int hours, int minutes, int seconds);
void convertIntToDoubleString(int number, char stringNumber[]);
void printTimerEndTime (int seconds);
void runEndSwitch(char* argSwitch, int *quietMode, int *dryRunMode, int *executeMode);
void runProgram(char* programLocation);

// ../src/convert_clock.c
void convert12to24(char* timeInput);
void convert24ClockTo12(char* clockTime);

// ../src/play_sound.c
void playSound(int times);

// ../src/countdown.c
void secondsCountdown (int seconds);

#endif

