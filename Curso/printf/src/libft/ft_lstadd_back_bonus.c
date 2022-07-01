/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:59:24 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/01 13:36:43 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux_lst;
	t_list	*last;

	aux_lst = *lst;
	if (aux_lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (aux_lst != NULL)
	{
		last = aux_lst;
		aux_lst = aux_lst->next;
	}
	last->next = new;
}
