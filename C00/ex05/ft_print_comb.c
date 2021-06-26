/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:32:11 by dcerrato          #+#    #+#             */
/*   Updated: 2021/06/26 15:48:09 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_print_comb(void)
{
	int		i;
	int		flag;
	char	number[3];

	i = 0;
	while (i < 3)
		number[i] = '0' + i;
	while (number[0] <= '7')
	{
		write (1, number, 3);
		if (number[0] < '7')
			write (1, ", ", 2);
		i = 2;
		flag = 1;
		while (flag)
		{
			number[i]++;
			if (number[i] > '9' - (2 - i))
			{
				number[i] = number[i - 1] + 2;
				i--;
			}
			else
				flag = 0;
		}	
	}
}

int	main(void)
{
	ft_print_comb();
	return (1);
}
