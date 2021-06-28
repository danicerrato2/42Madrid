/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:50:52 by dcerrato          #+#    #+#             */
/*   Updated: 2021/06/28 14:34:36 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	aux;
	int	tam;

	if (tab == NULL)
		return ;
	tam = size - 1;
	while (tam > 0)
	{
		i = 0;
		while (i < tam)
		{
			if (tab[i] > tab[i + 1])
			{
				aux = tab[i];
				tab[i] = tab [i + 1];
				tab[i + 1] = aux;
			}
			i++;
		}
		tam--;
	}
}
