#include <fcntl.h>

int main()
{
    int fd1 = open("fff", O_RDONLY | O_TRUNC | O_CREAT, 0666);
    int fd2 = open("fff", O_WRONLY);
    int fd3 = open("fff", O_RDWR);

    write(fd3, "Hello", 5);
    write(fd2, "worlds", 6);
    
    char buffer[20];
    read(fd1, buffer, 6);
    write(1, buffer, 6);

    close(fd2);
    write(fd3, "oops", 4);
    read(fd1, buffer, 6);
    write(1, buffer, 6);
}
