#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "ft_printf.h"

int main()
{
	char *str = "%.4dhola\n";
	int printf_n, ft_printf_n;

	printf("Inicio de programa...\n");

	printf_n = printf(str, 257);
	printf("\n");
//	ft_printf_n = ft_printf(str, 20);
	printf("\n");

	printf("printf escribió %d caracteres\n", printf_n);
	printf("ft_printf escribió %d caracteres\n", ft_printf_n);

	return 0;
}
