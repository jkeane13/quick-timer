#include "../include/timer.h"
#include <curses.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

static void init_screen(void) {
  setlocale(LC_ALL, "");
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  timeout(POLLING_WINDOW);
  curs_set(HIDE);
}

static void format_end_time_string(time_t end_timestamp, const char *clock_type,
                                   char *buffer) {
  struct tm *end_time_info = localtime(&end_timestamp);

  sprintf(buffer, "%02d:%02d", end_time_info->tm_hour, end_time_info->tm_min);

  if (strncmp(clock_type, "24Hour", 6) != 0) {
    t_convert_24_hour_clock_to_12(buffer);
  }
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
    printw("%02d:%02d:%02d [press Space to pause, q to quit]", h, m, s);
  }
}

static void draw_progress_bar(int remaining, int total,
                              const char *end_time_str) {
  double ratio = (total > 0) ? (double)remaining / (double)total : 0.0;
  int percentage = (int)(ratio * 100);
  int bar_width = 30;
  int filled = (int)(ratio * bar_width);

  if (filled < 0)
    filled = 0;
  if (filled > bar_width)
    filled = bar_width;

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
  printw("] %d%% (Ends at %s)", percentage, end_time_str);
}

static void update_display(int remaining, int total, int paused,
                           const char *end_time_str) {
  draw_countdown(remaining, paused);
  draw_progress_bar(remaining, total, end_time_str);
  refresh();
}

static void handle_time_tick(int *remaining_seconds, time_t *next_tick,
                             time_t *end_timestamp, int paused) {
  time_t now = time(NULL);
  if (now >= *next_tick) {
    if (paused) {
      (*end_timestamp)++;
    } else {
      (*remaining_seconds)--;
    }
    *next_tick = now + 1;
  }
}

static int handle_keyboard_input(int *paused, time_t *next_tick) {
  int ch = getch();

  if (ch == ' ') {
    *paused = !(*paused);
    if (!(*paused)) {
      *next_tick = time(NULL) + 1; // Align window on unpause
    }
  } else if (ch == 'q' || ch == 'Q' || ch == 'c' || ch == 'C') {
    curs_set(SHOW);
    endwin();
    printf("Timer cancelled.\n");
    return 1;
  }

  return 0;
}

int t_seconds_countdown(int seconds) {
  init_screen();

  int remaining_seconds = seconds;
  int paused = 0;
  time_t next_tick = time(NULL) + 1;
  time_t end_timestamp = time(NULL) + seconds;

  char end_time_str[MAX_CLOCK_12H];

  while (remaining_seconds > 0) {
    format_end_time_string(end_timestamp, "12Hour", end_time_str);
    update_display(remaining_seconds, seconds, paused, end_time_str);

    if (handle_keyboard_input(&paused, &next_tick)) {
      return 1;
    }

    handle_time_tick(&remaining_seconds, &next_tick, &end_timestamp, paused);
  }

  curs_set(SHOW);
  endwin();
  printf("Time's up!\n");
  return 0;
}
