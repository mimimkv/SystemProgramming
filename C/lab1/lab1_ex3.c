#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
    int fd = open(argv[1], O_RDONLY);
    char buffer[1000];
    int bytesRead = read(fd, buffer, 1000);
    printf("Chars read %d \n", bytesRead);
    write(1, buffer, bytesRead);
    return 0;
}
