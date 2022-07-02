/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:44:23 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/02 11:21:16 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	i;

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
