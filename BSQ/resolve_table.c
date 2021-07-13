/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:27:08 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/13 20:49:16 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	put_winner_in_table(t_b *table, t_s *winner)
{
	int	i;
	int	j;

	i = winner->row;
	while (i < winner->size)
	{
		j = winner->col;
		while (j < winner->size)
		{
			table->board[i][j] = table->filled;
			j++;
		}
		i++;
	}
}

void	try_squares(int row, int col, int size, t_b *table, t_s *winner)
{
	int	i;
	int	j;

	j = 1;
	while (j < size)
	{
		i = 1;
		while (i < size)
		{
			if (table->board[row + i][col + j] == table->block)
			{
				size = j;
				break;
			}
			i++;
		}	
		j++;
	}
	if (size > winner->size)
	{
		winner->size = size;
		winner->row = row;
		winner->col = col;
	}
}

void	resolve_table(t_b *table, t_s *winner)
{
	int	row;
	int	col;
	int col_ini;

	row = 0;
	winner->size = 0;
	while (row < table->rows)
	{
		col_ini = 0;
		col = 0;
		while (col < table->columns)
		{
			if (table->board[row][col] != table->empty)
			{
				if (col - col_ini != 0)
					try_squares(row, col_ini, col - col_ini, table, winner);
				col_ini = col + 1;
			}
			col++;
		}
		row++;
	}
}
