/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:43:03 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/02 12:03:03 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (str[i] != '\0')
	{
		j = i;
		k = 0;
		while (str[j] == to_find[k] && to_find[k] != '\0')
		{
			j++;
			k++;
		}
		if (to_find[k] == '\0')
			return (str + i);
		i++;
	}
	return (NULL);
}
