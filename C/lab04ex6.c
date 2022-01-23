#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main(int argc, char** argv)
{
    int fd;
    char buff[25], str[5];

    close(0);

    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        write(2, "Cannot open file for reading\n", 30);
        exit(1);
    }

    int bytesR, bytesW, fileSize = 0;
    while (bytesR = read(0, buff, 25))
    {
        bytesW = write(1, buff, bytesR);
        if (bytesR == bytesW)
        {
            fileSize += bytesR;
        }
        else
        {
            write(2, "I/O error!\n", sizeof("I/O error!\n"));
        }
    }

    write(1, "\nSize of file --> ", 18);
	sprintf(str, "%d", fileSize);
	write(1, str, strlen(str));
	write(1, " characters\n", 12); 

	printf ("\nSize of file --> %d characters\n", fileSize);
}