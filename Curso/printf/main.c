#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
//#include "inc/ft_printf.h"

int main()
{
	char *str = " %d ";
	void *mem;

	printf("Inicio de programa...\n");

//	printf(str, 0);
//	printf("\n");
//	ft_printf(str, 0);
//	printf("\n");

	mem = calloc(INT_MAX, INT_MAX - 1);
	if (mem == NULL)
		printf("Dio NULL\n");
	else
		printf("No dio NULL\n");

	printf("Fin de programa\n");

	if (mem != NULL)
		free(mem);
	return 0;
}
