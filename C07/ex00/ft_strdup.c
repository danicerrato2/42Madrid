/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:43:47 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/07 18:21:28 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*new;

	if (src == NULL)
		return (NULL);
	new = NULL;
	i = 0;
	while (src[i] != '\0')
		i++;
	new = (char *)malloc(i * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = src[i];
	return (new);
}
