/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:50:09 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/11 12:49:23 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_sqrt_prime(int nb)
{
	double	sqrt;
	double	temp;

	if (nb < 0)
		return (-1);
	sqrt = nb / 2.0;
	temp = 0.0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (nb / temp + temp) / 2;
	}
	return ((int)sqrt);
}

int	is_prime(int nb)
{
	int	sqrt;
	int	i;

	if (nb < 2)
		return (0);
	sqrt = get_sqrt_prime(nb);
	i = 2;
	while (i <= sqrt)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (2);
	if (nb % 2 == 0 && nb != 2)
		nb++;
	i = 0;
	while (is_prime(nb + i * 2) != 1)
		i++;
	return (nb + i * 2);
}
