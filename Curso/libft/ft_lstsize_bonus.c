#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*auxLst;

	i = 0;
	auxLst = lst;
	while (auxLst != NULL)
	{
		i++;
		auxLst = auxLst->next;
	}
	return (i);
}
