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
//	char buf[10];
//	size_t bytes_read;
	int fd = open("file.txt", O_RDONLY);

	printf("Inicio de programa ...\n");


	str = "";
	i = 0;
	while (str != NULL && i < 3){
		i++;
		str = get_next_line(fd);
		if (str != NULL){
			printf("\nLinea %d:\n", i);
			printf("\"%s\"\n", str);
			free(str);
		}
	}

/*
	strcpy(buf, "123456789");
	bytes_read = read(fd, buf, 4);
	printf("%s\n", buf);
*/

	close(fd);

	printf("Fin de programa\n");
	return 0;
}
