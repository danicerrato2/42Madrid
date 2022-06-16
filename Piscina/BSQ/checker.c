/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:44:02 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/14 17:13:09 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_size(int row, int size, t_b *table)
{
	if (row + size > table->rows)
		return (table->rows - row);
	return (size);
}

void	check_distance(int row, int col, int size, t_s *winner)
{
	if (size > winner->size || \
			(size == winner->size && row + col < winner->row + winner->col))
	{
		winner->size = size;
		winner->row = row;
		winner->col = col;
	}
}

int	check_position(int row, int col, int col_ini, t_b *table)
{
	if (col <= table->columns && \
			table->board[row][col_ini] == table->empty)
		return (1);
	return (0);
}
