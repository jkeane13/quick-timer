#include <stdio.h>
#include <stdbool.h>
#include "../include/timer.h"

#define ALERT_TIMES 1

void usage();

int main(int argc, char *argv[]){
    bool quietMode = false;
    bool dryRunMode = false;
    int seconds = 0;
    if (argc <= 1){
        usage();
        return 1;
    }

    switch (argc){
        case 2:
            seconds = convertArgsToSeconds("", "", argv[1]);
            break;
        case 3:
            checkforEndSwitch(argv[2], &quietMode, &dryRunMode);
            if (quietMode == true || dryRunMode == true)
                seconds = convertArgsToSeconds("", "", argv[1]);
            else
                seconds = convertArgsToSeconds("", argv[1], argv[2]);
            break;
        case 4:
            checkforEndSwitch(argv[3], &quietMode, &dryRunMode);
            if (quietMode == true || dryRunMode == true)
                seconds = convertArgsToSeconds("", argv[1], argv[2]);
            else
                seconds = convertArgsToSeconds(argv[1], argv[2], argv[3]);
            break;
        case 5:
            checkforEndSwitch(argv[4], &quietMode, &dryRunMode);
            if (quietMode == true || dryRunMode == true)
                seconds = convertArgsToSeconds(argv[1], argv[2], argv[3]);
            else{
                usage();
                return 1;
            }
            break;
        default:
            usage();
            return 1;
    }
    timerCountdown(seconds, dryRunMode);
    alert(ALERT_TIMES, quietMode);
}

void usage(void){
    printf("usage:\n"
           "Countdown to the second, minute or hour,  or by a clock time\n"
           "                                                            \n"
           "timer [seconds]                                             \n"
           "timer [minutes] [seconds]                                   \n"
           "timer [hours] [minutes] [seconds]                           \n"
           "timer [clockAM/PM]                                          \n"
           "timer -p                                                    \n"
           "                                                            \n"
           "Switches                                                    \n"
           "-p              prompt time input                           \n"
           "--quiet         Doesn't play the alert                      \n"
           "--dry-run         Doesn't play the alert                    \n"
           "                                                            \n"
           "EXAMPLE: 2 hours, 10 minutes, 1 second                      \n"
           "timer 2 10 1                                                \n"
           "                                                            \n"
           "EXAMPLE: Timer for 5:30 24 hours                            \n"
           "timer 5:30                                                  \n"
           "                                                            \n"
           "EXAMPLE: Timer for 5:30am 12 hour clock                     \n"
           "timer 5:30am                                                \n"
           "                                                            \n"
           "EXAMPLE: Timer for 5pm 12 hour clock                        \n"
           "timer 5pm                                                   \n"
           "                                                            \n"
           );
}

