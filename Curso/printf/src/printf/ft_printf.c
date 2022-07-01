/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:44:54 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/01 14:16:21 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libftprintf.h"

int	print_format(char *str, va_list args)
{
	if (str[1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (str[1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (str[1] == 'p')
		return (print_ptr(va_arg(args, void *)));
	if (str[1] == 'd' || str[1] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (str[1] == 'u')
		return (print_digits(va_arg(args, unsigned int)));
	if (str[1] == 'x' || str[1] == 'X')
		return (print_hexa(va_arg(args, unsigned int), str[1]));
	if (str[1] == '%')
		return (ft_putchar('%'));
	return (0);
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
			printed += print_format(str, args);
		ft_putchar_fd(str[0], 1);
		printed++;
		str++;
	}
	va_end(args);
	return printed;
}
