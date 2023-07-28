#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>

# include "libft/libft.h"

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**paths;
	int		infile;
	int		outfile;
	int		pipefd[2];
	int 	child;
}	t_pipex;

#endif