#include <stdio.h>

#include "processor.h"
#include "readbin.h"
#include "../Stack/stack.h"
#include "../Stack/poison.h"


int main()
{
    Processor Proc;

    ProcessorCtor_(Proc);
    //int comeback[SizeOfBack] = {0};
    /*for(int i = 0; i < Proc.Commands.NumberOfCommands; i++) {
        printf("%d %d\n", i, Proc.Commands.data[i]);
    }*/

    /*for(int i = 0; i < 9; i++)
        printf("%d ", Proc.Commands.data[i]);*/

    //printf("%d", Proc.Commands.NumberOfCommands);
    Perforn(&Proc, Proc.comeback);

    //int x =Proc.Commands.NumberOfCommands;

    //printf("ee%d", x);


}
