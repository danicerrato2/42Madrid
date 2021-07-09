/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:59:03 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/09 11:08:34 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	double	sqrt;
	double	temp;

	if (nb < 0)
		return (0);
	sqrt = nb / 2.0;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (nb / temp + temp) / 2.0;
	}
	if (sqrt - (int)sqrt == 0.0)
		return (sqrt);
	return (0);
}
