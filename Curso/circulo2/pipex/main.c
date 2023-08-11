/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:34:51 by dcerrato          #+#    #+#             */
/*   Updated: 2023/08/11 13:35:27 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_child(t_pipex *data)
{
	char	**args;

	(dup2(data->infile, 0), dup2(data->pipefd[1], 1));
	(close(data->pipefd[0]), close(data->infile));
	args = ft_pipex_split(data->argv[2], ' ');
	if (get_command(data, args) == 0)
		(free_fork_utils(NULL, args), \
		error(data, "Error: Command not found\n", 127));
	if (execve(data->cmd, args, data->envp) != -1)
		(free_fork_utils(data->cmd, args), \
		error(data, "Error: Command not found\n", 127));
	(free_fork_utils(data->cmd, args), close(data->pipefd[1]));
}

void	exec_father(t_pipex *data)
{
	char	**args;

	(dup2(data->outfile, 1), dup2(data->pipefd[0], 0));
	(close(data->pipefd[1]), close(data->outfile));
	args = ft_pipex_split(data->argv[3], ' ');
	if (get_command(data, args) == 0)
		(free_fork_utils(NULL, args), \
		error(data, "Error: Command not found\n", 127));
	if (execve(data->cmd, args, data->envp) != -1)
		(free_fork_utils(data->cmd, args), \
		error(data, "Error: Command not found\n", 127));
	(free_fork_utils(data->cmd, args), close(data->pipefd[0]));
}

void	init_data(t_pipex *data, int argc, char *argv[], char *envp[])
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->paths = get_paths(envp);
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1)
		ft_putstr_fd("Error: No such file or directory\n", 2);
	data->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 644);
	if (data->outfile == -1)
		error(data, "Error: Permission denied\n", 1);
	if (pipe(data->pipefd) == -1)
		error(data, "Error: Pipe not open\n", 1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	data;

	if (argc != 5)
		error(0, "Error: Command not found\n", 1);
	init_data(&data, argc, argv, envp);
	if (data.infile != -1)
		data.child = fork();
	if (data.infile != -1 && data.child == -1)
		error(&data, "Error: Process child not created\n", 0);
	if (data.infile != -1 && data.child == 0)
		exec_child(&data);
	else
		exec_father(&data);
	waitpid(data.child, NULL, 0);
	free_all(&data);
	return (1);
}
