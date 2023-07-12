#include "utils.h"

int swap(t_stack *stack, char *move)
{
	int aux;

	if (stack->top >= stack->size - 1)
		return (-1);
	aux = stack->content[stack->top];
	stack->content[stack->top] = stack->content[stack->top+1];
	stack->content[stack->top+1] = aux;
	ft_putstr_fd(move, 1);
	return (0);
}

int push(t_stack *stack1, t_stack *stack2, char *move)
{
	int aux;

	if (stack1 == NULL || stack2 == NULL || stack_pop(stack2, &aux) != 0)
		return (-1);
	if (stack_push(stack1, aux) != 0)
	{
		stack_push(stack2, aux);
		return (-1);
	}
	ft_putstr_fd(move, 1);
	return (0);
}

#include <stdio.h>

int sort_three(t_stack *stack)
{
	while (!is_in_order(stack))
	{
		printf("\n");
		printf("%d %d %d\n", stack->content[stack->top], stack->content[stack->top + 1], stack->content[stack->size - 1]);
		if (stack->content[stack->top] > stack->content[stack->top + 1])
		{
			if (stack->content[stack->top] > stack->content[stack->size - 1])
				(stack_rotate(stack, 0), ft_putstr_fd("ra\n", 1));
			else
				return (swap(stack, "sa\n"));
		}
		else
			(stack_rotate(stack, 1), ft_putstr_fd("rra\n", 1));
	}
	return (0);
}

int sort_stacks(t_stack *stacks[])
{
	// Bucle ida
	if (stacks[0]->size > 2)
		while (stacks[0]->top < stacks[0]->size - 3)
		{
			// No es algoritmo correcto, solo prueba
			push(stacks[1], stacks[0], "");
		}
	sort_three(stacks[0]);
	// Bucle vuelta
	return (0);
}

int main(int argc, char **argv)
{
	t_stack *stacks[2];
	int i;
	int num;

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
	if (stacks[0]->top == argc - 1 || sort_stacks(stacks) != 0)
		return (free_all(stacks, 1));
	return (free_all(stacks, 0));
}
