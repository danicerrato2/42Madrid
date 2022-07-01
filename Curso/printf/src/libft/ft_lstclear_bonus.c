/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:01:26 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/01 10:00:08 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux_lst;
	t_list	*aux2_lst;

	aux_lst = *lst;
	while (aux_lst != NULL)
	{
		aux2_lst = aux_lst->next;
		del(aux_lst->content);
		free(aux_lst);
		aux_lst = aux2_lst;
	}
	*lst = NULL;
}
