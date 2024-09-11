#include <stdio.h>
#include "../include/timer.h"

void usage(int toggle){
    if (toggle == 1 ){
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
}
