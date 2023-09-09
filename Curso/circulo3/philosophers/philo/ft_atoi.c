/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:42:27 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/08 19:02:45 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
