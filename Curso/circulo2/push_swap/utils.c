/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:12:00 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/13 17:12:00 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	check_int(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	if (len != 0 && str[0] == '-')
	{
		if (ft_strncmp("-2147483648", str, len) == 0)
			return (0);
		str++;
		len--;
	}
	if (len == 0 || len > 10)
		return (-1);
	i = -1;
	while (++i < len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if (len == 10 && str[i] < "2147483647"[i])
			return (0);
	}
	return (i == 10 && str[9] > '7');
}

int	is_in_stack(int num, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (num == stack->content[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_in_order(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (--i > 0)
	{
		if (stack->content[i] > stack->content[i - 1])
			return (0);
	}
	return (1);
}

void	convert_numbers(t_stack *stacks[])
{
	long long	min_value;
	int			min_pos;
	int			i;
	int			j;

	j = -1;
	while (++j < stacks[0]->top)
	{
		min_value = 2147483648;
		min_pos = 0;
		i = -1;
		while (++i < stacks[0]->top)
			if (stacks[2]->content[i] == 0 && stacks[0]->content[i] < min_value)
			{
					min_value = stacks[0]->content[i];
					min_pos = i;
			}
		stacks[0]->content[min_pos] = j + 1;
		stacks[2]->content[min_pos] = 1;
	}
}

int	free_all(t_stack *stacks[], int errorValue)
{
	stack_free(stacks[0]);
	stack_free(stacks[1]);
	if (errorValue != 0)
		ft_putstr_fd("Error\n", 1);
	return (0);
}
