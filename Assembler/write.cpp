#include <stdio.h>
#include <stdlib.h>

#include "write.h"

int write(int *commands)
{
    FILE *output;

    int i = 0;

    if((output = fopen("commands.bin", "wb")) == NULL) {

        return -1;

    }

    while(commands[i] != HLT) {

        fwrite(&commands[i++], sizeof(int), 1, output);

    }

    fwrite(&commands[i++], sizeof(int), 1, output);

    fclose(output);

    return 0;
}
