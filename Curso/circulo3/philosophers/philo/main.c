/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:38:00 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/19 17:55:06 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_threads(void *p)
{
	t_list	*philo;

	philo = (t_list *)p;
	pthread_join(philo->thread, 0);
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
	pthread_mutex_init(&data->wr_stdout, 0);
	pthread_mutex_init(&data->finished, 0);
	data->philos = NULL;
	init_philos(data);
	pthread_mutex_lock(&data->finished);
	while (data->num_philos != 0)
		pthread_mutex_lock(&data->finished);
	ft_lstiter(data->philos, data->num_philos, wait_threads);
	return (0);
}

int	free_table(t_data *data, char *msg)
{
	if (data->philos)
		ft_lstclear(&(data->philos), data->num_philos, free_philo);
	pthread_mutex_destroy(&data->wr_stdout);
	pthread_mutex_destroy(&data->finished);
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
