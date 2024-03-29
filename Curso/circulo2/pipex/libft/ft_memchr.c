/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:05:29 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/20 14:30:04 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t	i;

	if (str == NULL)
		return ((void *)str);
	i = 0;
	while (i < len && str + i != NULL)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
