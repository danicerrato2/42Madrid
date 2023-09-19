/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 02:26:03 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/19 20:17:58 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	live(t_philo *philo, t_data *data)
{
	while (data->num_philos != 0)
	{
		if (philo->id % 2 == 0)
			usleep(2);
		while (1)
		{
			pthread_mutex_lock(&philo->fork);
			pthread_mutex_lock(&philo->right->fork);
			// come
			// suelta_palillo(i)
			// suelta_palillo(i+1)
			// duerme
			// piensa
		}
		if (data->num_meals > 0)
			data->num_meals--;
		else if (data->num_meals != -1)
		{
			pthread_mutex_lock(&data->wr_stdout);
			data->num_philos--;
			pthread_mutex_unlock(&data->finished);
			pthread_mutex_unlock(&data->wr_stdout);
		}
	}
}

void	*exist(void *p)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)p;
	data = (t_data *)philo->table;
	if (philo->id < data->num_philos)
		pthread_mutex_lock(&philo->wait);
	if (philo->id > 1)
		pthread_mutex_unlock(&philo->right->wait);
	live(philo, data);
	return (0);
}

void	init_philos(t_data *data)
{
	t_list	*new;
	t_list	*last;
	int		i;

	i = -1;
	while (++i < data->num_philos)
	{
		new = ft_lstnew(malloc(sizeof(t_philo)));
		new->content->id = i + 1;
		new->content->num_meals = data->num_meals;
		new->content->table = data;
		pthread_mutex_init(&new->content->wait, 0);
		pthread_mutex_lock(&new->content->wait);
		pthread_mutex_init(&new->content->fork, 0);
		pthread_create(&(new->thread), 0, exist, new->content);
		ft_lstadd_front(&(data->philos), new);
	}
	last = ft_lstlast(data->philos, data->num_philos);
	new->prev = last;
	last->content->right = new->content;
	last->next = new;
}

void	free_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	philo->table = NULL;
	pthread_mutex_destroy(&philo->fork);
	free(philo);
}
