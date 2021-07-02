/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:39:03 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/02 14:41:01 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_non_printable(char c)
{
	char			hexa[2];
	unsigned char	uchar;

	if (c < 0)
		uchar = 256	+ c;
	else
		uchar = c;
	write (1, "\\", 1);
	if (uchar / 16 <= 9)
		hexa[0] = '0' + uchar / 16;
	else
		hexa[0] = 'a' + uchar / 16 - 10;
	if (uchar % 16 <= 9)
		hexa[1] = '0' + uchar % 16;
	else
		hexa[1] = 'a' + uchar % 16 - 10;
	write (1, hexa, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] == 127)
			print_non_printable(str[i]);
		else
			write (1, &str[i], 1);
		i++;
	}
}
