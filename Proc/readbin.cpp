#include <stdio.h>
#include <stdlib.h>

#include "readbin.h"

typedef int ProcElem;

long FileSize(FILE *Text)
{
    fseek(Text, SEEK_SET, SEEK_END);

    long sizeFile = 0;
    sizeFile = ftell(Text);

    rewind(Text);

    return sizeFile;
}

int readbin(struct CmdInfo *Command)
{
    FILE *Text;

    if((Text = fopen("../assembler/commands.bin", "rb")) == NULL) {
        return -1;
    }

    long sizeText = (FileSize(Text) / sizeof(ProcElem));

    if((Command->data = (ProcElem*)calloc(sizeText + 1, sizeof(ProcElem))) == NULL) {

        return -1;
    }

    fread(Command->data, sizeof(ProcElem), sizeText, Text);

    Command->NumberOfCommands = sizeText;

    fclose(Text);

    return 0;

}
