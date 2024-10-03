#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/testing.h"

#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define RESET   "\x1B[0m"
#define STATEMENT_MAX 81
#define MAX_NUMBER_PLACEMENT 20 

void assertInt(int expect, int result){
    char expectString[MAX_NUMBER_PLACEMENT];
    char resultsString[MAX_NUMBER_PLACEMENT];
    snprintf( expectString, MAX_NUMBER_PLACEMENT, "%d", expect );
    snprintf( resultsString, MAX_NUMBER_PLACEMENT,"%d", result );
    assertString(expectString, resultsString);
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

void statement(char* statement){
    int statementLength = strlen(statement);
    char fullStatement[STATEMENT_MAX];

    if (statementLength > STATEMENT_MAX){
       printf("Error: Statement \"%s\" must be under %d characters", 
              statement, STATEMENT_MAX-1);
       exit(1);
    }

    strcpy(fullStatement, statement);
    for (int i = statementLength; i < STATEMENT_MAX-1; i++)
        strcat(fullStatement, " ");

    printf(RESET "%s", fullStatement);
}

void testTitle(char* title, char* fileLocation){
    printf("--  %s --\n", fileLocation);
    printf("%s...\n",title);
}
