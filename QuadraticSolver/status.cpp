#include "status.h"

bool isFailure(input_errors statusCode)
{
    return statusCode != STATUS_SUCCESS;
}

const char *statusToString(input_errors statusCode)
{
    switch (statusCode) {
    case ERROR_NAN:
        return "Not three values were entered";
        break;
    case ERROR_INF:
        return "No number entered";
        break;
    case ERROR_BAD_INPUT:
        return "Incorrect input";
        break;
    }
}
