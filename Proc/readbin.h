#ifndef READBIN_H_INCLUDED
#define READBIN_H_INCLUDED

struct CmdInfo{

    int *data;
    int NumberOfCommands;

};

int readbin(struct CmdInfo *Command);


#endif // READBIN_H_INCLUDED
