#include "../include/edit_characters.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AF_PLAYER "afplay"
#define MPG_PLAYER "mpg123"
#define MAX_COMMAND_LENGTH 1024
#define WINDOWS_NULL_OUTPUT " > nul 2>&1"
#define UNIX_NULL_OUTPUT " >/dev/null 2>&1"

void play_sound(char *sound_file, int times) {
  char sound_command[MAX_COMMAND_LENGTH];
  const char *player = NULL;
  const char *null_output = NULL;

#if defined(__APPLE__)
  player = AF_PLAYER;
  null_output = UNIX_NULL_OUTPUT;
#elif defined(__linux__)
  player = MPG_PLAYER;
  null_output = UNIX_NULL_OUTPUT;
#elif defined(_WIN32)
  player = MPG_PLAYER;
  null_output = WINDOWS_NULL_OUTPUT;
#else
#error "Unsupported Platform"
#endif

  int len = snprintf(sound_command, MAX_COMMAND_LENGTH, "%s %s%s", player,
                     sound_file, null_output);

  if (len < 0 || len >= MAX_COMMAND_LENGTH) {
    return;
  }

#if defined(_WIN32)
  replace_char(sound_command, '/', '\\');
#endif
  for (int i = 0; i < times; i++)
    system(sound_command);
}
