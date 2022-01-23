#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char buff[512];
    int n;
	while ( (n = read(0, buff, 512)) > 0)
	{
		write(1, buff, n);
	}
	return 0;
}