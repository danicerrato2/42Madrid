/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:44:46 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/01 20:48:56 by dcerrato         ###   ########.fr       */
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

/*
void    free_player(t_player *player)
{

}

void    free_vars(t_vars *vars)
{

}
*/

int	free_all_sl(t_utils *utils)
{
	free_map(utils->map);
	if (utils->player){
        mlx_destroy_image(utils->vars->mlx, utils->player->img[0]);
        mlx_destroy_image(utils->vars->mlx, utils->player->img[1]);
        mlx_destroy_image(utils->vars->mlx, utils->player->img[2]);
        mlx_destroy_image(utils->vars->mlx, utils->player->img[3]);
        free(utils->player);
    }
	if (utils->vars)
    {
        mlx_destroy_image(utils->vars->mlx, utils->vars->exit);
        mlx_destroy_image(utils->vars->mlx, utils->vars->floor);
        mlx_destroy_image(utils->vars->mlx, utils->vars->reward);
        mlx_destroy_image(utils->vars->mlx, utils->vars->wall);
        mlx_destroy_window(utils->vars->mlx, utils->vars->window);
        free(utils->vars);
    }
	exit(0);
}