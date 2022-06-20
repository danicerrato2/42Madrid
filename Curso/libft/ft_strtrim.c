/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:37:52 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/20 20:20:14 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char *set)
{
	int	i;

	if (set == NULL)
		return (0);
	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	int		from;
	int		to;
	char	*trim;

	if (str == NULL)
		return (NULL);
	from = 0;
	to = ft_strlen((char *)str);
	while (from != to && is_in_set((char)str[from], (char *)set) == 1)
		from++;
	while (from != to && is_in_set((char)str[to - 1], (char *)set) == 1)
		to--;
	trim = malloc(to - from + 1);
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, (char *)str + from, to - from + 1);
	return (trim);
}
