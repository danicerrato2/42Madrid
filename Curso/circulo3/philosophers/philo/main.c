/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:38:00 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/20 21:04:33 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_threads(void *p)
{
	t_list	*philo_in_list;

	philo_in_list = (t_list *)p;
	pthread_join(philo_in_list->thread, 0);
}

void	init_threads(t_data *data)
{
	pthread_mutex_init(&data->wr_stdout, 0);
	pthread_mutex_init(&data->meal_completed, 0);
	data->philos = NULL;
	init_philos(data);
	ft_lstiter(data->philos, data->num_philos, wait_threads);
}

int	init_table(t_data *data, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc && check_arg(argv[i]) && ft_atoi(argv[i]) > 0)
		i++;
	if (i < argc)
		return (-1);
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]) * 1000;
	data->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (data->num_philos == 1)
	{
		printf("One philosopher can't eat\n");
		return (-1);
	}
	data->num_meals = -1;
	if (argc == 6)
		data->num_meals = ft_atoi(argv[5]);
	data->complete_meals = data->num_philos;
	init_threads(data);
	return (0);
}

int	free_table(t_data *data, char *msg)
{
	if (msg == NULL)
	{
		if (data->philos)
			ft_lstclear(&(data->philos), data->num_philos, free_philo);
		pthread_mutex_destroy(&data->wr_stdout);
		pthread_mutex_destroy(&data->meal_completed);
	}
	else
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
