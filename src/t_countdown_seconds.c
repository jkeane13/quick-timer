#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <curses.h>
#include <locale.h>
#include "../include/timer.h"

int t_seconds_countdown (int seconds){
  setlocale(LC_ALL, ""); // Enable UTF-8 support in the terminal
  initscr();             // Start curses mode
  cbreak();              // Line buffering disabled
  noecho();              // Don't echo characters
  keypad(stdscr, TRUE);  // Enable arrow keys, etc.
  timeout(50);           // Non-blocking getch with 50ms timeout

  int remaining_seconds = seconds;
  int paused = 0;
  time_t next_tick = time(NULL) + 1;

  while (remaining_seconds > 0) {
    int h = remaining_seconds / SECONDS_IN_HOUR;
    int m = (remaining_seconds % SECONDS_IN_HOUR) / SECONDS_IN_MINUTE;
    int s = remaining_seconds % SECONDS_IN_MINUTE;

    // Line 0: Countdown clock and controls
    move(0, 0);
    clrtoeol();
    if (paused) {
      printw("%02d:%02d:%02d [PAUSED - press Space to resume]", h, m, s);
    } else {
      printw("%02d:%02d:%02d [press Space to pause]", h, m, s);
    }

    // Line 1: Smooth Unicode progress bar
    double ratio = (seconds > 0) ? (double)remaining_seconds / (double)seconds : 0.0;
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

    refresh();

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

    if (!paused) {
      time_t now = time(NULL);
      if (now >= next_tick) {
        remaining_seconds--;
        next_tick = now + 1;
      }
    }
  }

  endwin();
  printf("Time's up!\n");
  return 0;
}
