// https://jera.com/techinfo/jtns/jtn002
#define mu_assert(message, test) \
    do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                               if (message) return message; } while (0)

extern int tests_run;
#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H
#endif

void assertString(char* expect, char* result);
void assertInt(int expect, int result);
void statement(char* statement);
