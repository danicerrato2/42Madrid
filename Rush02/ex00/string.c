/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:45:54 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/11 17:30:29 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

char	*concat_strs(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*new;
	int		i;

	s1_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	s2_len = 0;
	while (s2[s2_len] != '\0')
		s2_len++;
	new = (char *)malloc((s1_len + s2_len) * sizeof(char));
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[i - s1_len] != '\0')
	{
		new[i] = s2[i - s1_len];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*concat(char *str, char last, int size)
{
	char	*new;
	int		i;

	new = (char *)malloc((size + 1) * sizeof(char));
	i = 0;
	while (str != NULL && str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	new[i++] = last;
	new[i] = '\0';
	if (str != NULL)
		free(str);
	return (new);
}

char	*read_line(int fd)
{
	int		i;
	char	c;
	char	*line;

	i = 0;
	line = NULL;
	while (read(fd, &c, 1) != 0 && c != '\n')
	{
		i++;
		line = concat(line, c, i);
	}
	if (c == '\n' && line == NULL)
		return ("");
	return (line);
}

char	*safe_number(char *line, int *i)
{
	char	*number;

	number = NULL;
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		(*i)++;
		number = concat(number, line[*i - 1], *i);
	}
	return (number);
}

char	*safe_word(char *line, int *i)
{
	int		size;
	char	*word;

	word = NULL;
	size = 0;
	while (line[*i] != '\0')
	{
		if (line[*i] < 32 || line[*i] == 127)
			return (NULL);
		if (line[*i] != ' ' || line[*i - 1] != ' ')
		{
			size++;
			word = concat(word, line[*i], size);
		}
		(*i)++;
	}
	return (word);
}
