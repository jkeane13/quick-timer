#ifndef TIMER_H
#define TIMER_H
#define DISPLAY_OUTPUT 0
#define MAX_STRING 1024

// ../src/timer.c
int checkArgument(char* input);
int promptTimeEnd(int seconds);
int readTimeInput(char *input);
int convertToSeconds(char* input);
int convertArgsToSeconds(char* args);
int convertHoursMinsToSeconds(int hours, int minutes, int seconds);
void convertIntToDoubleString(int number, char stringNumber[]);
void printTimerEndTime (int seconds);
void runEndSwitch(char* argSwitch, int *quietMode, int *dryRunMode, int *executeMode);
void runProgram(char* programLocation, int silentOutput);
int convert24ClockToSeconds(char* input);
void checkFileExists(char* programLocation);

// ../src/convert_clock.c
void convert24ClockTo12(char* clockTime);
void convertInputClockto24(char* timeInput);

// ../src/play_sound.c
void playSound(char* soundFile, int times);

// ../src/countdown.c
void secondsCountdown (int seconds);

// ../convert_quick_clock_to_24
void convertQuickClockto24(char* timeInput);
int getHour(char* timeInput);
int getMinutes(char* timeInput);
void usage(int toggle);
void replaceChar(char* str, char find, char replace);
void removeChar(char *str, char keyCharacter) ;
void printSecondsEndAsClock(int seconds, char* clockType);
int getCurrentHourNumber();
int getCurrentMinuteNumber();
#endif
