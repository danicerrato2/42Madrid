/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:05:13 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/01 17:18:25 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"

# include "ft_stack.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "getNextLine/get_next_line.h"

# define SIZE 46

typedef struct s_map
{
	char	**map;
	int		height;
	int		widht;
	int		player[2];
	int		exit[2];
	int		num_rewards;
}	t_map;

typedef struct s_player
{
	void	*img[4];	// *player[4][2];
	int		moves;
	// int		timer;	// Probar distintos tiempos; Usar modulo y cambio de imagen
}	t_player;

typedef struct s_vars
{
	void	*mlx;
	void	*window;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*reward;
}	t_vars;

typedef struct s_utils
{
	t_map		*map;
	t_vars		*vars;
	t_player	*player;
}	t_utils;

void	init_map(t_map *map);
int		save_map(t_map *map, char *map_path);
int		free_all_sl(t_utils *utils);
char	**get_map(t_map *map);

int		check_route(t_map *map);
int		check_midline(char *line, t_map *map, int *i);
int		check_line(char *line, int line_num, t_map *map);
int		check_map(t_map *map, char *map_path);

void	init_utils(t_utils *utils, int size);
void	print_map(t_utils *utils);

#endif
