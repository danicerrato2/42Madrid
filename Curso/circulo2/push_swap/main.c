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



#include <stdio.h>




void print_stack(t_stack *stack, char *name)
{
	printf("\nStack %s: ", name);
	for (int i = stack->top - 1; i >= 0; i--)
		printf("%d ", stack->content[i]);
	printf("\n");
}









void	move_to_a(t_stack *stacks[], int move_code)
{
	int	value;
	int	rras;

	value = 0;
	rras = 0;
	if (move_code == 1)
	{
		rras = 1;
		while (stacks[0]->content[rras] == stacks[0]->content[rras - 1] - 1)
			rras++;
		if (stacks[0]->content[rras] == stacks[0]->size)
			value = stacks[0]->content[rras - 1] - 2;
		else
			value = stacks[0]->content[rras];
	}
	else if (move_code == 0)
		value = stacks[0]->content[stacks[0]->top - 1];
	else if (move_code == -1)
		value = stacks[0]->content[0];
//printf("Move code = %d, value = %d\n", move_code, value);
	do_moves_to_a(stacks, move_code, binary_search(stacks[1], value), rras);
}

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
		if (stacks[0]->content[stacks[0]->top - 1] <= chunks[1])
		{
			push(stacks[1], stacks[0], "pb\n");
			if (stacks[0]->top <= 3 || stacks[1]->top == 1)
				continue;
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

void	sort_stacks(t_stack *stacks[])
{
	float	chunks[2];
	int		move_code;
	int		top_A;

//print_stack(stacks[0], "A init");
	chunks[0] = stacks[0]->size / 3.0;
	chunks[1] = stacks[0]->size * 2.0 / 3.0;
	while (stacks[0]->top > 3)
	{
		move_to_b(stacks, chunks);
		chunks[0] = (stacks[0]->size + 2.0 * (int)chunks[1]) / 3.0;
		chunks[1] = (2.0 * stacks[0]->size + (int)chunks[1]) / 3.0;
	}
//print_stack(stacks[0], "A bf sort 3");
	sort_three(stacks[0]);
	while (stacks[1]->top > 0 || stacks[0]->content[stacks[0]->top - 1] != 1)
	{
		top_A = stacks[0]->top;
		move_code = -2;	// PA directamente
		if (stacks[0]->content[top_A - 1] != stacks[0]->content[top_A - 2] - 1)
			move_code = 0;	// RA
		else if (stacks[0]->content[0] == stacks[0]->content[top_A - 1] - 1)
			move_code = 1;	// RRA
		else if (stacks[0]->content[0] != stacks[0]->size)
			move_code = -1;	// PA siguiente mayor
//if (move_code == -1)
//	return;
		move_to_a(stacks, move_code);
//print_stack(stacks[0], "A"); print_stack(stacks[1], "B");
	}
//print_stack(stacks[0], "A fin");
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
