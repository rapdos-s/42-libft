#include "libft_bonus.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	node -> content = content;
	node -> next = NULL;
	return (node);
}
