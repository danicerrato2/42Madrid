/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:34:51 by dcerrato          #+#    #+#             */
/*   Updated: 2023/08/17 15:31:58 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_pipex *data, int argc, char *argv[], char *envp[])
{
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->paths = get_paths(envp);
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1)
		ft_putstr_fd("Error: No such file or directory\n", 2);
	data->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (data->outfile == -1)
		ft_putstr_fd("Error: Permission denied\n", 2);
	if (pipe(data->pipefd) == -1)
		ft_putstr_fd("Error: Pipe not open\n", 2);
	data->num_childs = argc - 2;
	data->cmd = 0;
}

void	exec_child1(t_pipex *data)
{
	char	**args;

	close(data->pipefd[0]);
	if (data->infile == -1)
		(close(data->pipefd[1]), exit(EXIT_FAILURE));
	(dup2(data->pipefd[1], 1), close(data->pipefd[1]));
	(dup2(data->infile, 0), close(data->infile));
	args = ft_split(data->argv[2], ' ');
	if (get_command(data, args) == 0 || \
		execve(data->cmd, args, data->envp) != -1)
		(free_fork_utils(data, args), \
			error(data, "Error: Command not found\n", 127));
	(free_fork_utils(data, args), exit(EXIT_FAILURE));
}

void	exec_child2(t_pipex *data)
{
	char	**args;

	close(data->pipefd[1]);
	(dup2(data->pipefd[0], 0), close(data->pipefd[0]));
	(dup2(data->outfile, 1), close(data->outfile));
	args = ft_split(data->argv[3], ' ');
	if (get_command(data, args) == 0 || \
		execve(data->cmd, args, data->envp) != -1)
		(free_fork_utils(data, args), \
			error(data, "Error: Command not found\n", 127));
	(free_fork_utils(data, args), exit(EXIT_FAILURE));
}

void	ft_leaks()
{
	system("leaks -q pipex");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	data;
	int		status;

	atexit(ft_leaks);
	if (argc != 5)
		error(0, "Error: Command not found\n", 1);
	init_data(&data, argc, argv, envp);
	data.childs[0] = fork();
	if (data.childs[0] == -1)
		error(&data, "Error: Process child not created\n", 0);
	if (data.childs[0] == 0)
		exec_child1(&data);
	data.childs[1] = fork();
	if (data.childs[1] == -1)
		error(&data, "Error: Process child not created\n", 0);
	if (data.childs[1] == 0)
		exec_child2(&data);
	(close(data.pipefd[0]), close(data.pipefd[1]));
	while (data.num_childs > 0)
	{
		waitpid(-1, &status, 0);
		data.num_childs--;
	}
	free_all(&data);
	return (WEXITSTATUS(status));
}
