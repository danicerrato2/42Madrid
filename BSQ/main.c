/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:03:39 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/12 20:23:57 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board.h"

int	main(int argc, char **argv)
{
	int	i;
	t_b	*table;

	i = 1;
	while (i < argc)
	{
		table = (t_b *)malloc(sizeof(t_b));
		if (table == NULL)
			return (print_map_error());
		open_file(argv[i], table);
		for(int j = 0; j < 10; j++)
			printf("%s", table->board[j]);
		/*handle_first_line_board(board);
		printf("BOARD: %s\n", board);*/
		i++;
	}
	return (0);
}
