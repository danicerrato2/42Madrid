/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:38:42 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/15 20:03:13 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	num_words(char *str, char *charset)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (is_charset(str[i], charset) == 1 && str[i])
			i++;
		if (!str[i])
			break ;
		while (is_charset(str[i], charset) == 0 && str[i])
			i++;
		words++;
	}
	return (words);
}

int	split_words(char **strings, char *str, char *charset)
{
	int	i;
	int	num_word;
	int	ini_word;

	num_word = 0;
	i = -1;
	while (str[++i])
	{
		while (is_charset(str[i], charset) == 1 && str[i])
			i++;
		ini_word = i;
		while (is_charset(str[i], charset) == 0 && str[i])
			i++;
		strings[num_word] = (char *)malloc((i - num_word + 1) * sizeof(char));
		if (strings[num_word] == NULL)
			return (0);
		copy_str(strings[num_word], &str[ini_word], i - ini_word);
		if (str[i] == '\0')
			break ;
		num_word++;
	}
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**strings;
	char	*aux;
	int		words;

	aux = str;
	words = num_words(aux, charset);
	strings = (char **)malloc((words + 1) * sizeof(char *));
	if (strings == NULL)
		return (0);
	if (split_words(strings, aux, charset) == 0)
		return (0);
	strings[words] = 0;
	return (strings);
}
