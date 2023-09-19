/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:42:27 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/19 16:44:25 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
