/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:42:12 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/01 18:27:46 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_save(char **save, char **str)
{
	size_t	n_pos;
	size_t	save_len;
	char	*new_save;

	if (*save == NULL)
		return (BUFFER_SIZE);
	save_len = ft_strlen_gnl(*save);
	n_pos = find_n(*save, save_len);
	*str = ft_strnjoin(NULL, *save, n_pos);
	if (*str == NULL)
		return (0);
	if (save_len == n_pos && (*str)[n_pos - 1] != '\n')
	{
		free(*save);
		return (BUFFER_SIZE);
	}
	new_save = ft_strnjoin(NULL, *save + n_pos, save_len - n_pos);
	free(*save);
	*save = new_save;
	return (0);
}

void	ft_bzero_gnl(void *str, size_t len)
{
	size_t	i;

	if (str == NULL)
		return ;
	i = 0;
	while (i < len)
	{
		((char *)str)[i] = 0;
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buf[BUFFER_SIZE];
	char		*str;
	size_t		n_pos;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	n_pos = check_save(&save, &str);
	if (n_pos == 0)
		return (str);
	ft_bzero_gnl(&buf, n_pos);
	while (n_pos == BUFFER_SIZE && buf[n_pos - 1] != '\n')
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		n_pos = find_n(buf, (size_t)bytes_read);
		str = ft_strnjoin(str, buf, n_pos);
		if (str == NULL)
			return (NULL);
	}
	save = ft_strnjoin(NULL, buf + n_pos, (size_t)bytes_read - n_pos);
	return (str);
}
