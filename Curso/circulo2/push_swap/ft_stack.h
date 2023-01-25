#ifndef FT_STACK_H
#define FT_STACK_H

#include <stdlib.h>

typedef struct s_stack
{
	int *content;
	int top;
	int size;
} t_stack;

t_stack *stack_init(int size);
int stack_push(t_stack *stack, int num);
int stack_pop(t_stack *stack, int *num);
int stack_rotate(t_stack *stack, int upOrDown);
void stack_free(t_stack *stack);

#endif
