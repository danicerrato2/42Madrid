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
//	char buf[BUFFER_SIZE];
//	size_t bytes_read;
	int fd = open("file.txt", O_RDONLY);

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

	close(fd);

/*	printf("Inicio de programa ...\n");
	bytes_read = read(fd, buf, 1);
	if ((int)bytes_read == 0)
		printf("Soy EOF\n");
	else
		printf("No guarda EOF\n");
*/

	return 0;
}
