/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:15:12 by dcerrato          #+#    #+#             */
/*   Updated: 2021/06/27 13:45:16 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_ini_combn(int digits, int lower, char *number)
{
	int	i;

	i = lower;
	while (i < digits)
	{
		number[i] = number[lower] + (i - lower);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	number[10];

	if ((n < 1) || (n > 10))
		return ;
	number[0] = '0';
	ft_ini_combn(n, 0, number);
	while (number[0] < '9' - (n - 1))
	{
		write (1, number, n);
		write (1, ", ", 2);
		i = n - 1;
		number[i]++;
		while (number[i] > '9' - ((n - 1) - i))
		{
			i--;
			number[i]++;
		}
		if (i != n - 1)
			ft_ini_combn(n, i, number);
	}
	write (1, number, n);
}
