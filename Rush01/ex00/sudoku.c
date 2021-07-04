/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:05:53 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/03 13:21:42 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_number_in_row(int matrix[4][4], int row, int number)
{
	int	j;
	
	j = 0;
	while (j < 4)
	{
		if (matrix[row][j] == number)
			return (j);
		j++;
	}
	return (-1);
}

int	find_number_in_column(int matrix[4][4], int column, int number)
{
	int	i;
	
	i = 0;
	while (i < 4)
	{
		if (matrix[i][column] == number)
			return (i);
		i++;
	}
	return (-1);
}

void	fill_sudoku(int matrix[4][4], int number)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < 4)
	{
		if (find_number_in_row(matrix, i, number) == -1)
		{
			j = 0;
			while (j < 4)
			{
				if (find_number_in_column(matrix, j, number) == -1)
					if (matrix[i][j] < 1 || matrix[i][j] > 4)
						matrix[i][j] = number;
				j++;
			}
		}
		i++;
	}
}
