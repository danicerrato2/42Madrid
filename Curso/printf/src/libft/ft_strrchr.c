/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:05:55 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/01 13:39:33 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i] != 0)
	{
		if (((char *)s)[i] == (char)c)
			last = (char *)s + i;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (last);
}
