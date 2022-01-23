
#include <fcntl.h>

int main() 
{
    int fd1 = open("fff", O_RDONLY | O_CREAT | O_TRUNC, 0666);
    int fd2 = open("fff", O_WRONLY);
    int fd3 = open("fff", O_RDWR);

    write(fd2, "Hello world", 11);
    char buffer1[6];
    read(fd3, buffer1, 6);
    write(1, buffer1, 6);

    char buffer2[5];
    read(fd1, buffer2, 5);
    write(1, buffer2, 5);

    write(fd3, "chil", 4);
    write(fd2, "!!!", 3);

    char buffer3[9];
    read(fd1, buffer3, 9);
    write(1, buffer3, 9);
    return 0;
}