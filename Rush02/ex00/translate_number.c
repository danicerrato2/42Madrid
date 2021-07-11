/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 12:25:54 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/11 17:41:18 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_number(char *str, int *num_size)
{
	int			i;
	long long	number;

	if (str == NULL)
		return (-1);
	i = 0;
	number = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		number = number *10 + str[i] - '0';
		if (number > 4294967295)
			return (-1);
		i++;
	}
	*num_size = i;
	return (0);
}

char	*translate_number(int num_size, char *num, s_dicc *entry)
{
}


