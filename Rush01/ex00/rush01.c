/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:18:10 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/03 13:08:05 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	fill_4_towers(int views[4][4], int matrix[4][4]);

void	split_str(int views[4][4], char *str, int count)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			views[j][k] = str[i] - '0';
			k++;
			if (k >= count / 4)
			{
				k = 0;
				j++;
			}
		}
		i++;
	}
}

int	split(char *str, int views[4][4])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			if (i == 0 || str[i - 1] == ' ')
				count++;
			else
				return (0);
		}
		else if (str[i] != ' ')
			return (-1);
		i++;
	}
	if (count % 4 != 0 || count != 16)
		return (-2);
	split_str(views, str, count);
	return (1);
}

int	main(int argc, char *args[])
{
	int	matrix[4][4];
	int	views[4][4];

	if (argc != 2)
	{
		write (1, "Error\n", 6);
		return (-1);
	}
	if (split(args[1], views) <= 0 || fill_4_towers(views, matrix) <= 0)
	{
		write (1, "Error\n", 6);
		return (-1);
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (matrix[i][j] >= 1 && matrix[i][j] <= 4)
				printf("%d ", matrix[i][j]);
			else printf("0 ");
		}
		printf("\n");
	}
}
