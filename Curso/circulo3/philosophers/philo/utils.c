/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:42:27 by dcerrat2          #+#    #+#             */
/*   Updated: 2023/09/20 20:50:38 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	signo;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	signo = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo *= (-1);
		i++;
	}
	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = 10 * number + str[i] - '0';
		i++;
	}
	number *= signo;
	return (number);
}

useconds_t	get_time_in_ms(void)
{
	struct timeval	t;

	gettimeofday(&t, 0);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	ft_usleep(long long time)
{
	useconds_t	init;
	useconds_t	now;

	init = get_time_in_ms() * 1000;  
	now = init;
	while (now - init < time)
	{
		usleep(50);
		now = get_time_in_ms() * 1000;
	}
}
