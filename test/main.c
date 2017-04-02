#include <stdio.h>

#define CTEST_MAIN

// uncomment lines below to enable/disable features. See README.md for details
#define CTEST_SEGFAULT
//#define CTEST_NO_COLORS
#define CTEST_COLOR_OK

#include "ctest.h"

CTEST(suite1, test1) {
    int a = 1, b = 2, c;
    c = a + b;
    ASSERT_EQUAL(a + b, c);
}

CTEST(suite1, test2) {
    char a[] = "hello", b[] = "hello";
    ASSERT_STR(a, b);
}


int main(int argc, const char *argv[])
{
    int result = ctest_main(argc, argv);

    return result;
}

