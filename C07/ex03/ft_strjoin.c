/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:41:12 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/08 13:24:18 by dcerrato         ###   ########.fr       */
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

int	ft_count_str(int size, char **strs)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	j = 0;
	while (i < size)
	{
		if (strs[counter][j] == '\0')
		{
			counter++;
			j = -1;
		}
		i++;
		j++;
	}
	return (counter);
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

void	ft_join(int tam, char *str, char *sep, char **strs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < tam - 1)
	{
		if (strs[j][k] == '\0')
		{
			concat_sep(str, sep, &i);
			j++;
			k = -1;
		}
		else
		{
			str[i] = strs[j][k];
			i++;
		}
		k++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		tam;

	if (size <= 0)
		return ("");
	tam = size + (ft_count_str(size, strs) - 1) * (ft_strlen(sep) - 1);
	str = (char *)malloc(tam * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_join(tam, str, sep, strs);
	return (str);
}
