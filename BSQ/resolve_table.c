/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:27:08 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/13 20:02:14 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	resolve_table(t_b *table, t_s *winner)
{
	int	row;
	int	col;
	int col_ini;
	t_s	winner;

	row = 0;
	winner->size = 0;
	while (row < table->rows)
	{
		col_ini = 0;
		col = 0;
		while (col < table->columns)
		{
			if (table->board[row][col] == tab->empty)
				tam++;
			else
			{
				if (col - col_ini != 0)
					try_squares(row, col_ini, col - col_ini, table, &winner);
			}
		}
	}
}
