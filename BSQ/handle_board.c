/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:46:56 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/15 10:16:48 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ignore_first_line(char *board)
{
	while (*board != '\n')
		board++;
	board++;
	return (board);
}

int	check_repeated_chars_and_non_print(char *board, t_b *table)
{
	int		i;
	int		c;
	int		is_rep;

	i = 0;
	c = 0;
	while (board[i] != '\n')
		i++;
	i--;
	while (c++ < 3)
	{
		is_rep = 0;
		if (board[i] < 32 || board[i] == 127)
			return (1);
		if (board[i] == table->empty)
			is_rep++;
		if (board[i] == table->filled)
			is_rep++;
		if (board[i] == table->block)
			is_rep++;
		if (is_rep > 1)
			return (1);
		i--;
	}
	return (0);
}

int	check_lines(char *board)
{
	int		sl;
	int		i;
	int		c;
	int		x;

	sl = 0;
	c = 0;
	i = 0;
	while (board[i] != '\n')
	{
		i++;
		sl++;
	}
	x = i + 1;
	while (board[x] != '\0')
	{
		if (board[x] == '\n' && c != sl)
			return (1);
		c++;
		if (board[x] == '\n')
			c = 0;
		x++;
	}
	return (0);
}

int	check_board_caracters(char *board, t_b *table)
{
	int	i;

	i = 0;
	while (board[i] != '\0')
	{
		if (board[i] != table->block && board[i] != table->empty && \
				board[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	handle_board(t_b *table)
{
	int		i;
	int		error;

	i = 0;
	error = check_repeated_chars_and_non_print(table->file_c, table);
	error = error || check_first_line(table->file_c);
	table->file_c = ignore_first_line(table->file_c);
	error = error || check_lines(table->file_c);
	error = error || check_board_caracters(table->file_c, table);
	if (error == 1)
		return (print_map_error());
	return (0);
}
