/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:38:42 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/24 17:34:42 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		free(strs[i]);
	free(strs);
}

void	copy_str(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	num_words(char *str, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (!str[i])
			break ;
		while (str[i] != c && str[i])
			i++;
		words++;
	}
	return (words);
}

int	split_words(char **strings, char *str, char c)
{
	int	i;
	int	num_word;
	int	ini_word;

	num_word = 0;
	i = -1;
	while (str[++i])
	{
		while (str[i] == c && str[i])
			i++;
		ini_word = i;
		while (str[i] != c && str[i])
			i++;
		strings[num_word] = (char *)malloc((i - ini_word + 1) * sizeof(char));
		if (strings[num_word] == NULL)
			return (0);
		copy_str(strings[num_word], &str[ini_word], i - ini_word);
		if (ft_strncmp(strings[num_word], "", -1) == 0)
			free(strings[num_word]);
		if (str[i] == '\0')
			break ;
		num_word++;
	}
	return (1);
}

char	**ft_split(const char *str, char c)
{
	char	**strings;
	char	*aux;
	int		words;

	aux = (char *)str;
	words = num_words(aux, c);
	strings = (char **)malloc((words + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	if (split_words(strings, aux, c) == 0)
	{
		free_all(strings);
		return (NULL);
	}
	strings[words] = 0;
	return (strings);
}
