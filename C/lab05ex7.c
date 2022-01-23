#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fd1, fd2;
    if ((fd1 = open("ff", O_WRONLY | O_CREAT, 0777)) == -1)
    {
        printf("ERROR\n");
        exit(1);
    }
    if ((fd2 = open("ff", O_WRONLY)) == -1)
    {
        printf("ERROR!\n");
        exit(1);
    }

    printf("fd1: %d\n", fd1);
    printf("fd2: %d\n", fd2);

    if (fork() == 0)
    {
        write(fd1, "Hello", 5);
    }
    else
    {
        write(fd2, "Hello", 5);
    }
}