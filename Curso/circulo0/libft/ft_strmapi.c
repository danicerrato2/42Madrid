/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:40:49 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/24 17:37:34 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		s_len;
	int		i;

	s_len = ft_strlen((char *)s);
	new_str = malloc(s_len + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i != s_len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
