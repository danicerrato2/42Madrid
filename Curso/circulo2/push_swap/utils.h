#ifndef UTILS_H
#define UTILS_H

#include "ft_stack.h"

int     check_int(char *str);
int     is_in_stack(int num, t_stack *stack);
void    are_in_order(t_stack *stacks[], int inOrder[2]);
int     free_all(t_stack *stacks[], int errorValue);

#endif