#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "get_next_line_bonus.h"

int main()
{
	char *str;
	int	i;
//	char buf[10];
//	size_t bytes_read;
	int fd = open("file.txt", O_RDONLY);
//	int fd1 = open("file1.txt", O_RDONLY);
//	int fd2 = open("file2.txt", O_RDONLY);

	printf("Inicio de programa ...\n");

/*
	printf("1000: %s\n", get_next_line(1000));
	printf("fd1: %s\n", get_next_line(fd1));
	printf("1001: %s\n", get_next_line(1001));
	printf("fd2: %s\n", get_next_line(fd2));
	printf("fd1: %s\n", get_next_line(fd1));
	printf("fd2: %s\n", get_next_line(fd2));
*/

	str = "";
	i = 0;
	while (str != NULL && i < 3){
		i++;
		str = get_next_line(1001);
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
//	close(fd1);
//	close(fd2);

	printf("Fin de programa\n");
	return 0;
}
