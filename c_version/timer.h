#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

int checkArgument(char* input);
int promptTimer();
int convertToSeconds(char* input);
int convertHoursMinsToSeconds(char* hoursString, char* minutesString, char* secondsString);
int convertHoursMinsToSecondsInt(int hours, int minutes, int seconds);
void runTimer (int seconds, bool dryRunMode);
void alert(int times, bool quietMode);
void checkforEndSwitch(char* argument, bool* quietMode, bool* dryRun);

#endif

