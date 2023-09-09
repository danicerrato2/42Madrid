/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcerrato <dcerrato@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:18:21 by dcerrato          #+#    #+#             */
/*   Updated: 2023/09/09 15:00:41 by dcerrato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list	*ft_lstnew(t_philo *content)
{
	t_list	*new_lst;

	new_lst = malloc(sizeof(t_list));
	if (new_lst == NULL)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	new_lst->prev = NULL;
	return (new_lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*first;

	if (*lst)
	{
		first = *lst;
		first->prev = new;
		new->content->right = first->content;
		new->next = first;
	}
	*lst = new;
}

void	ft_lstclear(t_list **lst, int num_nodes, void (*del)(void *))
{
	t_list	*aux_lst;
	t_list	*aux2_lst;
	int		i;

	aux_lst = *lst;
	i = -1;
	while (++i < num_nodes)
	{
		aux2_lst = aux_lst->next;
		if (del)
			del(aux_lst->content);
		free(aux_lst);
		aux_lst = aux2_lst;
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, int num_nodes, void (*f)(void *))
{
	t_list	*aux_lst;
	int		i;

	aux_lst = lst;
	i = -1;
	while (++i < num_nodes)
	{
		f(aux_lst);
		aux_lst = aux_lst->next;
	}
}

t_list	*ft_lstlast(t_list *lst, int num_nodes)
{
	t_list	*aux_lst;
	t_list	*last;
	int		i;

	aux_lst = lst;
	last = NULL;
	i = -1;
	while (++i < num_nodes)
	{
		last = aux_lst;
		aux_lst = aux_lst->next;
	}
	return (last);
}
