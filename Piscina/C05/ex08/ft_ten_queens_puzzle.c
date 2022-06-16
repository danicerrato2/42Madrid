/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:22:12 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/07 13:32:13 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	in_diagonal(char *queens, int q1, int q2)
{
	int	dif_col;
	int	dif_row;

	dif_row = queens[q1] - queens[q2];
	if (dif_row < 0)
		dif_row *= (-1);
	dif_col = q1 - q2;
	if (dif_col < 0)
		dif_col *= (-1);
	return (dif_col - dif_row);
}

int	validate_queen(char *queens, int queen)
{
	int	i;

	i = queen - 1;
	while (i >= 0)
	{
		if (queens[queen] == queens[i] || in_diagonal(queens, queen, i) == 0)
			return (0);
		i--;
	}
	return (1);
}

int	try_queen(char *queens, int queen)
{
	int	i;
	int	ret;

	if (queen >= 10)
	{
		write (1, queens, 10);
		write (1, "\n", 1);
		return (1);
	}
	i = 0;
	ret = 0;
	while (i < 10)
	{
		queens[queen] = '0' + i;
		if (validate_queen(queens, queen) != 0)
			ret += try_queen(queens, queen + 1);
		i++;
	}
	return (ret);
}

int	ft_ten_queens_puzzle(void)
{
	char	queens[10];

	return (try_queen(queens, 0));
}
