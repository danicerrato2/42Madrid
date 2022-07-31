/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:39:40 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/31 12:27:19 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define MAX_FDS 1024

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
size_t	find_n(const char *str, size_t size);
char	*ft_strnjoin(char *s1, char *s2, size_t size);

#endif
