#include <stdio.h>
#include <limits.h>
#include "inc/ft_printf.h"

int main()
{
	char *str = " %x ";

	printf("Inicio de programa...\n");

	printf(str, LONG_MAX);
	printf("\n");
	ft_printf(str, LONG_MAX);
	printf("\n");

	printf("Fin de programa\n");

	return 0;
}
