#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, char** argv)
{
    int fd1, fd2, status;
    
    if ((fd1 = open("ff", O_WRONLY | O_CREAT, 0777)) == -1)
    {
        printf("ERROR\n"); 
        exit(1);
    }
    printf("fd1 = %d\n", fd1);
    fd2 = dup(fd1);
    printf("fd2 = %d\n", fd2);

    if (fork() == 0)
    {
        close(1);
        open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
        write(1, "HELLO CHILD", 11);
    }
    else
    {
        wait(&status);
        write(1, "HELLO PARENT", 12);
    }

    write(1, " COMMON PART", 12);
}