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
	aux = stack->content[stack->top];
	stack->content[stack->top] = stack->content[stack->top - 1];
	stack->content[stack->top - 1] = aux;
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

/*
void	change_stack(t_stack *stack_from, t_stack *stack_to)
{
	int	maxB;
	int	minB;

	maxB = -2147483648;
	minB = 2147483647;
	while (from->top < from->size - 3)
	{
		if (stacks[1]->top > stacks[1]-> size - 2)
		{
			if (stacks[0]->content[stacks[0]->top] < minB)
				minB = stacks[0]->content[stacks[0]->top];
			if (stacks[0]->content[stacks[0]->top] > maxB)
				maxB = stacks[0]->content[stacks[0]->top];
			push(stacks[1], stacks[0], "pb\n");
		}
		else if (stacks[0]->top > maxB)
		{
			get_value_in_top(stack_to, maxB);
			//while (stacks[1]->content[stacks[1]->top] != maxB)
		}
		else if (stacks[0]->top < minB)

		else
	}
}
*/
void	sort_three(t_stack *stack)
{
	while (!is_in_order(stack))
	{
		if (stack->content[stack->top] > stack->content[stack->top - 1])
		{
			if (stack->content[stack->top] > stack->content[0])
				(stack_rotate(stack, 0), ft_putstr_fd("ra\n", 1));
			else
				return (void)(swap(stack, "sa\n"));
		}
		else
			(stack_rotate(stack, 1), ft_putstr_fd("rra\n", 1));
	}
}

/*
void	prepare_stacks(t_stack *stack_to, t_stack *stack_from, int *min_val, int *max_val)
{
	int	aux;
	int moves;

	aux = stack_from->content[stack_from->top];
	moves = 0;
	if (aux < min_val || aux > max_val)
		while (stack_to->content[moves] != max_val)
			moves++;
	else
		while (moves < stack_to->top && stack_to->content[moves] < )
			moves++;
}
*/

void	move_to_b(t_stack *stacks[], float chunks[])
{
	int	i;

	i = -1;
	while (++i < chunks[2] && stacks[0]->top > 3)
	{
		if (stacks[0]->content[stacks[0]->top] < chunks[1])
		{
			push(stacks[1], stacks[0], "pb\n");
			if (stacks[1]->content[stacks[1]->top] < chunks[0] && \
				stacks[0]->content[stacks[0]->top] >= chunks[1])
			{
				(stack_rotate(stacks[0], 0), stack_rotate(stacks[1], 0));
				ft_putstr_fd("rr\n", 1);
				i++;
			}
			else if (stacks[1]->content[stacks[1]->top] < chunks[0])
				(stack_rotate(stacks[1], 0), ft_putstr_fd("rb\n", 1));
		}
		else
			(stack_rotate(stacks[0], 0), ft_putstr_fd("ra\n", 1));
	}
}