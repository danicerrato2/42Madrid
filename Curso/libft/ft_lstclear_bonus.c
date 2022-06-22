#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*auxLst;
	t_list	*aux2Lst;

	auxLst = *lst;
	while (auxLst != NULL)
	{
		aux2Lst = auxLst->next;
		del(auxLst->content);
		free(auxLst);
		auxLst = aux2Lst;
	}
	*lst = NULL;
}
