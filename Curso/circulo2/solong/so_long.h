/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:05:13 by dcerrato          #+#    #+#             */
/*   Updated: 2023/08/23 12:29:05 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

# include "ft_stack.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "getNextLine/get_next_line.h"

typedef struct s_map
{
	char	**map;
	int		height;
	int		widht;
	int		player[2];
	int		exit[2];
	int		num_rewards;
}	t_map;

void	init_map(t_map *map);
int		save_map(t_map *map, char *map_path);
void	free_all_sl(t_map *map);
char	**prepare_and_free_map2(t_map *map);

int		check_route(t_map *map);
int		check_midline(char *line, t_map *map, int *i);
int		check_line(char *line, int line_num, t_map *map);
int		check_map(t_map *map, char *map_path);

#endif
