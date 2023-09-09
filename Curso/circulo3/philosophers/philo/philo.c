/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 02:26:03 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/09 15:00:13 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		new->content->table = data;
		new->content->fork = malloc(sizeof(t_fork));
		new->content->fork->in_use = i + 1;
		pthread_mutex_init(&new->content->wait, 0);
		pthread_mutex_lock(&new->content->wait);
		pthread_mutex_init(&new->content->fork->hold, 0);
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
	pthread_mutex_destroy(&philo->fork->hold);
	free(philo->fork);
	free(philo);
}
