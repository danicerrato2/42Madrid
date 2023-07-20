#include "push_swap_bonus.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stacks[2];
	int		i;
	int		num;

	if (argc < 2)
		return (0);
	stacks[0] = stack_init(argc - 1);
	stacks[1] = stack_init(argc - 1);
	i = argc;
	while (--i > 0 && check_int(argv[i]) == 0)
	{
		num = ft_atoi(argv[i]);
		if (is_in_stack(num, stacks[0]) == 1)
			return (free_all_bonus(stacks, "Error1\n", 2));
		stack_push(stacks[0], num);
	}
	if (stacks[0]->top != argc - 1)
		return (free_all_bonus(stacks, "Error2\n", 2));
	if (sort_stacks_bonus(stacks) == -1)
		return (free_all_bonus(stacks, "Error3\n", 2));
	if (!is_in_order(stacks[0]))
        return (free_all_bonus(stacks, "KO", 1));    
	return (free_all_bonus(stacks, "OK", 1));
}