#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERROR -1

int main(int argc, char** argv)
{
    int exitCode = 0;
    if (execlp("grep", "grep", "int", argv[1], 0) == ERROR)
    {
        perror("Error!");
        printf("This is never printed\n");
        exitCode = 1;
    }
    else
    {
        printf("This line is never printed\n");
    }
    exit(exitCode);
}