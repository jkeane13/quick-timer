#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

int checkArgument(char* input);
int promptTimer();
int convertToSeconds(char* input);
int convertHoursMinsToSeconds(char* hoursString, char* minutesString, char* secondsString);
void runTimer (int seconds);
void alert(int times, bool quietMode);
void checkforEndSwitch(char* argument, bool* quietMode, bool* dryRun);

#endif

