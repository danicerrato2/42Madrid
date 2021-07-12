/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:41:05 by dcerrato          #+#    #+#             */
/*   Updated: 2021/07/12 17:43:32 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*new_range;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	new_range = (int *)malloc((max - min) * sizeof(int));
	if (new_range == NULL)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		new_range[i] = min + i;
		i++;
	}	
	*range = new_range;
	return (max - min);
}
