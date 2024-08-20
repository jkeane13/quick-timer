
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "minunit.h"
#include "timer.h"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define RESET   "\x1B[0m"

int tests_run = 0;
double value = 10;
int expect;

void assertStats(int expect, int result);

 static char * hourMinsSeconds() {
     printf("Convert hours, mins, seconds parameters to just seconds...\t\t");
     expect = 10921;
     int result = convertHoursMinsToSecondsInt(3, 2, 1);
     assertStats(expect, result);
     mu_assert("", result == expect);
     return 0;
 }

 static char * all_tests() {
     mu_run_test(hourMinsSeconds);
     return 0;
 }

 int main(int argc, char **argv) {
     printf("Running function tests...\n");
     printf("Value to %.0lf\n", value);
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

void assertStats(int expect, int result){
     if (result != expect){
         printf(RED "[ FAIL] expected %d: ", expect);
         printf("got %d\n", result);
         printf(RESET);
     }else
        printf(GREEN "[ PASS ]\n");
         printf(RESET);

}
