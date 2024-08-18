#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

int checkArgument(char* input);
int promptTimer();
int convertToSeconds(char* input);
int convertArgsToSeconds(char* hoursString, char* minutesString, char* secondsString);
void runTimer (int seconds);
void alert(int times, bool quiet);

#endif

