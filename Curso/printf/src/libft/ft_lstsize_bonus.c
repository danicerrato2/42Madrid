/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:06:32 by dcerrato          #+#    #+#             */
/*   Updated: 2022/07/01 13:37:35 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*aux_lst;

	i = 0;
	aux_lst = lst;
	while (aux_lst != NULL)
	{
		i++;
		aux_lst = aux_lst->next;
	}
	return (i);
}
