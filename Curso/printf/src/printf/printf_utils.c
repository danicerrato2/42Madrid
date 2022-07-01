/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:45:30 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/01 14:20:21 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libftprintf.h"

int	print_ptr(void *ptr)
{
	char			digits[12];
	int				i;
	unsigned int	p;

	i = 11;
	p = (unsigned int)ptr;
	while (p != 0)
	{
		digits[i] = "0123456789abcdef"[p % 16];
		i--;
		p /= 16;
	}
	while (i >= 0)
	{
		digits[i] = '0';
		i--;
	}
	return write(1, "0x", 2) + write(1, digits, 12);
}

int	print_hexa(unsigned int n, char case_type)
{
	char	base16[16];
	int		written;

	if (case_type == 'X')
		ft_strlcpy(base16, "0123456789ABCDEF", 16);
	else
		ft_strlcpy(base16, "0123456789abcdef", 16);
	written = 0;
	while (n >= 16)
	{
		written += write(1, &base16[n / 16], 1);
		n %= 16;
	}
	written += write(1, &base16[n], 1);
	return written;
}
