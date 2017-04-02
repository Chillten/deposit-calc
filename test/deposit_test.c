#include <stdio.h>

#define CTEST_MAIN

// uncomment lines below to enable/disable features. See README.md for details
#define CTEST_SEGFAULT
//#define CTEST_NO_COLORS
#define CTEST_COLOR_OK

#include "ctest.h"
#include "deposit.h"

CTEST(deposit_test, testDeposit_0_30_days) {
    int deposit = 10000;
    float fdeposit, sdeposit;
    float p = 0.9;
    sdeposit = deposit * p;
    fdeposit = deposit * getPercentOfInc(0, deposit);
    ASSERT_DBL_NEAR(fdeposit, sdeposit);
    fdeposit = deposit * getPercentOfInc(15, deposit);
    ASSERT_DBL_NEAR(fdeposit, sdeposit);
    fdeposit = deposit * getPercentOfInc(30, deposit);
    ASSERT_DBL_NEAR(fdeposit, sdeposit);
}

CTEST(deposit_test, testDeposit_31_120_days_low) {
    float fdeposit, sdeposit;
    float p = 1.02;
    for(int deposit = 10000; deposit < 10020; deposit++){
        sdeposit = deposit * p;
        fdeposit = deposit * getPercentOfInc(31, deposit);
        ASSERT_DBL_NEAR(fdeposit, sdeposit);
        fdeposit = deposit * getPercentOfInc(60, deposit);
        ASSERT_DBL_NEAR(fdeposit, sdeposit);
        fdeposit = deposit * getPercentOfInc(120, deposit);
        ASSERT_DBL_NEAR(fdeposit, sdeposit);
    }
}

CTEST(deposit_test, testDeposit_31_120_days_hi) {
    float p = 1.03;
    for(int deposit = 100001; deposit < 100010; deposit++){
        // CTEST_LOG("%f",getPercentOfInc(31, deposit));
        ASSERT_DBL_NEAR(p, getPercentOfInc(31, deposit));
        // CTEST_LOG("%f",getPercentOfInc(31, deposit));
        ASSERT_DBL_NEAR(p, getPercentOfInc(40, deposit));
        // CTEST_LOG("%f",getPercentOfInc(31, deposit));
        ASSERT_DBL_NEAR(p, getPercentOfInc(120, deposit));
    }
}

CTEST(deposit_test, testDeposit_121_240_days_low) {
    float p = 1.06;
    for(int deposit = 10000; deposit < 10020; deposit++){
        ASSERT_DBL_NEAR(p, getPercentOfInc(121, deposit));
        ASSERT_DBL_NEAR(p, getPercentOfInc(200, deposit));
        ASSERT_DBL_NEAR(p, getPercentOfInc(240, deposit));
    }
}

CTEST(deposit_test, testDeposit_121_240_days_hi) {
    float p = 1.08;

    for(int deposit = 100001; deposit < 100010; deposit++){
        ASSERT_DBL_NEAR(p, getPercentOfInc(121, deposit));
        ASSERT_DBL_NEAR(p, getPercentOfInc(200, deposit));
        ASSERT_DBL_NEAR(p, getPercentOfInc(240, deposit));
    }
}

CTEST(deposit_test, testDeposit_241_365_days_low) {
    float p = 1.12;
    for(int deposit = 10000; deposit < 10020; deposit++){
        ASSERT_DBL_NEAR(p, getPercentOfInc(241, deposit));
        ASSERT_DBL_NEAR(p, getPercentOfInc(300, deposit));
        ASSERT_DBL_NEAR(p, getPercentOfInc(365, deposit));
    }
}

CTEST(deposit_test, testDeposit_241_365_days_hi) {
    float p = 1.15;
    for(int deposit = 100001; deposit < 100010; deposit++){
        ASSERT_DBL_NEAR(p, getPercentOfInc(241, deposit));
        ASSERT_DBL_NEAR(p, getPercentOfInc(300, deposit));
        ASSERT_DBL_NEAR(p, getPercentOfInc(365, deposit));
    }
}

int main(int argc, const char *argv[])
{
    int result = ctest_main(argc, argv);

    return result;
}