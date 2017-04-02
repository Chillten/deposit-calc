#include <stdio.h>

#define CTEST_MAIN

// uncomment lines below to enable/disable features. See README.md for details
#define CTEST_SEGFAULT
//#define CTEST_NO_COLORS
#define CTEST_COLOR_OK

#include "ctest.h"
#include "deposit.h"

CTEST(validation_test, testDaysNegValue) {
    ASSERT_EQUAL(daysCheck(-1), 0);
}

CTEST(validation_test, testDaysZeroValue) {
    ASSERT_EQUAL(daysCheck(0), 1);
}

CTEST(validation_test, testDaysValue) {
    ASSERT_EQUAL(daysCheck(1), 1);
    ASSERT_EQUAL(daysCheck(10), 1);
    ASSERT_EQUAL(daysCheck(365), 1);
}

CTEST(validation_test, testDaysOutOfRangeValue) {
    ASSERT_EQUAL(daysCheck(366), 0);
    ASSERT_EQUAL(daysCheck(999), 0);
}

CTEST(validation_test, testDepositNegValue) {
    ASSERT_EQUAL(depositCheck(-1), 0);
}

CTEST(validation_test, testDepositZeroValue) {
    ASSERT_EQUAL(depositCheck(0), 0);
}

CTEST(validation_test, testDepositValue) {
    ASSERT_EQUAL(depositCheck(10000), 1);
    ASSERT_EQUAL(depositCheck(99999), 1);
}

CTEST(validation_test, testDepositOutOfRangeValue) {
    ASSERT_EQUAL(depositCheck(1), 0);
    ASSERT_EQUAL(depositCheck(9990), 0);
}

int main(int argc, const char *argv[])
{
    int result = ctest_main(argc, argv);

    return result;
}