
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_towers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:05:53 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/03 13:21:42 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	fill_4(int i, int j, int matrix[4][4])
{
	int	k;
	
	if (i % 2 == 0)
	{
		k = 0;
		while (k < 4)
		{
			if (i == 0)
				matrix[k][j] = k + 1;
			else
				matrix[j][k] = k + 1;
			k++;
		}
	}
	else
	{
		k = 3;
		while (k >= 0)
		{
			if (i == 1)
				matrix[k][j] = 4 - k;
			else
				matrix[j][k] = 4 - k;
			k--;
		}
	}
}

void	fill_1(int i, int j, int matrix[4][4])
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

void	fill_3(int i, int j, int matrix[4][4])
{
	if (i == 0)
			
	else if (i == 1)

	else if (i == 2)

	else
}

int	fill_4_towers(int views[4][4], int matrix[4][4])
{
	int	i;
	int	j;
	
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (views[i][j] == 4)
				fill_4(i, j, matrix);
			else if (views[i][j] == 1)
				fill_1(i, j, matrix);
			else if (views[i][j] == 3)
				fill_3(i, j, matrix);
			j++;
		}
		i++;
	}

	return (1);
}
