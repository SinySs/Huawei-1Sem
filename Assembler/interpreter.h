#ifndef INTERPRETER_H_INCLUDED
#define INTERPRETER_H_INCLUDED

#define NumberOfLbls 10
#define NumberOfFuncs 10

int* InterpreteText(struct TextInfo *Text);

struct lables {

    int addres;  //куда будет переведется исполнение
    int ip;      //место, куда нужно поставить адрес
    char *name  = NULL;

};


struct ReadCommand {

    char *push = "push";
    char *pop  = "pop";
    char *in   = "in";
    char *add  = "add";
    char *sub  = "sub";
    char *mul  = "mul";
    char *div  = "div";
    char *jmp  = "jmp";
    char *ja   = "ja";
    char *call = "call";
    char *ret  = "ret";
    char *out  = "out";
    char *end  = "end";

};

enum {

    PUSH = 1,
    PUSHFROMREG = 17, ///!!!!!
    PUSHFROMRAM = 18, ///!!!!!
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
    END  = 666,
    HLT  = 1000,
};




#endif // INTERPRETER_H_INCLUDED
