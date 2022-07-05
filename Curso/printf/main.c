#include <stdio.h>
#include <limits.h>
#include "inc/ft_printf.h"

int main()
{
	char *str = " %d ";

	printf("Inicio de programa...\n");

	printf(str, 0);
	printf("\n");
	ft_printf(str, 0);
	printf("\n");

	printf("Fin de programa\n");

	return 0;
}
