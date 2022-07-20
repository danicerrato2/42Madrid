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

int	check_save(char **save, char **str)
{
	size_t	n_pos;
	size_t	save_len;
	char	*new_save;

	if (*save == NULL)
		return (0);
	save_len = ft_strlen(*save);
	n_pos = find_n(*save, save_len);
	*str = ft_strnjoin(NULL, *save, n_pos);
	if (*str == NULL)
		return (1);
	new_save = ft_strnjoin(NULL, *save + n_pos, save_len - n_pos);
	free(*save);
	*save = new_save;
	if (save_len == n_pos && (*str)[n_pos - 1] != '\n')
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			buf[BUFFER_SIZE];
	char			*str;
	size_t			n_pos;
	size_t			bytes_read;

	str = NULL;
	n_pos = check_save(&save, &str);
	if (n_pos != 0)
		return (str);
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE)
	{
		ft_bzero(&buf, BUFFER_SIZE);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		n_pos = find_n(buf, bytes_read);
		str = ft_strnjoin(str, buf, n_pos);
		if (str == NULL)
			return (NULL);
		if (n_pos != ft_strlen(buf) || buf[n_pos - 1] == '\n')
			break;
	}
	save = ft_strnjoin(NULL, buf + n_pos, ft_strlen(buf) - n_pos);
	return (str);
}
