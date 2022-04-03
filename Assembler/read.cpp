#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>


#include "read.h"

long FileSize(FILE *Text)
{
    fseek(Text, SEEK_SET, SEEK_END);

    long sizeFile = 0;
    sizeFile = ftell(Text);

    rewind(Text);

    return sizeFile;
}

int StrCount(char *Text, long sizeFile)
{
    int strCount = 1;
    char *ch = Text;

    while ((ch = strchr(ch, '\n')) != NULL) {

        strCount++;
        *ch++;

    }

    return strCount;
}

void CreateStrings(struct TextInfo Text, struct String *Str)
{

    int i = 0;

    char *bufSymbol = Text.buf;


    Str[i].data = bufSymbol;

    while((bufSymbol = strchr(bufSymbol, '\n')) != NULL) {

        *bufSymbol = '\0';
        *bufSymbol++;

        Str[++i].data = bufSymbol;

        Str[i-1].NumberOfChar = strlen(Str[i-1].data);


    }
    Str[i].NumberOfChar = strlen(Str[i].data);
}

int ReadInBuF(struct TextInfo *Text)
{
    FILE *TextC;
    if((TextC = fopen("test.txt", "r")) == NULL) {
        return -1;
    }

    Text->nameOfText = "Commands";

    long sizeText = FileSize(TextC);
    Text->sizeOfText = sizeText;


    if((Text->buf = (char*)calloc(sizeText + 1, sizeof(char))) == NULL) {
        return -1;
    }

    fread(Text->buf, 1, sizeText, TextC);

    int strText = StrCount(Text->buf, sizeText);

    Text->numberOfStrings = strText;

    fclose(TextC);

    return 0;

}

