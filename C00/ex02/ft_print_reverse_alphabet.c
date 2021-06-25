#include <stdio.h>
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	rev_alpha;

	rev_alpha = 'z';
	while (rev_alpha >= 'a')
	{
		write(1, &rev_alpha, 1);
		rev_alpha--;
	}
}
