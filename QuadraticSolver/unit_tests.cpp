#include "unit_tests.h"
#include "real_test.h"

#include <signal.h>
#include <stdio.h>
#include <assert.h>

static void signalHandler(int signalType)
{
    switch (signalType) {
    case SIGABRT:
        printf("Abnormal terminition.\n");
        break;

    case SIGFPE:
        printf("Arithmetic error.\n");
        break;

    case SIGILL:
        printf ("Invalid command.\n");
        break;

    case SIGINT:
        printf("Request for interaction.\n");
        break;

    case SIGSEGV:
        printf("Invalid memory access.\n");
        break;

    case SIGTERM:
        printf("Completion requirement.\n");
        break;
    }
}

void initUnitTesting(struct UnitTestInfo *info)
{
    assert(info);
    info->succededTests = 0;
    info->totalTests = 0;

    void (*oldHandler)(int) = NULL;

    oldHandler = signal(SIGABRT, signalHandler);
    if (oldHandler == SIG_ERR) {
        printf("Error when attaching signal handler.\n");
        return;
    }

    oldHandler = signal(SIGFPE, signalHandler);
    if (oldHandler == SIG_ERR) {
        printf("Error when attaching signal handler.\n");
        return;
    }
    oldHandler = signal(SIGILL, signalHandler);
    if (oldHandler == SIG_ERR) {
        printf("Error when attaching signal handler.\n");
        return;
    }
    oldHandler = signal(SIGINT, signalHandler);
    if (oldHandler == SIG_ERR) {
        printf("Error when attaching signal handler.\n");
        return;
    }
    oldHandler = signal(SIGSEGV, signalHandler);
    if (oldHandler == SIG_ERR) {
        printf("Error when attaching signal handler.\n");
        return;
    }
    oldHandler = signal(SIGTERM, signalHandler);
    if (oldHandler == SIG_ERR) {
        printf("Error when attaching signal handler.\n");
        return;
    }
}

void runUnitTest(
    struct UnitTestInfo *info,
    const char *name,
    UnitTestFunction func
)
{
    assert(info);

    info->totalTests++;

    printf("['%s' UNIT TEST]: STARTING\n", name);
    bool status = func();
    if (!status) {
        printf(
            "['%s' UNIT TEST]: internal FAILURE\n",
            name
        );
    } else {
        printf("['%s' UNIT TEST]: SUCCESS\n", name);
        info->succededTests++;
    }
}
