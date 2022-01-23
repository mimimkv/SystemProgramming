#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main()
{
    int fd = open("abc", O_CREAT | O_TRUNC | O_RDWR, 0744);
    printf("fd = %d\n", fd);
    if (fd == -1)
    {
        write(2, "Cannot open file abc\n", 22);
        exit(1);
    }

    for (int i = 0; i <= 9; ++i)
    {
        write(1, "EXAMPLE\n", 9);
    }

    int fd1 = dup(1);
    close(1);
    int fd2 = dup(fd);
    char str[32];

    for (int i = 0; i <= 9; ++i)
    {
        sprintf(str, "i = %d\n", i);
        write(1, str, strlen(str));
    }

    close(1);
    dup(fd1);

    for (int i = 0; i <= 9; ++i)
    {
        write(1, "HELLO you!!!\n", 16);
    }
}