#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *auxLst;

	auxLst = lst;
	while (auxLst != NULL)
	{
		f(auxLst->content);
		auxLst = auxLst->next;
	}
}
