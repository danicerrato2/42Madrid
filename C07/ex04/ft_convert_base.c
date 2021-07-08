/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:41:20 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/08 17:55:20 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	comprobar_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		else if ((base[i] > 8 && base[i] < 14) || base[i] == ' ')
			return (-1);
		j = i - 1;
		while (j >= 0)
		{
			if (base[i] == base[j])
				return (-1);
			j--;
		}
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	calculate_number(char *base, char *str, int num_base)
{
	int	number;
	int	i;
	int	value;

	number = 0;
	i = 0;
	value = is_in_base(str[i], base);
	while (value != -1)
	{
		number = num_base * number + value;
		i++;
		value = is_in_base(str[i], base);
	}
	return (number);
}

char	*ft_put_in_base(int nbr, char *base, int num_base)
{
	unsigned int	unbr;
	int				i;
	char			*number;

	number = (char *)malloc(34 * sizeof(char));
	i = 0;
	if (nbr < 0)
	{
		number[i++] = '-';
		unbr = (-1) * nbr;
	}
	else
		unbr = nbr;
	while (unbr >= 0)
	{
		number[i] = unbr % num_base;
		unbr /= num_base;
		i++;
	}
	while (i-- >= 0 && number[i] != '-')
	{
		number[i] = base[(int)number[i]];
		i--;
	}
	return (number);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		sign;
	int		nbase_from;
	int		nbase_to;
	int		number;

	nbase_from = comprobar_base(base_from);
	nbase_to = comprobar_base(base_to);
	if (nbase_from == -1 || nbase_to == -1)
		return (NULL);
	i = 0;
	while ((nbr[i] > 8 && nbr[i] < 14) || nbr[i] == ' ')
		i++;
	sign = 1;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign *= (-1);
		i++;
	}
	number = sign * calculate_number(base_from, nbr + i, nbase_from);
	return (ft_put_in_base(number, base_to, nbase_to));
}
