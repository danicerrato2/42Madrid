/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:08:49 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/20 14:04:32 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, size_t c)
{
	int	i;

	i = 0;
	while (str + i != NULL)
	{
		if (((char *)str)[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (0);
}
