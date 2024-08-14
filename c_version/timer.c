#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "../assets/duck_quack.mp3"
#define MAC_PLAYER "afplay"
#define LINUX_PLAYER "mpg123"

void inputTimer(int *seconds);
void runTimer(int seconds);
void alert();

int main(void){
    int seconds;

    inputTimer(&seconds);
    runTimer(seconds);
    alert();

    return 0;
}

void inputTimer(int *seconds){
    printf("Enter countdown time in seconds: ");
    scanf("%d", seconds);
}

void runTimer(int seconds){
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
}

void alert(){
    char soundPlayer[100];

    printf("\rTime's up!\n");
    #if defined(__APPLE__)
        strcpy (soundPlayer, MAC_PLAYER);
    #elif defined(__linux__)
        strcpy (soundPlayer, LINUX_PLAYER);
    #endif

    strcat (soundPlayer," ");
    strcat (soundPlayer,FILENAME);
    strcat (soundPlayer," >/dev/null 2>&1");
    system(soundPlayer);

}
