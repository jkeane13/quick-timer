
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "minunit.h"
#include "timer.h"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define RESET   "\x1B[0m"

#define MAX_STRING 100

int tests_run = 0;
int expect;
int result;
bool resultBool;
bool expectBool;

void assertInt(int expect, int result);
void assertBool(bool expect, bool result);

static char * correctQuietSwitch() {
     printf("Correct quiet switch entered...\t\t\t\t\t\t");
     char* switchEnd = "--quiet";

     bool quietMode = false;
     bool dryRun = false;
     checkforEndSwitch(switchEnd, &quietMode, &dryRun);

     expectBool = true;
     resultBool = quietMode;
     assertBool(expectBool, resultBool);
     mu_assert("", resultBool == expectBool);
     return 0;
 }

static char * correctDrySwitch() {
     printf("Correct dry switch entered...\t\t\t\t\t\t");
     char* switchEnd = "--dry-run";

     bool quietMode = false;
     bool dryRun = false;
     checkforEndSwitch(switchEnd, &quietMode, &dryRun);

     expectBool = true;
     resultBool = dryRun;
     assertBool(expectBool, resultBool);
     mu_assert("", resultBool == expectBool);
     return 0;
 }

 static char * hourMinsSeconds() {
     printf("Convert hours, mins, seconds parameters to just seconds...\t\t");
     expect = 10921;
     result = convertHoursMinsToSecondsInt(3, 2, 1);
     assertInt(expect, result);
     mu_assert("", result == expect);
     return 0;
 }

 static char * all_tests() {
     mu_run_test(hourMinsSeconds);
     mu_run_test(correctQuietSwitch);
     mu_run_test(correctDrySwitch);
     return 0;
 }

 int main(int argc, char **argv) {
     printf("Running function tests...\n");
     char *result = all_tests();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf("ALL FUNCTION TESTS PASSED\n");
     }
     printf("Tests run: %d\n", tests_run);

     return result != 0;
 }

void assertInt(int expect, int result){
     if (result != expect){
         printf(RED "[ FAIL] expected %d: ", expect);
         printf("got %d\n", result);
         printf(RESET);
     }else
        printf(GREEN "[ PASS ]\n");
         printf(RESET);
}

void assertBool(bool expect, bool result){
     if (result != expect){
         printf(RED "[ FAIL] expected %s: ", expect ? "true" : "false");
         printf("got %s\n", result ? "true": "false");
         printf(RESET);
     }else
        printf(GREEN "[ PASS ]\n");
         printf(RESET);
}

