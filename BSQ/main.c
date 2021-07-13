/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:03:39 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/13 20:01:01 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_table(t_b *table)
{
	printf("Rows = %d, Columns = %d\n", table->rows, table->columns);
	printf("Empty = %c, Block = %c, Filled = %c\n", table->empty, table->block, table->filled);
	for (int i = 0; i < table->rows; i++)
		printf("%s", table->board[i]);
}

int	main(int argc, char **argv)
{
	int	i;
	t_b	table;

	i = 1;
	while (i < argc)
	{
		if (open_file(argv[i], &table) == 0 && handle_board(&table) == 0)
		{
			resolve_table(&table);
			print_table(&table);
		}
		i++;
	}
	return (0);
}
