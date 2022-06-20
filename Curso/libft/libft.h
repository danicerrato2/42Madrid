/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:11:07 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/20 14:22:02 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(char *str);
void			ft_bzero(void *str, size_t len);
void			*ft_calloc(int count, int size);
int				isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *str, int c, size_t len);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *str, int c, size_t len);
char			**ft_split(char *str, char *charset);
char			*ft_strchr(const char *str, size_t c);
char			*ft_strdup(char *src);
char			*ft_strjoin(int size, char **strs, char *sep);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_strlen(char *str);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strnstr(const char *str, const char *substr, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif
