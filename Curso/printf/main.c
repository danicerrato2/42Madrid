#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "ft_printf.h"

int main()
{
	char *str = "%5sHola ";

	printf("Inicio de programa...\n");

	printf(str, "eiii");
	printf("\n");
	ft_printf(str, "eiii");
	printf("\n");

	return 0;
}
