#ifndef PROCESSOR_H_INCLUDED
#define PROCESSOR_H_INCLUDED

#include <malloc.h>
#include <stdlib.h>

#define NumberOfRegisters 10
#define SizeOfRAM 100
#define SizeOfBack 20

#include "readbin.h"
#include "../Stack/stack.h"
#include "../Stack/poison.h"

#define ProcessorCtor_(Proc)\
{                                                                 \
    Stack st = {};                                                \
    StackCtor_(st);                                               \
                                                                  \
    Proc.stack = &st;                                             \
                                                                  \
    Proc.Registers = (int*)calloc(NumberOfRegisters, sizeof(int));\
    Proc.RAM       = (int*)calloc(SizeOfRAM, sizeof(int));        \
                                                                  \
    readbin(&Proc.Commands);                                      \
                                                                  \
}

struct Processor {

    struct CmdInfo Commands;

    struct Stack *stack;

    int *RAM;

    int comeback[SizeOfBack] = {0};

    int *Registers;

};

enum {

    PUSH = 1,
    PUSHFROMREG = 17,
    PUSHFROMRAM = 18,
    POPINREG = 71,
    POPINRAM = 72,
    IN   = 2,
    ADD  = 3,
    SUB  = 4,
    MUL  = 5,
    DIV  = 6,
    OUT  = 7,
    CALL = 50,
    RET  = 500,
    JMP  = 100,
    JA   = 101,
    JE   = 102,
    JB   = 103,
    END  = 666,
};

int Perforn(struct Processor *Proc, int *comeback);

#endif // PROCESSOR_H_INCLUDED
