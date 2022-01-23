#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    char str[8];

    for (int i = 0; i <= 5; ++i)
    {
        printf("i = %d\n", i);
    }

    int fd = dup(1);
    write(1, "duplicated descriptor fd = ", sizeof("duplicated descriptor fd = "));
    sprintf(str, "%d", fd);
    write(1, str, strlen(str));
    write(1, "\n", 1);

    for (int i = 0; i <= 10; ++i)
    {
        sprintf(str, "i = %d\n", i);
        write(fd, str, strlen(str));
    }
}