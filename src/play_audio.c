#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stopwatch_audio.h"

static char* load_file(const char *path, size_t *file_size) {
  FILE *file = fopen(path, "rb");
  if (!file) return NULL;

  fseek(file, 0, SEEK_END);
  *file_size = ftell(file);
  rewind(file);

  char *buffer = malloc(*file_size);
  if (buffer)
    fread(buffer, 1, *file_size, file);
  fclose(file);
  return buffer;
}

void play_sound(char *sound_file, int times) {
  for (int i = 0; i < times; i++) {
    FILE *pipe = popen("ffplay -nodisp -autoexit - 2>/dev/null", "w");
    if (!pipe) {
      fprintf(stderr, "Warning: ffplay not found or installed, using system beep instead\n");
      fprintf(stderr, "\a");
      continue;
    }

    if (sound_file && sound_file[0] != '\0') {
      size_t file_size = 0;
      char *buffer = load_file(sound_file, &file_size);
      if (buffer) {
        fwrite(buffer, 1, file_size, pipe);
        free(buffer);
      }
    } else {
      fwrite(assets_stopwatch_mp3, 1, assets_stopwatch_mp3_len, pipe);
    }

    pclose(pipe);
  }
}
