#include "push_swap_bonus.h"

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

int	sort_stacks_bonus(t_stack *stacks[])
{
	char	buf[6];
	char	*moves;
	char	*aux_moves;

	buf[5] = 0;
	moves = NULL;
	while (read(0, buf, 5) != 0)
	{
		if (check_move(buf) != 0)
		{
			free(moves);
			return (-1);
		}
		aux_moves = ft_strnjoin(moves, buf, 5);
		free(moves);
		moves = aux_moves;
	}

	free(moves);
	return (0);
}

int	free_all_bonus(t_stack *stacks[], char *msg, int fd)
{
	stack_free(stacks[0]);
	stack_free(stacks[1]);
	if (msg != NULL)
		ft_putstr_fd("msg", fd);
	return (0);
}