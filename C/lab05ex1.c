#include <stdio.h>

int main()
{
    int status;

    if (fork() == 0)
    {
        printf("child --> pid = %d ppid = %d\n", getpid(), getppid());
        int i;
        for (i = 1; i<= 1000000000; i++);
    } 
    else
    {
        wait(&status);
        printf("parent --> pid = %d ppid = %d\n", getpid(), getppid());
    }
    printf("Common part\n");
}