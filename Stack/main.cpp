#include <stdio.h>

#define DefenceLevel 1

#include "stack.h"


int main()
{
    Stack st ={};

    //StackCtor(&st);
    //StackCtor(&st);
    StackCtor_(st);
    //printf("%d\n", st.Size);

    for(int i = 0; i < 100 ; i++)
    StackPush(&st, i);

    //printf("%d\n", st.data[1]);

    //StackDump(&st, "ii");
    for(int i = 0; i < 100; i++) {

        int x = StackPop(&st);
        printf("   %d", x);
    }

    StackDtor(&st);
    //StackPush(&st, 9);

    //printf("%d", st.Size);




    return 0;
}
