/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicerrato2 <danicerrato2@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:48:57 by dcerrato          #+#    #+#             */
/*   Updated: 2023/08/17 15:56:26 by danicerrato      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(t_pipex *data, char *msg, int code)
{
	if (data != 0)
		free_all(data);
	ft_putstr_fd(msg, 2);
	exit(code);
}

void	free_fork_utils(t_pipex *data, char **args)
{
	int	i;

	if (data->cmd)
		free(data->cmd);
	i = -1;
	if (args)
	{
		while (args[++i] != 0)
			free(args[i]);
		free(args);
	}
	(close(data->pipefd[0]), close(data->pipefd[1]));
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

int	get_command(t_pipex *data, char **args)
{
	int	i;

	i = -1;
	while (data->paths[++i] != 0)
	{
		data->cmd = ft_strjoin(data->paths[i], args[0]);
		if (access(data->cmd, X_OK) != -1)
			break ;
		free(data->cmd);
	}
	if (ft_strnstr(args[0], "/", ft_strlen(args[0])) != 0)
		data->cmd = args[0];
	else if (data->paths[i] == 0)
	{
		data->cmd = NULL;
		return (0);
	}
	return (1);
}
