/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:02:32 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/01 10:00:20 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*aux_lst;

	aux_lst = lst;
	while (aux_lst != NULL)
	{
		f(aux_lst->content);
		aux_lst = aux_lst->next;
	}
}
