#ifndef TIMER_H
#define TIMER_H
#define DISPLAY_OUTPUT 0
#define MAX_STRING 1024

#define PROMPT_TIME_SWITCH "-p"
#define AM_PM_ARGUMENT 'm'
#define TIME_SEPARATOR_ARGUMENT ':'
#define TEST_CHARACTER '?'
#define RANDOM_TEST_VALUE 42
#define POLLING_WINDOW 50

#define MAX_CLOCK_12H 9 // Room for "12:00am\0"
#define HOURS_IN_HALF_DAY 12

#define QUIET_MODE_SWITCH "--quiet"
#define DRY_RUN_MODE_SWITCH "--dry-run"
#define FILE_DIVIDER '.'

#define SECONDS_IN_DAY 86400
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

#define HIDE 0
#define SHOW 1

#define CLOCK_24_SIZE 6

#define VALID 0
#define INVALID 1

int t_check_argument(char* input);
int t_convert_24_clock_to_seconds(const char* input);
int t_convert_args_to_seconds(char* args);
int t_get_current_hour_number();
int t_get_current_minute_number();
int t_get_hour(char* time_input);
int t_get_minutes(char* time_input);
int t_prompt_time_input(int seconds);
int t_seconds_countdown(int seconds);
void t_convert_24_hour_clock_to_12(char* clock_time);
void t_convert_input_clock_to_24(char* time_input);
void t_convert_quick_clock_to_24(char* time_input);
void t_play_sound(char* sound_file, int times);
void t_set_mode_switch(const char* arg, int *quiet_mode, int *dry_run_mode, int *execute_mode);
int convertToSeconds(char* input);
int convert_hours_mins_to_seconds(int hours, int minutes, int seconds);
void convertIntToDoubleString(int number, char stringNumber[]);
void printTimerEndTime (int seconds);
void runProgram(char* programLocation, int silentOutput);
void checkFileExists(char* programLocation);
void usage(int toggle);
void printSecondsEndAsClock(int seconds, char* clockType);
#endif
