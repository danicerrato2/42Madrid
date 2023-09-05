/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   window.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: dcerrato <dcerrato@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/09/01 14:31:38 by dcerrato		  #+#	#+#			 */
/*   Updated: 2023/09/05 11:20:54 by dcerrato		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_utils *utils)
{
	int	pos[2];

	pos[0] = -1;
	while (++pos[0] < utils->map->height)
	{
		pos[1] = -1;
		while (++pos[1] < utils->map->widht)
		{
			if (utils->map->map[pos[0]][pos[1]] == '1')
				mlx_put_image_to_window(utils->vars->mlx, utils->vars->window, \
					utils->vars->wall, pos[1] * SIZE, pos[0] * SIZE);
			else if (utils->map->map[pos[0]][pos[1]] == '0')
				mlx_put_image_to_window(utils->vars->mlx, utils->vars->window, \
					utils->vars->floor, pos[1] * SIZE, pos[0] * SIZE);
			else if (utils->map->map[pos[0]][pos[1]] == 'C')
				mlx_put_image_to_window(utils->vars->mlx, utils->vars->window, \
					utils->vars->reward, pos[1] * SIZE, pos[0] * SIZE);
			else if (utils->map->map[pos[0]][pos[1]] == 'E')
				mlx_put_image_to_window(utils->vars->mlx, utils->vars->window, \
					utils->vars->stairs, pos[1] * SIZE, pos[0] * SIZE);
			else if (utils->map->map[pos[0]][pos[1]] == 'P')
				mlx_put_image_to_window(utils->vars->mlx, utils->vars->window, \
					utils->player->img[0], pos[1] * SIZE, pos[0] * SIZE);
		}
	}
}

int	move(t_utils *utils, int x, int y, void *img)
{
	int	*pos;

	if (utils->map->map[x][y] == '1')
		return (0);
	if (utils->map->map[x][y] == 'C')
	{
		utils->map->map[x][y] = '0';
		utils->map->num_rewards--;
	}
	pos = utils->map->player;
	if (utils->map->map[pos[0]][pos[1]] == 'E')
		mlx_put_image_to_window(utils->vars->mlx, utils->vars->window, \
			utils->vars->stairs, pos[1] * SIZE, pos[0] * SIZE);
	else
		mlx_put_image_to_window(utils->vars->mlx, utils->vars->window, \
			utils->vars->floor, pos[1] * SIZE, pos[0] * SIZE);
	utils->map->player[0] = x;
	utils->map->player[1] = y;
	if (utils->map->map[x][y] == 'E')
		return (2);
	mlx_put_image_to_window(utils->vars->mlx, utils->vars->window, \
		img, y * SIZE, x * SIZE);
	return (1);
}

int	check_key(int key_code, t_utils *utils)
{
	int	status;
	int	*pos;

	pos = utils->map->player;
	status = 0;
	if (key_code == 53)
		free_all_sl(utils);
	else if (key_code == 0)
		status = move(utils, pos[0], pos[1] - 1, utils->player->img[3]);
	else if (key_code == 1)
		status = move(utils, pos[0] + 1, pos[1], utils->player->img[2]);
	else if (key_code == 2)
		status = move(utils, pos[0], pos[1] + 1, utils->player->img[1]);
	else if (key_code == 13)
		status = move(utils, pos[0] - 1, pos[1], utils->player->img[0]);
	if (status != 0)
		ft_printf("Moves = %d\n", ++utils->player->moves);
	if (status != 2)
		return (0);
	if (utils->map->num_rewards == 0)
		(ft_printf("CONGRATS! You win\n"), free_all_sl(utils));
	ft_printf("Collect all the rewards before exit\n");
	mlx_put_image_to_window(utils->vars->mlx, utils->vars->window, \
		utils->vars->exit, pos[1] * SIZE, pos[0] * SIZE);
	return (0);
}

void	set_player(t_utils *utils, int size)
{
	utils->player->img[0] = mlx_xpm_file_to_image(utils->vars->mlx, \
		"textures/MudkipNorth1.xpm", &size, &size);
	utils->player->img[1] = mlx_xpm_file_to_image(utils->vars->mlx, \
		"textures/MudkipEast1.xpm", &size, &size);
	utils->player->img[2] = mlx_xpm_file_to_image(utils->vars->mlx, \
		"textures/MudkipSouth1.xpm", &size, &size);
	utils->player->img[3] = mlx_xpm_file_to_image(utils->vars->mlx, \
		"textures/MudkipWest1.xpm", &size, &size);
	utils->player->moves = 0;
}

void	set_utils(t_utils *utils, int size)
{
	if (size && utils)
		utils->vars->mlx = mlx_init();
	utils->vars->window = mlx_new_window(utils->vars->mlx, \
		SIZE * utils->map->widht, SIZE * utils->map->height, "so_long");
	utils->vars->floor = mlx_xpm_file_to_image(utils->vars->mlx, \
		"textures/Floor.xpm", &size, &size);
	utils->vars->reward = mlx_xpm_file_to_image(utils->vars->mlx, \
		"textures/Reward.xpm", &size, &size);
	utils->vars->stairs = mlx_xpm_file_to_image(utils->vars->mlx, \
		"textures/Stairs.xpm", &size, &size);
	utils->vars->exit = mlx_xpm_file_to_image(utils->vars->mlx, \
		"textures/Exit.xpm", &size, &size);
	utils->vars->wall = mlx_xpm_file_to_image(utils->vars->mlx, \
		"textures/Wall.xpm", &size, &size);
	set_player(utils, size);
	mlx_key_hook(utils->vars->window, check_key, utils);
	mlx_hook(utils->vars->window, 17, 0, free_all_sl, utils);
}
