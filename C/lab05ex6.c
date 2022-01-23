#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int exitCode = 0;
    
    if (execvp(argv[1], &argv[1]) == -1)
    {
        printf("ERROR!\n");
        exitCode = 1;
    }
    else
    {
        printf("This line is never printed\n");
    }
    exit(exitCode);
}