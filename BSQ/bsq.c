/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:59:16 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/12 19:12:49 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_Board
{
	char	**board;
	int		max_size;
	char	empty;
	char	filled; 
	char	block;
} t_b;

typedef struct s_square
{
	int	row;
	int	col;
	int	size;
} t_sq;

int	main(void)
{
	char	*board[7] = {"..o..o.\n", "...o.o.\n", "..o....\n", "o....o.\n", "....o.o\n", ".......\n", "...o..o\n"}; 

	resolve_board(board);
	for (int i = 0; i < 7; i++)
		printf("%s", board[i]);
}

void	resolve_board(char **board)
{
	t_sq	*sol;

	sol = (t_sq *)malloc(sizeof(t_sq));
}
