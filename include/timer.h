#ifndef TIMER_H
#define TIMER_H
#define DISPLAY_OUTPUT 0
#define MAX_STRING 1024

#define PROMPT_TIME_SWITCH "-p"
#define AM_PM_ARGUMENT 'm'
#define TIME_SEPARATOR_ARGUMENT ':'
#define TEST_CHARACTER '?'
#define RANDOM_TEST_VALUE 42

#define QUIET_MODE_SWITCH "--quiet"
#define DRY_RUN_MODE_SWITCH "--dry-run"
#define FILE_DIVIDER '.'

int t_check_argument(char* input);
int t_prompt_time_input(int seconds);
void t_set_mode_switch(const char* arg, int *quiet_mode, int *dry_run_mode, int *execute_mode);
int convertToSeconds(char* input);
int convertArgsToSeconds(char* args);
int convertHoursMinsToSeconds(int hours, int minutes, int seconds);
void convertIntToDoubleString(int number, char stringNumber[]);
void printTimerEndTime (int seconds);
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
