#include "asserts.h"
#include <stdio.h>

void assert_int(int expected, int actual, const char* functionName, int line) {
    if (expected != actual)
        printf("%s:%d - Assert FAILED: got %d, expected %d\n", functionName, line, actual, expected);
}
