/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:58:24 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/05 10:55:10 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digits(int nb)
{
	int		i;
	char	digits[10];

	i = 0;
	while (nb > 9)
	{
		digits[i] = '0' + nb % 10;
		i++;
		nb /= 10;
	}
	digits[i] = '0' + nb;
	while (i >= 0)
	{
		write(1, &digits[i], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{	
			write(1, "2", 1);
			nb = 147483648;
		}
		else
			nb *= (-1);
	}
	print_digits(nb);
}
