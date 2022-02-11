#include "message_xor.h"
#include <stdio.h>

void xorMessage(char *message, char key)
{
    while (*message)
    {
        *message = *message ^ key;
        printf("%c", *message);
        message++;
    }
    puts("");
}