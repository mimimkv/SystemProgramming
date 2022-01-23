#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
//#include <sys/wait.h>

int main(int argc, char** argv) 
{
    int fd, fd1;
    int status, i = 0;
    char buffer[64], c;

    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        printf("Cannot open %s\n", argv[1]);
        exit(1);
    }

    if ((fd1 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0744)) == -1)
    {
        printf("Cannot open %s\n", argv[2]);
        exit(1);
    }

    if (fork() != 0)
    {
        wait(&status);
        execlp("wc", "wc", "-l", argv[2], 0);
    } 
    else 
    {
        while (read(fd, &c, 1) > 0)
        {
            if (c != '\n')
            {
                buffer[i++] = c;
            }
            else
            {
                if (buffer[i - 1] == '$')
                {
                    for (int k = 0; k < i; ++k)
                    {
                        write(1, &buffer[k], 1);
                    }
                    write(1, "\n", 1);
                    buffer[0] = '\0';
                }
                else
                {
                    short containsDigit = 0; 
                    for (int k = 0; k < i; ++k)
                    {
                        if (buffer[k] >= '0' && buffer[k] <= '9')
                        {
                            write(fd1, &buffer[k], 1);
                            containsDigit = 1;
                        }
                    }
                    if (containsDigit)
                    {
                        write(fd1, "\n", 1);
                    }
                    buffer[0] = '\0';
                }
                i = 0;
            }
        }
    }
}
