#include "libft.h"

void ft_lstadd_toend(t_list **alst, t_list *new)
{
	int		length;

	length = ft_lstlength(*alst);
	while (length-- > 0)
		*alst = (*alst)->next;
	(*alst)->next = new;
}
