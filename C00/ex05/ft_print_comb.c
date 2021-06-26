/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:32:11 by dcerrato          #+#    #+#             */
/*   Updated: 2021/06/26 20:48:17 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_ini_comb(char lower, char *number)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		number[i] = lower + i;
		i++;
	}
}

void	ft_print_comb(void)
{
	int		i;
	char	number[3];

	ft_ini_comb('0', number);
	while (number[0] < '9' - 2)
	{
		write (1, number, 3);
		write (1, ", ", 2);
		i = 2;
		number[i]++;
		while (number[i] > '9' - (2 - i) && i > 0)
		{
			number[i] = number[i - 1] + 2;
			i--;
			if (i > 0)
				number[i]++;
		}
		if (i == 0)
			ft_ini_comb(number[0] + 1, number);
	}
	write (1, number, 3);
}

int	main(void)
{
	ft_print_comb();
	return (1);
}
