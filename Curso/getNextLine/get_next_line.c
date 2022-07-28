/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:42:12 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/28 20:07:47 by dcerrato         ###   ########.fr       */
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

char	*save_rest(int fd, size_t size)
{
	char	buf[BUFFER_SIZE];
	size_t	i;

	i = 0;
	while (i < size && read(fd, buf + i, 1) != 0)
		i++;
	return ft_strnjoin(NULL, buf, i);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			buf[BUFFER_SIZE + 1];
	char			*str;
	size_t			n_pos;
	size_t			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	n_pos = check_save(&save, &str);
	if (n_pos != 0)
		return (str);
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		n_pos = find_n(buf, bytes_read);
		str = ft_strnjoin(str, buf, n_pos);
		if (str == NULL)
			return (NULL);
		if (n_pos != bytes_read || buf[n_pos - 1] == '\n')
			break;
	}
	save = ft_strnjoin(NULL, buf + n_pos, bytes_read - n_pos);
	return (str);
}


/*
char	*get_next_line(int fd)
{
	static char		*save;
	char			buf[BUFFER_SIZE];
	char			*str;
	size_t			i;
	int				end_flag;

printf("\n");
	str = NULL;
	end_flag = check_save(&save, &str);
printf("Hola1\n");
	if (end_flag != 0)
		return (str);
	while (end_flag == 0)
	{
		ft_bzero(&buf, BUFFER_SIZE);
printf("Hola1.1\n");
		i = 0;
		while (i < BUFFER_SIZE && read(fd, buf + i, 1) != 0 && buf[i] != '\n')
			i++;
printf("Hola1.2\n");
		str = ft_strnjoin(str, buf, i);
printf("Hola1.3\n");
		if (i != BUFFER_SIZE || buf[i] == '\n')
			end_flag = 1;
	}
printf("Hola2\n");
	save = save_rest(fd, BUFFER_SIZE - i);
printf("Hola3\n");
	return (str);
}
*/
