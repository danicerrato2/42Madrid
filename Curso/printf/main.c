#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "ft_printf.h"

int main()
{
	char *str = "Hola%#-4xHola";

	printf("Inicio de programa...\n");

	printf(str, 13);
	printf("\n");
//	ft_printf(str, '1', '2', '3');
	printf("1111111111111\n");

	return 0;
}
