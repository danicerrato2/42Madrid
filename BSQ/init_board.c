/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:16:58 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/12 20:01:18 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board.h"

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
	line = (char *)malloc(sizeof(char) * nc);
	if (line == NULL)
		return (NULL);
	while (*board != '\n')
		board++;
	board++;
	while (board[c] != '\n')
	{
		line[x] = board[c];
		x++;
		c++;
	}
	line[x] = '\n';
	return (line);
}

char	**init_board(char *board)
{
	int		i;
	int		l;
	int		c;
	int		r;
	char	**bi_board;

	i = 0;
	r = 0;
	l = calculate_lines(board);
	c = calculate_columns(board);
	bi_board = (char **)malloc(sizeof(char **) * l);
	if (bi_board == NULL)
		return (NULL);
	while (i < l)
	{
		bi_board[i] = board_line(board, r, c);
		r += c + 1;
		i++;
	}
	return (bi_board);
}
