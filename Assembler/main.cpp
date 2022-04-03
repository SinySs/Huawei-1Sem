#include <stdio.h>

#include "read.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>


#include "read.h"
#include "interpreter.h"
#include "write.h"

int main()
{

    struct TextInfo Text;

    int error;
    error = ReadInBuF(&Text);

    if (error != 0) {
        printf("ERROR");

        return -1;
    }

    struct String Str[Text.numberOfStrings];
    CreateStrings(Text, Str);

    Text.strings = Str;

    int *code = InterpreteText(&Text);

    write(code);

}
