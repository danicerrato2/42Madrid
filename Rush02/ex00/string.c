/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:45:54 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/10 18:55:30 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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
	return (line);
}
