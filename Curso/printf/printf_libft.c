/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:45:22 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/07 13:54:30 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_flags flags)
{
	int	written;

	written = 0;
	if (flags.width != 0)
		flags.width -= 1;
	if (flags.minus == 0)
		written += print_width(flags);
	written += write(1, &c, 1);
	if (flags.minus != 0)
		written += print_width(flags);
	return (written);
}

int	ft_putstr(char *s, t_flags flags)
{
	int	written;
	int	s_len;

	if (s == NULL)
		return (write(1, "(null)", 6));
	written = 0;
	s_len = ft_strlen(s);
	if (flags.width != 0)
		flags.width -= s_len;
	if (flags.width < 0)
		flags.width = 0;
	if (flags.minus == 0)
		written += print_width(flags);
	written += write(1, s, s_len);
	if (flags.minus != 0)
		written += print_width(flags);
	return (written);
}

int	ft_strlen(char *str)
{
	int	i;
	int	length;

	length = 0;
	if (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			i++;
			length++;
		}
	}
	return (length);
}

int	print_digits(unsigned int n, t_flags flags)
{
	int		i;
	char	digit[10];
	int		written;

	i = 0;
	while (n > 9)
	{
		digit[i] = '0' + n % 10;
		i++;
		n /= 10;
	}
	digit[i] = '0' + n;
	flags.width -= i + 1;
	if (flags.width < 0)
		flags.width = 0;
	written = print_width(flags);
	while (i >= 0)
	{
		written += write (1, &digit[i], 1);
		i--;
	}
	return (written);
}

int	ft_putnbr(int n, t_flags flags)
{
	int	written;

 14
	written = 0;
	if (n < 0)
	{
		written += write(1, "-", 1);
		if (n == -2147483648)
		{
			written += write(1, "2", 1);
			n = 147483648;
		}
		else
			n *= (-1);
	}
	else if (flags.plus != 0)
		written += write(1, "+", 1);
	else if (flags.space != 0)
		written += write(1, " ", 1);
	return (written + print_digits((unsigned int)n, flags));
}
