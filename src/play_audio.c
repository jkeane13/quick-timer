#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stopwatch_audio.h"

void play_sound(unsigned int times) {
  for (unsigned int i = 0; i < times; i++) {
    FILE *pipe = popen("ffplay -nodisp -autoexit - 2>/dev/null", "w");
    if (!pipe) {
      fprintf(stderr, "Warning: ffplay not found or installed, using system beep instead\n");
      fprintf(stderr, "\a");
      continue;
    }

    fwrite(assets_stopwatch_mp3, 1, assets_stopwatch_mp3_len, pipe);
    pclose(pipe);
  }
}
