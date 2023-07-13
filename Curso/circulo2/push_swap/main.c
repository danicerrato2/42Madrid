/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:19:18 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/13 19:19:31 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stacks[2];
	int		i;
	int		num;

	if (argc < 3)
		return (0);
	stacks[0] = stack_init(argc - 1);
	stacks[1] = stack_init(argc - 1);
	i = argc;
	while (--i > 0 && check_int(argv[i]) == 0)
	{
		num = ft_atoi(argv[i]);
		if (is_in_stack(num, stacks[0]) == 1)
			return (free_all(stacks, 1));
		stack_push(stacks[0], num);
	}
	if (stacks[0]->top == argc - 1)
		return (free_all(stacks, 1));
	if (!is_in_order(stacks[0]))
		(to_stackB(stacks), sort_three(stacks[0]), to_stackA(stacks));
	return (free_all(stacks, 0));
}
