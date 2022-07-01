/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:44:23 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/01 13:41:08 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_calloc(int count, size_t size)
{
	void	*mem;
	size_t	i;

	if (count <= 0 || size <= 0)
		return (NULL);
	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}
