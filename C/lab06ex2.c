#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int fd;

    if ((fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0777)) == -1)
    {
        printf("ERROR\n"); 
        exit(1);
    }
    printf("fd = %d\n", fd);
    if (fork() == 0)
    {
        write(fd, "HELLO1", 6);
    }
    else
    {
        write(fd, "HELLO2", 6);
    }
    
}