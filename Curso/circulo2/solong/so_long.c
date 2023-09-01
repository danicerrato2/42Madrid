/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:05:27 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/01 16:23:47 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->map = NULL;
	map->height = 0;
	map->widht = 0;
	map->player[0] = -1;
	map->exit[0] = -1;
	map->num_rewards = 0;
}

int	save_map(t_map *map, char *map_path)
{
	int	map_fd;
	int	i;

	map->map = (char **)ft_calloc(map->height, sizeof(char *));
	map_fd = open(map_path, O_RDONLY);
	if (map->map == 0 || map_fd == -1)
		return (0);
	i = -1;
	while (++i < map->height)
		map->map[i] = get_next_line(map_fd);
	if (check_line(map->map[map->height - 1], -1, map) != 0)
		return (0);
	close(map_fd);
	return (1);
}

int	free_all_sl(t_utils *utils)
{
	int	i;

	i = -1;
	if (utils->map.map)
	{
		while (++i < utils->map.height)
			free(utils->map.map[i]);
		free(utils->map.map);
	}
	exit(0);
}

char	**get_map(t_map *map)
{
	int		i[2];
	char	**map2;

	i[0] = -1;
	map2 = (char **)malloc(map->height * sizeof(char *));
	while (++i[0] < map->height)
	{
		i[1] = -1;
		map2[i[0]] = (char *)malloc(map->widht * sizeof(char));
		while (++i[1] < map->widht)
			map2[i[0]][i[1]] = map->map[i[0]][i[1]];
	}
	return (map2);
}
