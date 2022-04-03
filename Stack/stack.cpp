#include <assert.h>
#include <stdio.h>
#include <malloc.h>

#include "stack.h"

#define print

char *StackErrorInfo(int error)
{
    switch(error) {

    case NoError:
        return "No errors\n ";

    case CtorError:
        return "Construction ERROR\n" ;

    case ReallocError:
        return "Dynamic memory is not allocated\n";

    case NothingPop:
        return "Stack is empty, nothing to pop\n";

    case RepeatedCtor:
        return "Colling constructor again\n";

    case SizeError:
        return "Stack size less then 0\n";

    case Overflow:
        return "Stack fullness is more then stack size\n";

    case InvalidStacPtr:
        return "Stack has invalid pointer\n";

    case InvalidDataPtr:
        return "Stack.data has invalid pointer\n";

    case Destroyed:
        return "Stack was destroyed\n";

    case FullnessError:
        return "Stack fullness contain incorrect data\n";

    case DamagedData:
        return "CANARY was danaged\n";
    }
}

int StackError(const struct Stack *Stack)
{
    if(Stack == NULL) {

        return InvalidStacPtr;
    }
    if(Stack->Size <= 0) {

        return SizeError;
    }

    if(Stack->Size < Stack->Fullness) {

        return Overflow;
    }

    if(Stack->Fullness < 0) {

        return FullnessError;
    }

    if(Stack->data == NULL) {

        return InvalidDataPtr;
    }

    long long *LCanary = (long long*)((char*)Stack->data - sizeof(long long));
    long long *RCanary = (long long*)((char*)Stack->data + sizeof(StackElem) * Stack->Fullness);

    if(*LCanary != CANARY || *RCanary != CANARY) {

        return DamagedData;
    }

    if(Stack->LCanary != CANARY || Stack->RCanary != CANARY) {

        return DamagedData;
    }

    return 0;

}

int StackCtor(struct Stack *Stack, struct StackInfo *info)
{
    assert(Stack);
    assert(info);

    Stack->info = info;

    if(Stack->Size != 0) {

        return RepeatedCtor;
    }

    Stack->Size = StartSize;
    Stack->Fullness = 0;

    Stack->data  = (StackElem *)calloc(Stack->Size * sizeof(StackElem) + 2 * sizeof(long long), sizeof(char));

    *((long long*)Stack->data) = CANARY;
    *((long long*)((char*)Stack->data + sizeof(long long) + sizeof(StackElem) * Stack->Size)) = CANARY;

    Stack->data = (StackElem*)((char*) Stack->data + sizeof(long long));

    StackOk_(Stack, "Function called from end of StackCtor\n");
    ErrorOk_(Stack);

    return 0;
}

enum errors StackResize(struct Stack *Stack, int NewSize)
{
     StackOk_(Stack, "Function called from start of StackResize\n");
     ErrorOk_(Stack);

     Stack->data = (StackElem*)((char*)Stack->data - sizeof(long long));

     StackElem* DataTmp = (StackElem *)realloc(Stack->data, NewSize  * sizeof(StackElem) + 2 * sizeof(long long));

     if(DataTmp == NULL) {

        return ReallocError;
     }

     Stack->Size = NewSize ;

     *(long long*)((char*)DataTmp + sizeof(long long) + sizeof(StackElem) * NewSize) = CANARY;

     Stack->data = (StackElem*)((char*)DataTmp + sizeof(long long));

     StackOk_(Stack, "Function called from end of  StackResize\n");
     ErrorOk_(Stack);

     return NoError;

}

int StackPush(struct Stack *Stack, int value)
{
    StackOk_(Stack, "Function called from start of StackPush\n");
    ErrorOk_(Stack);


    if(Stack->Size == Stack->Fullness) {

        if(StackResize(Stack, Stack->Size * 2) == ReallocError) {

            return ReallocError;
        }
    }

    Stack->data[Stack->Fullness++] = value;

    StackOk_(Stack, "Function called from end of StackPush\n");
    ErrorOk_(Stack);

    return NoError;
}

int StackPop(struct Stack *Stack)
{
    StackOk_(Stack, "Function called from start of StackPop\n");
    ErrorOk_(Stack);

    int x = Stack->data[Stack->Fullness - 1];

    Stack->Fullness--;

    if(Stack->Size >= StartSize && Stack->Fullness <= Stack->Size / 2) {

        StackResize(Stack, Stack->Size / 2);

    }

    StackOk_(Stack, "Function called from end of StackPop\n");
    ErrorOk_(Stack);

    return x;

}

int StackDtor(struct Stack *Stack)
{
    StackOk_(Stack, "Function called from StackDtor\n");
    ErrorOk_(Stack);

    if(DefenceLevel == 1) {
        for(int i = 0; i < Stack->Fullness; i++){
            Stack->data[i] = (StackElem)FreedElem;
        }
    }

    Stack->data = (StackElem*)((char*)Stack->data - sizeof(long long));
    free(Stack->data);

    Stack->Size = FreedElem;
    Stack->Fullness = FreedElem;
    Stack->data = (StackElem*)FreedPtr;

    return NoError;
}

int StackDump(const Stack *Stack, const StackInfo *info, char *place, char *LogFile)
{
    FILE *log = fopen(LogFile, "a");

    fprintf(log, "Stack Dump\n");

    int error = StackError(Stack);
    char *errorInfo = StackErrorInfo(error);

    if(error == 0) {
        fprintf(log, "Called from function: %s\n", info->func);
        fprintf(log, "Called from line: %d\n", info->line);
        fprintf(log, "Error information: ");
        fprintf(log, errorInfo);
        return 0;

    }


    fprintf(log, "Called from function: %s\n", info->func);
    fprintf(log, "Called from file: %s\n", info->file);
    fprintf(log, "Called from line: %d\n", info->line);
    fprintf(log, "Information about %s: ", info->name);

    fprintf(log, "Error information: ");

    fprintf(log, errorInfo);

    fprintf(log, "Stack <TYPE> [%p] ", Stack->data);
    fprintf(log, "Stack size: %d\n", Stack->Size);
    fprintf(log, "Stack fullness: %d\n", Stack->Fullness);

    for(int i = 0; i < Stack->Size; i++) {

        if(i < Stack->Fullness) {
            fprintf(log, "*[%d] = %d\n", i, Stack->data[i]);

        } else {

            fprintf(log, "[%d] = %p\n", i, Stack->data[i]);

        }
    }
}
