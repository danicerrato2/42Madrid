#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>

# include "ft_stack.h"

int	check_move(char move[]);
int	sort_stacks_bonus(t_stack *stacks[]);
int	free_all_bonus(t_stack *stacks[], char *msg, int fd);

#endif