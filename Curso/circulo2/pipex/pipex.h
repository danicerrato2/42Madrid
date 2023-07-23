#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>

# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_pipex
{
	int		argc;
	char	*argv[];
	int		infile;
	int		outfile;
	int		pipefd[2];
	int 	child;
}	t_pipex;

#endif