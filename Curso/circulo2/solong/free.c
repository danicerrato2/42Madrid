/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:44:46 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/06 22:02:38 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	if (map)
	{
		if (map->map)
		{
			while (++i < map->height)
				free(map->map[i]);
			free(map->map);
		}
		free(map);
	}
}

void	free_mlx(t_utils *utils)
{
	if (utils->player->img[0])
	{
		ft_printf("Hola1\n");
		mlx_destroy_image(utils->vars->mlx, utils->player->img[0]);
		mlx_destroy_image(utils->vars->mlx, utils->player->img[1]);
		mlx_destroy_image(utils->vars->mlx, utils->player->img[2]);
		mlx_destroy_image(utils->vars->mlx, utils->player->img[3]);
	}
	if (utils->vars->exit)
	{
		ft_printf("Hola2\n");
		mlx_destroy_image(utils->vars->mlx, utils->vars->exit);
		mlx_destroy_image(utils->vars->mlx, utils->vars->stairs);
		mlx_destroy_image(utils->vars->mlx, utils->vars->floor);
		mlx_destroy_image(utils->vars->mlx, utils->vars->reward);
		mlx_destroy_image(utils->vars->mlx, utils->vars->wall);
	}
	if (utils->vars->window)
	{
		ft_printf("Hola3\n");
		mlx_clear_window(utils->vars->mlx, utils->vars->window);
		mlx_destroy_window(utils->vars->mlx, utils->vars->window);
	}
	// mlx_destroy_display(utils->vars->mlx);
	free(utils->vars->mlx);
}

int	free_all_sl(t_utils *utils)
{
	free_map(utils->map);
	if (utils->vars)
	{
		if (utils->player)
		{
			if (utils->vars->mlx)
				free_mlx(utils);
			free(utils->player);
		}
		free(utils->vars);
	}
	exit(0);
}
