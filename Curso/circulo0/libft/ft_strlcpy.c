/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:48:59 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/06 14:38:17 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	while (src[count] != '\0')
		count++;
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && i < count)
		{
			dest[i] = ((char *)src)[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (count);
}
