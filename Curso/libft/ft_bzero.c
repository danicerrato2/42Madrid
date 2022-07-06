/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:03:44 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/06 10:29:30 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	size_t	i;

	if (str == NULL)
		return ;
	i = 0;
	while (i < len)
	{
		((char *)str)[i] = 0;
		i++;
	}
}
