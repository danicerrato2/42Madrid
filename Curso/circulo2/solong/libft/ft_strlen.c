/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:48:46 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/06 14:28:49 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;
	int	length;

	length = 0;
	if (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			i++;
			length++;
		}
	}
	return (length);
}
