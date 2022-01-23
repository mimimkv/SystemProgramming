#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int fd1, fd2;

    if ((fd1 = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0777)) == -1)
    {
        printf("ERROR\n"); 
        exit(1);
    }
    if ((fd2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0777)) == -1)
    {
        printf("ERROR\n"); 
        exit(1);
    }
    printf("fd1 = %d\n", fd1);
    printf("fd2 = %d\n", fd2);

    if (fork() == 0)
    {
        write(fd2, "HELLO1", 6);
    }
    else
    {
        wait(NULL);
        write(fd1, "HELLO2", 6);
    }

    write(1, "HELLO3", 6);
    write(fd2, "HELLO4", 6);
}