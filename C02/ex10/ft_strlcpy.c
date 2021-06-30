/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:44:28 by dcerrato          #+#    #+#             */
/*   Updated: 2021/06/30 13:58:55 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	while (src[count] != '\0')
		count++;
	if (size > 0)
	{	
		i = 0;
		while (i < size - 1 && i < count)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (count + 1);
}
