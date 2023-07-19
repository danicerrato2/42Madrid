/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicerrato2 <danicerrato2@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:12:02 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/18 19:08:18 by danicerrato      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack, char *move)
{
	int	aux;

	if (stack->top <= 1)
		return (-1);
	aux = stack->content[stack->top - 1];
	stack->content[stack->top - 1] = stack->content[stack->top - 2];
	stack->content[stack->top - 2] = aux;
	ft_putstr_fd(move, 1);
	return (0);
}

int	push(t_stack *stack1, t_stack *stack2, char *move)
{
	int	aux;

	if (stack1 == NULL || stack2 == NULL || stack_pop(stack2, &aux) != 0)
		return (-1);
	if (stack_push(stack1, aux) != 0)
	{
		stack_push(stack2, aux);
		return (-1);
	}
	ft_putstr_fd(move, 1);
	return (0);
}

void	rotate_stacks(t_stack *stacks[], int up_or_down)
{
	stack_rotate(stacks[0], up_or_down);
	stack_rotate(stacks[1], up_or_down);
	if (up_or_down == 0)
		ft_putstr_fd("rr\n", 1);
	else
		ft_putstr_fd("rrr\n", 1);
}

int	binary_search(t_stack *stack, int value)
{
	int moves;

	if (!stack || stack->top == 0)
		return (0);
	moves = 0;
	while (1)
	{
		if (stack->content[stack->top - 1 - moves] > value)
			break;
		moves = -moves - 1;
		if (stack->content[-moves - 1] > value)
			break;
		moves = -moves;
	}
	return (moves);
}



#include <stdio.h>

void	do_moves_to_a(t_stack *stacks[], int move_code, int moves, int rras)
{
//printf("Move code = %d, moves = %d\n", move_code, moves);
	if (move_code == 0 && moves <= 0)
		(stack_rotate(stacks[0], 0), ft_putstr_fd("ra\n", 1));
	else if (move_code == 0 && moves-- > 0)
		rotate_stacks(stacks, 0);
	if (move_code == 1 && moves <= 0)
		while (moves < 0 && rras > 0)
		{
			rotate_stacks(stacks, 1);
			moves++;
			rras--;
		}
	while (move_code == 1 && rras-- > 0)
		(stack_rotate(stacks[0], 1), ft_putstr_fd("rra\n", 1));
	while (moves < 0 && moves++ < 0)
		(stack_rotate(stacks[1], 1), ft_putstr_fd("rrb\n", 1));
	while (moves > 0 && moves-- > 0)
		(stack_rotate(stacks[1], 0), ft_putstr_fd("rb\n", 1));
	push(stacks[0], stacks[1], "pa\n");	
}