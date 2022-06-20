/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:23:57 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/20 11:59:07 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (str1 == NULL || str2 == NULL || n <= 0)
	{
		if (str1 == NULL && str2 != NULL)
			return (-1);
		if (str1 != NULL && str2 == NULL)
			return (1);
		return (0);
	}
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}
