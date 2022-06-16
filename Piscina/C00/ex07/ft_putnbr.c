/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:12:27 by dcerrato          #+#    #+#             */
/*   Updated: 2021/06/28 10:14:33 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_digits(int nb)
{
	int		i;
	char	digit[10];

	i = 0;
	while (nb > 9)
	{
		digit[i] = '0' + nb % 10;
		i++;
		nb /= 10;
	}
	digit[i] = '0' + nb;
	while (i >= 0)
	{
		write (1, &digit[i], 1);
		i--;
	}
}

void 	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write (1, "-", 1);
		if (nb == -2147483648)
		{
			write (1, "2", 1);
			nb = 147483648;
		}
		else
			nb *= (-1);
	}
	print_digits(nb);
}
