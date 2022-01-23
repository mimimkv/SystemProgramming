#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd1, fd2, status;
    if ((fd1 = open("ff", O_WRONLY | O_CREAT, 0777)) == -1)
    {
        printf("ERROR\n");
        exit(1);
    }
    printf("fd1: %d\n", fd1);
    fd2 = dup(fd1);
    printf("fd2: %d\n", fd2);

    if (fork() == 0)
    {
        write(fd1, "HELLO CHILD\n", 13);
    }
    else
    {
        wait(&status);
        write(fd2, "HELLO PARENT\n", 14);
    }
    write(fd1, "COMMON PART\n", 13);
}