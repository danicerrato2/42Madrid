/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:38:00 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/09 02:38:16 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char *arg)
{
	int	i;
	int	len;

	len = 0;
	while (arg[len])
		len++;
	if (len > 10)
		return (0);
	i = -1;
	while (arg[++i])
	{
		if (arg[i] < '0' || arg[i] > '9' || \
			(len == 10 && arg[i] > "2147483647"[i]))
			return (0);
	}
	return (1);
}

int	init_table(t_data *data, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc && check_arg(argv[i]) && ft_atoi(argv[i]) != 0)
		i++;
	if (i < argc)
		return (-1);
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->num_meals = -1;
	if (argc == 6)
		data->num_meals = ft_atoi(argv[5]);
	if (pthread_mutex_init(&data->wr_stdout, 0) != 0)
		return (-1);
	data->philos = NULL;
	init_philos(data);
	ft_lstiter(data->philos, data->num_philos, live);
	return (0);
}

int	free_table(t_data *data, char *msg)
{
	pthread_mutex_destroy(&data->wr_stdout);
	if (data->philos)
		ft_lstclear(&(data->philos), data->num_philos, free_philo);
	if (msg != NULL)
		printf("%s\n", msg);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 5 || argc > 6 || init_table(&data, argc, argv) == -1)
		return (free_table(&data, "Error: incorrect arguments"));
	free_table(&data, NULL);
	return (0);
}
