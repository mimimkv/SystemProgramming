#include <stdio.h>
#include <fcntl.h>
int main()
{
    int fd = creat("file1.txt", 0644);
    if(fd == -1)
    {
        printf("Can't create file!");
        return (-1);
    }
    printf("File created!");
    return 0;
}
