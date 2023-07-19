/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicerrato2 <danicerrato2@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:19:18 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/18 19:14:24 by danicerrato      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	move_to_a(t_stack *stacks[], int move_code)
{
	int moves;
	int	value;
	int	rras;

	rras = move_code;
	if (move_code == 1)
	{
		while (stacks[0]->content[rras] == stacks[0]->content[rras - 1] - 1)
			rras++;
		if (stacks[0]->content[rras] == stacks[0]->size)
			value = stacks[0]->content[rras - 1] - 2;
		else
			value = stacks[0]->content[rras];
	}
	else if (move_code == 0)
		value = stacks[0]->content[stacks[0]->top];
	else if (move_code == -1)
		value = stacks[0]->content[0];
	moves = binary_search(stacks[1], value);
	if (move_code == 0 && moves < 0)
		(stack_rotate(stacks[0], 0), ft_putstr_fd("ra\n", 1));
	else if (move_code == 0 && moves > 0)
		rotate_stacks(stacks, 0);
	else if (move_code == 1 && moves < 0)
	{
		while (moves++ < 0 && rras-- > 0)
			rotate_stacks(stacks, 1);
		while (rras-- > 0)
			(stack_rotate(stacks[0], 1), ft_putstr_fd("rra\n", 1));
	}
	while (moves != 0 && moves++ < 0)
		(stack_rotate(stacks[1], 1), ft_putstr_fd("rrb\n", 1));
	while (moves != 0 && moves-- > 0)
		(stack_rotate(stacks[1], 1), ft_putstr_fd("rb\n", 1));
	push(stacks[0], stacks[1], "pa\n");	
}


push(stacks[0], stacks[1], "pa\n");
(stack_rotate(stacks[0], 0), ft_putstr_fd("ra\n", 1));

void	sort_three(t_stack *stack)
{
	while (!is_in_order(stack))
	{
		if (stack->content[stack->top - 1] > stack->content[stack->top - 2])
		{
			if (stack->content[stack->top - 1] > stack->content[0])
				(stack_rotate(stack, 0), ft_putstr_fd("ra\n", 1));
			else
				return (void)(swap(stack, "sa\n"));
		}
		else
			(stack_rotate(stack, 1), ft_putstr_fd("rra\n", 1));
	}
}

void	move_to_b(t_stack *stacks[], float chunks[])
{
	int	i;

	i = stacks[0]->top;
	while (i-- > 0 && stacks[0]->top > 3)
	{
		if (stacks[0]->content[stacks[0]->top - 1] < chunks[1])
		{
			push(stacks[1], stacks[0], "pb\n");
			if (stacks[1]->content[stacks[1]->top - 1] <= chunks[0] && \
				stacks[0]->content[stacks[0]->top - 1] > chunks[1])
			{
				(stack_rotate(stacks[0], 0), stack_rotate(stacks[1], 0));
				ft_putstr_fd("rr\n", 1);
				i--;
			}
			else if (stacks[1]->content[stacks[1]->top - 1] <= chunks[0])
				(stack_rotate(stacks[1], 0), ft_putstr_fd("rb\n", 1));
		}
		else
			(stack_rotate(stacks[0], 0), ft_putstr_fd("ra\n", 1));
	}
}



#include <stdio.h>


void	sort_stacks(t_stack *stacks[])
{
	float	chunks[2];
	int		move_code;
	int		top_A;

	chunks[0] = stacks[0]->size / 3.0;
	chunks[1] = stacks[0]->size * 2.0 / 3.0;
	while (stacks[0]->top > 3)
	{
		move_to_b(stacks, chunks);
		chunks[0] = (stacks[0]->size + 2.0 * (int)chunks[1]) / 3.0;
		chunks[1] = (2.0 * stacks[0]->size + (int)chunks[1]) / 3.0;
	}
	sort_three(stacks[0]);
	while (stacks[1]->top > 0)
	{
		top_A = stacks[0]->top;
		move_code = -2;	// PA directamente
		if (stacks[0]->content[top_A - 1] != stacks[0]->content[top_A - 2] - 1)
			move_code = 0;	// RA
		else if (stacks[0]->content[0] == stacks[0]->content[top_A - 1] - 1)
			move_code = 1;	// RRA
		else if (stacks[0]->content[0] != stacks[0]->size)
			move_code = -1;	// PA siguiente mayor
		move_to_a(stacks, move_code);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stacks[3];
	int		i;
	int		num;

	if (argc < 3)
		return (0);
	stacks[0] = stack_init(argc - 1);
	stacks[1] = stack_init(argc - 1);
	stacks[2] = stack_init(argc - 1);
	i = argc;
	while (--i > 0 && check_int(argv[i]) == 0)
	{
		num = ft_atoi(argv[i]);
		if (is_in_stack(num, stacks[0]) == 1)
			return (free_all(stacks, 1));
		stack_push(stacks[0], num);
	}
	if (stacks[0]->top != argc - 1)
		return (free_all(stacks, 1));
	if (!is_in_order(stacks[0]))
		(convert_numbers(stacks), sort_stacks(stacks));
	return (free_all(stacks, 0));
}
