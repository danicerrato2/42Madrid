#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "ft_printf.h"

int main()
{
	char *str = "%p %phola";
	int printf_n = 0, ft_printf_n = 0;

	printf("Inicio de programa...\n");

	printf_n = printf(str, 0, 0);
	printf("\n");
	ft_printf_n = ft_printf(str, 0, 0);
	printf("\n");

	printf("printf escribió %d caracteres\n", printf_n);
	printf("ft_printf escribió %d caracteres\n", ft_printf_n);

	return 0;
}
