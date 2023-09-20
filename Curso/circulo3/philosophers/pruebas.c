/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:49:19 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/20 20:41:32 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	wait;
	struct s_philo	*friend;
}	t_philo;

void	*func(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	printf("My id = %d, my friend id = %d\n", philo->id, philo->friend->id);
	if (philo->id != 2)
		(printf("%d parando...\n", philo->id), pthread_mutex_lock(&philo->wait));
	else
		(printf("%d desbloqueando a compa\n", philo->id), pthread_mutex_unlock(&philo->friend->wait));
	printf("Saliendo %d...\n", philo->id);
	return (0);
}

int	check_arg(char *arg)
{
	int	i;
	int	len;

	if (arg[0] == '-')
		return (0);
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

int	init_table(int argc, char *argv[])
{
	if (argc > 1 && check_arg(argv[1]) != 0)
		return (-1);
	return (0);
}

int	main(int argc, char *argv[])
{
	// t_philo		*p1;
	// t_philo		*p2;
	// pthread_t	h1;
	// pthread_t	h2;

	// p1 = malloc(sizeof(t_philo));
	// p2 = malloc(sizeof(t_philo));
	// p1->id = 1;
	// pthread_mutex_init(&p1->wait, 0);
	// pthread_mutex_lock(&p1->wait);
	// p2->id = 2;
	// pthread_mutex_init(&p2->wait, 0);
	// pthread_mutex_lock(&p2->wait);
	// p1->friend = p2;
	// p2->friend = p1;
	// pthread_create(&h1, 0, func, (void *)p1);
	// pthread_create(&h2, 0, func, (void *)p2);
	// pthread_join(h1, 0);
	// pthread_join(h2, 0);
	// pthread_mutex_destroy(&p1->wait);
	// pthread_mutex_destroy(&p2->wait);
	// free(p1);
	// free(p2);

	if (argc > 1)
		printf("%d\n", init_table(argc, argv));
	return (0);
}
