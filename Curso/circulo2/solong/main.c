/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:05:16 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/01 20:43:57 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_leaks()
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	t_utils utils;

	atexit(ft_leaks);
	utils.map = malloc(sizeof(t_map));
	if (argc != 2 || check_map(utils.map, argv[1]) != 0 || \
		! save_map(utils.map, argv[1]) || check_route(utils.map) != 0)
	{
		free_all_sl(&utils);
		return (0);
	}
	utils.player = malloc(sizeof(t_player));
	utils.vars = malloc(sizeof(t_vars));
	(init_utils(&utils, SIZE));//, print_map(&utils));
	//mlx_loop(utils.vars.mlx);
	free_all_sl(&utils);
	return (0);
}
