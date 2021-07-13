/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:46:56 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/13 19:41:40 by dcerrato         ###   ########.fr       */
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

	sl = 0;
	c = 0;
	i = 0;
	while (*board != '\n')
	{
		board++;
		sl++;
	}
	sl++;
	board++;
	while (*board != '\0')
	{
		if (*board == '\n')
			if (c + 1 != sl)
				return (1);
		c++;
		if (*board == '\n')
			c = 0;
		board++;
	}
	return (0);
}

/*int	are_correct_chars(char *board, t_b *table)
{
	int		i;
	int		one_empty;
	int		are_ok;

	i = 0;
	one_empty = 1;
	are_ok = 1;
	while (board[i] != '\0' && are_ok == 1)
	{
		if (board[i] != table->empty || board[i] != '\n')
		i++;
	}
	return (1);
}*/

int	handle_board(t_b *table)
{
	int		i;
	int		error;

	i = 0;
	error = check_repeated_chars_and_non_print(table->file_c, table);
	//printf("ERR1: %d\n", error);
	table->file_c = ignore_first_line(table->file_c);
	error = error || check_lines(table->file_c);
	//printf("ERR2: %d\n", error);
	/*printf("CHECK: %d\n", error);*/
	//error = error || are_correct_chars(board, table);
	//printf("ERROR: %d\n", error);
	//printf("%s", board);
	return (error);
}
