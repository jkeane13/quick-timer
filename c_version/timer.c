#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    int seconds = 0;

    printf("Enter countdown time in seconds: ");
    scanf("%d", &seconds);
    printf("\e[?25l"); // disable cursor

    while(seconds > 0){

        int hours = seconds / 3600;
        int minutes = (seconds  % 3600) / 60;
        seconds = seconds  % 60;

        printf ("\r%02d:%02d:%02d", hours, minutes, seconds);

        fflush(stdout);

        clock_t stop = clock() + CLOCKS_PER_SEC;
        while (clock() < stop) {}

        seconds--;
        printf("\33[2K\r"); // clear line
    }

    printf("\rTime's up!\n");
    #if defined(__APPLE__)
        system("afplay ../assets/duck_quack.mp3");
    #endif
    return 0;
}

