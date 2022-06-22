#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newLst;
	t_list	*auxNewLst;
	t_list	*auxLst;

	if (lst == NULL)
		return (NULL);
	newLst = malloc(sizeof(t_list));
	if (newLst == NULL)
		return (NULL);
	auxNewLst = newLst;
	auxLst = lst;
	while (auxLst != NULL)
	{
		auxNewLst->content = f(auxLst->content);
		if (auxLst->next != NULL)
		{
			auxNewLst->next = malloc(sizeof(t_list));
			if (auxNewLst->next == NULL)
			{
				ft_lstclear(&newLst, del);
				return (NULL);
			}
			auxNewLst = auxNewLst->next;
		}
		auxLst = auxLst->next;
	}
	auxNewLst->next = NULL;
	return (newLst);
}
