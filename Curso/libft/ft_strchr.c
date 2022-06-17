/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:08:49 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/17 17:27:52 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str + i != NULL)
	{
		if (((char *)str)[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}