#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int fd[5], i;
    char buff[16];
    int nbytes = 0;

    for (i = 1; i < argc; ++i) 
    {
        if ((fd[i] = open(argv[i], O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
        {
            printf("Cannot create %s", argv[i]);
            exit(1);
        }
    }

    while (nbytes = read(0, buff, sizeof(buff))) 
    {
        for (i = 1; i < argc; ++i)
        {
            write(fd[i], buff, nbytes);
        }
    }
}