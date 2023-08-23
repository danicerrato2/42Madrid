/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:11:57 by dcerrato          #+#    #+#             */
/*   Updated: 2023/08/23 11:45:36 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack	*stack_init(int size)
{
	t_stack	*new_stack;

	if (size <= 0)
		return (NULL);
	new_stack = malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->content = (int **)ft_calloc(size, sizeof(int *));
	while (--size >= 0)
		new_stack->content[size] = (int *)ft_calloc(2, sizeof(int));
	new_stack->top = 0;
	new_stack->size = size;
	return (new_stack);
}

int	stack_push(t_stack *stack, int x, int y)
{
	if (stack == NULL || stack->top == stack->size)
		return (-1);
	stack->content[stack->top][0] = x;
	stack->content[stack->top][1] = y;
	stack->top++;
	return (0);
}

int	stack_pop(t_stack *stack, int *x, int *y)
{
	if (stack == NULL || stack->top == 0)
		return (-1);
	--stack->top;
	*x = stack->content[stack->top][0];
	*y = stack->content[stack->top][1];
	return (0);
}

void	stack_free(t_stack *stack)
{
	if (stack != NULL)
	{
		if (stack->content != NULL)
		{
			while (--stack->size >= 0)
				free(stack->content[stack->size]);
			free(stack->content);
		}
		free(stack);
	}
}
