/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:39:37 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/24 16:58:34 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_num_digits(int n)
{
	int	num_digits;

	num_digits = 1;
	while (n > 9)
	{
		n /= 10;
		num_digits++;
	}
	return (num_digits);
}

char	*ft_itoa(int n)
{
	int		is_negative;
	int		num_digits;
	char	*number;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	num_digits = get_num_digits(n);
	number = malloc(is_negative + num_digits + 1);
	if (number == NULL)
		return (NULL);
	if (is_negative)
		number[0] = '-';
	number[is_negative + num_digits] = '\0';
	while (--num_digits >= 0)
	{
		number[is_negative + num_digits] = n % 10 + 48;
		n /= 10;
	}
	return (number);
}
