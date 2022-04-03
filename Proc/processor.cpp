#include "stdio.h"
#include "processor.h"
#include "readbin.h"

int RecordToFile(int number)
{
    FILE *ForRecord;

    if( (ForRecord = fopen("Result.txt", "a")) == NULL)
       return -1;

    fprintf(ForRecord, "%d \n", number);

    return 1;


}

int SearchBack(int *comeback)
{
    int number;

    for(number = 0; number < SizeOfBack; number++) {

        if (comeback[number] == 0) {

            return number;

        }
    }
    return -1;
}

int Perforn(struct Processor *Proc, int *comeback)
{
    for(int i = 0; i < Proc->Commands.NumberOfCommands; i++) {

        //printf("n %d com %d ", i, Proc->Commands.data[i]);

        int FirstPop, SecondPop;
        int reg;
        int number;

        switch(Proc->Commands.data[i]){

            case PUSH:

                StackPush(Proc->stack, Proc->Commands.data[++i]);

                break;

            case PUSHFROMREG:

                reg = Proc->Commands.data[++i];

                if(reg > NumberOfRegisters) {

                    abort();
                }

                StackPush(Proc->stack, Proc->Registers[reg]);

                break;

            case PUSHFROMRAM:

                reg = Proc->Commands.data[++i];

                if(reg > SizeOfRAM) {

                    abort();
                }

                StackPush(Proc->stack, Proc->RAM[reg]);

                break;

            case POPINREG:

                reg = Proc->Commands.data[++i];

                if(reg > NumberOfRegisters) {

                    abort();
                }

                Proc->Registers[reg] = StackPop(Proc->stack);
                //printf("rrr %d %d", reg, Proc->Registers[reg]);

                break;

            case POPINRAM:

                reg = Proc->Commands.data[++i];

                if(reg > SizeOfRAM) {

                    abort();
                }

                Proc->RAM[reg] = StackPop(Proc->stack);

                break;

            case IN:

                int x;
                scanf("%d", &x);

                StackPush(Proc->stack, x);

                break;

            case ADD:

                FirstPop = StackPop(Proc->stack);
                SecondPop = StackPop(Proc->stack);

                StackPush(Proc->stack, FirstPop + SecondPop);

                break;

            case SUB:

                FirstPop = StackPop(Proc->stack);
                SecondPop = StackPop(Proc->stack);

                //printf("%d",SecondPop);

                StackPush(Proc->stack, FirstPop - SecondPop);

                break;

            case MUL:

                FirstPop = StackPop(Proc->stack);
                SecondPop = StackPop(Proc->stack);
                //printf("ddd\n");

                StackPush(Proc->stack, FirstPop * SecondPop);


                break;

            case DIV:

                FirstPop = StackPop(Proc->stack);
                SecondPop = StackPop(Proc->stack);

                StackPush(Proc->stack, FirstPop / SecondPop);

                break;

            case JMP:

                i = Proc->Commands.data[++i] - 1;

                break;

            case CALL:

                number = SearchBack(comeback);

                comeback[number] = i + 1;

                i = Proc->Commands.data[i + 1] - 1;
                //printf("www %d com %d www", i, comeback[number]);

                break;

            case RET:


                number = SearchBack(comeback);

                i = comeback[number - 1];

                comeback[number - 1] = 0;

                break;

            case JA:

                FirstPop = StackPop(Proc->stack);
                SecondPop = StackPop(Proc->stack);

                if(FirstPop < SecondPop) {

                    StackPush(Proc->stack, SecondPop);
                    StackPush(Proc->stack, FirstPop);

                    i = Proc->Commands.data[++i] - 1;

                } else {

                    StackPush(Proc->stack, SecondPop);
                    StackPush(Proc->stack, FirstPop);

                }

                break;

            case JE:

                FirstPop = StackPop(Proc->stack);
                SecondPop = StackPop(Proc->stack);

                //printf("ww %d %d\n", FirstPop, SecondPop);

                if(FirstPop == SecondPop) {

                    StackPush(Proc->stack, SecondPop);
                    StackPush(Proc->stack, FirstPop);

                    i = Proc->Commands.data[++i] - 1;

                } else {

                    StackPush(Proc->stack, SecondPop);
                    StackPush(Proc->stack, FirstPop);

                }

                break;

            case JB:

                FirstPop = StackPop(Proc->stack);
                SecondPop = StackPop(Proc->stack);

                if(FirstPop > SecondPop) {

                    StackPush(Proc->stack, SecondPop);
                    StackPush(Proc->stack, FirstPop);

                    i = Proc->Commands.data[++i] - 1;

                } else {

                    StackPush(Proc->stack, SecondPop);
                    StackPush(Proc->stack, FirstPop);

                }

                break;

            case OUT:

                //printf("%d\n", StackPop(Proc->stack));

                FirstPop = StackPop(Proc->stack);

                RecordToFile(FirstPop);

                break;

            case END:

                printf("End of work!\n");

                return 0;

        }

    }

    return 0;
}

