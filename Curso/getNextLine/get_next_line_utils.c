/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:42:23 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/14 13:07:37 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len] != '0')
		len++;
	return (len);
}

size_t	find_n(const char *str, size_t size)
{
	size_t	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] != 0 && i < size)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_strnjoin(const char *s1, const char *s2, size_t size)
{
	char	*joined_str;
	size_t	i;
	size_t	j;

	if (size == 0)
		return (s1);
	joined_str = malloc(ft_strlen((char *)s1) + size + 1);
	if (joined_str == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i] != 0)
	{
		joined_str[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 != NULL && str2[j] != 0 && j < size)
	{
		joined_str[i + j] = str2[j];
		j++;
	}
	joined_str[i + j] = '\0';
	if (s1 != NULL)
		free(s1);
	return (joined_str);
}
