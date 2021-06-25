/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:32:11 by dcerrato          #+#    #+#             */
/*   Updated: 2021/06/25 21:25:35 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_print_comb(void)
{
	char	number[3];
	int 	i;

	i = 0;
	while (i < 3)
		number[i] = '0' + i;
	while (number[0] <= '7')
	{
		write (1, number, 3);
		if(number[0] < '7')
			write (1, ", ", 2);
		
	}
}

int	main(void)
{
	ft_print_comb();
	return (1);
}
