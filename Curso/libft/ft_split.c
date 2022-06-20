/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:53:35 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/20 14:20:24 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	copy_str(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**new_split(char **strings, char *str, int size, int *g_num_strs)
{
	char	**new;
	int		i;

	if (size == 0)
		return (strings);
	(*g_num_strs)++;
	new = (char **)malloc((*g_num_strs + 1) * sizeof(char *));
	if (new == NULL)
		return (strings);
	i = 0;
	while (i < *g_num_strs - 1)
	{
		new[i] = strings[i];
		i++;
	}
	new[i] = (char *)malloc((size + 1) * sizeof(char));
	if (new[i] == NULL)
		return (strings);
	copy_str(new[i], str, size);
	new[i + 1] = "\0";
	return (new);
}

char	**ft_split(char *str, char *charset)
{
	char	**strings;
	int		from;
	int		to;
	int		g_num_strs;

	strings = (char **)malloc(sizeof(char *));
	strings[0] = "\0";
	to = 0;
	from = 0;
	g_num_strs = 0;
	while (str[to] != '\0')
	{
		if (is_charset(str[to], charset) == 1)
		{
			strings = new_split(strings, &str[from], to - from, &g_num_strs);
			from = to + 1;
		}
		to++;
	}
	strings = new_split(strings, &str[from], to - from, &g_num_strs);
	return (strings);
}
