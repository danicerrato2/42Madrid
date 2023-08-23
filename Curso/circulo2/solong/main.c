/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:05:16 by dcerrato          #+#    #+#             */
/*   Updated: 2023/08/23 12:27:49 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2 || check_map(&map, argv[1]) != 0 || \
		!save_map(&map, argv[1]) || check_route(&map) != 0)
		return (ft_printf("Error\n"));
	free_all_sl(&map);
	return (0);
}
