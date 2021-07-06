/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:23:55 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/06 14:44:14 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_sqrt(int nb)
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

int	ft_is_prime(int nb)
{
	int	sqrt;

	if (nb <= 1)
		return (0);
	sqrt = get_sqrt(nb);
	while (sqrt > 1)
	{
		if (nb % sqrt == 0)
			return (0);
		sqrt--;
	}
	return (1);
}
