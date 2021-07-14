/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:27:08 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/14 17:12:50 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	put_winner_in_table(t_b *table, t_s *winner)
{
	int	i;
	int	j;

	i = winner->row;
	while (i < winner->row + winner->size)
	{
		j = winner->col;
		while (j < winner->col + winner->size)
		{
			table->board[i][j] = table->filled;
			j++;
		}
		i++;
	}
}

int	try_squares(int row, int col, int size, t_b *table)
{
	int	i;
	int	j;

	size = check_size(row, size, table);
	j = 0;
	while (j < size)
	{
		i = 1;
		while (i < size)
		{
			if (table->board[row + i][col + j] == table->block)
			{
				if (j < i)
					size = i;
				else
					size = j;
				break ;
			}
			i++;
		}	
		j++;
	}
	return (size);
}

void	search_emptys_in_row(int row, t_b *table, t_s *winner)
{
	int	col;
	int	col_ini;
	int	size;

	col_ini = 0;
	while (col_ini <= table->rows)
	{
		col = col_ini;
		while (check_position(row, col, col_ini, table))
		{
			if (table->board[row][col] != table->empty)
			{
				if (col - col_ini != 0 && col - col_ini >= winner->size)
				{
					size = try_squares(row, col_ini, col - col_ini, table);
					check_distance(row, col_ini, size, winner);
				}
				break ;
			}
			col++;
		}
		col_ini++;
	}
}

void	resolve_table(t_b *table, t_s *winner)
{
	int	row;

	row = 0;
	while (row < table->rows)
	{
		search_emptys_in_row(row, table, winner);
		row++;
	}
}
