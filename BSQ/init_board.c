/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:16:58 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/14 20:48:43 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	calculate_lines(char *board)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (board[i] != '\0')
	{
		if (board[i] == '\n' && board[i + 1] != '\0' && board[i + 1] != '\n')
			l++;
		i++;
	}
	return (l);
}

int	calculate_columns(char *board)
{
	int		c;

	c = 0;
	while (*board != '\n')
		board++;
	board++;
	while (board[c] != '\n')
		c++;
	return (c);
}

char	*board_line(char *board, int c, int nc)
{
	int		x;
	char	*line;

	x = 0;
	line = (char *)malloc(sizeof(char) * (nc + 1));
	if (line == NULL)
		return (NULL);
	while (*board != '\n')
		board++;
	board++;
	while (board[c] != '\n' && board[c] != '\0')
	{
		line[x] = board[c];
		x++;
		c++;
	}
	line[x++] = '\n';
	line[x] = '\0';
	return (line);
}

void	read_first_line(char *board, t_b *table)
{
	int	i;

	i = 0;
	while (board[i] != '\n')
		i++;
	table->filled = board[i - 1];
	table->block = board[i - 2];
	table->empty = board[i - 3];
}

char	**init_board(char *board, t_b *table)
{
	int		i;
	int		r;
	char	**bi_board;

	i = 0;
	r = 0;
	read_first_line(board, table);
	table->rows = calculate_lines(board);
	table->columns = calculate_columns(board);
	bi_board = (char **)malloc(sizeof(char **) * table->rows);
	if (bi_board == NULL)
		return (NULL);
	while (i < table->rows)
	{
		bi_board[i] = board_line(board, r, table->columns);
		r += table->columns + 1;
		i++;
	}
	return (bi_board);
}
