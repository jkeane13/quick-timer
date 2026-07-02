#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stopwatch_audio.h"

#define MAX_BUFFER 4096

void play_sound(char *sound_file, int times) {
  for (int i = 0; i < times; i++) {
    FILE *pipe = popen("ffplay -nodisp -autoexit -", "w");
    if (!pipe) {
      fprintf(stderr, "Warning: ffplay not found or installed, using system beep instead\n");
      fprintf(stderr, "\a");
      continue;
    }

    if (sound_file && sound_file[0] != '\0') {
      FILE *f = fopen(sound_file, "rb");
      if (!f) {
        pclose(pipe);
        continue;
      }

      char buf[MAX_BUFFER];
      size_t n;
      while ((n = fread(buf, 1, sizeof(buf), f)) > 0)
        fwrite(buf, 1, n, pipe);
      fclose(f);
    } else {
      fwrite(assets_stopwatch_mp3, 1, assets_stopwatch_mp3_len, pipe);
    }

    pclose(pipe);
  }
}
