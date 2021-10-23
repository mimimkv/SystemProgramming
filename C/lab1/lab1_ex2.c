#include <stdio.h>
#include <fcntl.h>
int main()
{
    int fd = open("file2.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if(fd == -1)
    {
        printf("Cannot open file!");
        return (-1);
    }
    printf("File opened");
    return 0;
}
