#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "xor.h"
#include "message_xor.h"

int main(int argc, char **argv)
{
    char key = 0;
    char *filePath = "";

    int processReturnCode = processArgs(&argc, &argv, &key, filePath);
    if (processReturnCode)
    {
        return processReturnCode;
    }

    if (filePath[0])
    {
    }
    else
    {
        xorMessage(argv[0], key);
    }

    return 0;
}

int processArgs(int *argc, char **argv[], char *key, char *filePath)
{
    char ch;
    while ((ch = (getopt(*argc, *argv, "f:k:"))) != EOF)
    {
        switch (ch)
        {
        case 'k':
            *key = atoi(optarg);
            break;

        case 'f':
            filePath = optarg;
            break;
        default:
            fprintf(stderr, "invlid args \n");
            return 1;
        }
    }

    *argc -= optind;
    *argv += optind;
    
    if (*key == 0)
    {
        fprintf(stderr, "cypher key is required \n");
        return 1;
    }

    if (!filePath[0] && !*argv[0])
    {
        fprintf(stderr, "either file path or message is required \n");
        return 1;
    }

    return 0;
}