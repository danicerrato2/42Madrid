#include "push_swap.h"

int swap(t_stack *stack)
{
	int aux;

	if (stack->top >= stack->size - 1)
		return (-1);
	aux = stack->content[stack->top];
	stack->content[stack->top] = stack->content[stack->top+1];
	stack->content[stack->top+1] = aux;
	return (0);
}

int push(t_stack *stack1, t_stack *stack2)
{
	int aux;

	if (stack1 == NULL || stack2 == NULL || stack_pop(stack2, &aux) != 0)
		return (-1);
	if (stack_push(stack1, aux) != 0)
	{
		stack_push(stack2, aux);
		return (-1);
	}
	return (0);
}

int sort_stack(t_stack *stacks[], char *commands)
{
	int areSorted[2];

	are_in_order(stacks, &areSorted);
	while (stacks[0]->top != 0 || !areSorted[0] || !areSorted[1])
	{
		if (!areSorted[0] || !areSorted[1])
		{
			// Solo se indica el movimiento
			if (!areSorted[0])
			{
				/*
				 * Ver más pequeño de A:
				 * 	Si bottom -> RRA
				 * 	Si seg 	-> Si bottom < top -> RA
				 * 		-> Si bottom > top -> SA
				 * 	Si top 	-> Si bottom < prebottom -> RRA, RRA, SA, RA, RA
				 */
			}
			if (!areSorted[1])
			{
				/*
				 * Ver más pequeño (neg) de B:
				 * 	Si bottom -> RRB
				 * 	Si seg 	-> Si bottom < top -> RB
				 * 		-> Si bottom > top -> SB
				 * 	Si top -> PA
			 	 */
			}
			// Se hacen comprobaciones y luego movimientos
			/*
			 * Si RR? o S? o R? -> RRR o SS o RR
			 * Si PA y PB -> PB
			 */
		}
		else
			/*
			 * PA
			 */
	}
}

int main(int argc, char **argv)
{
	t_stack *stacks[2];
	int i;
	int num;
	char *commands;

	if (argc < 2)
		return (0);
	stacks[0] = stack_init(argc - 1);
	stacks[1] = stack_init(argc - 1);
	i = argc;
	while (--i > 0 && check_int(argv[i]) == 0)
	{
		num = ft_atoi(argv[i]);
		if (is_in_stack(num, stacks[0]) == 1)
			return (free_all(stacks, 1));
		stack_push(stacks[0], ft_atoi(argv[i]));		
	}
	if (i > 0 || sort_stack(stacks, commands) != 0)
		return (free_all(stacks, 1));
	return (free_all(stacks, 0));
}
