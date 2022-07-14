#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char buf[10];
	int	n;
	int fd = open("file.txt", 'r');

	n = read(fd, buf, 1);
	printf("%d\n", n);
	printf("%s\n", buf);

	close(fd);

	return 0;
}
