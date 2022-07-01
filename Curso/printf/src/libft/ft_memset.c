/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:25:32 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/01 13:38:02 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;

	if (str == NULL)
		return (str);
	i = 0;
	while (i < len)
	{
		((char *)str)[i] = c;
		i++;
	}
	return (str);
}
