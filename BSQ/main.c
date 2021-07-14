/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:03:39 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/14 16:28:28 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_table(t_b *table)
{
	int	i;

	i = 0;
	while (i < table->rows)
	{
		write(1, table->board[i], table->columns + 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	t_b	table;
	t_s	winner;

	i = 1;
	while (i < argc)
	{
		if (open_file(argv[i], &table) == 0 && handle_board(&table) == 0)
		{
			winner.size = 0;
			winner.col = 1000000000;
			winner.row = 1000000000;
			resolve_table(&table, &winner);
			put_winner_in_table(&table, &winner);
			print_table(&table);
		}
		i++;
	}
	return (0);
}
