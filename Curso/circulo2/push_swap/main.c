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

void	sort_stacks(t_stack *stacks[])
{
	float	chunks[3];

	chunks[2] = stacks[0]->top;
	chunks[0] = stacks[0]->size / 3.0;
	chunks[1] = stacks[0]->size * 2.0 / 3.0;
	while (stacks[0]->top > 3)
	{
		move_to_b(stacks, chunks);
		chunks[2] = stacks[0]->top;
		chunks[0] = stacks[0]->size - (stacks[0]->size - (int)chunks[1]) * 2.0 / 3.0;
		chunks[1] = stacks[0]->size - (stacks[0]->size - (int)chunks[1]) / 3.0;
	}
	sort_three(stacks[0]);
	// move_to_a
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
