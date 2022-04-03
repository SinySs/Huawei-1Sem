#include <stdlib.h>
#include <float.h>
#include <math.h>

#include "compare.h"



compare_result float_is_less(const float a, const float b)
{
    if ((a - b) < FLT_EPSILON) {
        return LESS;
    } else {
        return MORE;
    }
}



compare_result float_is_equal(const float a, const float b)
{
    if (a != a && b != b) {
        return EQUAL;
    } else if (fabsf(a - b) > FLT_EPSILON) {
        return float_is_less(a, b);
    } else {
        return EQUAL;
    }
}
