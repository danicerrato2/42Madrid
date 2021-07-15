/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:03:39 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/14 20:52:17 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_memory(t_b *table)
{
	int	i;

	i = 0;
	while (i < table->rows)
	{
		free(table->board[i]);
		i++;
	}
	free(table->board);
}

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

void	run_bsq(t_b *table)
{
	t_s	winner;

	winner.size = 0;
	winner.col = 1000000000;
	winner.row = 1000000000;
	resolve_table(table, &winner);
	put_winner_in_table(table, &winner);
	print_table(table);
}

void	no_arguments(t_b *table)
{
	char	buffer[1000];
	char	board[1000];

	while (read(0, buffer, 1000))
		concat(board, buffer);
	if (board[0] == '\0')
	{
		print_map_error();
		return ;
	}
	table->file_c = board;
	table->board = init_board(board, table);
	if (table->board == NULL)
	{
		print_map_error();
		return ;
	}
	if (handle_board(table) == 0)
		run_bsq(table);
	free_memory(table);
}

int	main(int argc, char **argv)
{
	int		i;
	t_b		table;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (open_file(argv[i], &table) == 0 && handle_board(&table) == 0)
				run_bsq(&table);
			free_memory(&table);
			i++;
		}
	}
	else
		no_arguments(&table);
	return (0);
}
