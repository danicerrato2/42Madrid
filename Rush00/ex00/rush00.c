/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 10:13:28 by dcerrato          #+#    #+#             */
/*   Updated: 2021/06/27 12:13:22 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);

void	ft_print_line(char first, char mid, char last, int column)
{
	int	j;

	ft_putchar(first);
	j = 2;
	while (j <= column - 1)
	{
		ft_putchar(mid);
		j++;
	}
	if (column > 1)
		ft_putchar(last);
}

void	rush(int column, int line)
{
	int	i;

	if ((line <= 0) || (column <= 0))
		return ;
	i = 1;
	while (i <= line)
	{
		if (i == 1)
			ft_print_line('o', '-', 'o', column);
		else if (i == line)
			ft_print_line('o', '-', 'o', column);
		else
			ft_print_line('|', ' ', '|', column);
		ft_putchar('\n');
		i++;
	}	
}
