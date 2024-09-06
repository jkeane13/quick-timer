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
void runProgram(char* programLocation, int silentOutput);
int convert24ClockToSeconds(char* input);

// ../src/convert_clock.c
void convert12to24(char* timeInput);
void convert24ClockTo12(char* clockTime);

// ../src/play_sound.c
void playSound(int times);

// ../src/countdown.c
void secondsCountdown (int seconds);

// ../convert_quick_clock_to_24
void convertQuickClockto24Hour(char* inputTime);

void usage();

#endif

