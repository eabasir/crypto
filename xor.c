#include <stdio.h>
#include <unistd.h>
#include <string.h>

int processArgs(int *argc, char *argv[], char *key, char *filePath, int *decrypt);

int main(int argc, char *argv[])
{
    char *key = "";
    char *filePath = "";
    int decrypt = 0;

    if (!processArgs(&argc, argv, key, filePath, &decrypt))
    {
        return 1;
    }

    return 0;
}

int processArgs(int *argc, char *argv[], char *key, char *filePath, int *decrypt)
{

    char ch;

    while ((ch = (getopt(*argc, argv, "f:k:d"))) != EOF)
    {
        switch (ch)
        {
        case 'k':
            key = optarg;
            break;

        case 'f':
            filePath = optarg;
            break;
        case 'd':
            *decrypt = 1;
            break;
        default:
            fprintf(stderr, "invlid args \n");
            return 1;
        }
    }

    argc -= optind;
    argv += optind;

    if (!key[0])
    {
        fprintf(stderr, "xor key is required \n");
        return 1;
    }

    return 0;
}