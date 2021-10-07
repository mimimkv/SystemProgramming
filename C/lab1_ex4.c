#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
    int fd1 = open("file1.txt", O_RDONLY | O_CREAT, 0644);
    printf("File descriptor number %d \n", fd1);
    
    int fd2 = open("file2.txt", O_RDONLY | O_CREAT, 0644);
    printf("File descriptor number %d \n", fd2);
    
    close(fd1);
    int fd3 = open("file3.txt", O_RDONLY | O_CREAT, 0644);
    printf("File descriptor number %d \n", fd3);
    return 0;
}
