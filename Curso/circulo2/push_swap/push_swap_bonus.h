#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

int     check_move(char move[]);
int     get_moves(char *moves);
void	do_move(t_stack *stacks[], char move[]);
int     sort_stacks_bonus(t_stack *stacks[]);
int     free_all_bonus(t_stack *stacks[], char *msg, int fd);

#endif