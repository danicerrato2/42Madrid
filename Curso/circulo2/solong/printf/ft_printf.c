/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicerrato2 <danicerrato2@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:44:54 by dcerrato          #+#    #+#             */
/*   Updated: 2023/08/20 13:26:24 by danicerrato      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char **str, va_list args)
{
	int		written;
	t_flags	flags;

	*str += 1;
	get_flags(str, &flags);
	if ((*str)[0] == 'c')
		written = ft_putchar(va_arg(args, int), flags);
	if ((*str)[0] == 's')
		written = ft_putstr(va_arg(args, char *), flags);
	if ((*str)[0] == 'p')
		written = print_ptr(va_arg(args, unsigned long long), flags);
	if ((*str)[0] == 'd' || (*str)[0] == 'i')
		written = ft_putnbr(va_arg(args, int), flags);
	if ((*str)[0] == 'u')
		written = print_digits(va_arg(args, unsigned int), 0, flags);
	if ((*str)[0] == 'x' || (*str)[0] == 'X')
		written = print_hexa(va_arg(args, unsigned int), (*str)[0], flags);
	if ((*str)[0] == '%')
		written = ft_putchar('%', flags);
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
			printed += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (printed);
}
