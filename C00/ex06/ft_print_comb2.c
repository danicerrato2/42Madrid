/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:11:14 by dcerrato          #+#    #+#             */
/*   Updated: 2021/06/27 16:31:05 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_print_numbers_comb2(char numbers[2][2])
{
	write (1, numbers[0], 2);
	write (1, " ", 1);
	write (1, numbers[1], 2);
	if (numbers[0][0] != '9' || numbers[0][1] != '8')
		write (1, ", ", 2);
}

void	ft_print_comb2(void)
{
	char	numbers[2][2];

	numbers[0][0] = '0';
	numbers[0][1] = '0';
	while (numbers[0][0] <= '9')
	{
		while (numbers[0][1] <= '9')
		{
			numbers[1][0] = numbers[0][0];
			numbers[1][1] = numbers[0][1] + 1;
			while (numbers[1][0] <= '9')
			{
				while (numbers[1][1] <= '9')
				{
					ft_print_numbers_comb2(numbers);
					numbers[1][1]++;
				}
				numbers[1][0]++;
				numbers[1][1] = '0';
			}
			numbers[0][1]++;
		}
		numbers[0][0]++;
		numbers[0][1] = '0';
	}
}
