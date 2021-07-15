/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:21:55 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/14 20:51:04 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

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
void	print_table(t_b *table);
int		check_size(int row, int size, t_b *table);
void	check_distance(int row, int col, int size, t_s *winner);
int		check_position(int row, int col, int col_ini, t_b *table);
void	concat(char *dest, char *src);
int		check_first_line(char *board);

#endif
