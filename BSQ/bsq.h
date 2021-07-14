/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:21:55 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/13 20:40:42 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_board
{
	char	**board;
	char	*file_c;
	int		rows;
	int		columns;
	char	empty;
	char	filled;
	char	block;
}	t_b;

typedef struct s_square
{
	int	row;
	int	col;
	int	size;
}	t_s;

int		open_file(char *file, t_b *table);
int		handle_first_line_board(char *board);
int		print_map_error(void);
char	**init_board(char *board, t_b *table);
void	resolve_table(t_b *table, t_s *winner);
int		handle_board(t_b *table);
void	put_winner_in_table(t_b *table, t_s *winner);

#endif