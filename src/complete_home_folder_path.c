#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_COMMAND_LENGTH 1024

void completeHomeFolderPath(char* filePath){
  if (filePath[0] == '~') {
    char full_filename_path[MAX_COMMAND_LENGTH];
    size_t home_length, remaining;

#if defined(__linux__) || defined(__APPLE__)
    char *home = getenv("HOME");
    if (home == NULL) {
      fprintf(stderr, "Error, HOME environment variable is not set\n");
      exit(EXIT_FAILURE);
    }
    snprintf(full_filename_path, MAX_COMMAND_LENGTH, "%s", home);
#elif defined(_WIN32)
    char *homedrive = getenv("HOMEDRIVE");
    char *homepath = getenv("HOMEPATH");
    if (homedrive == NULL || homepath == NULL) {
      fprintf(stderr, "Error, HOMEDRIVE or HOMEPATH environment variable is"
                      "not set");
      exit(EXIT_FAILURE);
    }
    snprintf(full_filename_path, MAX_COMMAND_LENGTH, "%s%s", homedrive,
             homepath);
#endif
    home_length = strlen(full_filename_path);
    remaining = MAX_COMMAND_LENGTH - home_length - 1;

    if (remaining <= 0) {
      fprintf(stderr, "Error: Path too long, more than %d bytes", MAX_COMMAND_LENGTH);
      exit(EXIT_FAILURE);
    }

    strncat(full_filename_path, filePath + 1, remaining);
    strncpy(filePath, full_filename_path, MAX_COMMAND_LENGTH - 1);
    filePath[MAX_COMMAND_LENGTH - 1] = '\0';
  }
}
