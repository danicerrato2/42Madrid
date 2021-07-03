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

	k = 0;
	if (i % 2 == 1)
		k = 3;
	if (i == 0)
	{

	}
	else if (i == 1)
	{

	}
	else if (i == 2)
	{

	}
	else
	{

	}	
}

int	fill_towers(int views[4][4], int matrix[4][4])
{
	int	i;
	int	j;
	
	i = 0;
	while (i < 4)
	{
		j = 0
		while (j < 4)
		{
			if (views[i][j] == 4)
				fill_4(i, j)
			j++;
		}
		i++;
	}

	return (1);
}
