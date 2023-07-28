/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:48:57 by dcerrato          #+#    #+#             */
/*   Updated: 2023/07/28 23:41:57 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_fork_utils(char *cmd, char **args)
{
	int	i;

	if (cmd)
		free(cmd);
	i = -1;
	if (args)
	{
		while (args[++i] != 0)
			free(args[i]);
		free(args); 
	}
}

void	free_all(t_pipex *data)
{
	int	i;

	i = -1;
	if (data->paths)
	{
		while (data->paths[++i] != 0)
			free(data->paths[i]);
		free(data->paths);
	}
	(close(data->infile), close(data->outfile));
	(close(data->pipefd[0]), close(data->pipefd[1]));
}

char	**get_paths(char *envp[])
{
	char	*aux;
	char	**paths;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths[++i] != 0)
	{
		aux = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = aux;
	}
	return (paths);
}
