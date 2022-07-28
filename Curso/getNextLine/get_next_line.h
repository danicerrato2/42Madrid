/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:39:40 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/28 18:36:38 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
size_t	find_n(const char *str, size_t size);
char	*ft_strnjoin(char *s1, char *s2, size_t size);


void	ft_bzero(char (*str)[], size_t size);
#endif
