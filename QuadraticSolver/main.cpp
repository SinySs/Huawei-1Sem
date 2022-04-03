/*!
    \param[in] a coefficient before x^2
    \param[in] b coefficient before x
    \param[in] c free member
    \param[out] x1 the first solution
    \param[out] x2 the second solution

*/
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




input_errors inputCoefficents(float *a, float *b, float *c)
{
    assert(a);
    assert(b);
    assert(c);

    int valuesRead = scanf("%f %f %f", a, b, c);

    if (valuesRead != 3) {
        return ERROR_INF;
    }

    if (!isspace(getchar())) {
        return ERROR_BAD_INPUT;
    }

    if (isnanf(*a)) {
        return ERROR_NAN;
    }

    return STATUS_SUCCESS;

}

int main ()
{
    printf("If you want to start testing, press 'y'\n");
    if (getchar() == 'y') {
            realTest();
    }
    printf("Enter a, b, c (for ax^2 + bx + c = 0):");

    float a = NAN, b = NAN, c = NAN;

    input_errors statusCode = inputCoefficents(&a, &b, &c);
    if (isFailure(statusCode)) {
        printf(
            "failed to input coefficents: %s",
            statusToString(statusCode)
        );

        return EINVAL;
    }

    float x1 = NAN, x2 = NAN;
    solutions_amount number_of_solutions = ZERO_SOLUTIONS;

    number_of_solutions = solveQuadratic(a, b, c, &x1, &x2);
    switch (number_of_solutions) {
    case ZERO_SOLUTIONS:
        printf("No solutions.\n");
        break;
    case ONE_SOLUTION:
        printf("x1 = %f", x1);
        break;
    case TWO_SOLUTIONS:
        printf("x1 = %f\n", x1);
        printf("x2 = %f\n", x2);
        break;
    case INFINITE_SOLUTIONS:
        printf("Infinite number of solutions.\n");
        break;
    }

    return 0;
}

