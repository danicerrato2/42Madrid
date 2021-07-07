/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:23:55 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/07 20:04:08 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_sqrt(int nb)
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
		sqrt = (nb / temp + temp) / 2.0;
	}
	return ((int)sqrt);
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
