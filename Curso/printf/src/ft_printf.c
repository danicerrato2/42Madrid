/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:44:54 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/05 11:42:36 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	print_format(char **str, va_list args)
{
	int		written;
//	t_flags	flags;

	*str += 1;
//	get_flags(str, &flags) == 0);
	if ((*str)[0] == 'c')
		written = ft_putchar(va_arg(args, int));
	if ((*str)[0] == 's')
		written = ft_putstr(va_arg(args, char *));
	if ((*str)[0] == 'p')
		written = print_ptr(va_arg(args, unsigned long long));
	if ((*str)[0] == 'd' || (*str)[0] == 'i')
		written = ft_putnbr(va_arg(args, int));
	if ((*str)[0] == 'u')
		written = print_digits(va_arg(args, unsigned int));
	if ((*str)[0] == 'x' || (*str)[0] == 'X')
		written = print_hexa(va_arg(args, unsigned int), (*str)[0]);
	if ((*str)[0] == '%')
		written = ft_putchar('%');
	return (written);
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
		if (str[0] == '%')
			printed += print_format(&str, args);
		else
			printed += ft_putchar(str[0]);
		str++;
	}
	va_end(args);
	return (printed);
}
