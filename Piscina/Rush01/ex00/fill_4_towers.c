/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_4_towers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:05:53 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/05 09:14:27 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	fill_sudoku(int matrix[4][4], int number);

void	fill_4_with_4(int i, int j, int matrix[4][4])
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (i == 0)
			matrix[k][j] = k + 1;
		else if (i == 1)
			matrix[k][j] = 4 - k;
		else if (i == 2)
			matrix[j][k] = k + 1;
		else if (i == 3)
			matrix[j][k] = 4 - k;
		k++;
	}
}

void	fill_4_with_1(int i, int j, int matrix[4][4])
{
	if (i == 0)
		matrix[0][j] = 4;
	else if (i == 1)
		matrix[3][j] = 4;
	else if (i == 2)
		matrix[j][0] = 4;
	else
		matrix[j][3] = 4;
}

void	fill_4_with_3(int i, int j, int matrix[4][4])
{
	printf("%d, %d\n", i, j);
	if (i == 0 && matrix[3][j] != 4)
		matrix[2][j] = 4;
	else if (i == 1 && matrix[0][j] != 4)
		matrix[1][j] = 4;
	else if (i == 2 && matrix[j][3] != 4)
		matrix[j][2] = 4;
	else if (i == 3 && matrix[j][0] != 4)
		matrix[j][1] = 4;
}

void	fill_4_towers(int views[4][4], int matrix[4][4])
{
	int	i;
	int	j;
	int	condition;

	condition = 1;
	while (condition < 3)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (condition == 1 && views[i][j] == 4)
					fill_4_with_4(i, j, matrix);
				else if (condition == 2 && views[i][j] == 1)
					fill_4_with_1(i, j, matrix);
				else if (condition == 3 && views[i][j] == 3)
					fill_4_with_3(i, j, matrix);
				j++;
			}
			i++;
		}
		condition++;
	}
}
