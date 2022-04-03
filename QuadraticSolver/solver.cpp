#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "solver.h"
#include "compare.h"

solutions_amount solveLinear(float b, float c, float *x1)
{
    assert(x1);

    if (float_is_equal(b, 0.0) == EQUAL && float_is_equal(c, 0.0) != EQUAL) {
        return ZERO_SOLUTIONS;
    } else if (float_is_equal(b, 0.0) == EQUAL && float_is_equal(c, 0.0) == EQUAL) {
        return INFINITE_SOLUTIONS;
    } else {
        if (float_is_equal(c, 0.0) == EQUAL) {
            *x1 = 0;
        } else{
            *x1 = -1 * c / b;
        }

        return ONE_SOLUTION;
    }
}

static float quadraticDiscriminant(const float a, const float b, const float c)
{
    return b * b - 4 * a * c;
}

solutions_amount solveQuadratic(const float a, const float b, const float c, float *x1, float *x2)
{
    assert(x1);
    assert(x2);
    assert(x1 != x2);

    solutions_amount number_of_lineral = ZERO_SOLUTIONS;
    float discrim = 0;

    if (float_is_equal(a, 0.0) == EQUAL) {
        number_of_lineral = solveLinear(b, c, x1);
        return solveLinear(b, c, x1);
    } else {
        discrim = quadraticDiscriminant(a, b, c);
        if (float_is_equal(discrim, 0.0) == EQUAL && x1) {
            *x1 = -b / (2 * a);
            *x2 = *x1;

            return ONE_SOLUTION;
        } else if (float_is_less(discrim, 0.0) == LESS) {
            return ZERO_SOLUTIONS;
        } else if (float_is_equal(c, 0.0) == EQUAL) {
            *x2 = 0;
            solveLinear(a, b, x1);

            return TWO_SOLUTIONS;
        } else if (float_is_less(discrim, 0.0) == MORE && x1 && x2) {
            *x1 = (-b + sqrt(discrim)) / (2 * a);
            *x2 = (-b - sqrt(discrim)) / (2 * a);

            return TWO_SOLUTIONS;
        }
    }

}
