#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "get_next_line.h"

int main()
{
	char *str;
	int	i;
	int fd = open("file.txt", O_RDWR);

	str = "";
	i = 0;
	while (str != NULL){
		i++;
		printf("\nLinea %d:\n", i);
		str = get_next_line(fd);
		if (str != NULL)
			printf("\"%s\"\n", str);
	}
	close(fd);

	return 0;
}
