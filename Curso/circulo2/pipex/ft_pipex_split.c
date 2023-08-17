/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 12:38:42 by dcerrato          #+#    #+#             */
/*   Updated: 2023/08/17 19:13:25 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>




void	pipex_copy_str(char *dest, char *src, int size)
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

int	pipex_num_words(char *str, char c)
{
	int		words;
	int		i;
	char	c_to_search;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		c_to_search = c;
		if (str[i] == '\"' || str[i] == '\'')
			c_to_search = str[i++];
		if (str[i] == 0)
			break ;
		while (str[i] && str[i] != c_to_search)
			i++;
		printf("%c\n", str[i]);
		words++;
	}
	return (words);
}

void	pipex_split_words(char **strings, char *str, char c)
{
	int		i;
	int		num_word;
	int		ini_word;
	char	c_to_search;

	num_word = 0;
	i = -1;
	while (str[++i])
	{
		while (str[i] && str[i] == c)
			i++;
		c_to_search = c;
		if (str[i] == '\"' || str[i] == '\'')
			c_to_search = str[i++];
		ini_word = i;
		while (str[i] && str[i] != c_to_search)
			i++;
		strings[num_word] = (char *)malloc((i - ini_word + 1) * sizeof(char));
		pipex_copy_str(strings[num_word], &str[ini_word], i - ini_word);
		if (ft_strncmp(strings[num_word], "", -1) == 0)
			free(strings[num_word]);
		if (str[i] == '\0')
			break ;
		num_word++;
	}
}

char	**ft_pipex_split(const char *str, char c)
{
	char	**strings;
	char	*aux;
	int		words;

	aux = (char *)str;
	words = pipex_num_words(aux, c);
	printf("Num words = %d\n", words);
	strings = (char **)malloc((words + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	pipex_split_words(strings, aux, c);
	strings[words] = 0;
	return (strings);
}
