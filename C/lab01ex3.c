#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    
	int fd1 = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0700);
	if (fd1 == -1)
	{
		perror("cannot open file");
		exit(-1);
	}

	char buff[512];
    int n;
	while ( (n = read(0, buff, 512)) > 0)
	{
		write(fd1, buff, n);
	}
	return 0;
}