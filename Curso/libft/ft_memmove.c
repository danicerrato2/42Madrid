/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:45:49 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/17 14:02:13 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	buff[len];

	if (dst == NULL || scr == NULL)
		return (dst);
	while (i < len)
	{
		buff[i] = ((char *)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = buff[i];
		i++;
	}
	return (dst);
}
