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
        printf("%s\n",buff,i);
    }
    close(fd);
    return 0;
}
