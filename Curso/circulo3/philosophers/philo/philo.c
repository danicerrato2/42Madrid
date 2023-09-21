/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 02:26:03 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/21 18:37:23 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *action, t_data *data)
{
	useconds_t	now_time;
	useconds_t	life_time;
	useconds_t	dead_time;

	now_time = get_time_in_ms();
	dead_time = now_time - philo->last_meal;
	life_time = now_time - data->init_time;
	if (dead_time > data->time_to_die)
		action = "died";
	pthread_mutex_lock(&data->wr_stdout);
	if (data->complete_meals != 0)
	{
		if (philo->num_meals > 0 && --philo->num_meals == 0)
			data->complete_meals--;
		printf("%u %d %s\n", life_time, philo->id, action);
	}
	pthread_mutex_unlock(&data->wr_stdout);
	if (dead_time > data->time_to_die)
	{
		pthread_mutex_lock(&data->dead);
		data->complete_meals = 0;
		data->num_meals = 0;
		pthread_mutex_unlock(&data->dead);
	}
}

void	live(t_philo *philo, t_data *data)
{	
	pthread_mutex_lock(&philo->fork);
	print_action(philo, "has taken a fork", data);
	pthread_mutex_lock(&philo->right->fork);
	print_action(philo, "has taken a fork", data);
	print_action(philo, "is eating", data);
	philo->last_meal = get_time_in_ms();
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->right->fork);
	print_action(philo, "is sleeping", data);
	ft_usleep(data->time_to_sleep);
	print_action(philo, "is thinking", data);
}

void	*exist(void *p)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)p;
	data = (t_data *)philo->table;
	pthread_mutex_lock(&philo->wait);
	pthread_mutex_unlock(&philo->right->wait);
	philo->last_meal = get_time_in_ms();
	ft_usleep((philo->id % 2) * 2);
	pthread_mutex_lock(&data->dead);
	while (data->num_meals == -1 || data->complete_meals != 0)
	{
		pthread_mutex_unlock(&data->dead);
		live(philo, data);
		pthread_mutex_lock(&data->dead);
	}
	pthread_mutex_unlock(&data->dead);
	return (0);
}

void	init_philos(t_data *data)
{
	t_list		*new;
	t_list		*last;
	int			i;

	data->init_time = get_time_in_ms();
	i = -1;
	while (++i < data->num_philos)
	{
		new = ft_lstnew(malloc(sizeof(t_philo)));
		new->content->id = i + 1;
		new->content->num_meals = data->num_meals;
		new->content->table = data;
		pthread_mutex_init(&new->content->fork, 0);
		pthread_mutex_init(&new->content->wait, 0);
		pthread_mutex_lock(&new->content->wait);
		pthread_create(&(new->thread), 0, exist, new->content);
		ft_lstadd_front(&(data->philos), new);
	}
	last = ft_lstlast(data->philos, data->num_philos);
	last->content->right = new->content;
	last->next = new;
}

void	free_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	philo->table = NULL;
	pthread_mutex_destroy(&philo->fork);
	pthread_mutex_destroy(&philo->wait);
	free(philo);
}
