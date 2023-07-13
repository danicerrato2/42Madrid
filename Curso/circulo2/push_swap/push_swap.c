/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:12:02 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/13 19:43:38 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack, char *move)
{
	int	aux;

	if (stack->top >= stack->size - 1)
		return (-1);
	aux = stack->content[stack->top];
	stack->content[stack->top] = stack->content[stack->top + 1];
	stack->content[stack->top + 1] = aux;
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

void	sort_three(t_stack *stack)
{
	while (!is_in_order(stack))
	{
		if (stack->content[stack->top] > stack->content[stack->top + 1])
		{
			if (stack->content[stack->top] > stack->content[stack->size - 1])
				(stack_rotate(stack, 0), ft_putstr_fd("ra\n", 1));
			else
				return (swap(stack, "sa\n"));
		}
		else
			(stack_rotate(stack, 1), ft_putstr_fd("rra\n", 1));
	}
	return (0);
}

void	sort_stacks(t_stack *stacks)
{
	int max_value;
	int min_value;

	max_value = -2147483648;
	min_value = 2147483647;
}

void	to_stackA(t_stack *stacks[])
{
	
}
