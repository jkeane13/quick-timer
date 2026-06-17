#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <curses.h>
#include <locale.h>
#include "../include/timer.h"

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <curses.h>
#include <locale.h>
#include "../include/timer.h"


static void init_screen(void) {
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    timeout(POLLING_WINDOW); // 50ms non-blocking polling rate
}

static void draw_countdown(int remaining_seconds, int paused) {
    int h = remaining_seconds / SECONDS_IN_HOUR;
    int m = (remaining_seconds % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;
    int s = remaining_seconds % SECONDS_IN_MINUTE;

    move(0, 0);
    clrtoeol();
    if (paused) {
        printw("%02d:%02d:%02d [PAUSED - press Space to resume]", h, m, s);
    } else {
        printw("%02d:%02d:%02d [press Space to pause]", h, m, s);
    }
}

static void draw_progress_bar(int remaining, int total) {
    double ratio = (total > 0) ? (double)remaining / (double)total : 0.0;
    int percentage = (int)(ratio * 100);
    int bar_width = 30;
    int filled = (int)(ratio * bar_width);

    if (filled < 0) filled = 0;
    if (filled > bar_width) filled = bar_width;

    move(1, 0);
    clrtoeol();
    printw("[");
    for (int i = 0; i < bar_width; i++) {
        if (i < filled) {
            printw("█");
        } else {
            printw("░");
        }
    }
    printw("] %d%%", percentage);
}

static void update_display(int remaining, int total, int paused) {
    draw_countdown(remaining, paused);
    draw_progress_bar(remaining, total);
    refresh();
}

static void handle_time_tick(int *remaining_seconds, time_t *next_tick, int paused) {
    if (paused) return;

    time_t now = time(NULL);
    if (now >= *next_tick) {
        (*remaining_seconds)--;
        *next_tick = now + 1;
    }
}

int t_seconds_countdown(int seconds) {
    init_screen();

    int remaining_seconds = seconds;
    int paused = 0;
    time_t next_tick = time(NULL) + 1;

    while (remaining_seconds > 0) {
        update_display(remaining_seconds, seconds, paused);

        int ch = getch();
        if (ch == ' ') {
            paused = !paused;
            if (!paused) {
                next_tick = time(NULL) + 1;
            }
        } else if (ch == 'q' || ch == 'Q' || ch == 'c' || ch == 'C') {
            endwin();
            printf("Timer cancelled.\n");
            return 1;
        }

        handle_time_tick(&remaining_seconds, &next_tick, paused);
    }

    endwin();
    printf("Time's up!\n");
    return 0;
}

