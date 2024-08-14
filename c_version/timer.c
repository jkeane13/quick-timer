#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "../assets/duck_quack.mp3"
#define MAC_PLAYER "afplay"
#define LINUX_PLAYER "mpg123"

void inputTimer(int *seconds);
void alert();

int main(int argc, char *argv[]){
    int seconds = 0;

    if (argc <= 1){
        printf("Usage: timer [hour minute second] or -p switch to prompt\n");
        return 1;
    }

    if (argc == 2 || strcmp(argv[1],"-p") == 0 ){
        seconds = atoi(argv[1]);
        if (seconds == 0)
            inputTimer(&seconds);
    }

    if (argc == 3){
        seconds = atoi(argv[1]) * 60;
        seconds += atoi(argv[2]);
    }

    if (argc == 4){
        seconds = atoi(argv[1]) * 60 * 60;
        seconds += atoi(argv[2]) * 60;
        seconds += atoi(argv[3]);
    }

    // clock() does not like being put into a function, mucks with CPU execution?
    // May need to try gettimeofday function instead, if I want to put this into a function.
    // Example: <sys/time.h> and gettimeofday()

    printf("\e[?25l"); // disable cursor

    while(seconds > 0){

    int h = seconds / 3600;
    int m = (seconds  % 3600) / 60;
    int s = seconds  % 60;

    printf ("\r%02d:%02d:%02d", h, m, s);

    fflush(stdout);

    clock_t stop = clock() + CLOCKS_PER_SEC;
    while (clock() < stop) {}

    seconds--;
    printf("\33[2K\r"); // clear line
    }

    printf("\rTime's up!\n");
    alert();

    return 0;
}

void inputTimer(int *seconds){
    printf("Enter countdown time in seconds: ");
    scanf("%d", seconds);
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
