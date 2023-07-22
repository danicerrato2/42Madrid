/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:44:23 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/06 11:31:27 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	total_size;

	total_size = count * size;
	mem = malloc(total_size);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, total_size);
	return (mem);
}
