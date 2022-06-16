/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:45:54 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/11 22:42:09 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

int	g_i;
int	g_s1_len;
int	g_s2_len;

char	*concat_strs(char *s1, char *s2)
{
	char	*new;

	g_s1_len = 0;
	while (s1[g_s1_len] != '\0')
		g_s1_len++;
	g_s2_len = 0;
	while (s2[g_s2_len] != '\0')
		g_s2_len++;
	new = (char *)malloc((g_s1_len + g_s2_len + 1) * sizeof(char));
	g_i = 0;
	while (s1[g_i] != '\0')
	{
		new[g_i] = s1[g_i];
		g_i++;
	}
	new[g_i++] = ' ';
	while (s2[g_i - g_s1_len - 1] != '\0')
	{
		new[g_i] = s2[g_i - g_s1_len - 1];
		g_i++;
	}
	new[g_i] = '\0';
	return (new);
}

char	*concat(char *str, char last, int size)
{
	char	*new;

	new = (char *)malloc((size + 1) * sizeof(char));
	g_i = 0;
	while (str != NULL && str[g_i] != '\0')
	{
		new[g_i] = str[g_i];
		g_i++;
	}
	new[g_i++] = last;
	new[g_i] = '\0';
	if (str != NULL)
		free(str);
	return (new);
}

char	*read_line(int fd)
{
	char	c;
	char	*line;

	g_i = 0;
	line = NULL;
	while (read(fd, &c, 1) != 0 && c != '\n')
	{
		g_i++;
		line = concat(line, c, g_i);
	}
	if (c == '\n' && line == NULL)
		return ("");
	return (line);
}

char	*safe_number(char *line, int *j)
{
	char	*number;

	number = NULL;
	while (line[*j] >= '0' && line[*j] <= '9')
	{
		(*j)++;
		number = concat(number, line[*j - 1], *j);
	}
	return (number);
}

char	*safe_word(char *line, int *j)
{
	int		size;
	char	*word;

	word = NULL;
	size = 0;
	while (line[*j] != '\0')
	{
		if (line[*j] < 32 || line[*j] == 127)
			return (NULL);
		if (line[*j] != ' ' || line[*j - 1] != ' ')
		{
			size++;
			word = concat(word, line[*j], size);
		}
		(*j)++;
	}
	return (word);
}
