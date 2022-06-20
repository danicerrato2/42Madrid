/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:45:49 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/20 14:17:28 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL || src == NULL)
		return (dst);
	i = 0;
	while (i < len && src + i > dst)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	while (i < len && src + i < dst + len)
	{
		((char *)dst)[len - 1] = ((char *)src)[len - 1];
		len--;
	}
	return (dst);
}
