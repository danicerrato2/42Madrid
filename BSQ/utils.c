/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:44:36 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/15 10:17:20 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_space(char c)
{
	int		is_space;

	is_space = 0;
	if (c == '\n' || c == '\t' || c == '\r' \
			|| c == ' ' || c == '\v')
		is_space = 1;
	return (is_space);
}

int	ft_atoi(char *str)
{
	int		neg;
	int		res;

	res = 0;
	neg = 0;
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			break ;
		res = 10 * res + *str - '0';
		str++;
	}
	if (neg % 2 == 1)
		res = -res;
	return (res);
}

int	check_lines_with_board(char *board, int nl)
{
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (board[i] != '\0')
	{
		if (board[i] == '\n')
			l++;
		i++;
	}
	if (l - 1 != nl)
		return (1);
	return (0);
}

int	check_first_line(char *board)
{
	int		l;
	int		i;
	int		nlines;
	char	*nums;

	l = 0;
	i = 0;
	while (board[l] != '\n')
		l++;
	l -= 3;
	nums = (char *)malloc((l - i) * sizeof(char));
	while (i < l)
	{
		nums[i] = board[i];
		i++;
	}
	l += 4;
	nlines = ft_atoi(nums);
	if (nlines == 0)
		return (1);
	if (check_lines_with_board(board, nlines) == 1)
		return (1);
	return (0);
}
