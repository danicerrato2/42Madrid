int check_int(char *str)
{
	int i;
	int len;
	
	if (str != NULL && str[0] == '-')
	{
		if (ft_strcmp("-2147483648", str) == 0)
			return (0);
		str++;
	}
	len = ft_strlen(str);
	if (len == 0 || len > 10)
		return (-1);
	if (len == 10) 
	{
		i = -1;
		while (++i < len)
		{
			if (str[i] < '0' || str[i] > "2147483647"[i])
				return (-1);
			if (str[i] < "2147483647"[i])
				return (0);
		}
	}		
	return (0);
}

int is_in_stack(int num, t_stack *stack)
{
	int i;

	i = stack->top;
	while (i < stack->size)
	{
		if (num == stack->content[i])
			return (1);
		i++;
	}
	return (0);
}


int *are_in_order(t_stack *stacks[])
{
	int i;
	int j;
	int inOrder[2];

	i = -1;
	while (++i < 2)
	{
		inOrder[i] = 1;
		j = stack[i]->top - 1;
		while (inOrder[i] == 1 && ++j < stack[i]->size - 1)
		{
			if (stack[i]->content[j] > stack[i]->content[j+1])
				inOrder[i] = 0;
		}
	}
	return (inOrder);
}

int free_all(t_stack *stacks[], int error)
{
	stack_free(stacks[0]);
	stack_free(stacks[1]);
	if (error != 0)
		ft_printf("Error\n");
	return (0);
}
