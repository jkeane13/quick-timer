#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_COMMAND_LENGTH 1024

void complete_home_folder_path(char* file_path){
  if (file_path[0] != '~') {
    return;
  }

  const char *home = NULL;

#if defined(__linux__) || defined(__APPLE__)
  home = getenv("HOME");
#elif defined(_WIN32)
  char temp[MAX_COMMAND_LENGTH];
  const char *home_drive = getenv("HOMEDRIVE");
  const char *home_path = getenv("HOMEPATH");

  if (home_drive == NULL || home_path == NULL) {
    fprintf(stderr, "Error: HOMEDRIVE or HOMEPATH environment variable not set\n");
    exit(EXIT_FAILURE);
  }
  snprintf(temp, MAX_COMMAND_LENGTH, "%s%s", home_drive, home_path);
  home = temp;
#endif

  if (home == NULL){
    fprintf(stderr, "Error: HOME environment variable not set\n");
    exit(EXIT_FAILURE);
  }

  size_t home_length = strlen(home);
  size_t suffix_length = strlen(file_path + 1);

  if (home_length + suffix_length + 1 > MAX_COMMAND_LENGTH) {
    fprintf(stderr, "Error: Path too long, more than %d bytes\n", MAX_COMMAND_LENGTH);
    exit(EXIT_FAILURE);
  }

  char temp[MAX_COMMAND_LENGTH];
  snprintf(temp, MAX_COMMAND_LENGTH, "%s%s", home, file_path + 1);
  strncpy(file_path, temp, MAX_COMMAND_LENGTH - 1);
  file_path[MAX_COMMAND_LENGTH - 1] = '\0';
}
