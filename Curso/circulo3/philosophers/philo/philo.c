/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 02:26:03 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/09 02:39:50 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	live(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	philo->live = 1;
}

void	*exist(void *p)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)p;
	data = (t_data *)philo->table;
	usleep(999999);
	while (data && philo->live != 1)
		continue ;
	// pthread_mutex_lock(data->wr_stdout);
	printf("Filosofo %d\n", philo->id);
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
		new->content->live = 0;
		new->content->table = data;
		new->content->right = malloc(sizeof(t_fork));
		new->content->right->in_use = i + 1;
		pthread_mutex_init(&new->content->right->hold, 0);
		ft_lstadd_front(&(data->philos), new);
		pthread_create(&(new->thread), 0, exist, data->philos->content);
		pthread_join(new->thread, 0);
	}
	last = ft_lstlast(data->philos, data->num_philos);
	new->prev = last;
	new->content->left = last->content->right;
	last->next = new;
}

void	free_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	philo->table = NULL;
	pthread_mutex_destroy(&philo->right->hold);
	free(philo->right);
	free(philo);
}
