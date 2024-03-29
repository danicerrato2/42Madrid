/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:52:30 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/06 14:37:22 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*joined_str;
	int		i;
	int		j;

	joined_str = malloc(ft_strlen((char *)str1) + ft_strlen((char *)str2) + 1);
	if (joined_str == NULL)
		return (NULL);
	i = 0;
	while (str1 != NULL && str1[i] != 0)
	{
		joined_str[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 != NULL && str2[j] != 0)
	{
		joined_str[i + j] = str2[j];
		j++;
	}
	joined_str[i + j] = '\0';
	return (joined_str);
}
