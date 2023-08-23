/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:05:08 by dcerrato          #+#    #+#             */
/*   Updated: 2023/08/23 12:45:31 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_paths(t_map *map, char **map2)
{
	t_stack	*stack;
	int		actual[2];

	stack = stack_init(map->height * map->widht);
	stack_push(stack, map->player[0], map->player[1]);
	while (stack->top != 0)
	{
		stack_pop(stack, &actual[0], &actual[1]);
		map2[actual[0]][actual[1]] = 'X';
		if (map2[actual[0] - 1][actual[1]] != '1' && \
			map2[actual[0] - 1][actual[1]] != 'X')
			stack_push(stack, actual[0] - 1, actual[1]);
		if (map2[actual[0]][actual[1] - 1] != '1' && \
			map2[actual[0]][actual[1] - 1] != 'X')
			stack_push(stack, actual[0], actual[1] - 1);
		if (map2[actual[0] + 1][actual[1]] != '1' && \
			map2[actual[0] + 1][actual[1]] != 'X')
			stack_push(stack, actual[0] + 1, actual[1]);
		if (map2[actual[0]][actual[1] + 1] != '1' && \
			map2[actual[0]][actual[1] + 1] != 'X')
			stack_push(stack, actual[0], actual[1] + 1);
	}
	stack_free(stack);
}

int	check_route(t_map *map)
{
	char	**map2;
	int		i[2];
	int		error_flag;

	map2 = prepare_and_free_map2(map);
	fill_paths(map, map2);
	i[0] = 0;
	error_flag = 0;
	while (error_flag == 0 && ++i[0] < map->height - 1)
	{
		i[1] = 0;
		while (error_flag == 0 && ++i[1] < map->widht - 1)
		{
			if ((map->map[i[0]][i[1]] == 'C' || map->map[i[0]][i[1]] == 'E') \
				&& map2[i[0]][i[1]] != 'X')
				error_flag = 1;
		}
	}
	i[0] = -1;
	while (++i[0] < map->height)
		free(map2[i[0]]);
	free(map2);
	return (error_flag);
}

int	check_midline(char *line, t_map *map, int *i)
{
	while (line[*i] != '\n')
	{
		if (line[*i] == 'C')
			map->num_rewards++;
		else if (line[*i] == 'E' && map->exit[0] == -1)
		{
			map->exit[0] = map->height;
			map->exit[1] = *i;
		}
		else if (line[*i] == 'P' && map->player[0] == -1)
		{
			map->player[0] = map->height;
			map->player[1] = *i;
		}
		else if (line[*i] != '0' && line[*i] != '1')
			return (-1);
		(*i)++;
	}
	return (0);
}

int	check_line(char *line, int line_num, t_map *map)
{
	int	i;

	if (line == NULL || line[0] != '1')
		return (-1);
	i = 1;
	if (line_num == 1 || line_num == -1)
	{
		while (line[i] != '\n' && line[i] == '1')
			i++;
		if (line_num == 1)
			map->widht = i;
	}
	else if (check_midline(line, map, &i) != 0)
		return (-1);
	if (line[i] != '\n' || i != map->widht || line[i - 1] != '1')
		return (-1);
	if (line_num != -1)
		map->height = line_num;
	return (0);
}

int	check_map(t_map *map, char *map_path)
{
	int		map_fd;
	char	*line;
	int		line_num;
	int		path_len;

	path_len = ft_strlen(map_path);
	if (path_len < 5 || ft_strncmp(map_path + (path_len - 4), ".ber", 4) != 0)
		return (-1);
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (-1);
	init_map(map);
	line_num = 0;
	line = get_next_line(map_fd);
	while (line && check_line(line, ++line_num, map) == 0)
		line = get_next_line(map_fd);
	if (line != NULL || line_num < 3 || map->player[0] == -1 || \
		map->exit[0] == -1 || map->num_rewards == 0)
		return (-1);
	close(map_fd);
	return (0);
}
