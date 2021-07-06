/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:50:09 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/06 15:33:35 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_sqrt_prime(int nb)
{
	int	i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i - 1);
}

int	is_prime(int nb)
{
	int	sqrt;
	int	i;

	if (nb < 2)
		return (0);
	sqrt = get_sqrt_prime(nb);
	i = 2;
	while (i < sqrt)
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
