#include "libftprintf.h"

int	print_format(char *str, va_list args)
{
	char str[1];

	if (str[1] == 'c')
		return ft_putchar(va_arg(args, char));
	if (str[1] == 's')
		return ft_putstr(va_arg(args, char *));
	if (str[1] == 'p')
		return print_ptr(va_arg(args, void *));
	if (str[1] == 'd' || type == 'i')
		return ft_putnbr(va_arg(args, int));
	if (str[1] == 'u')
		return print_digits(va_arg(args, unsigned int));
	if (str[1] == 'x' || str[1] == 'X')
		return print_hexa(va_arg(args, unsigned int), str[1]);
	if (str[1] == '%')
		return ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		printed;

	va_start(args, format);
	printed = 0;
	str = (char *)format;
	while (str[0] != 0)
	{
		if (str == '%')
			printed += print_format(str, args);
		ft_putchar_fd(str[0], 1);
		printed++;
		str++;
	}
	va_end(args);
	return printed;
}
