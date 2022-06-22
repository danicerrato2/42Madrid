#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*auxLst;
	t_list	*last;

	auxLst = *lst;
	if (auxLst == NULL)
	{
		*lst = new;
		return ;
	}
	while (auxLst != NULL)
	{
		last = auxLst;
		auxLst = auxLst->next;
	}
	last->next = new;
}
