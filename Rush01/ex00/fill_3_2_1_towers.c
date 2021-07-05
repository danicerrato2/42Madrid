/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_3_2_1_towers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:05:53 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/05 08:32:52 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	fill_sudoku(int matrix[4][4], int number);
int		find_number_in_row(int matrix[4][4], int row, int number);
int		find_number_in_column(int matrix[4][4], int column, int number);

void	fill_3_with_2(int views[4][4], int matrix[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (views[i][j] == 2)
			{
				if (i == 0 && matrix[3][j] == 4)
					matrix[0][j] = 3;
				else if (i == 1 && matrix[0][j] == 4)
					matrix[3][j] = 3;
				else if (i == 2 && matrix[j][3] == 4)
					matrix[j][0] = 3;
				else if (i == 3 && matrix[j][0] == 4)
					matrix[j][3] = 3;
			}	
			j++;
		}
		i++;
	}
}

void	fill_2_towers(int views[4][4], int matrix[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (views[i][j] == 3)
			{
				if (i == 0 && matrix[3][j] == 4)
					matrix[0][j] = 2;
				else if (i == 1 && matrix[0][j] == 4)
					matrix[3][j] = 2;
				else if (i == 2 && matrix[j][3] == 4)
					matrix[j][0] = 2;
				else if (i == 3 && matrix[j][0] == 4)
					matrix[j][3] = 2;
			}	
			j++;
		}
		i++;
	}
}

void	fill_3_2_1_towers(int views[4][4], int matrix[4][4])
{
	fill_2_towers(views, matrix);
	fill_sudoku(matrix, 2);
	fill_3_with_2(views, matrix);
	fill_sudoku(matrix, 3);
	fill_sudoku(matrix, 1);
	fill_sudoku(matrix, 2);
}
