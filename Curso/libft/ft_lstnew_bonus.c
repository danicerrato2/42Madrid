#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newLst;

	newLst = malloc(sizeof(t_list));
	if (newLst == NULL)
		return (NULL);
	newLst->content = content;
	newLst->next = NULL;
	return (newLst);
}
