#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*auxLst;
	t_list	*last;

	auxLst = lst;
	last = NULL;
	while (auxLst != NULL)
	{
		last = auxLst;
		auxLst = auxLst->next;
	}
	return (last);
}
