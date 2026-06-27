#include "../include/timer.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  t_set_windows_console();
  t_start_timer(argc, argv);
  return EXIT_SUCCESS;
}
