#include "real_test.h"

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include "real_test.h"
#include "solver.h"
#include "compare.h"
#include "status.h"
#include "unit_tests.h"
bool unitTestDummy()
{
    //abort();
    return true;
}

bool unitTestPass()
{
    return true;
}
bool unitTest1()
{
    float x1 = NAN, x2 = NAN;
    float standart_x1 = 1, standart_x2 = 2;
    solutions_amount number_roots = solveQuadratic(1, -3, 2, &x1, &x2);
    if ( float_is_equal(x1, standart_x1) != EQUAL || float_is_equal(x2, standart_x2) != EQUAL || number_roots != 2) {
        printf("FAIL:\n number_roots = %d,  x1 = %f, x2 =%f\n"
               "Should be: number_roots = %d, x1 = %f, x2 = %f\n",
               number_roots, x1, x2, 2, standart_x1, standart_x2);
               return false;
    } else {
        return true;
    }
}

bool unitTest2()
{
    float x1 = NAN, x2 = NAN;
    float standart_x1 = -1, standart_x2 = NAN;
    solutions_amount number_roots = solveQuadratic(0, 1, 1, &x1, &x2);
    if ( float_is_equal(x1, standart_x1) != EQUAL || float_is_equal(x2, standart_x2) != EQUAL || number_roots != 1) {
        printf("FAIL:\n number_roots = %d,  x1 = %f, x2 =%f\n"
               "Should be: number_roots = %d, x1 = %f, x2 = %f\n",
               number_roots, x1, x2, 1, standart_x1, standart_x2);
               return false;
    } else {
        return true;
    }

}

bool unitTest3()
{
    float x1 = NAN, x2 = NAN;
    float standart_x1 = -2, standart_x2 = -2;
    solutions_amount number_roots = solveQuadratic(1, 4, 4, &x1, &x2);
    if ( float_is_equal(x1, standart_x1) != EQUAL || float_is_equal(x2, standart_x2) != EQUAL || number_roots != 1) {
        printf("FAIL:\n number_roots = %d,  x1 = %f, x2 =%f\n"
               "Should be: number_roots = %d, x1 = %f, x2 = %f\n",
               number_roots, x1, x2, 1, standart_x1, standart_x2);
               return false;
    } else {
        return true;
    }
}

bool unitTest4()
{
    float x1 = NAN, x2 = NAN;
    float standart_x1 = 1, standart_x2 = 0;
    solutions_amount number_roots = solveQuadratic(4, -4, 0, &x1, &x2);
    if ( float_is_equal(x1, standart_x1) != EQUAL || float_is_equal(x2, standart_x2) != EQUAL || number_roots != 2) {
        printf("FAIL:\n number_roots = %d,  x1 = %f, x2 =%f\n"
               "Should be: number_roots = %d, x1 = %f, x2 = %f\n",
               number_roots, x1, x2, 2, standart_x1, standart_x2);
               return false;
    } else {
        return true;
    }
}

void realTest()
{
    UnitTestInfo testInfo;
    initUnitTesting(&testInfo);

    runUnitTest(&testInfo, "dummy test", unitTestDummy);
    runUnitTest(&testInfo, "pass", unitTestPass);
    runUnitTest(&testInfo, "Test1", unitTest1);
    runUnitTest(&testInfo, "Test2", unitTest2);
    runUnitTest(&testInfo, "Test3", unitTest3);
    runUnitTest(&testInfo, "Test4", unitTest4);



}
