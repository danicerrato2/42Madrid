/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:41:20 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/13 16:33:06 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		comprobar_base(char *base);
int		calculate_number(char *base, char *str, int num_base);
void	reverse_number(char *number, int size);

char	*ft_put_in_base(int nbr, char *base, int num_base)
{
	unsigned int	unbr;
	int				i;
	char			*number;
	int				sign;

	number = (char *)malloc(34 * sizeof(char));
	sign = 1;
	if (nbr < 0)
	{
		sign = 0;
		unbr = (-1) * nbr;
	}
	else
		unbr = nbr;
	i = 0;
	while (unbr > (unsigned int)num_base)
	{
		number[i++] = base[unbr % num_base];
		unbr /= num_base;
	}
	number[i++] = base[unbr];
	if (sign == 0)
		number[i++] = '-';
	reverse_number(number, i);
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
