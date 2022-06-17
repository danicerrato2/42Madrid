/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:52:30 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/17 09:52:32 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	concat_sep(char *str, char *sep, int *pos_str)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		str[*pos_str] = sep[i];
		i++;
		(*pos_str)++;
	}
}

void	ft_join(int size, char *str, char *sep, char **strs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			str[k] = strs[i][j];
			k++;
			j++;
		}
		if (i + 1 != size)
			concat_sep(str, sep, &k);
		i++;
	}
	str[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		tam;
	char	*str;

	if (size <= 0)
		return ("");
	i = 0;
	tam = 0;
	while (i < size)
	{
		tam += ft_strlen(strs[i]);
		i++;
	}
	tam += (size - 1) * ft_strlen(sep) + 1;
	str = (char *)malloc(tam * sizeof(char));
	ft_join(size, str, sep, strs);
	return (str);
}
