/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 23:43:01 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/31 19:02:10 by dcerrato         ###   ########.fr       */
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
	int		infile;
	int		outfile;
	int		pipefd[2];
	int		child;
}	t_pipex;

char	**ft_pipex_split(const char *str, char c);
void	free_fork_utils(char *cmd, char **args);
void	free_all(t_pipex *data);
char	**get_paths(char *envp[]);

#endif