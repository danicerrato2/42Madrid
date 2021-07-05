/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:01:49 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/05 14:28:20 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	comprobar_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
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

void	convert_to_base(int *number, char *base, int tam)
{
	int	i;

	i = tam;
	while (i >= 0)
	{
		write(1, &base[number[i]], 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				num_base;
	unsigned int	unbr;
	int				number[32];
	int				i;

	num_base = comprobar_base(base);
	if (num_base == -1)
		return ;
	if (nbr < 0)
		unbr = 4294967296 + nbr;
	else
		unbr = nbr;
	i = 0;
	while (unbr > (unsigned int) num_base)
	{
		number[i] = unbr % num_base;
		unbr /= num_base;
		i++;
	}
	number[i] = unbr;
	convert_to_base(number, base, i);
}
