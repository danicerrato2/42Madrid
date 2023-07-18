/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicerrato2 <danicerrato2@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:11:57 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/15 18:16:32 by danicerrato      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "ft_stack.h"

t_stack	*stack_init(int size)
{
	t_stack	*new_stack;

	if (size <= 0)
		return (NULL);
	new_stack = malloc(sizeof(t_stack));
	if (new_stack == NULL)
		return (NULL);
	new_stack->content = (int *)ft_calloc(size, sizeof(int));
	new_stack->top = 0;
	new_stack->size = size;
	return (new_stack);
}

int	stack_push(t_stack *stack, int num)
{
	if (stack == NULL || stack->top == stack->size)
		return (-1);
	stack->content[(stack->top)++] = num;
	return (0);
}

int	stack_pop(t_stack *stack, int *num)
{
	if (stack == NULL || stack->top == 0)
		return (-1);
	*num = stack->content[--stack->top];
	return (0);
}

// upOrDown = 0 => RA; = 1 => RRA
int	stack_rotate(t_stack *stack, int upOrDown)
{
	int	i;
	int	aux;

	if (stack == NULL || stack->top <= 1)
		return (-1);
	if (upOrDown == 0)
	{
		i = stack->top - 1;
		aux = stack->content[i];
		while (--i >= 0)
			stack->content[i + 1] = stack->content[i];
		stack->content[i + 1] = aux;
	}
	else
	{
		i = 0;
		aux = stack->content[i];
		while (++i < stack->top)
			stack->content[i - 1] = stack->content[i];
		stack->content[i - 1] = aux;
	}
	return (0);
}

void	stack_free(t_stack *stack)
{
	if (stack != NULL)
	{
		if (stack->content != NULL)
			free(stack->content);
		free(stack);
	}
}
