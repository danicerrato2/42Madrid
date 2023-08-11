/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 23:43:01 by dcerrato          #+#    #+#             */
/*   Updated: 2023/08/11 15:14:31 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "libft/libft.h"

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**paths;
	char	*cmd;
	int		infile;
	int		outfile;
	int		pipefd[2];
	int		childs[2];
	int		num_childs;
}	t_pipex;

char	**ft_pipex_split(const char *str, char c);

void	error(t_pipex *data, char *msg, int code);
void	free_fork_utils(t_pipex *data, char **args);
void	free_all(t_pipex *data);
char	**get_paths(char *envp[]);
int		get_command(t_pipex *data, char **args);

#endif