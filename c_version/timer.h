#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

int checkArgument(char* input);
int promptTimer();
int convertToSeconds(char* input);
int convertArgsToSeconds(char* hoursString, char* minutesString, char* secondsString);
int convertHoursMinsToSeconds(int hours, int minutes, int seconds);
void convert12to24(char* timeInput);
void convert24ClockTo12(char* clock24Time);
void runTimer (int seconds, bool dryRunMode);
void alert(int times, bool quietMode);
void checkforEndSwitch(char* argument, bool* quietMode, bool* dryRun);

#endif

