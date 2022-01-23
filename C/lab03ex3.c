
#include <fcntl.h>
#include <stdio.h>

int main() 
{
    int fd = open("f1", O_WRONLY | O_TRUNC | O_CREAT, 0744);
    write(fd, "abcd-abcd-abcd", 15);
    close(fd);

    int fd1 = open("f1", O_RDONLY);
    int fd2 = open("f1", O_WRONLY);

    int l1 = lseek(fd2, -3, SEEK_END);
    printf("\nlseek returns -->%d\n", l1);
    write(fd2, "wxyz", 4);

    int l2 = lseek(fd2, 4, SEEK_SET);
    printf("\nlseek returns -->%d\n", l2);
    write(fd2, "12",2);

    char buffer[20];
    lseek(fd1, 0, SEEK_SET);
    int readBytes = read(fd1, buffer, 20);
    write(1, buffer, readBytes);
    return 0;
}