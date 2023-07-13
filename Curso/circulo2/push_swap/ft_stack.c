/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:11:57 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/13 17:31:24 by dcerrato         ###   ########.fr       */
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
	new_stack->content = malloc(size * sizeof(int));
	new_stack->top = size;
	new_stack->size = size;
	return (new_stack);
}

int	stack_push(t_stack *stack, int num)
{
	if (stack == NULL || stack->top == 0)
		return (-1);
	stack->content[--(stack->top)] = num;
	return (0);
}

int	stack_pop(t_stack *stack, int *num)
{
	if (stack == NULL || stack->top == stack->size)
		return (-1);
	*num = stack->content[stack->top++];
	return (0);
}

int	stack_rotate(t_stack *stack, int upOrDown)
{
	int	i;
	int	aux;

	if (stack == NULL || stack->top >= stack->size - 1)
		return (-1);
	if (upOrDown == 0)
	{
		i = stack->top;
		aux = stack->content[i];
		while (i++ < stack->size - 1)
			stack->content[i - 1] = stack->content[i];
		stack->content[i - 1] = aux;
	}
	else
	{
		i = stack->size - 1;
		aux = stack->content[i];
		while (i-- > stack->top)
			stack->content[i + 1] = stack->content[i];
		stack->content[i + 1] = aux;
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
