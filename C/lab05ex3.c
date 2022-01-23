#include <stdio.h>

int main()
{
    int number, status;

    if (fork())
    {
        printf("parent: pid = %d, ppid = %d\n", getpid(), getppid());
        number = 100;
    }
    else
    {
        printf("child: pid = %d, ppid = %d\n", getpid(), getppid());
        number = 200;
    }
    printf("Common part, number = %d\n", number);
}