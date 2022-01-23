#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd = open("abc", O_CREAT | O_TRUNC | O_RDWR, 0744);
    if (fd == -1)
    {
        write(2, "Cannot open file abc\n", 22);
        exit(1);
    }

    close(1);
    int k = dup(fd);

    printf("Number of file descriptor k is %d\n", k);

    for (int i = 0; i <= 15; ++i)
    {
        printf("i = %d\n", i);
    }
}