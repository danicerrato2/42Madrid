/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:45:22 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/05 09:57:27 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
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

int	print_digits(unsigned int n)
{
	int		i;
	char	digit[10];
	int		size;

	i = 0;
	while (n > 9)
	{
		digit[i] = '0' + n % 10;
		i++;
		n /= 10;
	}
	digit[i] = '0' + n;
	size = i + 1;
	while (i >= 0)
	{
		write (1, &digit[i], 1);
		i--;
	}
	return (size);
}

int	ft_putnbr(int n)
{
	int	written;

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
	return (written + print_digits((unsigned int)n));
}
