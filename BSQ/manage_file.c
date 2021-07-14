/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:10:27 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/14 17:15:22 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	fill_board(int fd, char *board)
{
	int		sz;

	sz = read(fd, board, 1000);
	if (sz == 0)
		return (print_map_error());
	board[sz] = '\0';
	return (sz);
}

int	print_map_error(void)
{
	write(1, "map error\n", 10);
	return (-1);
}

int	open_file(char *file, t_b *table)
{
	int		fd;
	int		sz;
	char	*board;

	board = (char *)malloc(sizeof(char) * 1000);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_map_error());
	sz = fill_board(fd, board);
	table->file_c = board;
	table->board = init_board(board, table);
	if (sz <= 0 || close(fd) < 0)
		return (print_map_error());
	return (0);
}
