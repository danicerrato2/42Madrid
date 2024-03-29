/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:37:58 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/06 14:32:47 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*new;

	if (src == NULL)
		return (NULL);
	new = NULL;
	i = 0;
	while (src[i] != '\0')
		i++;
	new = (char *)malloc(i + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		new[i] = ((char *)src)[i];
		i++;
	}
	new[i] = 0;
	return (new);
}
