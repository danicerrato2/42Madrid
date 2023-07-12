/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:37:30 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/06 14:43:38 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_length;
	unsigned int	src_length;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (size <= 0)
		return (src_length);
	i = 0;
	while (src[i] != '\0' && dest_length + i < size - 1)
	{
		dest[dest_length + i] = ((char *)src)[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	if (size < dest_length)
		return (size + src_length);
	return (dest_length + src_length);
}
