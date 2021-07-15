/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:10:27 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/14 20:52:50 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	concat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
}

char	*fill_board(int fd)
{
	int		sz;
	char	*board;

	board = (char *)malloc(sizeof(char) * 100000000);
	sz = read(fd, board, 100000000);
	if (sz == 0)
	{
		print_map_error();
		return (NULL);
	}
	board[sz] = '\0';
	return (board);
}

int	print_map_error(void)
{
	write(1, "map error\n", 10);
	return (-1);
}

int	open_file(char *file, t_b *table)
{
	int		fd;
	char	*board;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_map_error());
	board = fill_board(fd);
	if (board == NULL)
		return (print_map_error());
	table->file_c = board;
	table->board = init_board(board, table);
	if (close(fd) < 0 || table->board == NULL)
		return (print_map_error());
	return (0);
}
