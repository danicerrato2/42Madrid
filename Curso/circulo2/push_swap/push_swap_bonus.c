#include "push_swap_bonus.h"


#include <stdio.h>

int	check_move(char move[])
{
	int	move_len;

	move_len = ft_strlen(move);
	if (move_len < 3 || move_len > 4 || move[move_len - 1] != '\n')
		return (-1);
	if (move_len == 3 && (move[0] == 'p' || move[0] == 'r' || move[0] == 's'))
	{
		if (move[1] == 'a' || move[1] == 'b' || \
			(move[0] == 'r' && move[1] == 'r') || \
			(move[0] == 's' && move[1] == 's'))
				return (0);
	}
	else if (move_len == 4 && move[0] == 'r' && move[1] == 'r')
		if (move[2] == 'a' || move[2] == 'b' || move[2] == 'r')
			return (0);
	return (-1);
}

int	get_moves(char *moves)
{
	char	buf[6];
	char	*aux_moves;
	int		bytes;

	bytes = read(0, buf, 6); 
	while (bytes >= 0 && buf[0] != '\n')
	{
		buf[bytes] = 0;
		if (check_move(buf) != 0)
		    return (-1);
		aux_moves = ft_strjoin(moves, buf);
		free(moves);
		moves = aux_moves;
		bytes = read(0, buf, 6);
	}
	printf("Moves:\n%sFin\n", moves);
	return (0);
}

void	do_move(t_stack *stacks[], char move[])
{
	if (ft_strncmp(move, "sa", 3) == 0)
		swap(stacks[0], "");
	else if (ft_strncmp(move, "sb", 3) == 0)
		swap(stacks[1], "");
	else if (ft_strncmp(move, "ss", 3) == 0)
		(swap(stacks[0], ""), swap(stacks[1], ""));
	else if (ft_strncmp(move, "pa", 3) == 0)
		push(stacks[1], stacks[0], "");
	else if (ft_strncmp(move, "pb", 3) == 0)
		push(stacks[0], stacks[1], "");
	else if (ft_strncmp(move, "ra", 3) == 0)
		stack_rotate(stacks[0], 0);
	else if (ft_strncmp(move, "rb", 3) == 0)
		stack_rotate(stacks[1], 0);
	else if (ft_strncmp(move, "rr", 3) == 0)
		(stack_rotate(stacks[0], 0), stack_rotate(stacks[1], 0));
	else if (ft_strncmp(move, "rra", 3) == 0)
		stack_rotate(stacks[0], 1);
	else if (ft_strncmp(move, "rrb", 3) == 0)
		stack_rotate(stacks[1], 1);
	else if (ft_strncmp(move, "rrr", 3) == 0)
		(stack_rotate(stacks[0], 1), stack_rotate(stacks[1], 1));
}

int	sort_stacks_bonus(t_stack *stacks[])
{
	char	*moves;
	char	next_move[4];
	int		i;
	int		j;

	moves = (char *)ft_calloc(1, sizeof(char));
	if (get_moves(moves) == -1)
	{
		free(moves);
		return (-1);
	}
	printf("Moves:\n%sFin\n", moves);
	i = -1;
	j = -1;
	while (moves[++i] != 0)
	{
		if (moves[i] != '\n')
			next_move[++j] = moves[i];
		else
		{
			next_move[++j] = 0;
			j = -1;
			do_move(stacks, next_move);
		}
	}
	printf("Moves:\n%sFin\n", moves);
	if (moves)
		free(moves);
	return (0);
}

int	free_all_bonus(t_stack *stacks[], char *msg, int fd)
{
	stack_free(stacks[0]);
	stack_free(stacks[1]);
	if (msg != 0)
		ft_putstr_fd(msg, fd);
	return (0);
}
