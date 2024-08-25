#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

// ../src/timer.c
int checkArgument(char* input);
int promptTimer();
int convertToSeconds(char* input);
int convertArgsToSeconds(char* hoursString, char* minutesString, char* secondsString);
int convertHoursMinsToSeconds(int hours, int minutes, int seconds);
void timerCountdown (int seconds, bool dryRunMode);
void checkforEndSwitch(char* argument, bool* quietMode, bool* dryRun);

// ../src/convert_clock.c
void convert12to24(char* timeInput);
void convert24ClockTo12(char* clockTime);

// ../src/play_sound.c
void alert(int times, bool quietMode);

#endif

