#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0700);
	if (fd1 == -1 || fd2 == -1)
	{
		perror("cannot open file");
		exit(-1);
	}
	
	char buffer[100];
	int n;
	while( (n = read( fd1, buffer, 100)) > 0) 
	{
		write(fd2, buffer, n);
	}
	
	close(fd1);
	close(fd2);
	return 0;	
}