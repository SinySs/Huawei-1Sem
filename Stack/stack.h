#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define CANARY 0xDEADC0DE
#define StartSize 128

#define TYPE int
typedef int StackElem;

#if !defined(DefenceLevel)
    #define DefenceLevel 1
#endif

//#define LOCATION(obj)  {#obj, __FUNCTION__, __FILE__, __LINE__}

#define StackCtor_(st)                                                   \
{                                                                        \
    StackInfo info = LOCATION(st);                                       \
    StackCtor(&st, &info);                                               \
}

#define StackOk_(Stack, place)                                           \
{                                                                        \
                                                                         \
    if(StackError(Stack) && DefenceLevel >= 1) {                         \
        StackInfo TmpInfo = LOCATION(Stack);                             \
        StackDump(Stack, &TmpInfo, place, "LogFile.txt");                \
    }                                                                    \
                                                                         \
}

#define ErrorOk_(Stack)                                                  \
{                                                                        \
    if(DefenceLevel == 0)                                                \
    int error = StackError(Stack);                                       \
                                                                         \
}

#include "poison.h"

enum errors {

    NoError = 0,
    CtorError = -1,
    ReallocError = -2,
    NothingPop = -3,
    RepeatedCtor = -4,
    SizeError = -5, ///size < 0
    Overflow = -6,
    FullnessError = -7,
    InvalidStacPtr = -8,
    InvalidDataPtr = -9,
    DamagedData = -10,
    Destroyed = -100,


};

int StackCtor(struct Stack *Stack, struct StackInfo *info);

int StackPush(struct Stack *Stack, int value);

int StackPop(struct Stack *Stack);

int StackDtor(struct Stack *Stack);

int StackError(const struct Stack *Stack);

int StackDump(const Stack *Stack, const StackInfo *info, char *place, char *LogFile);

struct Stack{

    const long long  LCanary = CANARY;

    int *data;
    int Size;
    int Fullness;

    const struct StackInfo* info;

    const long long  RCanary = CANARY;

};

struct StackInfo{

    const char *name;
    const char *func;
    const char *file;
    int line;

};

#endif // STACK_H_INCLUDED
