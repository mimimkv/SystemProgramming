#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char buff[16];
int main()
{
    int fd = open("aa", O_RDONLY);
    int bytes = 0;
    for(int i = 5; i >= 1; --i)
    {
        read(fd, buff, i);
        write(1, buff, i);
        printf("\n");
    }
    close(fd);
    return 0;
}
