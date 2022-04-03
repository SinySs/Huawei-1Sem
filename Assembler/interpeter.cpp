#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "interpreter.h"
#include "read.h"

int SearchName(char *str)
{
    int number = 0;
    while(!isspace(str[number])) {

        number++;

        if(number > 100) {
            abort();
        }
    }

    return number + 1;

}

int searchLable(struct lables *lbl, char *str)
{
    for (int i = 0; i < NumberOfLbls; i++) {

        if(lbl[i].name != NULL) {

            if(strncmp(str, lbl[i].name, 4) == 0) {

                return i;
            }
        }
    }

    return -1;
}

void CompletionStruct1(int number, struct lables *lbls, int ComandNumber, struct TextInfo *Text, int i, int shag)
{

    if(number != -1) {

        lbls[number].ip = ComandNumber - 1;

    } else {

        for(int j = 0; j < NumberOfLbls; j++ ) {

            if(lbls[j].name == NULL) {

                lbls[j].name = Text->strings[i].data + shag;

                lbls[j].ip = ComandNumber - 1;

                break;
            }
        }
    }

}

void CompletionStruct2(int number, struct lables *lbls, int ComandNumber, struct TextInfo *Text, int i)
{
    if(number != -1) {

        lbls[number].addres = ComandNumber;

    } else {

        for(int j = 0; j < NumberOfLbls; j++ ) {

            if(lbls[j].name == NULL) {

                lbls[j].name = Text->strings[i].data + 1;

                lbls[j].addres = ComandNumber;

                break;
            }
        }
    }
}

int* InterpreteText(struct TextInfo *Text)
{
    int* command = (int*)calloc(Text->numberOfStrings * 2, sizeof(int));

    ReadCommand rc;

    int ComandNumber = 0;
    struct lables lbls[NumberOfLbls];
    struct lables funcs[NumberOfFuncs];

    int ok = 0;
    char str[6];
    int number;
    char reg;

    for(int i = 0; i < Text->numberOfStrings; i++) {


        if(strncmp(Text->strings[i].data, rc.push, 4) == 0) {

            if(sscanf(Text->strings[i].data, "%s [%d]", str, &number) == 2) {

                command[ComandNumber++] = PUSHFROMRAM;

                command[ComandNumber++] = number;

            } else if(sscanf(Text->strings[i].data, "%s %d", str, &number) == 2) {

                command[ComandNumber++] = PUSH;
                //printf("pu %d\n", i);

                command[ComandNumber++] = number;

            } else if( sscanf(Text->strings[i].data, "%s %cx", str, &reg) == 2) {

                command[ComandNumber++] = PUSHFROMREG;
                //printf("PU %d\n", i);

                command[ComandNumber++] = reg - 'a';

            }

        } else if(strncmp(Text->strings[i].data, rc.pop, 3) == 0) {

            if( sscanf(Text->strings[i].data, "%s %d", str, &number) == 2) {

                command[ComandNumber++] = POPINRAM;

                command[ComandNumber++] = number;

            }

            if( sscanf(Text->strings[i].data, "%s %cx", str, &reg) == 2) {

                command[ComandNumber++] = POPINREG;

                command[ComandNumber++] = reg - 'a';

            }

        } else if(strncmp(Text->strings[i].data, rc.add, 3) == 0) {

            command[ComandNumber++] = ADD;

        } else if(strncmp(Text->strings[i].data, rc.div, 3) ==0) {

            command[ComandNumber++] = DIV;

        } else if(strncmp(Text->strings[i].data, rc.mul, 3) == 0) {

            command[ComandNumber++] = MUL;

        } else if(strncmp(Text->strings[i].data, rc.sub, 3) == 0) {

            command[ComandNumber++] = SUB;

        } else if(strncmp(Text->strings[i].data, rc.out, 3) == 0) {

            command[ComandNumber++] = OUT;

        } else if(strncmp(Text->strings[i].data, rc.end, 3) == 0) {

            command[ComandNumber++] = END;

        } else if(strncmp(Text->strings[i].data, rc.in, 2) == 0) {

            command[ComandNumber++] = IN;

        } else if(strncmp(Text->strings[i].data, rc.jmp, 3) == 0) {

            command[ComandNumber++] = JMP;
            command[ComandNumber++] = -100;

            char lablename[10];

            sscanf(Text->strings[i].data, "%s %s", str, lablename);

            number = searchLable(lbls, lablename);

            CompletionStruct1(number, lbls, ComandNumber, Text, i, 4);

        } else if(strncmp(Text->strings[i].data, rc.ja, 2) == 0) {

            command[ComandNumber++] = JA;
            command[ComandNumber++] = -100;

            char lablename[10];
            int PositionOfName;

            sscanf(Text->strings[i].data, "%s %s", str, lablename);

            number = searchLable(lbls, lablename);

            PositionOfName = SearchName(Text->strings[i].data);

            CompletionStruct1(number, lbls, ComandNumber, Text, i, PositionOfName);

            //printf("%d %d %s\n", lbls[1].ip, lbls[1].addres, lbls[1].name);
        } else if(strncmp(Text->strings[i].data, rc.call, 4) == 0) {

            command[ComandNumber++] = CALL;
            command[ComandNumber++] = -100;

            char funcname[10];
            int PositionOfName;

            sscanf(Text->strings[i].data, "%s %s", str, funcname);

            number = searchLable(lbls, funcname);

            PositionOfName = SearchName(Text->strings[i].data);
            //printf("%s", funcname);

            CompletionStruct1(number, funcs, ComandNumber, Text, i, PositionOfName);
        } else if(strncmp(Text->strings[i].data, rc.ret, 3) == 0) {

            command[ComandNumber++] = RET;

        } else {

            ok = sscanf(Text->strings[i].data, ":%s", str);

            if(ok == 1) {  /// to fnc

                number = searchLable(lbls, str);
                //printf("wwwww %sw w", str);

                CompletionStruct2(number, lbls, ComandNumber, Text, i);

            } else if  (ok = sscanf(Text->strings[i].data, "%s :", str)) {

                number = searchLable(funcs, str);
                //printf(" wwww %d www", ComandNumber);
                command[funcs[number].ip] = ComandNumber;


            }
        }

    }
    command[ComandNumber] = HLT;

    command = (int*)realloc(command, (ComandNumber + 1) * sizeof(int));


    /*for(int i = 0; i < NumberOfLbls; i++) {

        //printf(" %d ", Text->numberOfStrings);

        printf("%d %d %s\n", lbls[0].ip, lbls[0].addres, lbls[0].name);
        printf("%d %d %s\n", lbls[1].ip, lbls[1].addres, lbls[1].name);
    }*/

    for(int i = 0; lbls[i].name != NULL; i++) {

        command[lbls[i].ip] = lbls[i].addres;

    }
    //printf("%d %s", funcs[0].ip, funcs[0].name);


    for (int i = 0; i < ComandNumber; i++) {
        printf(" %d %d \n", i, command[i]);
    }

    printf("%s", "Readind is completed!\n");

    return command;
}
