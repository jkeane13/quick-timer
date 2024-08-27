#include <stdio.h>
#include <string.h>
#include "../include/testing.h"

#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define RESET   "\x1B[0m"

void assertInt(int expect, int result){
     if (result != expect){
         printf(RED "[ FAIL ] expected %d, ", expect);
         printf("got %d\n", result);
         printf(RESET);
     }else
        printf(GREEN "[ PASS ]\n");
         printf(RESET);
}

void assertString(char* expect, char* result){
     if (strcmp(expect,result) != 0){
         printf(RED "[ FAIL ] expected %s, ", expect);
         printf("got %s\n", result);
         printf(RESET);
     }else
        printf(GREEN "[ PASS ]\n");
         printf(RESET);
}

