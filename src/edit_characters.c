#include <string.h>
#include "../include/timer.h"

void replaceChar(char* str, char find, char replace){
    char *current_pos = strchr(str,find);
    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
}

void removeChar(char *str, char keyCharacter) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != keyCharacter) dst++;
    }
    *dst = '\0';
}
