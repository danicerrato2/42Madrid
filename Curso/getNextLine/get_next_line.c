/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:42:12 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/14 13:08:57 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cut_and_save(const char *buf, size_t n, char *str, char *save)
{
	if (str == NULL)
	{
		str = ft_strnjoin(str, save, n);
		save = save + n;
	}
	else
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			buf[BUFFER_SIZE];
	char			*str;
	size_t			n_flag;
	size_t			bytes_read;

	n_flag = find_n(save, ft_strlen(save));
	str = NULL;
	bytes_read = BUFFER_SIZE;
	while (n_flag == -1 && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		n_flag = find_n(buf, bytes_read);
		if (n_flag == -1)
		{
			str = ft_strnjoin(str, buf, bytes_read);
			if (str == NULL)
				return (NULL);
		}
	}
	cut_and_save(buf, n_flag, str, save);
	return (str);
}
