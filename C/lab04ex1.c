#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int fd;

    if ((fd = open("abc", O_CREAT | O_TRUNC | O_RDWR, 0744)) == -1)
    {
        write(2, "Cannot open file abc\n", 23);
        exit(1);
    }

    int fd1 = dup(fd);
    write(fd, "I AM A STUDENT ", 16);
    write(fd1, "AT FMI", 6);
}