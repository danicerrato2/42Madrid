/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:38:51 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/20 11:13:17 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	int	i;
	int	j;

	if (str == NULL || substr == NULL || n <= 0)
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (str[i + j] == substr[j] && i + j < n)
		{
			if (substr[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
