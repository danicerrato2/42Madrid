/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:03:48 by dcerrato          #+#    #+#             */
/*   Updated: 2022/06/24 17:04:22 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux_lst;
	t_list	*last;

	aux_lst = lst;
	last = NULL;
	while (aux_lst != NULL)
	{
		last = aux_lst;
		aux_lst = aux_lst->next;
	}
	return (last);
}
