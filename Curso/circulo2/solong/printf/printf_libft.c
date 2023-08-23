/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicerrato2 <danicerrato2@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:45:22 by dcerrato          #+#    #+#             */
/*   Updated: 2023/08/20 13:26:36 by danicerrato      ###   ########.fr       */
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
		s = "(null)";
	written = 0;
	s_len = ft_strlen_p(s);
	if (flags.dot >= 0 && s_len > flags.dot)
		s_len = flags.dot;
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

int	print_flags_and_nbr(char *digits, int is_negative, t_flags flags)
{
	int	written;
	int	digits_len;

	written = 0;
	digits_len = ft_strlen_p(digits);
	if (flags.dot >= 0 && digits[0] == '(' && flags.dot < digits_len)
		return (0);
	if (flags.minus == 0 && flags.zero == 0)
		written += print_width(flags);
	if (is_negative != 0)
		written += write(1, "-", 1);
	while (flags.dot-- > 0)
		written += write(1, "0", 1);
	if (flags.minus == 0 && flags.zero != 0)
		written += print_width(flags);
	written += write(1, digits, digits_len);
	if (flags.minus != 0)
		written += print_width(flags);
	return (written);
}

int	print_digits(unsigned int n, int is_negative, t_flags flags)
{
	int		nbr_size;
	char	digits[11];

	nbr_size = get_nbr_size_in_base((unsigned long long)n, 10);
	if (n == 0 && flags.dot == 0)
		nbr_size = 0;
	flags.dot -= nbr_size;
	if (flags.dot < 0)
		flags.dot = 0;
	flags.width -= flags.dot + nbr_size + is_negative;
	if (flags.width < 0)
		flags.width = 0;
	digits[nbr_size] = 0;
	while (--nbr_size >= 0)
	{
		digits[nbr_size] = '0' + n % 10;
		n /= 10;
	}
	return (print_flags_and_nbr(digits, is_negative, flags));
}

int	ft_putnbr(int n, t_flags flags)
{
	int				written;
	unsigned int	nbr;
	int				is_negative;

	written = 0;
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		nbr = -n;
	}
	else
	{
		nbr = n;
		if (flags.plus != 0)
			written += write(1, "+", 1);
		else if (flags.space != 0)
			written += write(1, " ", 1);
	}
	return (written + print_digits(nbr, is_negative, flags));
}
