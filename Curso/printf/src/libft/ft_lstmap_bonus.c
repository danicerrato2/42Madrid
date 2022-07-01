/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:04:28 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/01 10:00:33 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*aux_lst;
	t_list	*new_elem;

	if (lst == NULL)
		return (NULL);
	aux_lst = lst;
	new_lst = NULL;
	while (aux_lst != NULL)
	{
		new_elem = ft_lstnew(f(aux_lst->content));
		if (new_elem == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		aux_lst = aux_lst->next;
	}
	return (new_lst);
}
