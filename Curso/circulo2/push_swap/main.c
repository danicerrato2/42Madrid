#include <stdio.h>

#include "ft_stack.h"

int main()
{
	t_stack *stack;
	int num;

	stack = stack_init(5);
	for (int i = 0; i < 6; i++)
	       stack_push(stack, i+1);
	stack_rotate(stack, 1);
	for (; stack_pop(stack, &num) == 0;)
		printf("%d ", num);
	stack_free(stack);
	printf("\n");
	return 0;	
}
