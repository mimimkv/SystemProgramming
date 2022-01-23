#include <stdio.h>

int main()
{
    int fd = dup(1);
    printf("Number of fd = %d\n", fd);

    write(1, "Hello", sizeof("Hello"));
    write(fd, "-guys", sizeof("-guys"));
    write(1, "-and-goodbye!\n", 15);

    close(1);
    write(1, "No\n", sizeof("No\n"));
    write(fd, "Yes\n", sizeof("Yes\n"));
}